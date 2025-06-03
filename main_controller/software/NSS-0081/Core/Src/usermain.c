/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.00
 *
 *    Copyright (C) 2006-2019 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2019/12/11.
 *
 *----------------------------------------------------------------------
*/

//インクルードエリア BEGIN

#include <t_def.h>


//インクルードエリア END

//タスク定義エリア BEGIN

//メインタスク定義
static void task_State(int stacd, void *exinf);
static ID	tskid_state;						//タスクID
static T_CTSK ctsk_state = {					//タスク生成情報
	.itskpri	= 3,
	.stksz		= 1024,
	.task		= task_State,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//Flash管理タスク定義
static void task_Flash(int stacd, void *exinf);
static ID	tskid_flash;					//タスクID
static T_CTSK ctsk_flash = {				//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Flash,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//Flash周期保存管理タスク定義
static void task_pFlash(int stacd, void *exinf);
static ID	tskid_pflash;					//タスクID
static T_CTSK ctsk_pflash = {				//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_pFlash,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// 通常時パワー制御タスク定義
static void task_Power(int stacd, void *exinf);
static ID	tskid_power;					//タスクID
static T_CTSK ctsk_power = {				//タスク生成情報
	.itskpri	= 4,
	.stksz		= 1024,
	.task		= task_Power,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// ソフトスタート時パワー制御タスク定義
static void task_Soft(int stacd, void *exinf);
static ID	tskid_soft;					//タスクID
static T_CTSK ctsk_soft = {				//タスク生成情報
	.itskpri	= 4,
	.stksz		= 1024,
	.task		= task_Soft,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// 位相差計算タスク定義
static void task_Phase(int stacd, void *exinf);
static ID	tskid_phase;					//タスクID
static T_CTSK ctsk_phase = {				//タスク生成情報
	.itskpri	= 6,
	.stksz		= 1024,
	.task		= task_Phase,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// 周波数制御タスク定義
static void task_Freq(int stacd, void *exinf);
static ID	tskid_freq;					//タスクID
static T_CTSK ctsk_freq = {				//タスク生成情報
	.itskpri	= 5,
	.stksz		= 1024,
	.task		= task_Freq,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// ADC管理タスク定義
static void task_ADC(int stacd, void *exinf);
static ID	tskid_adc;						//タスクID
static T_CTSK ctsk_adc = {					//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_ADC,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// 入力管理タスク定義
static void task_Input(int stacd, void *exinf);
static ID	tskid_input;					//タスクID
static T_CTSK ctsk_input = {				//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Input,
	.tskatr		= TA_HLNG | TA_RNG3,
};

// 出力管理タスク定義
static void task_Output(int stacd, void *exinf);
static ID	tskid_output;					//タスクID
static T_CTSK ctsk_output = {				//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Output,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//外部通信管理タスク定義
static void task_Communication(int stacd, void *exinf);
static ID	tskid_communication;			//タスクID
static T_CTSK ctsk_communication = {		//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Communication,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//計算管理タスク定義
static void task_Calc(int stacd, void *exinf);
static ID	tskid_calc;						//タスクID
static T_CTSK ctsk_calc = {					//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Calc,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//警報監視タスク定義
static void task_Alart(int stacd, void *exinf);
static ID	tskid_alart;					//タスクID
static T_CTSK ctsk_alart = {				//タスク生成情報
	.itskpri	= 4,
	.stksz		= 1024,
	.task		= task_Alart,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//LCD管理タスク定義
static void task_Lcd(int stacd, void *exinf);
static ID	tskid_lcd;					//タスクID
static T_CTSK ctsk_lcd = {				//タスク生成情報
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_Lcd,
	.tskatr		= TA_HLNG | TA_RNG3,
};

//状態監視タスク定義
static void task_Monitor(int stacd, void *exinf);
static ID	tskid_monitor;					//タスクID
static T_CTSK ctsk_monitor = {				//タスク生成情報
	.itskpri	= 2,
	.stksz		= 512,
	.task		= task_Monitor,
	.tskatr		= TA_HLNG | TA_RNG1,
};

// タスク定義エリア END

// 周期ハンドラ定義エリア BEGIN
// 1秒周期ハンドラ
static void Cyc_1Sec_Handler(void *exinf);
static ID	cycid_1;						// タスクID
static T_CCYC ccyc_1 = {					// タスク生成情報
	.cycatr		= TA_HLNG,
	.cychdr		= Cyc_1Sec_Handler,
	.cyctim		= 1000,
};
// 定期保存用周期ハンドラ 
static void Periodic_Write_Handler(void *exinf);
static ID	cycid_2;						// タスクID
static T_CCYC ccyc_2 = {					// タスク生成情報
	.cycatr		= TA_HLNG,
	.cychdr		= Periodic_Write_Handler,
	.cyctim		= 900000,
};
// 周期ハンドラ定義エリア END

// ミューテックス定義エリア BEGIN
static ID		mtxid_a;				// ミューテックスID
static T_CMTX	cmtx_a = {				// ミューテックス生成情報
	.mtxatr = TA_INHERIT,				// 優先度継承プロトコル設定
};
// ミューテックス定義エリア END

// イベントフラグ定義エリア BEGIN
// 環境設定用イベントフラグ
static ID flgid_a;						// イベントフラグID
static T_CFLG cflg_a = {				// イベントフラグ生成情報
	.flgatr = TA_TPRI | TA_WMUL,		// イベントフラグ属性
	.iflgptn = 0,
};
// 周期保存用イベントフラグ
static ID flgid_b;						// イベントフラグID
static T_CFLG cflg_b = {				// イベントフラグ生成情報
	.flgatr = TA_TPRI | TA_WMUL,		// イベントフラグ属性
	.iflgptn = 0,
};
// イベントフラグ定義エリア END

// セマフォ定義エリアBEGIN
// 環境設定用セマフォ
static ID 		FLASH_SEM;				// セマフォID
static T_CSEM	csem_a = {				// セマフォ生成情報
	.sematr = TA_TFIFO | TA_FIRST,		// セマフォ属性
	.isemcnt = 1,						// 資源数初期値
	.maxsem = 1,						// 資源数最大値
};

// LCD利用I2C用セマフォ
static ID 		I2C_SEM;				// セマフォID
static T_CSEM	csem_b = {				// セマフォ生成情報
	.sematr = TA_TFIFO | TA_FIRST,		// セマフォ属性
	.isemcnt = 1,						// 資源数初期値
	.maxsem = 1,						// 資源数最大値
};

// LCD利用I2C用セマフォ
static ID 		PHASE_SEM;				// セマフォID
static T_CSEM	csem_c = {				// セマフォ生成情報
	.sematr = TA_TFIFO | TA_FIRST,		// セマフォ属性
	.isemcnt = 1,						// 資源数初期値
	.maxsem = 1,						// 資源数最大値
};

// セマフォ定義エリアEND

// グローバル変数宣言
static uint32_t periodic_sequence = 0;
static uint32_t request_sequence = 0;
static BOOL g_over_temp = FALSE;
// グローバル変数としてLCDハンドルを定義
LCD_HandleTypeDef lcd_handle = {
    .hi2c = &hi2c1,            // 使用するI2Cハンドル
    .address = LCDADRESS,      // LCDのI2Cアドレス
    .timeout = 100,            // タイムアウト時間(ms)
    .buffer = {                // バッファの初期化
        .str1 = {0},          // 1行目バッファ初期化
        .str2 = {0},          // 2行目バッファ初期化
        .is_initialized = FALSE // 初期化フラグ
    }
};

const version_info_t VERSION_INFO = {
    .version = SOFTWARE_VERSION_STRING,
    .buildDate = __DATE__,
    .buildTime = __TIME__
};
//タスク関数エリア BEGIN

//メインタスク関数
static void task_State(int stacd, void *exinf)
{
	while(1) {
		state[scnt.mstn]();																					//メインステート番号によるステート関数実行
		tk_dly_tsk(10);
	}
}

//Flash管理タスク関数
static void task_Flash(int stacd, void *exinf)
{
    ER ercd;
	UINT flgptn;
    while (1) {
        // 環境設定保存用イベントフラグを待機
        ercd = tk_wai_flg(flgid_a,FLG_ON,(TWF_ANDW | TWF_CLR),&flgptn,TMO_FEVR);
        if (ercd == E_OK) {
            // data_Settingの書き込み
			data_Setting[0][1] = 0;
			Write_Request_Data((uint8_t*)data_Setting,sizeof(data_Setting));
			data_Setting[0][1] = 1;
        }
    }
}

//Flash周期保存管理タスク関数
static void task_pFlash(int stacd, void *exinf)
{
    ER ercd;
	UINT flgptn;
    while (1) {
        // 周期保存用イベントフラグを待機
        ercd = tk_wai_flg(flgid_b,FLG_ON,(TWF_ANDW | TWF_CLR),&flgptn,TMO_FEVR);
        if (ercd == E_OK) {
            // periodic_dataの書き込み
			Write_Periodic_Data((uint8_t*)&periodic_data, sizeof(periodic_data));
        }
    }
}

// パワー制御タスク関数
static void task_Power(int stacd, void *exinf)
{
	HRTIM_CompareCfgTypeDef sCompareCfg = {0};
	while(1){	
		if(!ihp.ss_en && ihp.pcnt_en){ // 通常時
			ppi.kp = data_Setting[EA_KPADJUST/ENV_GM][EA_KPADJUST%ENV_GM] / (float)100u;
			ppi.ki = data_Setting[EA_KIADJUST/ENV_GM][EA_KIADJUST%ENV_GM] / (float)1000u;
			ihpcntPout();
			update_hrtim_registers(); 																				// 周波数を反映したレジスタ値に更新
			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,calc.pw_mpwm);												// PWMモニタ出力
		}
		tk_dly_tsk(10);
	}
}

// ソフトスタート時パワー制御タスク関数
static void task_Soft(int stacd, void *exinf){
	while (1){	
		if (ihp.ss_en){ // ソフトスタート中
			if(data_Setting[EA_COMPEXPLORE/ENV_GM][EA_COMPEXPLORE%ENV_GM]){
				ihpcntSoftstart();																					// ソフトスタート計算・実行
			} else {
				ihpcntPwmstart();	// PWM出力を有効化
				if(!data_Setting[EA_FIXEDFREQ/ENV_GM][EA_FIXEDFREQ%ENV_GM]){										// 周波数固定モードではない
					Search_resonance();										// 共振周波数探査
				}
				Search_maxoutput();											// 最大出力探査
				data_Setting[EA_COMPEXPLORE/ENV_GM][EA_COMPEXPLORE%ENV_GM] = 1; // 
				tk_set_flg(flgid_a, FLG_ON);								// データ保存フラグオン
			}
		}
		tk_dly_tsk(10);			// 10ms待機
	}
}

// 周波数管理タスク関数
static void task_Freq(int stacd, void *exinf){
	while(1){
		if(!data_Setting[EA_FIXEDFREQ/ENV_GM][EA_FIXEDFREQ%ENV_GM]){												// 周波数固定モードではない
			adjust_Freq();
		}else{
			ihp.current_freq = data_Setting[EA_DEFFREQ/ENV_GM][EA_DEFFREQ%ENV_GM] * 1000;
            ihp.new_period = (uint32_t)(HRTIM_CLOCK / ihp.current_freq);
		}
        tk_dly_tsk(10);  // 10msごとに周波数更新
    }
}

// 位相差反映周波数計算タスク関数
static void task_Phase(int stacd, void *exinf){
	while(1){
		if(!ihp.manualmode_Freq && ihp.sstart_end && !data_Setting[EA_FIXEDFREQ/ENV_GM][EA_FIXEDFREQ%ENV_GM]){		// 自動周波数制御モードかつソフトスタート完了後かつ周波数固定モードではない
			phase_Direction();					// 周波数調整
		}
		tk_dly_tsk(10);
	}
}

//　ADC管理タスク関数
static void task_ADC(int stacd, void *exinf)
{
	uint16_t adc_mem_buf[7] = {0};													// ADCメモリバッファ
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);							// キャリブレーション
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_mem_buf, 7);	 						// DMA利用ADCスタート
	while(1) {
		// ADCメモリバッファ読み込み
		adc.inputI = adc_mem_buf[0];											//入力電流AD値格納
		adc.outputI = adc_mem_buf[1];											//出力電流AD値格納
		adc.hstmp = adc_mem_buf[2];												//ヒートシンク温度AD値格納
		adc.interfaceI = adc_mem_buf[3];										//インターフェース電流AD値格納
		adc.phase1 = adc_mem_buf[4];											//位相比較電圧1AD値格納
		adc.phase2 = adc_mem_buf[5];											//位相比較電圧2AD値格納
		adc.cntV = adc_mem_buf[6];												//監視電圧AD値格納
		tk_dly_tsk(10);
	}
}

// 信号入力管理タスク関数
static void task_Input(int stacd, void *exinf)
{
	while(1) {
		sigI.heat = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_13)== 1 ? OFF : ON;			//	加熱ON/OFF信号確認(反転させる)
		sigI.ilock = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_14);						//	インターロック信号確認
		sigI.reset = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_15)== 1 ? OFF : ON;		//	リセット信号確認(反転させる)
		if(sigI.reset != sigI.reset_old && sigI.reset){
			ihp.reset_on = ON;													//	リセットスタートフラグON
		}
		sigI.reset_old = sigI.reset;
		sigI.encoder = HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4) == 1 ? OFF : ON;		//	ロータリーエンコーダ押下信号確認(反転させる)
		if(sigI.encoder != sigI.encoder_old && sigI.encoder){
			lcd.encoder_on = ON;												//　エンコーダ押下信号オン
		}
		sigI.encoder_old = sigI.encoder;
		tk_dly_tsk(50);															//	タスクディレイ
	}
}

// 信号出力管理タスク関数
static void task_Output(int stacd, void *exinf)
{
	while(1) {
		if(sigO.heating){
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,ON);								//	加熱中信号出力オン
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,OFF);							//	加熱中LED信号出力オン
		}else{
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,OFF);							//	加熱中信号出力オフ
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,ON);							//	加熱中LED信号出力オフ
		}
		if(sigO.ready){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,ON);								//	READY信号出力オン
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,OFF);							//	READYLED信号出力オン
		}else{
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,OFF);							//	READY信号出力オフ
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,ON);							//	READYLED信号出力オフ
		}
		if(sigO.alarm){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,ON);								//	エラー発生信号出力オン
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,OFF);							//	エラー発生LED信号出力オン
		}else{
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,OFF);							//	エラー発生信号出力オフ
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,ON);							//	エラー発生LED信号出力オフ
		}
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,ON);								//	LCDバックライト制御信号出力
		tk_dly_tsk(100);
	}
}

