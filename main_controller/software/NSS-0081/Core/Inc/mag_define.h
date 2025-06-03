#define 	ON					1				// オン
#define		OFF					0				// オフ
#define		EN					1				// 許可	
#define		DIS					0				// 禁止
#define		FLG_ON				(1<<0)			// イベントフラグオン
#define		FLG_OFF				(0<<0)			// イベントフラグオフ
#define 	CHANNEL2  			2				// TIM2チャンネル2キャプチャメッセージ
#define 	CHANNEL3			3		  		// TIM2チャンネル3キャプチャメッセージ

// LCDコマンド送信用定数(I2C)
#define 	LCDADRESS 			0x50 << 1 		// スレーブ7ビットアドレスを左シフト
#define 	CMDSEND 			0x00			// コマンド送信
#define		DATASEND 			0x80			// データ送信
#define		LCD_MAX_CHARS		16				// LCD列数

// ADC値の変換係数 (14bit → 10bit相当に変換)
#define 	ADC_14BIT_TO_10BIT_FACTOR  (16)

// 表示フォーマット定義
#define 	CONFIG_FORMAT 		"CONFIG %02d: %5d"
#define 	BLANK_VALUE   		"     "  		// 5桁分の空白

#define		CNTV_10V			400				//制御電源電圧10VAD値　（仮）

// Flashメモリアドレスの定義
#define		FLASH_BANK2_BASE	0x08040000UL

// PERIODIC_DATAセクション（周期保存データ用）
#define 	PERIODIC_DATA_START 0x08070000UL
#define 	PERIODIC_DATA_SIZE  (48 * 1024)  // 48 KB
#define 	PERIODIC_DATA_END   (PERIODIC_DATA_START + PERIODIC_DATA_SIZE - 1)
// 周期保存データ用のページ数
#define 	PERIODIC_DATA_PAGES (PERIODIC_DATA_SIZE / FLASH_PAGE_SIZE)  // 24ページ
// 周期保存データの開始ページ番号
#define 	PERIODIC_START_PAGE ((PERIODIC_DATA_START - FLASH_BANK2_BASE) / FLASH_PAGE_SIZE)

// REQUEST_DATAセクション（要求保存データ用）
#define 	REQUEST_DATA_START  0x0807C000UL
#define 	REQUEST_DATA_SIZE   (16 * 1024)  // 16 KB
#define 	REQUEST_DATA_END    (REQUEST_DATA_START + REQUEST_DATA_SIZE - 1)
// 要求保存データ用のページ数
#define 	REQUEST_DATA_PAGES  (REQUEST_DATA_SIZE / FLASH_PAGE_SIZE)   // 8ページ
// 要求保存データの開始ページ番号
#define 	REQUEST_START_PAGE  ((REQUEST_DATA_START - FLASH_BANK2_BASE) / FLASH_PAGE_SIZE)

// フラッシュ管理用の定数
#define 	FLASH_VERIFY_RETRY_COUNT  3
#define 	FLASH_WRITE_RETRY_COUNT   3
#define 	FLASH_PAGE_LIMIT          10000   	// 書き込み回数の警告閾値
#define 	FLASH_OPERATION_TIMEOUT   1000    	// タイムアウト時間(ms)

#define 	TOTAL_INFO_PAGES 	15				// 基本情報表示ページ数
#define		ENV_GM				10				// 動作環境データグループ内メンバ数 

