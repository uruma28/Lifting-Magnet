#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// BLE サービスとキャラクタリスティックのUUID
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// BOOTボタンのピン定義
#define BUTTON_PIN 9  // D9(GPIO9) - BOOTボタンに接続済み

// BLEパラメータ設定 - uint16_t型に明示的に定義
#define MIN_CONN_INTERVAL (uint8_t)8  // 最小接続間隔（10ms = 8 * 1.25ms）
#define MAX_CONN_INTERVAL (uint16_t)16 // 最大接続間隔（20ms = 16 * 1.25ms）

// 状態変更の最小間隔（ミリ秒）
#define MIN_STATE_CHANGE_INTERVAL 150  // 150msの間は状態変更を無視

// グローバル変数
BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool enableBroadcast = true;

// ボタン状態を管理する変数
bool buttonReading = 1;     // ボタンの現在の読み取り値（プルアップなのでデフォルトは1=HIGH）
bool ledState = false;      // LED状態（最初はOFF）
unsigned long lastStateChangeTime = 0;  // 最後に状態を変更した時刻

// 接続状態を監視するコールバック
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t* param) {
    deviceConnected = true;
    Serial.println("デバイスが接続されました");
    
    // 接続デバイスのアドレスを取得して接続パラメータを更新
    pServer->updateConnParams(param->connect.remote_bda, 
                              8,     // minInterval (8 * 1.25ms = 10ms)
                              16,    // maxInterval (16 * 1.25ms = 20ms)
                              0,     // latency
                              400);  // timeout (400 * 10ms = 4000ms)
  }

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("デバイスが切断されました");
    
    if (enableBroadcast) {
      BLEDevice::startAdvertising();
      Serial.println("アドバタイズを再開しました");
    }
  }
};

void setup() {
  Serial.begin(115200);
  
  // ボタンピン設定
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 内部プルアップを使用
  
  // BLEデバイスの初期化
  BLEDevice::init("XIAO-Switch");
  
  // BLEサーバー作成
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  
  // BLEサービス作成
  BLEService *pService = pServer->createService(SERVICE_UUID);
  
  // BLEキャラクタリスティック作成
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
  
  // BLE 2902記述子追加（通知用）
  pCharacteristic->addDescriptor(new BLE2902());
  
  // サービス開始
  pService->start();
  
  // アドバタイジング開始
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMaxPreferred(0x12);
  BLEDevice::startAdvertising();
  
  Serial.println("アドバタイズ開始、接続待機中...");
  
  // 初期時刻を設定
  lastStateChangeTime = millis();
}

void loop() {
  // ボタンの状態を読み取り
  bool currentReading = digitalRead(BUTTON_PIN);
  
  // ボタンの状態が変化した場合
  if (currentReading != buttonReading) {
    // 読み取り値を更新
    buttonReading = currentReading;
    
    // ボタンが押されて離された（LOW→HIGH）タイミングでアクション
    if (buttonReading == 1) {  // 1=HIGH=ボタンが離された
      unsigned long currentTime = millis();
      
      // 最小間隔チェック - 前回の状態変更から一定時間が経過していない場合は無視
      if (currentTime - lastStateChangeTime < MIN_STATE_CHANGE_INTERVAL) {
        Serial.println("状態変更が短時間に連続したため無視しました");
      } else {
        // LED状態をトグル
        ledState = !ledState;
        Serial.print("LED状態変更: ");
        Serial.println(ledState ? "ON" : "OFF");
        
        // 新しい状態を送信
        if (deviceConnected) {
          uint8_t value = ledState ? 1 : 0;
          pCharacteristic->setValue(&value, 1);
          pCharacteristic->notify();
          Serial.println("状態を通知しました");
        } else {
          Serial.println("デバイスが接続されていないため通知できません");
        }
        
        // 状態変更時刻を更新
        lastStateChangeTime = currentTime;
      }
    }
  }
  
  delay(2);  // 2msに短縮
}