//外部通信管理タスク関数
static void task_Communication(int stacd, void *exinf)
{
	while(1) {
		tk_dly_tsk(5000);
	}
}

//計算管理タスク関数
static void task_Calc(int stacd, void *exinf)
{
	while(1) {
		calcControlv();															// 15V制御電圧計算
		calcInterface();														// インターフェース電流計算
		calcMpwm();																// モニタPWM計算
		calcInputW();															// 入力電流W換算値計算
		calcOutputI();															// 出力電流値計算
		calcHeattemp();															// ヒートシンク温度計算
		tk_dly_tsk(10);
	}
}

//警報監視タスク
static void task_Alart(int stacd, void *exinf)
{
	while (1){	
		if(calc.htmp > data_Setting[EA_TMPALM/ENV_GM][EA_TMPALM%ENV_GM] || calc.htmp < -5){		// ヒートシンクオーバーヒート検知 (-5℃以下もエラーとして扱う)
			if(!ihp.hstoverr){													// ヒートシンクオーバーヒート初回検知 
				ihp.hstoverr = ON;												// オーバーヒート検知済み設定 
			}
		}
		if(ihp.hstoverr){														// オーバーヒート検知済み 
			if(calc.htmp <= data_Setting[EA_TMPREL/ENV_GM][EA_TMPREL%ENV_GM] && calc.htmp >= -5){	// オーバーヒートプロテクト解除チェック 
				ihp.hstoverr = OFF;												// オーバーヒート検知済みクリア
			}
		}

		if(calc.pw_outputi > data_Setting[EA_LMTOUTPUT/ENV_GM][EA_LMTOUTPUT%ENV_GM] * 100 && !ihp.Searching){	// 過電流検知　1000倍値比較かつ最大出力探査時以外
			if(!ihp.oscerr){
				ihp.oscerr = ON;												// 発振器エラー検知済み設定
			}
		}
		tk_dly_tsk(100);
	}
}

// LCD管理タスク
static void task_Lcd(int stacd, void *exinf)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;  									// LCD制御ハンドルを取得

	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, 70);							// LCDコントラスト
	lcd.rotaryState = LCD_INFO;													// 基本情報表示画面で開始
	LCD_State current_state = LCD_INFO;     									// 基本情報表示画面で開始
	uint8_t info_display_no = 0;            									// 基本情報番号0番設定
	uint8_t place10 =0 ,place1 = 0;												// 位別選択番号
	int16_t temp_value = 0;  													// 一時的な設定値
	uint8_t powerset = 0;														// パワー手動設定値
	uint16_t freqset = 25000;													// 周波数手動設定値
	ihp.manualmode_Power = ihp.manualmode_Freq = FALSE;							// 手動制御モードオフ

	// 時間管理
	SYSTIM current_time;														// 時間取得用
	uint32_t last_blink_time  = 0;												// 点滅用前回時間
	uint32_t last_refresh_time  = 0;											// 前回画面更新時間
	BOOL blink_flag = FALSE;													// 点滅フラグ定義

	// 初期画面表示
	if(lcd.status == LCD_OK){
		disp[info_display_no]();
	}

	while (1){
		current_time  = Get_Current_Time();										// 現在時刻取得
		// 点滅制御（500ms間隔）
		if ((current_time.lo - last_blink_time) >= 500){ // 0.5秒間隔で点滅処理
            blink_flag = !blink_flag;
            last_blink_time = current_time.lo;									// ラストタイム更新
        }
		if(lcd.status == LCD_OK){
			// ロータリーエンコーダ読み取り
			tk_loc_mtx(mtxid_a,TMO_FEVR);											// ミューテックスロック
			int16_t rotary_count  = readEncvalue();									// ロータリーエンコーダの回転情報処理・初期化
			tk_unl_mtx(mtxid_a);													// ミューテックスアンロック

			// 状態に応じた処理
			switch (current_state){
				// 基本情報表示画面
				case LCD_INFO:
					// リフレッシュレートに基づく表示更新
					if((current_time.lo - last_refresh_time) >= 200){ // リフレッシュレート確認
						disp[info_display_no]();									// 画面表示更新
						last_refresh_time = current_time.lo;						// ラストタイム更新
					}

					// ロータリーエンコーダ操作処理
					if(rotary_count){
						info_display_no = (info_display_no + rotary_count + TOTAL_INFO_PAGES) % TOTAL_INFO_PAGES;
						disp[info_display_no]();									// 基本情報表示番号によるLCD表示関数実行
					}

					// ボタン押下で設定モードへ
					if(lcd.encoder_on){
						current_state = LCD_DIGIT2;								// 環境設定項目番号10の位選択画面に遷移
						LCD_DisplayConfig10(hlcd, place10, place1, FALSE);  		// LCD表示を更新	
						lcd.encoder_on = OFF;  										// ボタン押下フラグリセット	
					}
					break;

				// 環境設定項目番号10の位選択画面
				case LCD_DIGIT2:
					// ロータリーエンコーダ操作処理
					if (rotary_count){
        		        place10 = (place10 + rotary_count + 10) % 10;  				// 10の位保持
        		        LCD_DisplayConfig10(hlcd, place10, place1, FALSE);  		// LCD表示を更新
					}

					// 点滅表示更新
					LCD_DisplayConfig10(hlcd, place10, place1, blink_flag);

					// ボタン押下で1の位選択へ
					if (lcd.encoder_on) {
						current_state = LCD_DIGIT1;
						LCD_DisplayConfig1(hlcd, place10, place1, FALSE);
						lcd.encoder_on = OFF;
					}
					break;
				case LCD_DIGIT1: // 環境設定項目番号1の位桁選択画面
					// ロータリー操作処理
					if (rotary_count) {
        	            place1 = (place1 + rotary_count + 10) % 10;					// 1の位保持
        		        LCD_DisplayConfig1(hlcd, place10, place1, FALSE);  			// LCD表示を更新
					}

        	        // 点滅表示更新
					LCD_DisplayConfig1(hlcd, place10, place1, blink_flag);

        	        // ボタン押下処理
					if (lcd.encoder_on) {
						if (place10 == 0 && place1 == 0) {
        	                // 設定00選択時は基本画面に戻る
							current_state = LCD_INFO;
							info_display_no = 0;
							data_Setting[0][1] = 0;
							disp[info_display_no]();
        	            } else if (place10 == 8 && place1 == 0) { // 出力手動制御モードに移行
							current_state = LCD_DirectPower;
							ihp.manualmode_Power = TRUE;
							LCD_DisplayPowerSet(hlcd,powerset);
						} else if (place10 == 8 && place1 == 1) { // 周波数手動制御モードに移行
							current_state = LCD_DirectFreq;
							ihp.manualmode_Freq = TRUE;
							ihp.manual_freq = data_Setting[EA_DEFFREQ/ENV_GM][EA_DEFFREQ%ENV_GM] * 1000;				// デフォルト周波数セット
							LCD_DisplayFreqSet(hlcd,freqset);
						} else {
        	                // 設定値変更モードへ
							temp_value = data_Setting[place10][place1];
							current_state = LCD_SETCONFIG;
							LCD_DisplayConfigSet(hlcd, place10, place1, temp_value);
						}
						lcd.encoder_on = OFF;
					}
					break;
				case LCD_SETCONFIG: // 環境設定選択項目設定画面
					// 設定変更許可時のみ値を変更
					if (rotary_count && (data_Setting[0][1] == 1 || (place10 == 0 && place1 == 1))) {
        	            SettingRange *range = &setting_ranges[place10][place1];
						temp_value = LCD_ClampValue(temp_value + rotary_count, range->min, range->max);
						LCD_DisplayConfigSet(hlcd, place10, place1, temp_value);
					}

        	        // ボタン押下で値を確定
					if (lcd.encoder_on) {
        	            if (place10 == 0 && place1 == 1) { // 変更許可設定
							data_Setting[0][1] = temp_value;
						} else if (data_Setting[0][1] == 1) {
        	                if (place10 == 9 && place1 == 9 && temp_value == 1) { // 設定初期化
								initSetting();
        	                } else { // 設定値セット
								data_Setting[place10][place1] = temp_value;
							}
							tk_set_flg(flgid_a, FLG_ON);		// データ保存フラグオン
						}
						current_state = LCD_DIGIT2;
						LCD_DisplayConfig10(hlcd, place10, place1, FALSE);
						lcd.encoder_on = OFF;
					}
					break;
				case LCD_DirectPower:	// パワー手動制御モード
					// リフレッシュレートに基づく表示更新
					if((current_time.lo - last_refresh_time) >= 200){ // リフレッシュレート確認
						LCD_DisplayPowerSet(hlcd, powerset);								// 画面表示更新
						last_refresh_time = current_time.lo;						// ラストタイム更新
					}
					// ロータリー操作処理
					if (rotary_count) {
        	            powerset = LCD_ClampPower(powerset + rotary_count); // 設定範囲制限
        		        LCD_DisplayPowerSet(hlcd, powerset);  			// LCD表示を更新
						ihp.manual_power = powerset;					// 設定値を処理用変数に反映
					}
					// ボタン押下でモード終了 基本情報画面に戻る
					if (lcd.encoder_on) {
						current_state = LCD_INFO;
						ihp.manualmode_Freq = FALSE;
						powerset = 0;
						info_display_no = 0;
						disp[info_display_no]();
					}
					break;
				case LCD_DirectFreq:	// 周波数手動制御モード
					// リフレッシュレートに基づく表示更新
					if((current_time.lo - last_refresh_time) >= 200){ // リフレッシュレート確認
						LCD_DisplayFreqSet(hlcd, freqset);									// 画面表示更新
						last_refresh_time = current_time.lo;						// ラストタイム更新
					}
					// ロータリー操作処理
					if (rotary_count) {
        	            freqset = LCD_ClampFreq(freqset + (rotary_count * 100)); // 設定範囲制限 数値は100単位で変更する
        		        LCD_DisplayFreqSet(hlcd, freqset);  			// LCD表示を更新
						ihp.manual_freq = freqset;						// 設定値を処理用変数に反映
					}
					// ボタン押下でモード終了 基本情報画面に戻る
					if (lcd.encoder_on) {
						current_state = LCD_INFO;
						ihp.manualmode_Freq = FALSE;
						freqset = data_Setting[EA_DEFFREQ/ENV_GM][EA_DEFFREQ%ENV_GM] * 1000;
						ihp.current_freq = freqset;
						ihp.new_period = (uint32_t)(HRTIM_CLOCK / freqset);
						info_display_no = 0;
						disp[info_display_no]();
					}
					break;
				default:
					break;
			}
		}else{
			lcd.status = LCD_Init(hlcd);
		}
		tk_dly_tsk(10);
	}
}

// 監視タスク関数
static void task_Monitor(int stacd, void *exinf){
	while(1) {
		HAL_IWDG_Refresh(&hiwdg);					// ウォッチドッグカウンタリセット
        tk_dly_tsk(100);
    }
}

// タスク関数エリア END

// 周期ハンドラ関数エリア BEGIN

// LED点滅周期ハンドラ
static void Cyc_1Sec_Handler(void *exinf)
{
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_11);										// LED出力反転
	periodic_data.atimtt++;														// 稼働時間更新
}

// 15分ごとの定期書き込みを行う周期ハンドラ
// 引数：無し
// 返り値：無し
void Periodic_Write_Handler(void *exinf) {
    tk_set_flg(flgid_b,FLG_ON);													// 周期保存イベントフラグセット
}

// 周期ハンドラ関数エリア END

// 入力キャプチャ割り込み関数
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	static BOOL voltage_captured = FALSE;
    static BOOL current_captured = FALSE;
	static uint32_t voltage_capture, current_capture;

    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {  // 電圧波形
        voltage_capture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
        voltage_captured = TRUE;
    }
    else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {  // 電流波形
        current_capture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
        current_captured = TRUE;
    }

    // 両方のキャプチャが完了したら位相比較タスクを起動
    if(voltage_captured && current_captured) {
        voltage_captured = FALSE;
        current_captured = FALSE;
		ihp.voltage_capture = voltage_capture;
		ihp.current_capture = current_capture;
    }	
}