// 動作環境データ 00～09：システムコントロール
#define		EA_EXIT				0				// 00:環境データ設定終了(オートロック付き)
#define		EA_SEN				1				// 01:環境データ変更許可(0:禁止 1:許可) 
#define		EA_LCDCNT			2				// 02:LCDｺコントラスト 
#define		EA_LCDBR			3				// 03:LCD輝度 
#define		EA_LCDCHG			4				// 04:LCD表示更新周期 
#define		EA_RESERVR05		5				// 05:予備5
#define		EA_RESERVR06		6				// 06:予備6
#define		EA_RESERVR07		7				// 07:予備7
#define		EA_RESERVR08		8				// 08:予備8
#define		EA_RESERVR09		9				// 09:予備9
// 動作環境データ 10～19：BMUコントロール1 
#define		EA_PWMSTOP			10				// 10:出力パワー制御PWM停止レベル(1～25%) 
#define		EA_PWMLMT			11				// 11:出力パワー制御PWMリミット値(0～100%) 
#define		EA_IINF				12				// 12:電流インターフェース選択0:4-20mA、1:0-20mA) 
#define		EA_TSENS			13				// 13:温度センサ選択(0:STS-60、1:STS-73) 
#define		EA_SSTART			14				// 14:ソフトスタート時間(0.01～1.0秒) 
#define		EA_RESETEN			15				// 15:外部リセット操作許可 
#define		EA_TMPALM			16				// 16:温度異常警報判定値(45～60℃) 
#define		EA_TMPREL			17				// 17:温度異常警報解除温度(35～44℃) 
#define		EA_ILIMIT			18				// 18:入力電流リミット値(0.0～19.5A)
#define		EA_PCNTTM			19				// 19:出力制御周期(100μS～49999μS) 
// 動作環境データ 20～29：BMUコントロール2 
#define		EA_HZMT				20				// 20:発振器周波数計測周期 
#define		EA_PWMADJ			21				// 21:PWM補正不感帯(0.0～3.0%) 
#define		EA_PFACTOR			22				// 22:力率設定(80%～99%) 
#define		EA_POUTADJ			23				// 23:パワー補正領域上限値設定(10～50%) 
#define		EA_PADJCYC			24				// 24:パワー補正制御実行周期(0.5～2.0秒) 
#define		EA_MPWMRANGE		25				// 25:モニタPWMレンジ選択 
#define		EA_1KWADJ			26				// 26:1KWレンジモニタPWM補正係数(1.0～1.5) 
#define		EA_ADJONOFF			27				// 27:パワー補正制御許可(禁止(Dis)/許可(En))
#define		EA_PWMPHASE			28				// 28:PWM出力位相差設定
#define		EA_LMTOUTPUT		29				// 29:制限出力電流
// 動作環境データ 30～39：BMUデータ1 
#define		EA_MAXFREQ			30				// 30:最大周波数
#define		EA_MINFREQ			31				// 31:最小周波数
#define		EA_DEFFREQ			32				// 32:標準周波数
#define		EA_RUNW3AT2			33				// 33: 
#define		EA_RUNW3AT1			34				// 34: 
#define		EA_RUNW4AT5			35				// 35: 
#define		EA_RUNW4AT4			36				// 36: 
#define		EA_RUNW4AT3			37				// 37: 
#define		EA_RUNW4AT2			38				// 38: 
#define		EA_RUNW4AT1			39				// 39: 
// 動作環境データ 40～49：BMUデータ2 
#define		EA_RUNW5AT5			40				// 40: 
#define		EA_RUNW5AT4			41				// 41: 
#define		EA_RUNW5AT3			42				// 42: 
#define		EA_RUNW5AT2			43				// 43: 
#define		EA_RUNW5AT1			44				// 44: 
#define		EA_RUNW6AT5			45				// 45:
#define		EA_RUNW6AT4			46				// 46:
#define		EA_RUNW6AT3			47				// 47:
#define		EA_RUNW6AT2			48				// 48:
#define		EA_RUNW6AT1			49				// 49:
// 動作環境データ 50～59：システム管理データ 
#define		EA_DEBUG			50				// 50:検証モードON/OFF(1/0) 
#define		EA_IINFAD			51				// 51:電流インターフェースAD値設定 
#define		EA_HSTAD			52				// 52:ヒートシンク温度AD値設定 
#define		EA_PINIAD			53				// 53:入力電流AD値設定 
#define		EA_P12VAD			54				// 54:＋１２V制御電源電圧AD値設定 
#define		EA_BLANK			55				// 55:
#define		EA_SYSMEMO			56				// 56:システムメモ(00.00~99.99) 
#define		EA_CPTEST			57				// 57:サーキッドプロテクタ動作テスト(0:OFF 1:ON) 
#define		EA_EPRTERR			58				// 58:EEPROMリード・ライトリトライエラー状況 
#define		EA_TEST				59				// 59:組立検査 
// 動作環境データ 60～69：テスト用 
#define		EA_RUNW7AT5			60				// 60:
#define		EA_RUNW7AT4			61				// 61: 
#define		EA_RUNW7AT3			62				// 62: 
#define		EA_RUNW7AT2			63				// 63: 
#define		EA_RUNW7AT1			64				// 64: 
#define		EA_RUNW8AT5			65				// 65:
#define		EA_RUNW8AT4			66				// 66:
#define		EA_RUNW8AT3			67				// 67:
#define		EA_RUNW8AT2			68				// 68:
#define		EA_RUNW8AT1			69				// 69:
// 動作環境データ 70～79：予備 
#define		EA_RUNW0ABI			70				// 70:
#define		EA_RUNW1AI			71				// 71:
#define		EA_RUNW1BI			72				// 72:
#define		EA_RUNW2AI			73				// 73: 
#define		EA_RUNW3AI			74				// 74:
#define		EA_RUNW4AI			75				// 75:
#define		EA_RUNW5AI			76				// 76:
#define		EA_RUNW6AI			77				// 77:
#define		EA_RUNW7AI			78				// 78: 
#define		EA_RUNW8AI			79				// 79:
// 動作環境データ 80～89：予備 
#define		EA_MANUALPOWER		80				// 80:出力手動制御モード
#define		EA_MANUALFREQ		81				// 81:周波数手動制御モード
#define		EA_COMPEXPLORE		82				// 81:共振周波数探査完了フラグ
#define		EA_RESONANTFREQ		83				// 82:共振周波数記録(10Hz単位)
#define		EA_RESONANTDIFF		84				// 83:共振周波数位相差記録
#define		EA_MAXPWM			85				// 84:最大PWM設定値
#define		EA_MAXINPUT			86				// 85:最大入電流
#define		EA_FIXEDFREQ		87				// 87:周波数固定モード
#define		EA_KPADJUST			88				// 88:比例ゲイン調整
#define		EA_KIADJUST			89				// 89:積分ゲイン調整
// 動作環境データ 90～99：予備 
#define		EA_TP5ADJ			90				// 90: 
#define		EA_TP4ADJ			91				// 91: 
#define		EA_TP3ADJ			92				// 92: 
#define		EA_TP2ADJ			93				// 93: 
#define		EA_TP1ADJ			94				// 94: 
#define		EA_VFMIN			95				// 95:
#define		EA_T5SQTM			96				// 96:
#define		EA_TPCGT			97				// 97:
#define		EA_TOFFSET			98				// 98:
#define		EA_SYSINIT			99				// 99: システム立ち上げ(製造、検査、出荷用) 

