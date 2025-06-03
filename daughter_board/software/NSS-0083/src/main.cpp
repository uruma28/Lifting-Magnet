#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEClient.h>

// BLE サービスとキャラクタリスティックのUUID
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// LEDピン定義
#define LED_PIN D1  // D1ピン（GPIO1）を使用

// LEDCの設定
#define LEDC_CHANNEL 0
#define LEDC_FREQ 5000
#define LEDC_RESOLUTION 8

// グローバル変数
BLEClient* pClient = NULL;
BLERemoteCharacteristic* pRemoteCharacteristic = NULL;
bool deviceConnected = false;
bool doScan = true;

// 接続状態を保持する変数
BLEAddress* serverAddress;
const char* targetDeviceName = "XIAO-Switch";

// 接続コールバック
class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
    deviceConnected = true;
  }

  void onDisconnect(BLEClient* pclient) {
    deviceConnected = false;
    ledcWrite(LEDC_CHANNEL, 0);  // 切断時にLEDをOFF
  }
};

// LED状態変更時のコールバック - 最優先処理
void notifyCallback(BLERemoteCharacteristic* pBLERemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify) {
  if (length > 0) {
    bool ledState = pData[0] == 1;
    
    // LEDの状態を直ちに更新
    ledcWrite(LEDC_CHANNEL, ledState ? 255 : 0);
    
    // デバッグ出力は後回し（オプション）
    Serial.print("LED: ");
    Serial.println(ledState ? "ON" : "OFF");
  }
}

// BLEデバイススキャンコールバック
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    // 指定したサービスUUIDを持つデバイスまたは名前が一致するデバイスを探す
    if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(BLEUUID(SERVICE_UUID)) ||
        (advertisedDevice.haveName() && strcmp(advertisedDevice.getName().c_str(), targetDeviceName) == 0)) {
      
      BLEDevice::getScan()->stop();
      serverAddress = new BLEAddress(advertisedDevice.getAddress());
      doScan = false;
    }
  }
};

// サーバーへの接続 - 優先処理
bool connectToServer() {
  // クライアント作成
  pClient = BLEDevice::createClient();
  pClient->setClientCallbacks(new MyClientCallback());
  
  // サーバーに接続
  if (!pClient->connect(*serverAddress)) {
    return false;
  }
  
  // サービスを取得
  BLERemoteService* pRemoteService = pClient->getService(BLEUUID(SERVICE_UUID));
  if (pRemoteService == nullptr) {
    pClient->disconnect();
    return false;
  }
  
  // キャラクタリスティックを取得
  pRemoteCharacteristic = pRemoteService->getCharacteristic(BLEUUID(CHARACTERISTIC_UUID));
  if (pRemoteCharacteristic == nullptr) {
    pClient->disconnect();
    return false;
  }
  
  // 通知を登録 - コールバックを最優先
  if (pRemoteCharacteristic->canNotify()) {
    pRemoteCharacteristic->registerForNotify(notifyCallback, true); // true=通知を優先
  }
  
  return true;
}

void setup() {
  Serial.begin(115200);
  
  // LEDCの設定
  ledcSetup(LEDC_CHANNEL, LEDC_FREQ, LEDC_RESOLUTION);
  ledcAttachPin(LED_PIN, LEDC_CHANNEL);
  ledcWrite(LEDC_CHANNEL, 0);  // 初期状態はOFF
  
  // BLEデバイスの初期化
  BLEDevice::init("XIAO-LED");
  
  // スキャナーセットアップ - スキャン間隔を短く設定
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(45);  // 短いスキャン間隔
  pBLEScan->setWindow(15);    // 短いスキャンウィンドウ
  pBLEScan->setActiveScan(true);
  
  pBLEScan->start(5, false);  // 5秒間スキャン
}

void loop() {
  // スキャンが完了し、デバイスが見つかった場合
  if (!doScan && !deviceConnected) {
    if (connectToServer()) {
      // 接続成功 - LED点滅表示
      for (int i = 0; i < 3; i++) {
        ledcWrite(LEDC_CHANNEL, 255);
        delay(50);
        ledcWrite(LEDC_CHANNEL, 0);
        delay(50);
      }
    } else {
      doScan = true;
      delete serverAddress;
      BLEDevice::getScan()->start(5, false);
    }
  }
  
  // 接続が切れた場合、再スキャン
  if (!deviceConnected && !doScan) {
    if (connectToServer()) {
      // 再接続成功
    } else {
      doScan = true;
      delete serverAddress;
      BLEDevice::getScan()->start(5, false);
    }
  }
  
  // delayを短くして応答性を向上
  delay(2);
}