//usermain関数
EXPORT int usermain(void)
{
	// PWMタイマ開始
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	// エンコーダ読み取りタイマ開始
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	// 入力キャプチャの割り込み開始
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3);
	// LCDコントラストタイマ
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);

	// 周期ハンドラ生成&開始
	cycid_1 = tk_cre_cyc(&ccyc_1);
	tk_sta_cyc(cycid_1);
	cycid_2 = tk_cre_cyc(&ccyc_2);
	tk_sta_cyc(cycid_2);
	// ミューテックス生成
	mtxid_a = tk_cre_mtx(&cmtx_a);
	// イベントフラグ生成
	flgid_a = tk_cre_flg(&cflg_a);
	flgid_b = tk_cre_flg(&cflg_b);
	// セマフォ生成
	FLASH_SEM = tk_cre_sem(&csem_a);
	I2C_SEM = tk_cre_sem(&csem_b);
	// LCD初期化
	lcd.status = LCD_Init(&lcd_handle);
	// Flashから最新のデータを読み込む
	Flash_Init();
	// PI制御構造体初期化
	Init_picontroller();
	// 各変数初期値セット
	Init_parameter();
	//タスク作成&開始
	tskid_state = tk_cre_tsk(&ctsk_state);
	tk_sta_tsk(tskid_state, 0);
	tskid_flash = tk_cre_tsk(&ctsk_flash);
	tk_sta_tsk(tskid_flash, 0);
	tskid_pflash = tk_cre_tsk(&ctsk_pflash);
	tk_sta_tsk(tskid_pflash, 0);
	tskid_power = tk_cre_tsk(&ctsk_power);
	tk_sta_tsk(tskid_power, 0);
	tskid_soft = tk_cre_tsk(&ctsk_soft);
	tk_sta_tsk(tskid_soft, 0);
	tskid_freq = tk_cre_tsk(&ctsk_freq);
	tk_sta_tsk(tskid_freq, 0);
	tskid_phase = tk_cre_tsk(&ctsk_phase);
	tk_sta_tsk(tskid_phase, 0);
	tskid_adc = tk_cre_tsk(&ctsk_adc);
	tk_sta_tsk(tskid_adc, 0);
	tskid_input = tk_cre_tsk(&ctsk_input);
	tk_sta_tsk(tskid_input, 0);
	tskid_output = tk_cre_tsk(&ctsk_output);
	tk_sta_tsk(tskid_output, 0);
	tskid_communication = tk_cre_tsk(&ctsk_communication);
	tk_sta_tsk(tskid_communication, 0);
	tskid_calc = tk_cre_tsk(&ctsk_calc);
	tk_sta_tsk(tskid_calc, 0);
	tskid_alart = tk_cre_tsk(&ctsk_alart);
	tk_sta_tsk(tskid_alart, 0);
	tskid_lcd = tk_cre_tsk(&ctsk_lcd);
	tk_sta_tsk(tskid_lcd, 0);
	tskid_monitor = tk_cre_tsk(&ctsk_monitor);
	tk_sta_tsk(tskid_monitor, 0);
	
	scnt.mstn = IH_STARTUP;										// スタートアップステート設定
	scnt.sstn = 0;
	// 永久スリープ
	tk_slp_tsk(TMO_FEVR);
	return 0;
}


//ユーザー関数定義エリア BEGIN

//ステート関数 BEGIN
//スタートアップステート関数
void stateStartup(void)
{
	switch (scnt.sstn)
	{
		case 0: // 起動チェック
			ihpcntPoff();
			sigO.heating = OFF;										// 加熱中ランプ消灯
			ihp.reset_on = OFF;										// リセット要請オフ
			if(adc.cntV > CNTV10V){									// +15V制御電源正常チェック
				scnt.sstn = 1;
			}
			break;
		case 1:
			if (!sigI.ilock && sigI.heat && calc.iinf_ratio > 0){ // インターロック・加熱ON・インターフェース電流チェック
				scnt.sstn = 2;
			}
			break;
		case 2:
			sigO.heating = ON;										// 加熱中ランプ点灯
			sigO.alarm = OFF;										// 警報ランプ消灯
			ihp.ss_en = EN;											// ソフトスタート許可
			ihp.ss_stn = 0;											// ソフトスタートステート番号初期化
			ihp.sstart_end = OFF;									// ソフトスタート完了フラグオフ
			scnt.sstn = 3;
		case 3:
			if(ihp.sstart_end){	// ソフトスタート完了
				ihp.ss_en = DIS;
				periodic_data.ponct++;										// 総起動回数カウンタ更新
				scnt.mstn = IH_PON;									// パワーオンステート設定
				scnt.sstn = 0 ;
			}else{
				ihp.ss_en = EN;
			}
			break;
	}
}
//パワーオンステート関数
void statePwon(void)
{
	if(sigI.heat && !sigI.ilock && !ihp.oscerr && !ihp.hstoverr && !ihp.pcnt_en && !ihp.pwm_stoplv){ // 加熱条件チェック 
		ihpcntPon();											// パワーオン処理 
	}
	if(sigI.ilock){ // インターロック検知 
		ihpcntPoff();											// パワーオフ処理 
		scnt.mstn = IH_ILOCK;									// インターロックステート設定 
	}
	if(ihp.reset_on){ // リセット検知
		ihpcntReset();											// リセットリクエスト処理
	}
	if(ihp.pwm_stoplv || !sigI.heat){ // PWM停止レベル検知または加熱リクエストオフ
		ihpcntPoff();											// パワーオフ処理 
		scnt.mstn = IH_POFF;									// パワーオフステート設定 
	}
	if(ihp.oscerr){
		ihpcntPerr();
		periodic_data.oscerr_ct++;								// OSCエラーカウンター更新
		scnt.mstn = IH_ALARM;									// アラームステート設定
	}
	if(ihp.hstoverr){
		ihpcntPerr();
		periodic_data.hstovr_ct++;								// ヒートシンク温度オーバーエラーカウンター更新
		scnt.mstn = IH_ALARM;									// アラームステート設定
	}
}
//パワーオフステート関数
void statePwoff(void)
{
	if(!sigI.heat){ // 加熱信号OFF 
		ihpcntReset();											// リセットリクエスト処理 
	}
	if(calc.iinf_ratio > 0){ // PWM停止レベル以上検知(パワー再起動) 
		if(sigI.heat && !sigI.ilock && !ihp.oscerr && !ihp.hstoverr && !ihp.pcnt_en){ // 加熱開始条件チェック
			ihp.pwm_stoplv = OFF;							// PWM停止レベル検知OFF 
			sigO.ready = ON;								// READYランプ点灯 
			sigO.heating = ON;								// 加熱中ランプ点灯 
			sigO.alarm = OFF;								// 警報ランプ消灯 
			scnt.mstn = IH_STARTUP;							// スタートアップステート設定 
			scnt.sstn = 0;									// サブステート0設定：起動チェックステート 
		}
	}
	if(ihp.reset_on){
		ihpcntReset();											// リセットリクエスト処理
	}
	if(ihp.oscerr){ // OSCエラー発生
		ihpcntPerr();											// パワーエラー発生処理 
		ihp.oscerr_ct++;										// OSCエラー発生カウンタ更新 
		scnt.mstn = IH_ALARM;									// アラームステート設定 
	}
	if(ihp.hstoverr){ // ヒートシンクオーバーヒート発生 
		ihpcntPerr();											// パワーエラー発生処理 
		ihp.hstocerr_cnt++;										// ヒートシンクオーバーヒートカウンタ更新 
		scnt.mstn = IH_ALARM;									// アラームステート設定 
	}
	if(sigI.ilock){ // インターロック検知 
		scnt.mstn = IH_ILOCK;									// インターロックステート設定 
	}
}
//インターロックステート関数
void stateIlock(void)
{
	sigO.heating = OFF;											// 加熱中ランプ消灯

	if(!sigI.ilock){ // インターロック解除
		ihpcntReset();											// リセット実行 
	}
	if(ihp.reset_on){ // リセット信号確認
		ihpcntReset();										// リセットリクエスト処理
	}
}
//アラームステート関数
void stateAlarm(void)
{
	if(!ihp.hstoverr && !ihp.oscerr){ // ヒートシンク温度エラー解除(OSCエラー無しのとき) 
		ihpcntReset();											// リセット実行 
	}
	if(ihp.reset_on){ // リセット信号確認
		ihpcntReset();										// リセットリクエスト処理
	}
}
//テストステート関数
void stateTest(void)
{
	
}
// ステート関数 END

// 計算処理関数 BEGIN
// 制御電源電圧計算
void calcControlv(void)
{
	calc.cntrolV = (uint32_t)(adc.cntV * 100) / ADCMAX * 2 * 11.316;		// 桁落ち防止しつつ計算
}
// インターフェース電流計算関数
void calcInterface(void)
{
	if(data_Setting[EA_IINF/ENV_GM][EA_IINF%ENV_GM]){ // 0-20mA電流インターフェース 
		calc.iinf_ratio = ((uint32_t)adc.interfaceI * 10000) / IINF20MA;							// 0-20mA電流インターフェース入力100倍% 
	}
	else{ // 4-20mA電流インターフェース 
		if(adc.interfaceI <= IINF4MA){ // 4-20mA電流インターフェース:4mA以下 
			calc.iinf_ratio = 0;																	// 0.0%設定 
		}
		else{ // 4-20mA電流インターフェース:4mA～20mA 
			calc.iinf_ratio = ((uint32_t)adc.interfaceI - IINF4MA) * 10000 / (IINF20MA - IINF4MA);	// 4-20mA電流インターフェース入力100倍% 
		}
	}
	if(calc.iinf_ratio < 100){
		calc.iinf_ratio = 0;
	}
	calc.iinf_ratio = calc.iinf_ratio < IINF100P ? calc.iinf_ratio : IINF9999;						// 電流インターフェース入力100%以上リミット値(9999)設定 
}

// モニタPWM計算関数
void calcMpwm(void)
{
	if(adc.inputI > IH_INIOFFSET){
		calc.pw_ini100 = (uint32_t)((adc.inputI - IH_INIOFFSET) * 1000 / IH_INIX10);				// 誘導加熱電源入力電流100倍値
	} else {
		calc.pw_ini100 = 0;
	}
	calc.pw_rilimit = data_Setting[EA_MPWMRANGE/ENV_GM][EA_MPWMRANGE%ENV_GM];						// モニタPWMレンジ設定値読み出し
	if(calc.pw_ini100 >= calc.pw_rilimit){ // 入力電流がモニタPWMレンジ電流リミット値以上 
		calc.pw_mpwm = 10000;																		// モニタPWMカウント上限値設定 
	}
	else{ // 入力電流がモニタPWMレンジ電流上限未満 
		calc.pw_mpwm = (uint16_t)((uint32_t)calc.pw_ini100*10000 / calc.pw_rilimit);				// 各モニタPWMレンジでスケーリング実施(リミット値を100%とする：10000カウント) 
	}
}
//入力電流W換算値計算関数
void calcInputW(void)
{
	calc.pw_inputw = ((uint32_t)calc.pw_ini100 * IH_AC200V * IH_ROOT3) / 10000;			// 入力電流W換算値
	calc.pw_inputw *= data_Setting[EA_PFACTOR/ENV_GM][EA_PFACTOR%ENV_GM];							// 力率考慮W換算値
	calc.pw_inputw /= 100;																			// 桁合わせ
}

// 出力電流計算関数
void calcOutputI(void)
{
	calc.pw_outputi = (uint32_t)(adc.outputI * 1000 / IH_OUTIX);				// 誘導加熱電源出力電流100倍値
}

void calcHeattemp(void)
{
    // 14bitADC値を10bit相当に変換
    uint16_t converted_adc = adc.hstmp / ADC_14BIT_TO_10BIT_FACTOR;
    int16_t temp_index, num_elements;
    int16_t table_index;

	// テーブル範囲チェック
    if ((converted_adc/10) > 99) {  // 温度区分の範囲チェック
        calc.htmp = TEMP_SENSOR_ERROR;
        return;
    }

    switch (data_Setting[EA_TSENS/ENV_GM][EA_TSENS%ENV_GM]) {
        case THERMISTOR_STS60:
            // STS-60の場合
            temp_index = sts_60_temp_params[converted_adc/ENV_GM].top_temp;
            num_elements = sts_60_temp_params[converted_adc/ENV_GM].num_elements;
            
            if (num_elements == 1) {
                calc.htmp = temp_index;  // 単一要素の場合はそのまま返す
                return;
            }

            // 複数要素がある場合はテーブル探索
            for (int i = 0; i < num_elements; i++, temp_index++) {
                table_index = temp_index + IH_TCVP60;
                if (sts_60_temp_ad[table_index] <= converted_adc * 10) {
                    calc.htmp = temp_index;
                    return;
                }
            }
            // テーブル探索で見つからなかった場合は最後の値を使用
            calc.htmp = temp_index;
            break;

        case THERMISTOR_STS73:
            // STS-73の場合（同様の処理）
            temp_index = sts_73_temp_params[converted_adc/ENV_GM].top_temp;
            num_elements = sts_73_temp_params[converted_adc/ENV_GM].num_elements;
            
            if (num_elements == 1) {
                calc.htmp = temp_index;
                return;
            }

            for (int i = 0; i < num_elements; i++, temp_index++) {
                table_index = temp_index + IH_TCVP73;
                if (sts_73_temp_ad[table_index] <= converted_adc * 10) {
                    calc.htmp = temp_index;
                    return;
                }
            }
            calc.htmp = temp_index;
            break;

        default:
            calc.htmp = 0;  // エラー時のデフォルト値
            break;
    }
}
// 計算処理関数 END

//パワー制御関数 BEGIN
//リセット処理関数
void ihpcntReset(void)
{
	if(!data_Setting[EA_RESETEN/ENV_GM][EA_RESETEN%ENV_GM]){ // 外部リセット禁止
		return;
	}
	ihp.sstart_end = OFF;																			// ソフトスタート完了フラグオフ
	ihp.reset_on = OFF;																				// リセット指令オフ
	ihpcntPoff();																					// パワーオフ処理
	ihp.oscerr = ihp.hstoverr = FALSE;																// エラー解除
	scnt.mstn = IH_STARTUP;																			// スタートアップステート設定
	scnt.sstn = 0;
}

//パワーオン関数
void ihpcntPon(void)
{
	ihp.pcnt_en = EN;										// パワー制御許可
	sigO.ready = ON;										// READYランプ点灯
	sigO.heating = ON;										// 加熱中ランプ点灯
	sigO.alarm = OFF;										// 警報ランプ消灯
}

