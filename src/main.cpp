#include <Arduino.h>
#include "WiFiManager.h"

const char *ssid = "TECNO SPARK 10 Pro";
const char *password = "12345687";

WiFiManager wifiManager(ssid, password);

void setup()
{
  Serial.begin(115200);
  delay(100);

  wifiManager
      .begin()
      .connect();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
