#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "你的AP ID";
char _lwifi_pass[] = "你的AP PW";
String upload_led; 
int buttonPinRoom = 2;
int buttonPinWC = 3;
int buttonPinLiving = 4;
int buttonPinBalcony = 5;
boolean i;

MCSDisplayOnOff buttonRoom("buttonRoom");
MCSDisplayOnOff buttonWC("buttonWC");
MCSDisplayOnOff buttonLiving("buttonLiving");
MCSDisplayOnOff buttonBalcony("buttonBalcony");
MCSDevice mcs("MCS的DeviceID", "MCS的Device key");

void setup()
{
  Serial.begin(9600);

  mcs.addChannel(buttonRoom);
  mcs.addChannel(buttonWC);
  mcs.addChannel(buttonLiving);
  mcs.addChannel(buttonBalcony);
  Serial.println("Wi-Fi 開始連線");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("Wi-Fi 連線成功");
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("MCS 連線成功");
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPinRoom, INPUT);
  pinMode(buttonPinWC, INPUT);
  pinMode(buttonPinLiving, INPUT);
  pinMode(buttonPinBalcony, INPUT);
}

void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
  }
  mcs.process(100);
  
  if(digitalRead(buttonPinRoom)==1) {  //開關啟動
    i = 1;
    buttonRoom.set(i);
    Serial.println("1");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {  //開關未啟動
    i = 0;
    buttonRoom.set(i);
    Serial.println("0");
    digitalWrite(LED_BUILTIN, LOW);
    }

   if(digitalRead(buttonPinWC)==1) {  //開關啟動
    i = 1;
    buttonWC.set(i);
    Serial.println("1");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {  //開關未啟動
    i = 0;
    buttonWC.set(i);
    Serial.println("0");
    digitalWrite(LED_BUILTIN, LOW);
    }
       
  if(digitalRead(buttonPinLiving)==1) {  //開關啟動
    i = 1;
    buttonLiving.set(i);
    Serial.println("1");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {  //開關未啟動
    i = 0;
    buttonLiving.set(i);
    Serial.println("0");
    digitalWrite(LED_BUILTIN, LOW);
    }

if(digitalRead(buttonPinBalcony)==1) {  //開關啟動
    i = 1;
    buttonBalcony.set(i);
    Serial.println("1");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {  //開關未啟動
    i = 0;
    buttonBalcony.set(i);
    Serial.println("0");
    digitalWrite(LED_BUILTIN, LOW);
    }

  delay(100);
}