//パワーオフ関数
void ihpcntPoff(void)
{
	ihp.pcnt_en = DIS;										// パワー制御禁止
	sigO.ready = ON;										// READYランプ点灯
	if(ihp.pwm_stoplv && sigI.heat){
		sigO.heating = ON;									// 加熱中ランプ点灯(PWM停止レベル検知のとき点灯維持する）
	}else{
		sigO.heating = OFF;									// 加熱中ランプ消灯
	}
	sigO.alarm = OFF;										// 警報ランプ消灯
	ppi.i_term = 0.0f;										// 積分項リセット
	ppi.prev_error = 0.0f;									// 前回差分リセット
	ihpcntPwmstop();										// PWMタイマ停止処理
}

//パワーエラー発生関数
void ihpcntPerr(void)
{
	ihp.pcnt_en = DIS;										// パワー制御禁止
	sigO.ready = OFF;										// READYランプ消灯
	sigO.heating = OFF;										// 加熱中ランプ消灯
	sigO.alarm = ON;										// 警報ランプ点灯
	ihpcntPwmstop();										// PWMタイマ停止処理
}

void ihpcntPwmstart(void)
{
    // 出力を有効化
    HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TC1 | HRTIM_OUTPUT_TC2 | HRTIM_OUTPUT_TD1 | HRTIM_OUTPUT_TD2);

    // タイマーを開始
    HAL_HRTIM_WaveformCounterStart(&hhrtim1, HRTIM_TIMERID_MASTER | HRTIM_TIMERID_TIMER_C | HRTIM_TIMERID_TIMER_D);

}

// PWMタイマ停止関数
void ihpcntPwmstop(void)
{
	// 設定値を0にする
    HRTIM_CompareCfgTypeDef sCompareCfg = {0};
	ihp.pwmct = 0;
	ihp.pwmlevel = 0;
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);              // PWMモニタ出力
    HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_TIMER_C, HRTIM_COMPAREUNIT_1, &sCompareCfg);                   // PWMパワー制御出力
	HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_TIMER_D, HRTIM_COMPAREUNIT_1, &sCompareCfg);                   // PWMパワー制御出力
    // 出力を停止
    HAL_HRTIM_WaveformOutputStop(&hhrtim1, HRTIM_OUTPUT_TC1 | HRTIM_OUTPUT_TC2 | HRTIM_OUTPUT_TD1 | HRTIM_OUTPUT_TD2);

    // タイマーを停止
    HAL_HRTIM_WaveformCounterStop(&hhrtim1, HRTIM_TIMERID_MASTER | HRTIM_TIMERID_TIMER_C | HRTIM_TIMERID_TIMER_D);
}

//ソフトスタート関数
void ihpcntSoftstart(void)
{
	static uint32_t pwmstep,target_power;

	switch (ihp.ss_stn){	//ステータス処理
		case 0:	//　ソフトスタート準備
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,ON); // ランプ制御(PWM調整中)
			ihp.pwmct = 0;
			target_power = data_Setting[EA_PWMLMT/ENV_GM][EA_PWMLMT%ENV_GM] * calc.iinf_ratio / 100;			// パワー制御上限値読み出して入力インターフェイスの設定値をかける
			target_power = target_power * PWMEFFECTIVE / 10000;														// レジスタ設定値に合わせる
			pwmstep = target_power / ((uint16_t)data_Setting[EA_SSTART/ENV_GM][EA_SSTART%ENV_GM] );			// ソフトスタートPWMステップをソフトスタート時間から計算 
			ihpcntPwmstart();
			ihp.ss_stn = 1;
			break;
		case 1:	// ソフトスタート中 
			if(((uint32_t)(adc.inputI - IH_INIOFFSET) * 1000)/IH_INIX10 > (uint32_t)data_Setting[EA_ILIMIT/ENV_GM][EA_ILIMIT%ENV_GM] *10){		// 入力電流リミットチェック： 10倍値で比較
				ihp.ss_stn = 2;				 																				// 入力電流リミット検知：ソフトスタート完了ステート設定 
			}
			ihp.pwmct += pwmstep;
			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,calc.pw_mpwm);														// PWMモニタ出力
			update_hrtim_registers();																						// 周波数を初期化して出力
			if(ihp.pwmct >= target_power){
				ihp.ss_stn = 2;																								// PWMリミット検知：ソフトスタート完了ステート設定 
			}
			break;
		case 2:	// ソフトスタート完了 
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,OFF); // ランプ制御(PWM調整中オフ)
			ihp.ss_en = DIS;
			ihp.sstart_end = ON;
			break;
		}
}

// PWM出力関数
void ihpcntPout(void)
{
	
	if(!ihp.pcnt_en) return;
    
    // パワーダウン判定
    if(calc.iinf_ratio <= 0) {
        ihp.pwm_stoplv = ON;
        ihp.pcnt_en = DIS;
        ihp.pwmct = 0;
        ppi.i_term = 0;
		ppi.prev_error = 0;
        return;
    }
    
    // 目標出力電流の計算
    float target_current = ppi.limit_current * calc.iinf_ratio / 10000.0f;
    
    // 目標値に対する現在値の割合を計算（%）
	float current_percentage;
	if(adc.inputI > IH_INIOFFSET){
    	current_percentage = (float)((adc.inputI - IH_INIOFFSET) / target_current) * 100.0f;
	} else {
		current_percentage = 0.0f;
	}
	// 誤差の変化率制限（急激な変化を防ぐ）
    float percentage_error = 100.0f - current_percentage;
	float error_delta = percentage_error - ppi.prev_error;
	const float MAX_ERROR_DELTA = 10.0f;  // 1サンプル当たりの最大変化量

	if(error_delta > MAX_ERROR_DELTA) {
        percentage_error = ppi.prev_error + MAX_ERROR_DELTA;
    } else if(error_delta < -MAX_ERROR_DELTA) {
        percentage_error = ppi.prev_error - MAX_ERROR_DELTA;
    }
    ppi.prev_error = percentage_error;

	// I項の制限値設定
    const float I_TERM_MAX = 50.0f;   // 適切な値に調整要
    const float I_TERM_MIN = -50.0f;
    
    // PI制御によるPWM値の調整
    float p_term = ppi.kp * percentage_error;
    ppi.i_term += ppi.ki * percentage_error;

	// 積分項の制限（アンチワインドアップ）
    if(ppi.i_term > I_TERM_MAX) {
        ppi.i_term = I_TERM_MAX;
    } else if(ppi.i_term < I_TERM_MIN) {
        ppi.i_term = I_TERM_MIN;
    }

    float adjustment_percentage = p_term + ppi.i_term;
    
    // 現在のPWM値に対する調整量を計算
    int32_t pwm_adjustment = (int32_t)((adjustment_percentage / 100.0f) * ihp.pwmct);

	 // PWM値の更新
    int32_t prev_pwmct = ihp.pwmct;  // 前回値保存
    ihp.pwmct += pwm_adjustment;
    
    // PWM値の制限
    if(ihp.pwmct > ppi.limit_pwm) {
        ihp.pwmct = ppi.limit_pwm;
        // 積分項の巻き戻し
        ppi.i_term -= (adjustment_percentage - ((float)(ppi.limit_pwm - prev_pwmct) / prev_pwmct * 100.0f));
    } else if(ihp.pwmct < 0) {
        ihp.pwmct = 0;
        ppi.i_term = 0;
    }
    
    // パーセント表示用の計算
    ihp.pwmlevel = (ihp.pwmct * 1000) / PWMEFFECTIVE;
}

// 周波数調整関数
void adjust_Freq(void)
{
	float new_freq,freq_diff;
	if(ihp.manualmode_Freq){ // 周波数手動制御モード
        if(ihp.current_freq != ihp.manual_freq){
            freq_diff = ihp.manual_freq - ihp.current_freq;
            new_freq = ihp.current_freq;
            
            if(freq_diff > FREQ_STEP){
                new_freq += FREQ_STEP;
            }else if(freq_diff < -FREQ_STEP){
                new_freq -= FREQ_STEP;
            }else{
                new_freq = ihp.manual_freq;
            }
            if(new_freq < data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000){
                new_freq = data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000;
            }else if(new_freq > data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000){
                new_freq = data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
            }
            
            ihp.current_freq = new_freq;
            ihp.new_period = (uint32_t)(HRTIM_CLOCK / new_freq);
        }
    }
}

// 自動調整時周波数計算関数
void phase_Direction(void)
{
	uint32_t local_voltage_capture,local_current_capture;
    int32_t capture_diff;
    float phase_diff;

	__HAL_TIM_DISABLE_IT(&htim2,TIM_IT_CC2 | TIM_IT_CC3);								// 割り込み禁止
	local_voltage_capture = ihp.voltage_capture;
	local_current_capture = ihp.current_capture;
	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC2 | TIM_IT_CC3);								// 割り込み許可

    // 範囲チェックの追加
    if (local_voltage_capture >= ihp.timer_period || local_current_capture >= ihp.timer_period) {
        // エラー処理
        return;
    }

    // 電圧と電流のキャプチャ値の差分を計算
    uint32_t forward_diff, backward_diff;
    
    // 電流を基準とした位相差計算
    if (local_current_capture >= local_voltage_capture) {
        forward_diff = local_current_capture - local_voltage_capture;
        backward_diff = ihp.timer_period - forward_diff;
        
        // より短い方の差分を採用（正の値は電流遅れを示す）
        if (forward_diff <= backward_diff) {
            capture_diff = (int32_t)forward_diff;  // 電流遅れは正
        } else {
            capture_diff = -(int32_t)backward_diff;  // 電流進みは負
        }
    } else {
        forward_diff = local_voltage_capture - local_current_capture;
        backward_diff = ihp.timer_period - forward_diff;
        
        if (forward_diff <= backward_diff) {
            capture_diff = -(int32_t)forward_diff;  // 電流進みは負
        } else {
            capture_diff = (int32_t)backward_diff;  // 電流遅れは正
        }
    }

    // 位相差を角度に変換（-180度から+180度の範囲）
    // 正の値：電流遅れ → 周波数を下げる
    // 負の値：電流進み → 周波数を上げる
    phase_diff = (float)capture_diff * 360.0f / (float)ihp.new_period;

    // PI制御による周波数補正値の計算
    float error = phase_diff - fpi.target; 
    // errorが正 → phase_diffが目標より小さい → 周波数を下げる
    // errorが負 → phase_diffが目標より大きい → 周波数を上げる

    // 以降のPI制御処理
    fpi.i_term += fpi.ki * error;
    float freq_change = (fpi.kp * error) + fpi.i_term;
    
    // 周波数更新
    float new_freq = ihp.current_freq - freq_change;  // 符号を反転
    
    // 周波数範囲の制限とアンチワインドアップ
    if (new_freq < data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000) {
        new_freq = data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000;
        fpi.i_term -= (new_freq - data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000);
    } else if (new_freq > data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000) {
        new_freq = data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
        fpi.i_term -= (new_freq - data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000);
    }
    
    // 周波数更新
    ihp.current_freq = new_freq;
    ihp.new_period = (uint32_t)(HRTIM_CLOCK / new_freq);
    
    // 前回値の更新
    fpi.prev_error = error;
    fpi.prev_output = new_freq;
}

// HRTIM更新関数
void update_hrtim_registers(void)
{
    // 引数のnew_periodを半周期として使用
    uint32_t half_period = ihp.new_period / 2;
    
    // デフォルト値(PWMMAX)に対するスケーリング倍率を計算
    float scaling_ratio = (float)half_period / (float)PWMMAX;
    
    // PWM周期値を設定
    HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].PERxR = half_period;
    HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].PERxR = half_period;
    
    // PWM出力値とデッドタイムをスケーリング
    uint32_t cmp_value = (uint32_t)((float)(ihp.pwmct + PWMDEADTIM) * scaling_ratio);
	if(cmp_value >= PWMMAX){
		cmp_value = PWMMAX - 1;		// オーバーフローは是正する
	}
    HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_C].CMP1xR = cmp_value;
    HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_D].CMP1xR = cmp_value;
    
    // レジスタ更新を要求
    HRTIM1->sCommonRegs.CR2 |= HRTIM_CR2_TASWU;
}

// PI制御構造体初期化関数
void Init_picontroller(void)
{
	// 周波数PI制御構造体
	fpi.kp = 10.0f;			// チューニングが必要
	fpi.ki = 0.5f;			// チューニングが必要
	fpi.i_term = 0.0f;
	fpi.target = data_Setting[EA_RESONANTDIFF/ENV_GM][EA_RESONANTDIFF%ENV_GM];
	fpi.prev_error = 0.0f;
	fpi.prev_output = data_Setting[EA_DEFFREQ/ENV_GM][EA_DEFFREQ%ENV_GM] * 1000;

	// パワーPI制御構造体
	ppi.i_term = 0.0f;
	ppi.prev_error = 0.0f;
	ppi.limit_pwm = data_Setting[EA_MAXPWM/ENV_GM][EA_MAXPWM%ENV_GM] * PWMEFFECTIVE / 100;
    ppi.limit_current = data_Setting[EA_MAXINPUT/ENV_GM][EA_MAXINPUT%ENV_GM];
}

void Init_parameter(void)
{
    ihp.timer_period = __HAL_TIM_GET_AUTORELOAD(&htim2);												// キャプチャタイマーの周期を取得

	ihp.current_freq = data_Setting[EA_RESONANTFREQ/ENV_GM][EA_RESONANTFREQ%ENV_GM];							// 初期周波数をセット
	ihp.new_period = (uint32_t)HRTIM_CLOCK / ihp.current_freq;		// HRTIMの初期周期を設定
}