//	ステート定義
#define		STATE_INITIAL 		0				// 初期化ステート
#define		STATE_STANDBY 		1				// 待機ステート
#define		STATE_LIFTING 		2				// 着磁ステート
#define		STATE_HOLDING 		3				// 保持ステート
#define		STATE_RELEASE 		4				// 脱磁ステート
#define		STATE_ERROR 		5				// 異常発生ステート
#define		STATE_TEST 			6				// テストステート

#define		IINF4MA				3008			// 電流インターフェース4mAのAD値(実測値3008　計算値3031)
#define		IINF20MA			15060			// 電流インターフェース20mAのAD値(実測値15000 計算値15238)
#define		IINF100P			10000			// 電流インターフェース入力100%値 
#define		IINF9999			9999			// 電流インターフェース入力100%制限値 

#define		CNTV10V				7448			// +15V制御電源10V AD値 

#define		PWMMAX				3400			// PWMタイマ最大値
#define		PWMDEADTIM			680				// デッドタイム
#define		PWMEFFECTIVE		(PWMMAX - PWMDEADTIM)		// PWM有効範囲
#define		PWMPOW				1000			// PWM値1000倍%(例：MAX10000000--->2500(25%の100倍)*PWMPOW=2500000(pwmct*PWMPOW)) 
												// PWMを100μS単位で制御するための制御ｽﾃｯﾌﾟの計算上の桁落ち防止。 
