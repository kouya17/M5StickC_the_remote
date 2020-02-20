#include <M5StickC.h>
#include "SimpleWebServer.h"    // webサーバ用ライブラリ(機能esp02ほぼ同等)

#define MAX_TRY_CONNECT_INI   10      // 最大WiFi接続試行回数(初期接続)

SimpleWebServer server("room_monitor", "12345678", IPAddress(192, 168, 11, 99), IPAddress(255, 255, 255, 0), 80);

void setup(){
  M5.begin();
  M5.Axp.ScreenBreath(10);    // 画面の輝度を少し下げる
  M5.Lcd.setRotation(3);      // 左を上にする
  M5.Lcd.setTextSize(2);      // 文字サイズを2にする
  M5.Lcd.fillScreen(BLACK);   // 背景を黒にする
  
  int connect_try_count = 0;
  
  // シリアルポート開放
  Serial.begin(115200);
  delay(10);

  // webサーバ設定処理
  //set_server();
  
  WiFi.begin("SSID", "PASS");

  while (WiFi.status() != WL_CONNECTED && connect_try_count < MAX_TRY_CONNECT_INI) {
    delay(500);
    Serial.print(".");
    connect_try_count++;
  }

  if (WiFi.status() == WL_CONNECTED) {  
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    return;
  } else {
    Serial.println("WiFi connect process time out.");
  }
}

void loop(){

}