// 共振周波数探査関数
void Search_resonance(void)
{
    float best_freq,best_current,best_phase;
    float max_current = 0;
    float current_freq;
    float phase_diff;
    int32_t capture_diff;
    uint32_t forward_diff, backward_diff, local_voltage_capture, local_current_capture;

	//20%出力にする
	ihp.pwmct = PWMEFFECTIVE * 20 / 100;
    
    // 粗いスキャン
    const float coarse_step = 100.0f;
    current_freq = data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
    float rough_best_freq = data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
    
    while (current_freq >= data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000) {
        ihp.current_freq = current_freq;
        ihp.new_period = (uint32_t)(HRTIM_CLOCK / current_freq);
        update_hrtim_registers();	// 出力を行う
        
        tk_dly_tsk(10);
        float current = adc.inputI;
        
        if (current > max_current) {
            max_current = current;
            rough_best_freq = current_freq;
        }
        current_freq -= coarse_step;
    }
    
    // 詳細スキャン（粗スキャンで見つけた周波数の前後）
    const float fine_step = 10.0f;
    const float fine_range = coarse_step;  // 粗スキャンステップ分の範囲を詳細スキャン
    float start_freq = rough_best_freq + fine_range/2;
	if(start_freq >= data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000){
		start_freq = data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
	}
    float end_freq = rough_best_freq - fine_range/2;
	if(end_freq <= data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000){
		end_freq = data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000;
	}
    
    max_current = 0;  // 最大電流値をリセット
    current_freq = start_freq;
    
    while (current_freq >= end_freq) {
        ihp.current_freq = current_freq;
        ihp.new_period = (uint32_t)(HRTIM_CLOCK / current_freq);
        update_hrtim_registers();
        
        tk_dly_tsk(10);
        float current = adc.inputI;
        
        if (current > max_current) {
            max_current = current;
            best_freq = current_freq;
            best_current = current;
            
            __HAL_TIM_DISABLE_IT(&htim2,TIM_IT_CC2 | TIM_IT_CC3);
            local_voltage_capture = ihp.voltage_capture;
            local_current_capture = ihp.current_capture;
            __HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC2 | TIM_IT_CC3);

            if (local_current_capture >= local_voltage_capture) {
                forward_diff = local_current_capture - local_voltage_capture;
                backward_diff = ihp.timer_period - forward_diff;
                if (forward_diff <= backward_diff) {
                    capture_diff = (int32_t)forward_diff;
                } else {
                    capture_diff = -(int32_t)backward_diff;
                }
            } else {
                forward_diff = local_voltage_capture - local_current_capture;
                backward_diff = ihp.timer_period - forward_diff;
                if (forward_diff <= backward_diff) {
                    capture_diff = -(int32_t)forward_diff;
                } else {
                    capture_diff = (int32_t)backward_diff;
                }
            }
            best_phase = (float)capture_diff * 360.0f / (float)ihp.new_period;
        }
        current_freq -= fine_step;
    }
    
    // 最適周波数に設定
    ihp.current_freq = best_freq;
    ihp.new_period = (uint32_t)(HRTIM_CLOCK / best_freq);
    update_hrtim_registers();
    
    fpi.target = best_phase;
	data_Setting[EA_RESONANTFREQ/ENV_GM][EA_RESONANTFREQ%ENV_GM] = best_freq / 10;				// 10Hz単位で記録
	data_Setting[EA_RESONANTDIFF/ENV_GM][EA_RESONANTDIFF%ENV_GM] = best_phase;
}

// 最大出力探査関数
void Search_maxoutput(void)
{
	ihp.Searching = TRUE;		// 探査中フラグオン
    const float MAX_CURRENT = data_Setting[EA_LMTOUTPUT/ENV_GM][EA_LMTOUTPUT%ENV_GM] * IH_OUTIX / 10;
    const float CURRENT_MARGIN = MAX_CURRENT * 0.95f;
	uint32_t PWM_COUNTER = 0;
    
    ihp.pwmct = 0;
    update_hrtim_registers();
    tk_dly_tsk(10);
    
    float current_out = adc.outputI;
	float current_in = adc.inputI;
	// 0%からソフトスタートしながら出力を上げていく
    while (current_out <= CURRENT_MARGIN && PWM_COUNTER <= 100) {
		PWM_COUNTER++;
        ihp.pwmct = PWMEFFECTIVE * PWM_COUNTER / 100;
        update_hrtim_registers();
        tk_dly_tsk(10);
		current_out = adc.outputI;
        current_in = adc.inputI;
    }
    ihpcntPwmstop();

	data_Setting[EA_MAXPWM/ENV_GM][EA_MAXPWM%ENV_GM] = PWM_COUNTER - 1;
    ppi.limit_pwm = data_Setting[EA_MAXPWM/ENV_GM][EA_MAXPWM%ENV_GM] * PWMEFFECTIVE / 100;
    ppi.limit_current = data_Setting[EA_MAXINPUT/ENV_GM][EA_MAXINPUT%ENV_GM] = current_in - IH_INIOFFSET;
	ihp.Searching = FALSE;		// 探査中フラグオフ
}

//パワー制御関数 END

// 現在時刻を取得する関数（μT-Kernel 3.0を使用）
// 引数：無し
// 返り値：現在時刻（SYSTIM型）
SYSTIM Get_Current_Time() {
    SYSTIM systim;
    tk_get_tim(&systim);
    return systim;
}

// flash制御関数 BEGIN

// フラッシュページの状態を確認する関数
static BOOL Is_Page_Empty(const PageHeader* header) {
    return (header->sequence == 0xFFFFFFFF && 
            header->write_count == 0xFFFF && 
            header->data_size == 0xFFFF);
}

// CRC-32計算関数
// 引数：data - CRCを計算するデータへのポインタ
//       size - データのサイズ（バイト数）
// 返り値：計算されたCRC値
static uint32_t Calculate_CRC(const void* data, uint32_t size) 
{
    const uint8_t* bytes = (const uint8_t*)data;
    uint32_t crc = 0xFFFFFFFF;

    for (uint32_t i = 0; i < size; i++) {
        crc ^= bytes[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc = crc >> 1;
            }
        }
    }

    return ~crc;
}

// ページヘッダーを読み込む関数
// 引数：page - 読み込むページ番号
// 返り値：uint64_t - ページヘッダーの内容
PageHeader Read_Page_Header(uint32_t page) 
{
    uint32_t address = FLASH_BANK2_BASE + (page * FLASH_PAGE_SIZE);
    PageHeader header;
    memcpy(&header, (void*)address, sizeof(PageHeader));
    return header;
}

// 最新のデータが書き込まれたページを探す関数
// 引数：flash[] - 対象のFlashページ情報配列
// 返り値：最新のデータが書き込まれたページのインデックス
uint32_t Find_Latest_Data_Page(uint32_t start_page, uint32_t num_pages)
{
    uint32_t max_sequence = 0;
    uint32_t latest_page = start_page;
	BOOL found_valid_data = FALSE;

    for (uint32_t i = 0; i < num_pages; i++) {
		uint32_t current_page = start_page + i;
        PageHeader header = Read_Page_Header(current_page);
		 // 消去済みページはスキップ
        if (Is_Page_Empty(&header)) {
            continue;
        }
		 // ヘッダーの妥当性チェック
        if (header.data_size != 0 && header.data_size != 0xFFFF) {
            // シーケンス番号が大きい方が新しいデータ
            if (!found_valid_data || header.sequence > max_sequence) {
                max_sequence = header.sequence;
                latest_page = current_page;
                found_valid_data = TRUE;
            }
        }
	}
    return found_valid_data ? latest_page : start_page;
}

// データを書き込む共通関数
// 引数：start_page - 書き込み開始ページ
//       num_pages - 使用可能なページ数
//       data - 書き込むデータへのポインタ
//       size - データのサイズ
//       sequence - シーケンス番号へのポインタ
// 返り値：エラーコード
FlashError_t Write_Data(uint32_t start_page, uint32_t num_pages, void* data, uint32_t size, uint32_t *sequence) 
{
	if (!data || !sequence || size > (FLASH_PAGE_SIZE - sizeof(PageHeader))) {
        return FLASH_ERROR_PARAM;
    }

	// フラッシュアクセスの排他制御
    ER ercd = tk_wai_sem(FLASH_SEM, 1, TMO_FEVR);
    if (ercd != E_OK) {
        return FLASH_ERROR_LOCKED;
    }

    FlashError_t result = FLASH_OK;
    uint32_t write_page = Find_Next_Write_Page(start_page, num_pages);

	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
    
    HAL_FLASH_Unlock();

	// 割り込み禁止
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
    HAL_FLASH_Unlock();
    __HAL_FLASH_DATA_CACHE_DISABLE();

	// ページ消去
    FLASH_EraseInitTypeDef erase_init = {
        .TypeErase = FLASH_TYPEERASE_PAGES,
        .Banks = FLASH_BANK_2,
        .Page = write_page,
        .NbPages = 1
    };

    uint32_t page_error = 0;
    if (HAL_FLASHEx_Erase(&erase_init, &page_error) != HAL_OK) {
        result = FLASH_ERROR_ERASE;
        goto cleanup;
    }

    // ヘッダー準備
    uint32_t address = FLASH_BANK2_BASE + (write_page * FLASH_PAGE_SIZE);
    PageHeader header = {
        .sequence = *sequence + 1,
        .write_count = 0,
        .data_size = size,
    };

	// 書き込み回数の更新
    PageHeader old_header = Read_Page_Header(write_page);
    if (old_header.write_count != 0xFFFF) {
        header.write_count = old_header.write_count + 1;
        if (header.write_count >= FLASH_PAGE_LIMIT) {
            // 警告通知処理をここに実装
        }
    }
	
    // ヘッダー書き込み
    for (int retry = 0; retry < FLASH_WRITE_RETRY_COUNT; retry++) {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, address, 
                            *(uint64_t*)&header) == HAL_OK) {
            break;
        }
        if (retry == FLASH_WRITE_RETRY_COUNT - 1) {
            result = FLASH_ERROR_WRITE;
            goto cleanup;
        }
    }

    // データ書き込み
    address += sizeof(PageHeader);
    const uint8_t* src = (const uint8_t*)data;
    
    for (uint32_t i = 0; i < size; i += 8) {
        uint64_t data64 = 0;
        uint32_t chunk_size = (size - i >= 8) ? 8 : (size - i);
        memcpy(&data64, src + i, chunk_size);

        for (int retry = 0; retry < FLASH_WRITE_RETRY_COUNT; retry++) {
            if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, 
                                address + i, data64) == HAL_OK) {
                break;
            }
            if (retry == FLASH_WRITE_RETRY_COUNT - 1) {
                result = FLASH_ERROR_WRITE;
                goto cleanup;
            }
        }
    }

    // ベリファイ
    if (memcmp((void*)(address), data, size) != 0) {
        result = FLASH_ERROR_VERIFY;
        goto cleanup;
    }

    // 成功したらシーケンス番号を更新
    *sequence = header.sequence;

cleanup:
    __HAL_FLASH_DATA_CACHE_ENABLE();
    HAL_FLASH_Lock();
    __set_PRIMASK(primask);
    tk_sig_sem(FLASH_SEM, 1);
    
    return result;
}

// 周期保存データを読み込む関数
// 引数：data - 読み込んだデータを格納するバッファへのポインタ
//       max_size - バッファの最大サイズ
// 返り値：エラーコード
FlashError_t Read_Latest_Periodic_Data(DAT_CBL* data, uint32_t max_size)
{
	if (!data || max_size == 0) {
        return FLASH_ERROR_PARAM;
    }
	
    uint32_t latest_page = Find_Latest_Data_Page(PERIODIC_START_PAGE, PERIODIC_DATA_PAGES);
    PageHeader header = Read_Page_Header(latest_page);


	// 通常の読み込み処理
	if (header.data_size > max_size || header.data_size == 0 || 
        header.data_size == 0xFFFF) {
        return FLASH_ERROR_SIZEE;
    }

	uint32_t address = FLASH_BANK2_BASE + (latest_page * FLASH_PAGE_SIZE) + sizeof(PageHeader);

	memcpy(data, (void*)address, header.data_size);
    return FLASH_OK;
}

// 要求保存データを読み込む関数
// 引数：data - 読み込んだデータを格納するバッファへのポインタ
//       max_size - バッファの最大サイズ
// 返り値：エラーコード
FlashError_t Read_Latest_Request_Data(int16_t data[10][10], uint32_t max_size) {
    if (!data || max_size == 0) {
        return FLASH_ERROR_PARAM;
    }

    uint32_t latest_page = Find_Latest_Data_Page(REQUEST_START_PAGE, REQUEST_DATA_PAGES);
    PageHeader header = Read_Page_Header(latest_page);

	// 初回起動判定（ページが消去済み）
    if (header.sequence == 0xFFFFFFFF && header.write_count == 0xFFFF && header.data_size == 0xFFFF) {
        // 初回起動時はデフォルト値を設定
        initSetting();
        
        // デフォルト値をフラッシュに保存
        Write_Request_Data(data_Setting, sizeof(data_Setting));
        return LCD_OK;
    }

    if (header.data_size > max_size || header.data_size == 0 || header.data_size == 0xFFFF) {
        return FLASH_ERROR_SIZEE;
    }

    uint32_t address = FLASH_BANK2_BASE + (latest_page * FLASH_PAGE_SIZE) + sizeof(PageHeader);

    memcpy(data, (void*)address, header.data_size);
    return FLASH_OK;
}