#define		ADCMAX				16383			// ADC14ビット最大値(0~16383)

//計測処理用定義
#define		IH_MAXCT			65536			// 発振器周波数計測キャプチャタイマ最大値 
#define		IH_VREF				200				// AD変換基準電圧x100倍 
#define		IH_AC200V			200				// 誘導加熱電源電圧AC200V 
#define		IH_INIOFFSET		113				// 入力電流オフセット
#define		IH_INIX10			3001			// 入力電流1.0A AD値*10倍
#define		IH_OUTIX			1482			// 出力電流1.0A AD値
#define		IH_ROOT3			173.21			// ルート3 100倍
#define		IH_ROOT2			141.41			// ルート2 100倍
#define		IH_TCVP60			30				// 温度変換パラメータSTS-60用(0℃位置) 
#define		IH_TCVP73			40				// 温度変換パラメータSTS-73用(0℃位置)

// 周波数制御パラメータ
#define 	HRTIM_CLOCK        	170000000.0f  	// 170MHz
#define 	HIGH_RES_MULT      	0.25f         	// 分周比4
#define 	EFFECTIVE_CLOCK    	(HRTIM_CLOCK * HIGH_RES_MULT)  // 42.5MHz
#define 	FREQ_STEP          	10.0f          	// 周波数調整ステップ 10Hz
#define 	TEMP_SENSOR_ERROR	999				// エラー用温度

// LCD表示状態の定義
typedef enum {
    LCD_INFO = 0,     	// 基本情報表示状態
    LCD_DIGIT2,       	// 環境設定項目番号10の位選択状態
    LCD_DIGIT1,       	// 環境設定項目番号1の位選択状態
    LCD_SETCONFIG,     	// 環境設定選択項目設定状態
	LCD_DirectPower,	// パワー手動制御モード
	LCD_DirectFreq		// 周波数手動制御モード
} LCD_State;

// Flash制御のエラーコード定義
typedef enum {
    FLASH_OK = 0,
    FLASH_ERROR_PARAM,        // パラメータエラー
    FLASH_ERROR_LOCKED,       // フラッシュがロックされている
    FLASH_ERROR_ERASE,        // 消去エラー
    FLASH_ERROR_WRITE,        // 書き込みエラー
    FLASH_ERROR_VERIFY,       // ベリファイエラー
    FLASH_ERROR_SIZEE,         // サイズエラー
    FLASH_ERROR_TIMEOUT       // タイムアウト
} FlashError_t;

// LCD制御のエラーコード定義
typedef enum {
    LCD_OK = 0,
    LCD_ERROR_PARAM,    // パラメータエラー
    LCD_ERROR_I2C,      // I2C通信エラー
    LCD_ERROR_TIMEOUT   // タイムアウトエラー
} LcdError_t;

//システムコントロールブロック
typedef struct t_syscbl				
{
	uint16_t	mstn;						// メインステート番号
	uint16_t	sstn;						// サブステート番号
	int16_t		tim;						// コントロールタイマ
	uint8_t		texe;						// テスト実行指令 
	uint16_t	tstmd;						// テストモードNO 
	int16_t		twai;						// テスト待ち表示用カウンタ 
	int16_t		tsct;						// テストカウンタ(汎用) 
	int16_t		tswk;						// テストワーキングエリア
	int16_t		tsrz;						// テスト結果 
	int16_t		ercd;						// エラーコード(テスト結果) 
	uint8_t		tbuf1[64];					// 基本情報1Byte送信データ格納
	uint8_t		tbuf2[64];					// 基本情報2Byte送信データ格納
	uint8_t		stbuf1[64];					// 環境設定1Byte送信データ格納
	uint8_t		stbuf2[64];					// 環境設定2Byte送信データ格納
	uint8_t		stbufr[5];					// 環境設定受信データ格納 [更新有無][Byte数][設定番号][1Byteデータまたは上位ビット][下位ビット]
	uint8_t		bufchk;
} SYS_CBL;

