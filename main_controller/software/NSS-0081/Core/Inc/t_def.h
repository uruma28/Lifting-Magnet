//インクルードファイル
#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include <main.h>
#include <mag_define.h>
#include <stm32g4xx_hal_flash.h>
#include <iwdg.h>
#include <tim.h>
#include <hrtim.h>
#include <usart.h>
#include <i2c.h>
#include <adc.h>
#include <string.h>
#include <stdio.h>
#include <arm_math.h>
#include <mag_table.h>
#include <version.h>

// ステート関数プロトタイプ
void State_Initial_Process(void);      // 初期化ステート処理
void State_Standby_Process(void);      // 待機ステート処理
void State_Lifting_Process(void);      // 着磁ステート処理
void State_Holding_Process(void);      // 保持ステート処理
void State_Release_Process(void);      // 脱磁ステート処理 
void State_Error_Process(void);        // 異常発生ステート処理
void State_Test_Process(void);         // テストステート処理
// 計算関数プロトタイプ
void calcControlv(void);
void calcInterface(void);
void calcMpwm(void);
void calcInputW(void);
void calcOutputI(void);
void calcHeattemp(void);
// パワーコントロール関数プロトタイプ
void ihpcntReset(void);
void ihpcntPon(void);
void ihpcntPoff(void);
void ihpcntPerr(void);
void ihpcntPwmstart(void);
void ihpcntPwmstop(void);
void ihpcntSoftstart(void);
void ihpcntPout(void);
// 周波数制御関数プロトタイプ
void adjust_Freq(void);
void phase_Direction(void);
void update_hrtim_registers(void);
void Init_picontroller(void);
void Search_resonance(void);
void Search_maxoutput(void);

// flash関連プロトタイプ
SYSTIM Get_Current_Time();
PageHeader Read_Page_Header(uint32_t page);
uint32_t Find_Latest_Data_Page(uint32_t start_page, uint32_t num_pages);
FlashError_t  Write_Data(uint32_t start_page, uint32_t num_pages, void* data, uint32_t size, uint32_t *sequence);
FlashError_t Read_Latest_Periodic_Data(DAT_CBL* data, uint32_t max_size);
FlashError_t Read_Latest_Request_Data(int16_t data[10][10], uint32_t max_size);
uint32_t Find_Next_Write_Page(uint32_t start_page, uint32_t num_pages) ;
FlashError_t Write_Periodic_Data(const DAT_CBL* data, uint32_t size);
FlashError_t Write_Request_Data(const int16_t data[10][10], uint32_t size);
FlashError_t Flash_Init(void);

// LCD関連プロトタイプ
int16_t readEncvalue(void);
int LCD_ClampValue(int value, int min, int max);
int LCD_ClampPower(int value);
int LCD_ClampFreq(int value);
void initSetting(void);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
LcdError_t LCD_WriteCmd(LCD_HandleTypeDef* hlcd, uint8_t cmd);
LcdError_t LCD_WriteData(LCD_HandleTypeDef* hlcd, uint8_t data);
LcdError_t LCD_Init(LCD_HandleTypeDef* hlcd);
LcdError_t LCD_Clear(LCD_HandleTypeDef* hlcd);
LcdError_t LCD_ClearBuffer(LCD_HandleTypeDef* hlcd);
LcdError_t LCD_ConvU16(char* str, uint8_t pos, uint16_t val, uint8_t width);
LcdError_t LCD_ConvU32(char* str, uint8_t pos, uint32_t val, uint8_t width);
LcdError_t LCD_ConvFloat(char* str, uint8_t pos, float val, uint8_t total_width, uint8_t frac_width);
LcdError_t LCD_Print(LCD_HandleTypeDef* hlcd, const char* str, uint8_t col, uint8_t row);
LcdError_t LCD_UpdateDisplay(LCD_HandleTypeDef* hlcd);
LcdError_t LCD_UpdateBuffer(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, int16_t value, BOOL show_value, BOOL blink_10, BOOL blink_1);
LcdError_t LCD_DisplayConfig10(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, BOOL blink);
LcdError_t LCD_DisplayConfig1(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, BOOL blink);
LcdError_t LCD_DisplayConfigSet(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, int16_t value);
LcdError_t LCD_DisplayPowerSet(LCD_HandleTypeDef* hlcd, uint8_t powerset);
LcdError_t LCD_DisplayFreqSet(LCD_HandleTypeDef* hlcd, uint16_t freqset);

// 基本情報表示プロトタイプ
void page00Dsp(void);
void page01Dsp(void);
void page02Dsp(void);
void page03Dsp(void);
void page04Dsp(void);
void page05Dsp(void);
void page06Dsp(void);
void page07Dsp(void);
void page08Dsp(void);
void page09Dsp(void);
void page10Dsp(void);
void page11Dsp(void);
void page12Dsp(void);
void page13Dsp(void);
void versionDsp(void);

// ポインタ関数テーブル定義
// ステート関数の型定義
typedef void (*StateFunction)(void);
// ステート関数テーブル
StateFunction stateTable[] = {
    State_Initial_Process,  // STATE_INITIAL
    State_Standby_Process,  // STATE_STANDBY
    State_Lifting_Process,  // STATE_LIFTING
    State_Holding_Process,  // STATE_HOLDING
    State_Release_Process,  // STATE_RELEASE
    State_Error_Process,    // STATE_ERROR
    State_Test_Process      // STATE_TEST
};
typedef void (*DisplayFunc)(void);
DisplayFunc disp[] = {page00Dsp,page01Dsp,page02Dsp,page03Dsp,page04Dsp,page05Dsp,page06Dsp,page07Dsp,
                        page08Dsp,page09Dsp,page10Dsp,page11Dsp,page12Dsp,page13Dsp,versionDsp};	                                                    // LCD表示関数を格納


//共通構造体タイプ宣言
ADC_CBL     adc;                // ADCコントロールブロック
IHP_CBL     ihp;                // パワーコントロールブロック
SIGI_CBL    sigI;               // 入力信号コントロールブロック
SIGO_CBL    sigO;               // 出力信号コントロールブロック
SYS_CBL     scnt;               // システムコントロールブロック
CALC_CBL    calc;               // 計算結果格納ブロック
LCD_CBL     lcd;                // LCDコントロールブロック
DAT_CBL     periodic_data;      // 周期保存データコントロールブロック
FreqPI_CBL  fpi;                // 周波数PI制御コントロールブロック
PowerPI_CBL ppi;                // 出力PI制御コントロールブロック

int16_t     data_Setting[10][10];   // 動作環境データ(RAM)00～99


arm_fir_instance_f32 S;