// 次の書き込みページを見つける関数
uint32_t Find_Next_Write_Page(uint32_t start_page, uint32_t num_pages) 
{
    uint32_t min_write_count = UINT16_MAX;
    uint32_t min_count_page = start_page;
	uint32_t empty_page = 0xFFFFFFFF;

    for (uint32_t i = 0; i < num_pages; i++) {
        uint32_t current_page = start_page + i;
        PageHeader header = Read_Page_Header(current_page);

		// 消去済みページを発見
        if (Is_Page_Empty(&header)) {
            empty_page = current_page;
            break;
        }

		// 有効なデータを持つページの中から最小書き込み回数のページを探す
        if (header.data_size != 0 && header.data_size != 0xFFFF) {
            if (header.write_count < min_write_count) {
                min_write_count = header.write_count;
                min_count_page = current_page;
            }
        }
    }

    // 消去済みページがあればそれを使用、なければ最小書き込み回数のページを使用
    return (empty_page != 0xFFFFFFFF) ? empty_page : min_count_page;
}

// 周期保存データを書き込む関数
// 引数：data - 書き込むデータへのポインタ
//       size - データのサイズ
// 返り値：エラーコード
FlashError_t Write_Periodic_Data(const DAT_CBL* data, uint32_t size) {
    if (!data || size == 0 || size > (FLASH_PAGE_SIZE - sizeof(PageHeader))) {
        return FLASH_ERROR_PARAM;
    }

    // データのアライメントチェック
    if ((uintptr_t)data % 8 != 0) {
        // アライメントされていない場合は一時バッファにコピー
        uint8_t* aligned_buffer = NULL;
        aligned_buffer = (uint8_t*)__builtin_alloca((size + 7) & ~7);
        if (!aligned_buffer) {
            return FLASH_ERROR_PARAM;
        }
        memcpy(aligned_buffer, data, size);
        data = (const DAT_CBL*)aligned_buffer;
    }

    return Write_Data(PERIODIC_START_PAGE, PERIODIC_DATA_PAGES, (void*)data, size, &periodic_sequence);
}

// 要求保存データを書き込む関数
// 引数：data - 書き込むデータへのポインタ
//       size - データのサイズ
// 返り値：エラーコード
FlashError_t Write_Request_Data(const int16_t data[10][10], uint32_t size) {
    if (!data || size == 0 || size > (FLASH_PAGE_SIZE - sizeof(PageHeader))) {
        return FLASH_ERROR_PARAM;
    }

    // データのアライメントチェック
    if ((uintptr_t)data % 8 != 0) {
        // アライメントされていない場合は一時バッファにコピー
        uint8_t* aligned_buffer = NULL;
        aligned_buffer = (uint8_t*)__builtin_alloca((size + 7) & ~7);
        if (!aligned_buffer) {
            return FLASH_ERROR_PARAM;
        }
        memcpy(aligned_buffer, data, size);
        data = (const int16_t(*)[10])aligned_buffer;
    }

    return Write_Data(REQUEST_START_PAGE, REQUEST_DATA_PAGES, (void*)data, size, &request_sequence);
}
// システム初期化関数
FlashError_t Flash_Init(void) {
    FlashError_t result;
    
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

    // 周期保存データの読み込み
    result = Read_Latest_Periodic_Data(&periodic_data, sizeof(periodic_data));
    if (result != FLASH_OK) {
        // エラー処理（デフォルト値の設定など）
    }

    // 要求保存データの読み込み
    result = Read_Latest_Request_Data(data_Setting, sizeof(data_Setting));
    if (result != FLASH_OK) {
        // エラー処理
		initSetting();			// デフォルト値を設定する
    }

    // シーケンス番号の初期化
    periodic_sequence = Read_Page_Header(Find_Latest_Data_Page(PERIODIC_START_PAGE, PERIODIC_DATA_PAGES)).sequence;
    request_sequence = Read_Page_Header(Find_Latest_Data_Page(REQUEST_START_PAGE, REQUEST_DATA_PAGES)).sequence;

    return FLASH_OK;
}
// FLASH制御関数 END

// ロータリーエンコーダ読み込み関数
int16_t readEncvalue(void)
{
	uint16_t enc_buff = __HAL_TIM_GET_COUNTER(&htim3);			// ロータリーエンコーダ数値読み出し
	__HAL_TIM_SET_COUNTER(&htim3,0);							// ロータリーエンコーダ数値リセット
	if (enc_buff > 32767) // 左回り時
	{
		return (int16_t)enc_buff - 65536;
	}
	else // 右回り時
	{
		return (int16_t)enc_buff;
	}
}

// 設定範囲制限関数
int LCD_ClampValue(int value, int min, int max) 
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// パワー手動制御範囲制限関数
int LCD_ClampPower(int value) 
{
	int min = 0 ,max = 100;
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// 周波数手動制御範囲制限関数
int LCD_ClampFreq(int value) 
{
    if (value < data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000) return data_Setting[EA_MINFREQ/ENV_GM][EA_MINFREQ%ENV_GM] * 1000;
    if (value > data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000) return data_Setting[EA_MAXFREQ/ENV_GM][EA_MAXFREQ%ENV_GM] * 1000;
    return value;
}

// 環境設定初期化関数
void initSetting(void)
{
	for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            data_Setting[i][j] = setting_ranges[i][j].default_value;
        }
    }
}

// LCD制御関数(I2C) BEGIN

// 基本的なI2C通信関数
static LcdError_t LCD_I2C_Write(LCD_HandleTypeDef* hlcd, uint8_t control, uint8_t data) {
    ER ercd;
    uint8_t buf[2] = {control, data};
    
    // I2Cバスの排他制御
    ercd = tk_wai_sem(I2C_SEM, 1, hlcd->timeout);
    if (ercd != E_OK) {
        return LCD_ERROR_TIMEOUT;
    }
    
    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(
        hlcd->hi2c,
        hlcd->address,
        buf,
        sizeof(buf),
        hlcd->timeout
    );
    
    tk_sig_sem(I2C_SEM, 1);
    
    return (status == HAL_OK) ? LCD_OK : LCD_ERROR_I2C;
}

// コマンド送信用関数
// 引数：LCD制御ハンドラ、送信コマンド
// 返り値：エラーコード
LcdError_t LCD_WriteCmd(LCD_HandleTypeDef* hlcd, uint8_t cmd)
{
    if (!hlcd) {
        return LCD_ERROR_PARAM;
    }
    return LCD_I2C_Write(hlcd, CMDSEND, cmd);
}

// データ送信用関数
// 引数：LCD制御ハンドラ、送信データ
// 返り値：エラーコード
LcdError_t LCD_WriteData(LCD_HandleTypeDef* hlcd, uint8_t data)
{
    if (!hlcd || !hlcd->buffer.is_initialized) {
        return LCD_ERROR_PARAM;
    }
    return LCD_I2C_Write(hlcd, DATASEND, data);
}


// LCD初期化関数
// 引数：LCD制御ハンドラ
// 返り値：エラーコード
LcdError_t LCD_Init(LCD_HandleTypeDef* hlcd)
{
    if (!hlcd || !hlcd->hi2c) {
        return LCD_ERROR_PARAM;
    }
    
    LcdError_t status;
    
    // 起動待ち時間
    tk_dly_tsk(50);
    
    // 基本設定シーケンス
    const uint8_t init_sequence[] = {
        0x38,  // Function set
        0x0C,  // Display ON, cursor OFF
        0x01,  // Clear display
        0x06   // Entry mode set
    };
    
    for (int i = 0; i < sizeof(init_sequence); i++) {
        status = LCD_WriteCmd(hlcd, init_sequence[i]);
        if (status != LCD_OK) {
            return status;
        }
        tk_dly_tsk(5);
    }
    
    hlcd->buffer.is_initialized = TRUE;
    LCD_ClearBuffer(hlcd);
    
    return LCD_OK;
}

// LCD画面クリア
// 引数：LCD制御ハンドラ
// 返り値：エラーコード
LcdError_t LCD_Clear(LCD_HandleTypeDef* hlcd)
{
    if (!hlcd || !hlcd->buffer.is_initialized) {
        return LCD_ERROR_PARAM;
    }
    
    LcdError_t status = LCD_WriteCmd(hlcd, 0x01);
    if (status == LCD_OK) {
        tk_dly_tsk(5);
        LCD_ClearBuffer(hlcd);
    }
    return status;
}