// パワーコントロールブロック
typedef struct t_ihpcnt
{
	
	uint8_t		hstoverr;					// パワーデバイスヒートシンクオーバーヒート 
	uint16_t	hstocerr_cnt;				// パワーデバイスヒートシンクオーバーヒートカウンタ
	uint8_t		ss_en;						// ソフトスタート処理許可 
	uint8_t		ss_stn;						// ソフトスタート処理ステータス 
	uint8_t		sstart_end;					// ソフトスタート完了 
	uint8_t		pcnt_en;					// パワー制御許可 
	uint8_t		restart_req;				// パワー制御ﾘｽﾀｰﾄﾘｸｴｽﾄ(ソフトスタート完了後にパワーOFFになったときON) 
	uint8_t		pwm_stoplv;					// パワー制御PWM停止レベル検知 

	int32_t		pwmct;						// PWM設定値
	uint16_t	pwmlevel;					// PWM出力割合
	BOOL		Searching;					// 最大出力探査中フラグ

	uint16_t	oscerr_ct;					// 発振器エラーカウンタ
	uint16_t	oscerrcnt;					// 誤検知カウント
	uint16_t	oscerrclrcnt;				// 誤検知クリアカウント
	uint16_t	oscstpcnt;					// 誤検知停止時間 

	uint8_t		reset_on;					// リセット指令
	uint8_t		oscerr;						// OSCエラー検知

	uint32_t 	current_capture;    		// 出力電流フィードバックのキャプチャ値
    uint32_t 	voltage_capture;    		// PWM出力のキャプチャ値
	BOOL 		current_valid;          	// 電流キャプチャ有効フラグ
    BOOL 		voltage_valid;          	// 電圧キャプチャ有効フラグ
	uint32_t 	timer_period;       		// タイマーの周期

	uint32_t 	period;       				// 現在の周期レジスタ値
    uint32_t 	compare;      				// 比較レジスタ値（デューティ比制御用）
    uint16_t 	deadtime;     				// デッドタイム値
    uint16_t 	phase_diff;      			// 検出された位相差
    int8_t		freq_direction; 			// 周波数調整方向 (-1, 0, 1)

	BOOL		manualmode_Power;			// パワー手動制御モード
	BOOL		manualmode_Freq;			// 周波数手動制御モード

	uint16_t	manual_power;				// 手動制御目標出力値
	uint16_t	manual_freq;				// 手動制御目標周波数
	uint16_t 	current_freq;    			// 現在の周波数
	uint32_t	new_period;					// 次回周期値

} IHP_CBL;

//ADCコントロールブロック
typedef struct t_adc
{
    uint16_t inputI;                		// 入力電流 
    uint16_t outputI;               		// 出力電流
    uint16_t hstmp;                 		// ヒートシンク温度
    uint16_t interfaceI;            		// 4-20mA制御インターフェース
    uint16_t phase1;                		// 位相比較電圧1
    uint16_t phase2;                		// 位相比較電圧2
	uint16_t cntV;							// 監視電圧
}ADC_CBL;

//入力信号コントロールブロック
typedef struct t_sigI
{
    uint8_t heat;                    		// 加熱信号 (0:OFF,1:ON))
    uint8_t ilock;                   		// インターロック信号 (0:OFF,1:ON)
    uint8_t reset;                   		// リセット信号 (0:OFF,1:ON)
	uint8_t reset_old;						// リセット信号前回値(0:OFF,1:ON)
    uint8_t encoder;                 		// エンコーダ押下信号 (0:OFF,1:ON)
	uint8_t	encoder_old;					// エンコーダ押下信号前回値 (0:OFF,1:ON)
}SIGI_CBL;

//出力信号コントロールブロック
typedef struct t_sigO
{
    int8_t heating;                    		// 加熱中信号 (0:OFF,1:ON)
    int8_t ready;                      		// READY信号 (0:OFF,1:ON)
    int8_t alarm;                      		// エラー発生信号 (0:OFF,1:ON)
}SIGO_CBL;

