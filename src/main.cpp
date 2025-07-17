#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"

const char *ssid = "TECNO SPARK 10 Pro";
const char *password = "12345687";

Buzzer buzzer(4);
WiFiManager wifiManager(ssid, password);

void setup()
{
  Serial.begin(115200);
  buzzer.begin();
  delay(100);

  wifiManager
      .onConnected([]()
                   { buzzer.beep(100, 2); })
      .onDisconnected([]()
                      { buzzer.beep(3000); })
      .connect();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