// LCD文字出力バッファクリア
// 引数：LCD制御ハンドラ
// 返り値：無し
LcdError_t LCD_ClearBuffer(LCD_HandleTypeDef* hlcd)
{
    if (!hlcd) {
        return LCD_ERROR_PARAM;
    }

    // 両方のバッファをクリア
    memset(hlcd->buffer.current_str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.current_str2, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    
    // NULL終端
    hlcd->buffer.current_str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.current_str2[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';

    return LCD_OK;
}

// 数値→文字列変換関数（16ビット整数対応）
// 引数：str：格納する配列  pos:格納する配列位置 val:変換する数字　width:表示桁数
// 返り値：エラーコード
LcdError_t LCD_ConvU16(char* str, uint8_t pos, uint16_t val, uint8_t width)
{
    if (!str || pos >= LCD_MAX_CHARS) {
        return LCD_ERROR_PARAM;
    }
    
    // 一時バッファで変換
    char format[8];
    char temp[32];
    snprintf(format, sizeof(format), "%%%du", width);
    int written = snprintf(temp, sizeof(temp), format, val);
    
    // 結果コピー（ヌル文字なし）
    for (int i = 0; i < width && (pos + i) < LCD_MAX_CHARS; i++) {
        str[pos + i] = temp[i];
    }
    
    return LCD_OK;
}

// 数値→文字列変換関数（32ビット整数対応）
// 引数：str：格納する配列  pos:格納する配列位置 val:変換する数字　width:表示桁数
// 返り値：エラーコード
LcdError_t LCD_ConvU32(char* str, uint8_t pos, uint32_t val, uint8_t width)
{
    if (!str || pos >= LCD_MAX_CHARS) {
        return LCD_ERROR_PARAM;
    }
    
    // 一時バッファで変換
    char format[8];
    char temp[32];
    snprintf(format, sizeof(format), "%%%du", width);
    int written = snprintf(temp, sizeof(temp), format, val);
    
    // 結果コピー（ヌル文字なし）
    for (int i = 0; i < width && (pos + i) < LCD_MAX_CHARS; i++) {
        str[pos + i] = temp[i];
    }
    
    return LCD_OK;
}

// 数値→文字列変換関数（浮動小数点数対応）
// 引数：str：格納する配列  pos:格納する配列位置  val:変換する数字  total_width:全体の桁数  frac_width:小数点以下の桁数
// 返り値：エラーコード
LcdError_t LCD_ConvFloat(char* str, uint8_t pos, float val, uint8_t total_width, uint8_t frac_width)
{
    if (!str || pos >= LCD_MAX_CHARS) {
        return LCD_ERROR_PARAM;
    }
    
    // 一時バッファで変換
    char format[8];
    char temp[32];
    snprintf(format, sizeof(format), "%%%d.%df", total_width, frac_width);
    int written = snprintf(temp, sizeof(temp), format, val);
    
    // 結果コピー（ヌル文字なし）
    for (int i = 0; i < total_width && (pos + i) < LCD_MAX_CHARS; i++) {
        str[pos + i] = temp[i];
    }
    
    return LCD_OK;
}

// LCD文字出力
// 引数：hlcd:LCD制御ハンドラ char str：送信する文字 col:出力開始列 row:出力開始行
// 返り値：無し
LcdError_t LCD_Print(LCD_HandleTypeDef* hlcd, const char* str, uint8_t col, uint8_t row)
{
    if (!hlcd || !str || row > 1 || col >= LCD_MAX_CHARS) {
        return LCD_ERROR_PARAM;
    }
    
    static const uint8_t row_offsets[] = {0x00, 0x40};
    
    // カーソル位置設定
    LcdError_t status = LCD_WriteCmd(hlcd, 0x80 | (col + row_offsets[row]));
    if (status != LCD_OK) {
        return status;
    }
    
    // 文字列出力
    while (col < LCD_MAX_CHARS) {
        status = LCD_WriteData(hlcd, (uint8_t)*str++);
        if (status != LCD_OK) {
            return status;
        }
        col++;
    }
    
    return LCD_OK;
}

// LCD更新関数
LcdError_t LCD_UpdateDisplay(LCD_HandleTypeDef* hlcd)
{
    LcdError_t status = LCD_OK;

    // 1行目の比較と更新
    if (strcmp(hlcd->buffer.current_str1, hlcd->buffer.str1) != 0) {
        status = LCD_Print(hlcd, hlcd->buffer.str1, 0, 0);
        if (status != LCD_OK) {
            return status;
        }
        strcpy(hlcd->buffer.current_str1, hlcd->buffer.str1);
    }
    
    // 2行目の比較と更新
    if (strcmp(hlcd->buffer.current_str2, hlcd->buffer.str2) != 0) {
        status = LCD_Print(hlcd, hlcd->buffer.str2, 0, 1);
        if (status != LCD_OK) {
            return status;
        }
        strcpy(hlcd->buffer.current_str2, hlcd->buffer.str2);
    }

    return status;
}

// LCD表示バッファ更新関数（点滅用）
LcdError_t LCD_UpdateBuffer(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, int16_t value, BOOL show_value, BOOL blink_10, BOOL blink_1)
{
    if (!hlcd || place10 > 9 || place1 > 9) {
        return LCD_ERROR_PARAM;
    }

    // バッファクリア
    LCD_ClearBuffer(hlcd);

    // "CONFIG xx: "のフォーマットで固定文字を配置
	hlcd->buffer.str1[0] = 'C';
	hlcd->buffer.str1[1] = 'O';
	hlcd->buffer.str1[2] = 'N';
	hlcd->buffer.str1[3] = 'F';
	hlcd->buffer.str1[4] = 'I';
	hlcd->buffer.str1[5] = 'G';
	hlcd->buffer.str1[9] = ':';
    //strcpy(hlcd->buffer.str1, "CONFIG    : ");
    
    // 数字を配置（点滅でない時のみ）
    if (!blink_10) {
        hlcd->buffer.str1[7] = '0' + place10;
    }
    if (!blink_1) {
        hlcd->buffer.str1[8] = '0' + place1;
    }

    // 値の表示（指定時のみ）
    if (show_value) {
        char value_str[6];
        snprintf(value_str, sizeof(value_str), "%5d", value);
        memcpy(&hlcd->buffer.str1[10], value_str, 5);
    }

    return LCD_OK;
}

// 設定画面表示関数（10の位選択）
LcdError_t LCD_DisplayConfig10(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, BOOL blink){
    LcdError_t status;
    // バッファ更新
    status = LCD_UpdateBuffer(hlcd, place10, place1, 0, FALSE, blink, FALSE);
    if (status != LCD_OK) {
        return status;
    }

    // 画面更新
    status = LCD_Print(hlcd, hlcd->buffer.str1, 0, 0);
    if (status != LCD_OK) {
        return status;
    }
    
    return LCD_Print(hlcd, hlcd->buffer.str2, 0, 1);
}

// 設定画面表示関数（1の位選択）
LcdError_t LCD_DisplayConfig1(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, BOOL blink){
    LcdError_t status;
    LCD_ClearBuffer(hlcd);
    // バッファ更新
    status = LCD_UpdateBuffer(hlcd, place10, place1, 0, FALSE, FALSE, blink);
    if (status != LCD_OK) {
        return status;
    }

    // 画面更新
    status = LCD_Print(hlcd, hlcd->buffer.str1, 0, 0);
    if (status != LCD_OK) {
        return status;
    }
    
    return LCD_Print(hlcd, hlcd->buffer.str2, 0, 1);
}

// 設定値表示画面
LcdError_t LCD_DisplayConfigSet(LCD_HandleTypeDef* hlcd, uint8_t place10, uint8_t place1, int16_t value){
    LcdError_t status;
    LCD_ClearBuffer(hlcd);
    // バッファ更新
    status = LCD_UpdateBuffer(hlcd, place10, place1, value, TRUE, FALSE, FALSE);
    if (status != LCD_OK) {
        return status;
    }

    // 画面更新
    status = LCD_Print(hlcd, hlcd->buffer.str1, 0, 0);
    if (status != LCD_OK) {
        return status;
    }
    
    return LCD_Print(hlcd, hlcd->buffer.str2, 0, 1);
}

// パワー手動制御モード表示画面
LcdError_t LCD_DisplayPowerSet(LCD_HandleTypeDef* hlcd, uint8_t powerset){
    LcdError_t status;
    LCD_ClearBuffer(hlcd);

    char str[16];
    snprintf(str, sizeof(str), "%d", powerset);
    size_t len = strlen(str);

	hlcd->buffer.str1[0] = 'P';
	hlcd->buffer.str1[1] = 'O';
	hlcd->buffer.str1[2] = 'W';
	hlcd->buffer.str1[3] = 'E';
	hlcd->buffer.str1[4] = 'R';
    
    // 残りのスペースで右詰め
    memcpy(&hlcd->buffer.str1[15 - len], str, len);
	hlcd->buffer.str1[15] = '%';

	hlcd->buffer.str2[0] = 'H';
	hlcd->buffer.str2[1] = 'E';
	if(sigI.heat)				hlcd->buffer.str2[3] = '1';														// 外部加熱要求ON 
	else						hlcd->buffer.str2[3] = '0';														// 外部加熱要求OFF 
	hlcd->buffer.str2[5] = 'R';
	hlcd->buffer.str2[6] = 'E';
	if(sigI.reset)				hlcd->buffer.str2[8] = '1';														// 外部リセット要求ON 
	else						hlcd->buffer.str2[8] = '0';														// 外部リセット要求OFF 
	hlcd->buffer.str2[10] = 'I';
	hlcd->buffer.str2[11] = 'L';
	if(sigI.ilock)				hlcd->buffer.str2[13] = '1';													// 外部インターロック要求ON 
	else						hlcd->buffer.str2[13] = '0';													// 外部インターロック要求OFF 
    
	return LCD_UpdateDisplay(hlcd);
}

// 周波数手動制御モード表示画面
LcdError_t LCD_DisplayFreqSet(LCD_HandleTypeDef* hlcd, uint16_t freqset){
    LcdError_t status;
    LCD_ClearBuffer(hlcd);

    char str1[16],str2[16];
    snprintf(str1, sizeof(str1), "%d", freqset);
    size_t len1 = strlen(str1);
	hlcd->buffer.str1[0] = 'T';
	hlcd->buffer.str1[1] = 'a';
	hlcd->buffer.str1[2] = 'r';
	hlcd->buffer.str1[3] = 'g';
	hlcd->buffer.str1[4] = 'e';
	hlcd->buffer.str1[5] = 't';
	hlcd->buffer.str1[6] = ':'; 
    // 残りのスペースで右詰め
    memcpy(&hlcd->buffer.str1[14 - len1], str1, len1);
	hlcd->buffer.str1[14] = 'H';
	hlcd->buffer.str1[15] = 'z';

	snprintf(str2, sizeof(str2), "%d", ihp.current_freq);
    size_t len2 = strlen(str2);
	hlcd->buffer.str2[0] = 'A';
	hlcd->buffer.str2[1] = 'c';
	hlcd->buffer.str2[2] = 't';
	hlcd->buffer.str2[3] = 'u';
	hlcd->buffer.str2[4] = 'a';
	hlcd->buffer.str2[5] = 'l';
	hlcd->buffer.str2[6] = ':';
	// 残りのスペースで右詰め
    memcpy(&hlcd->buffer.str2[14 - len2], str2, len2);
	hlcd->buffer.str2[14] = 'H';
	hlcd->buffer.str2[15] = 'z';
    return LCD_UpdateDisplay(hlcd);
}

// LCD制御関数(I2C) END

// LCD基本情報表示関数エリア BEGIN
// 備考:基本情報表示項目を増やしたい場合は関数を作りt_def.hのdispポインタ関数に追加すること  ih_define.hの基本情報ページ数も変更すること

// 00.誘導加熱電源入力電流W換算値表示
// 引数：無し
// 返り値：無し
void page00Dsp(void)
{
    LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';

    // 1行目構築
    hlcd->buffer.str1[0] = '0';
    hlcd->buffer.str1[1] = '0';
    hlcd->buffer.str1[2] = '-';
    hlcd->buffer.str1[5] = 'P';
    hlcd->buffer.str1[6] = 'i';
    hlcd->buffer.str1[7] = 'n';
    hlcd->buffer.str1[8] = 'W';
    hlcd->buffer.str1[9] = '=';
    
    LCD_ConvU32(hlcd->buffer.str1, 11, (uint16_t)calc.pw_inputw, 4);
    
    hlcd->buffer.str2[0] = 'P';
    LCD_ConvU32(hlcd->buffer.str2, 1, calc.pon_ratio, 4);
    hlcd->buffer.str1[15] = 'W';

    // 2行目後半構築
    hlcd->buffer.str2[5] = 'P';
    hlcd->buffer.str2[6] = 'i';
    hlcd->buffer.str2[7] = 'n';
    hlcd->buffer.str2[8] = 'I';
    hlcd->buffer.str2[9] = '=';
    LCD_ConvFloat(hlcd->buffer.str2, 10, (float)calc.pw_ini100/100.0, 5, 2);
    hlcd->buffer.str2[15] = 'A';

    // 差分のある部分のみ更新
    LCD_UpdateDisplay(hlcd);
}

// 01.誘導加熱電源入力電流表示(0～5.77A)
// 引数：無し
// 返り値：無し
void page01Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '1';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'P';
	hlcd->buffer.str1[6] = 'i';
	hlcd->buffer.str1[7] = 'n';
	hlcd->buffer.str1[8] = 'I';
	hlcd->buffer.str1[9] = '=';
	LCD_ConvFloat(hlcd->buffer.str1,10,(float)calc.pw_ini100/100.0,5,2);													// 誘導加熱電源入力電流値
	hlcd->buffer.str1[15] = 'A';

	hlcd->buffer.str2[3] = 'P';
	hlcd->buffer.str2[4] = 'i';
	hlcd->buffer.str2[5] = 'n';
	hlcd->buffer.str2[6] = 'I';
	hlcd->buffer.str2[7] = 'A';
	hlcd->buffer.str2[8] = 'D';
	hlcd->buffer.str2[9] = '=';
	LCD_ConvU16(hlcd->buffer.str2,11,adc.inputI,5);																// 誘導加熱電源入力電流AD値


	LCD_UpdateDisplay(hlcd);
}

// 02.出力パワー設定値表示(PWM--->%)
// 引数：無し
// 返り値：無し

void page02Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';

	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '2';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'P';
	hlcd->buffer.str1[6] = 'o';
	hlcd->buffer.str1[7] = 'u';
	hlcd->buffer.str1[8] = 't';
	hlcd->buffer.str1[9] = '=';
	hlcd->buffer.str1[10] = ' ';
	LCD_ConvFloat(hlcd->buffer.str1,10,(float)ihp.pwmlevel/10.0,5,1);												// 出力パワー値(%)
	hlcd->buffer.str1[15] = '%';

	hlcd->buffer.str2[0] = 'P';
	hlcd->buffer.str2[1] = 'I';
	hlcd->buffer.str2[2] = '=';
	LCD_ConvFloat(hlcd->buffer.str2,3,(float)calc.pw_ini100/100.0,4,1);													// 誘導加熱電源入力電流値
	hlcd->buffer.str2[7] = 'A';
	hlcd->buffer.str2[8] = 'I';
	hlcd->buffer.str2[9] = 'H';
	hlcd->buffer.str2[10] = '=';
	LCD_ConvFloat(hlcd->buffer.str2,11,(float)data_Setting[EA_ILIMIT/ENV_GM][EA_ILIMIT%ENV_GM]/10.0,4,1);						// 入力電流上限値(0.0～19.5A)
	hlcd->buffer.str2[15] = 'A';
	
	LCD_UpdateDisplay(hlcd);
}

// 03.ヒートシンク温度表示
// 引数：無し
// 返り値：無し

void page03Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '3';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'H';
	hlcd->buffer.str1[6] = 'S';
	hlcd->buffer.str1[7] = 'T';
	hlcd->buffer.str1[8] = '=';
	if(calc.htmp == TEMP_SENSOR_ERROR){ // センサー未接続
		hlcd->buffer.str1[9] = 'O';
		hlcd->buffer.str1[10] = 'P';
		hlcd->buffer.str1[11] = 'E';
		hlcd->buffer.str1[12] = 'N';
		hlcd->buffer.str1[13] = 'E';
		hlcd->buffer.str1[14] = 'R';
		hlcd->buffer.str1[15] = 'R';
	} else {
		LCD_ConvU16(hlcd->buffer.str1,9,calc.htmp,2);																// ヒートシンク温度 
		hlcd->buffer.str1[11] = 0xDF;
		hlcd->buffer.str1[12] = 'C';
	}
	
	if(data_Setting[EA_TSENS/ENV_GM][EA_TSENS%ENV_GM]){ // STS-73温度ｾﾝｻ 
		hlcd->buffer.str2[0] = 'S';
		hlcd->buffer.str2[1] = 'T';
		hlcd->buffer.str2[2] = '7';
		hlcd->buffer.str2[3] = '3';
	}
	else{ // STS-60温度ｾﾝｻ 
		hlcd->buffer.str2[0] = 'S';
		hlcd->buffer.str2[1] = 'T';
		hlcd->buffer.str2[2] = '6';
		hlcd->buffer.str2[3] = '0';
	}

	hlcd->buffer.str2[5] = 'P';
	hlcd->buffer.str2[6] = 'H';
	hlcd->buffer.str2[7] = 'L';
	hlcd->buffer.str2[8] = '=';
	LCD_ConvU16(hlcd->buffer.str2,9,data_Setting[EA_TMPALM/ENV_GM][EA_TMPALM%ENV_GM], 2);							// ヒートシンクオーバープロテクト温度
	hlcd->buffer.str2[11] = ',';
	LCD_ConvU16(hlcd->buffer.str2,12,data_Setting[EA_TMPREL/ENV_GM][EA_TMPREL%ENV_GM], 2);							// ヒートシンクオーバープロテクト解除温度
	hlcd->buffer.str2[14] = ' ';

	LCD_UpdateDisplay(hlcd);
}

// 04.誘導加熱電源発振器周波数表示
// 引数：無し
// 返り値：無し

void page04Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '4';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'O';
	hlcd->buffer.str1[6] = 'S';
	hlcd->buffer.str1[7] = 'C';
	hlcd->buffer.str1[8] = '=';
	LCD_ConvFloat(hlcd->buffer.str1,9, (float)ihp.current_freq/1000.0, 6,2);															// 発振器周波数(Hz) 
	hlcd->buffer.str1[15] = 'K';

	hlcd->buffer.str2[5] = 'P';
	hlcd->buffer.str2[6] = 'i';
	hlcd->buffer.str2[7] = 'n';
	hlcd->buffer.str2[8] = 'W';
	hlcd->buffer.str2[9] = '=';
	if(calc.iinf_ratio < data_Setting[EA_POUTADJ/ENV_GM][EA_POUTADJ%ENV_GM] * 100){ // パワー補正領域起点10～50%：標準値は40%以下 2022.09.30
		calc.pon_ratio = calc.iinf_ratio / data_Setting[EA_POUTADJ/ENV_GM][EA_POUTADJ%ENV_GM];				// パワーON比率計算 
		LCD_ConvU32(hlcd->buffer.str2,10, (uint16_t)calc.pw_inputw, 4);										// 誘導加熱電源入力電流W換算値(0～2000W: W = V*I*SQR(3)) 補正禁止 
		hlcd->buffer.str2[0] = 'P';
		LCD_ConvU32(hlcd->buffer.str2,1, calc.pon_ratio, 3);
	}
	else{ // パワー補正領域外 
		LCD_ConvU32(hlcd->buffer.str2,10, (uint16_t)calc.pw_inputw, 4);											// 誘導加熱電源入力電流W換算値(0～2000W: W = V*I*SQR(3)) 
		hlcd->buffer.str2[0] = 'P';
		hlcd->buffer.str2[1] = '1';
		hlcd->buffer.str2[2] = '0';
		hlcd->buffer.str2[3] = '0';
	}
	hlcd->buffer.str2[14] = 'W';

	LCD_UpdateDisplay(hlcd);
}