//計算結果格納ブロック
typedef struct t_calc
{
	uint16_t 	pon_ratio;					// 出力比率
	int16_t		htmp;						// ヒートシンク温度 
	uint16_t	pw_ini100;					// 誘導加熱電源入力電流100倍値
	uint16_t	pw_rilimit;					// モニタPWMレンジ電流上限値 
	uint16_t	pw_mpwm;					// 入力電流モニタPWMカウント値 
	
	uint16_t	iinf_ratio;					// 出力パワー制御用電流インターフェース入力比率(100倍%) 
	uint32_t	pw_inputw;					// 誘導加熱電源入力電流W換算値 
	uint32_t	pw_outputi;					// 出力電流100倍値
	uint16_t	cntrolV;					// 監視電圧

	int32_t		phaseDiff;					// 位相差
}CALC_CBL;

// LCDコントロールブロック
typedef struct t_ctrlLcd
{
	uint8_t		encoder_on;					// エンコーダー押下信号
	LCD_State 	rotaryState;      			// 現在のLCD表示画面
	LcdError_t	status;						// LCDステータス					
}LCD_CBL;

// 周期保存データコントロールブロック
typedef struct t_dat						
{
	uint16_t	wct;						// 計測データライトブロックカウンタ(0～35040：4*24*365=35040) 
	uint16_t	ponct;						// 積算起動カウンタ(スタートアップ回数: 0～65535回まで巡回ｶｳﾝﾄ) 
	uint32_t	atimtt;						// 積算稼働時間(秒) 
	uint16_t	oscerr_ct;					// OSCエラー発生カウンタ(0～65535回まで巡回ｶｳﾝﾄ) 
	uint16_t	hstovr_ct;					// ヒートシンク温度オーバー発生カウンタ(0～65535回まで巡回ｶｳﾝﾄ) 
} DAT_CBL;

// 周波数PI制御コントロールブロック
typedef struct {
    float 		kp;           				// 比例ゲイン
    float 		ki;           				// 積分ゲイン
    float 		i_term;       				// 積分項
    float 		target;       				// 目標位相差（度）
    float 		prev_error;   				// 前回の偏差
    float 		prev_output;  				// 前回の出力値
} FreqPI_CBL;

// 出力PI制御コントロールブロック
typedef struct {
    float 		kp;							// 比例ゲイン
    float 		ki;							// 積分ゲイン
    float 		i_term;						// 積分項
	float		prev_error;					// 前回差分値
	uint16_t	limit_current;				// 最大出力電流
	uint16_t	limit_pwm;					// 最大PWMデューティ
} PowerPI_CBL;

// ページヘッダー構造体（8バイトアライメント）
#pragma pack(8)
typedef struct {
    uint32_t 	sequence;      				// シーケンス番号
    uint16_t 	write_count;   				// 書き込み回数
    uint16_t 	data_size;     				// データサイズ
} PageHeader;
#pragma pack()

// LCDバッファ構造体
typedef struct {
    char 		str1[LCD_MAX_CHARS + 1];  			// 1行目バッファ（+1 for null terminator）
    char 		str2[LCD_MAX_CHARS + 1];  			// 2行目バッファ
	char 		current_str1[LCD_MAX_CHARS + 1];  	// 現在表示中の1行目
    char 		current_str2[LCD_MAX_CHARS + 1];  	// 現在表示中の2行目
    BOOL 		is_initialized;           			// 初期化フラグ
} LCD_Buffer;

// LCD制御ハンドラ
typedef struct {
    I2C_HandleTypeDef* 	hi2c;    			// 指定されたI2Cハンドル
    uint8_t 			address;            			// LCDのI2Cアドレス
    LCD_Buffer 			buffer;          			// 表示バッファ
    uint32_t 			timeout;           			// タイムアウト時間
} LCD_HandleTypeDef;

// サーミスタの種類を定義
typedef enum {
    THERMISTOR_STS60,
    THERMISTOR_STS73
} ThermistorType;