// 05.出力パワー制御用電流インターフェース入力値表示(%)
// 引数：無し
// 返り値：無し

void page05Dsp(void)
{
	uint16_t	pwmmax;

	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '5';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'P';
	hlcd->buffer.str1[6] = 'c';
	hlcd->buffer.str1[7] = 'n';
	hlcd->buffer.str1[8] = 't';
	hlcd->buffer.str1[9] = '=';
	LCD_ConvFloat(hlcd->buffer.str1,10, (float)calc.iinf_ratio/100.0, 5,1);														// 電流インターフェース入力値(%) 
	hlcd->buffer.str1[15] = '%';

	if(data_Setting[EA_IINF/ENV_GM][EA_IINF%ENV_GM]){ // 0-20mA電流インターフェース 
		hlcd->buffer.str2[0] = '0';
		hlcd->buffer.str2[1] = '-';
		hlcd->buffer.str2[2] = '2';
		hlcd->buffer.str2[3] = '0';
	}
	else{ // 4-20mA電流インターフェース 
		hlcd->buffer.str2[0] = '4';
		hlcd->buffer.str2[1] = '-';
		hlcd->buffer.str2[2] = '2';
		hlcd->buffer.str2[3] = '0';
	}
	hlcd->buffer.str2[9] = 'M';
	hlcd->buffer.str2[10] = 'A';
	hlcd->buffer.str2[11] = 'X';
	pwmmax = data_Setting[EA_PWMLMT/ENV_GM][EA_PWMLMT%ENV_GM];
	pwmmax = pwmmax < 100 ? pwmmax : 100;
	LCD_ConvU32(hlcd->buffer.str2,12, pwmmax, 3);																// 電流インターフェース入力AD値 
	hlcd->buffer.str2[15] = '%';

	LCD_UpdateDisplay(hlcd);
}

// 06.＋１２V制御系電源電圧表示
// 引数：無し
// 返り値：無し

void page06Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '6';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'C';
	hlcd->buffer.str1[6] = 'n';
	hlcd->buffer.str1[7] = 't';
	hlcd->buffer.str1[8] = 'V';
	hlcd->buffer.str1[9] = '=';
	LCD_ConvFloat(hlcd->buffer.str1,10, (float)calc.cntrolV/100.0, 5,2);														// 監視電源電圧(V) 
	hlcd->buffer.str1[15] = 'V';

	hlcd->buffer.str2[5] = 'C';
	hlcd->buffer.str2[6] = 'v';
	hlcd->buffer.str2[7] = 'A';
	hlcd->buffer.str2[8] = 'D';
	hlcd->buffer.str2[9] = '=';
	LCD_ConvU32(hlcd->buffer.str2,10, adc.cntV, 5);																// 監視電源電圧AD値 

	LCD_UpdateDisplay(hlcd);
}

// 07.誘導加熱電源INPUTステータス表示
// 引数：無し
// 返り値：無し

void page07Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '7';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'H';
	hlcd->buffer.str1[6] = 'E';
	hlcd->buffer.str1[8] = 'R';
	hlcd->buffer.str1[9] = 'E';
	hlcd->buffer.str1[11] = 'I';
	hlcd->buffer.str1[12] = 'L';
	hlcd->buffer.str1[14] = 'O';
	hlcd->buffer.str1[15] = 'S';

	hlcd->buffer.str2[0] = 'I';
	hlcd->buffer.str2[1] = 'N';
	hlcd->buffer.str2[2] = ' ';
	if(sigI.heat)				hlcd->buffer.str2[5] = '1';														// 外部加熱要求ON 
	else						hlcd->buffer.str2[5] = '0';														// 外部加熱要求OFF 
	if(sigI.reset)				hlcd->buffer.str2[8] = '1';														// 外部リセット要求ON 
	else						hlcd->buffer.str2[8] = '0';														// 外部リセット要求OFF 
	if(sigI.ilock)				hlcd->buffer.str2[11] = '1';														// 外部インターロック要求ON 
	else						hlcd->buffer.str2[11] = '0';														// 外部インターロック要求OFF 

	LCD_UpdateDisplay(hlcd);
}

// 08.誘導加熱電源OUTPUTステータス表示
// 引数：無し
// 返り値：無し

void page08Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '8';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'R';
	hlcd->buffer.str1[7] = 'A';
	hlcd->buffer.str1[9] = 'H';
	
	hlcd->buffer.str2[0] = 'O';
	hlcd->buffer.str2[1] = 'U';
	hlcd->buffer.str2[2] = 'T';
	if(sigO.ready)				hlcd->buffer.str2[5] = '1';														// READY外部出力ON
	else						hlcd->buffer.str2[5] = '0';														// READY外部出力OFF
	if(sigO.alarm)				hlcd->buffer.str2[7] = '1';														// ALARM外部出力ON
	else						hlcd->buffer.str2[7] = '0';														// ALARM外部出力OFF
	if(sigO.heating)			hlcd->buffer.str2[9] = '1';														// 加熱中外部出力ON
	else						hlcd->buffer.str2[9] = '0';														// 加熱中外部出力OFF	

	LCD_UpdateDisplay(hlcd);
}

// 09.稼働時間表示
// 引数：無し
// 返り値：無し

void page09Dsp(void)
{
	uint32_t	hour, sec;
	SYSTIM 		tim;
	tk_get_tim(&tim);

	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '0';
	hlcd->buffer.str1[1] = '9';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'A';
	hlcd->buffer.str1[6] = '=';
	LCD_ConvU32(hlcd->buffer.str1, 7, periodic_data.atimtt, 8);  // 稼働時間 msを秒に変換
    hlcd->buffer.str1[15] = 's';																	

	// 状態表示
    switch(scnt.mstn) {
        case IH_PON:
            memcpy(&hlcd->buffer.str2[0], "PON  ", 5);
            break;
        case IH_POFF:
            memcpy(&hlcd->buffer.str2[0], "POFF ", 5);
            break;
        case IH_ILOCK:
            memcpy(&hlcd->buffer.str2[0], "INLK ", 5);
            break;
        case IH_ALARM:
            memcpy(&hlcd->buffer.str2[0], "Err  ", 5);
            break;
        case IH_STARTUP:
            memcpy(&hlcd->buffer.str2[0], "INIT ", 5);
            break;
    }

	// 時分秒の計算
    uint32_t total_sec = periodic_data.atimtt;
    uint32_t hours = total_sec / 3600;
    uint32_t minutes = (total_sec % 3600) / 60;
    uint32_t seconds = total_sec % 60;

	// 下段右側：時:分:秒（時間は可変桁、分秒は2桁固定）
    char timestr[16];
    snprintf(timestr, sizeof(timestr), "%u:%02u:%02u", hours, minutes, seconds);
    size_t len = strlen(timestr);
    
    // 状態表示の後（5文字）から残りのスペースで右詰め
    if (len <= 11) {  // 16 - 5 = 11（残りのスペース）
        memcpy(&hlcd->buffer.str2[16 - len], timestr, len);
    } else {
        // 長すぎる場合は切り詰め
        memcpy(&hlcd->buffer.str2[5], timestr, 11);
    } 

	LCD_UpdateDisplay(hlcd);
}

// 10.警報情報表示
// 引数：無し
// 返り値：無し

void page10Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '1';
	hlcd->buffer.str1[1] = '0';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'O';
	hlcd->buffer.str1[6] = 'S';
	hlcd->buffer.str1[7] = 'C';
	hlcd->buffer.str1[8] = '=';
	LCD_ConvU32(hlcd->buffer.str1,9, periodic_data.oscerr_ct, 5);								// OSCエラー累積カウンタ表示 
	hlcd->buffer.str1[14] = ' ';

	hlcd->buffer.str2[1] = '-';
	if(ihp.oscerr)			hlcd->buffer.str2[1] = 'O';											// OSCエラー発生 
	else					hlcd->buffer.str2[1] = '-';
	if(ihp.hstoverr)		hlcd->buffer.str2[2] = 'H';											// ヒートシンク温度オーバーエラー発生 
	else					hlcd->buffer.str2[2] = '-';

	hlcd->buffer.str2[5] = 'H';
	hlcd->buffer.str2[6] = 'S';
	hlcd->buffer.str2[7] = 'T';
	hlcd->buffer.str2[8] = '=';
	LCD_ConvU32(hlcd->buffer.str2,9, periodic_data.hstovr_ct, 5);								// ヒートシンク温度オーバーエラー累積カウンタ表示 
	hlcd->buffer.str2[14] = ' ';

	LCD_UpdateDisplay(hlcd);
}

// 11.稼働時間・起動回数表示
// 引数：無し
// 返り値：無し

void page11Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '1';
	hlcd->buffer.str1[1] = '1';
	hlcd->buffer.str1[2] = '-';

	hlcd->buffer.str1[5] = 'A';
	hlcd->buffer.str1[6] = '=';
	LCD_ConvU32(hlcd->buffer.str1,7, periodic_data.atimtt, 9);					// 稼働時間(秒) 

	hlcd->buffer.str2[5] = 'P';
	hlcd->buffer.str2[6] = 'o';
	hlcd->buffer.str2[7] = 'n';
	hlcd->buffer.str2[8] = 'C';
	hlcd->buffer.str2[9] = 't';
	hlcd->buffer.str2[10] = '=';
	LCD_ConvU32(hlcd->buffer.str2,11, periodic_data.ponct, 5);						// 起動(スタートアップ回数)積算カウンタ 

	LCD_UpdateDisplay(hlcd);
}

// 12.共振周波数・位相差表示
// 引数：無し
// 返り値：無し

void page12Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '1';
	hlcd->buffer.str1[1] = '2';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[5] = 'F';
	hlcd->buffer.str1[6] = 'R';
	hlcd->buffer.str1[7] = 'Q';
	hlcd->buffer.str1[8] = '=';
	LCD_ConvFloat(hlcd->buffer.str1,9, 	(float)data_Setting[EA_RESONANTFREQ/ENV_GM][EA_RESONANTFREQ%ENV_GM]/100.0, 6,2);		// 共振周波数(Hz) 
	hlcd->buffer.str1[15] = 'K';

	hlcd->buffer.str2[3] = 'P';
	hlcd->buffer.str2[4] = 'h';
	hlcd->buffer.str2[5] = 'a';
	hlcd->buffer.str2[6] = 's';
	hlcd->buffer.str2[7] = 'e';
	hlcd->buffer.str2[8] = '=';
	LCD_ConvFloat(hlcd->buffer.str2,10, (float)data_Setting[EA_RESONANTDIFF/ENV_GM][EA_RESONANTDIFF%ENV_GM],5,1);				// 共振位相差
	hlcd->buffer.str2[15] = 0xDF;
	LCD_UpdateDisplay(hlcd);
}

// 13.最大デューティ・最大出力電流表示
// 引数：無し
// 返り値：無し

void page13Dsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = '1';
	hlcd->buffer.str1[1] = '3';
	hlcd->buffer.str1[2] = '-';
	hlcd->buffer.str1[7] = 'D';
	hlcd->buffer.str1[8] = 'u';
	hlcd->buffer.str1[9] = 't';
	hlcd->buffer.str1[10] = 'y';
	hlcd->buffer.str1[11] = '=';
	LCD_ConvU32(hlcd->buffer.str1,12, data_Setting[EA_MAXPWM/ENV_GM][EA_MAXPWM%ENV_GM], 3);		// 最大デューティ(%) 
	hlcd->buffer.str1[15] = '%';

	hlcd->buffer.str2[3] = 'O';
	hlcd->buffer.str2[4] = 'u';
	hlcd->buffer.str2[5] = 't';
	hlcd->buffer.str2[6] = 'p';
	hlcd->buffer.str2[7] = 'u';
	hlcd->buffer.str2[8] = 't';
	hlcd->buffer.str2[9] = '=';
	LCD_ConvFloat(hlcd->buffer.str2,10, (float)data_Setting[EA_MAXINPUT/ENV_GM][EA_MAXINPUT%ENV_GM] * 10 / IH_INIX10 ,5,1);				// 最大出力電流
	hlcd->buffer.str2[15] = 'A';
	LCD_UpdateDisplay(hlcd);
}

// ex.バージョン情報
// 引数：無し
// 返り値：無し

void versionDsp(void)
{
	LCD_HandleTypeDef* hlcd = &lcd_handle;
    
    // バッファクリア（次表示用バッファのみ）
    memset(hlcd->buffer.str1, ' ', LCD_MAX_CHARS);
    memset(hlcd->buffer.str2, ' ', LCD_MAX_CHARS);
    hlcd->buffer.str1[LCD_MAX_CHARS] = '\0';
    hlcd->buffer.str2[LCD_MAX_CHARS] = '\0';
	
	hlcd->buffer.str1[0] = 'V';
	hlcd->buffer.str1[1] = 'e';
	hlcd->buffer.str1[2] = 'r';

	size_t len = strlen(VERSION_INFO.version);
	memcpy(&hlcd->buffer.str1[16 - len], VERSION_INFO.version, len);
	len = strlen(VERSION_INFO.buildDate);
	memcpy(&hlcd->buffer.str2[16 - len], VERSION_INFO.buildDate, len);
	LCD_UpdateDisplay(hlcd);
}
// LCD基本情報表示関数エリア END

//ユーザー関数定義エリア END
