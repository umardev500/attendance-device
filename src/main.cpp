#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "Button.h"
#include "OLEDDisplay.h"
#include "mode/ModeManager.h"
#include "scan/ScanRFID.h"
#include "RFIDReader.h"
#include "WiFiManager.h"
#include "MqttClient.h"
#include "connection/WiFiConnection.h"

// Mqtt
const char *mqttServer = "10.195.145.44";

// WiFi creds
const char *ssid = "TECNO SPARK 10 Pro";
const char *password = "12345687";

// PIN
const int RFID_RST_PIN = 14;
const int RFID_SDA_PIN = 16;

// State
bool attendanceMode = false;

Buzzer buzzer(4);
Button button;
OLEDDisplay display(128, 32);
ModeManager mode(display, buzzer);
RFIDReader rfid(RFID_SDA_PIN, RFID_RST_PIN);
ScanRFID scanRFID(rfid, mode, display, buzzer);
WiFiManager wifiManager(ssid, password);
WiFiConnection wifiConnection(wifiManager);
MqttClient mqtt(mqttServer);

void setup()
{
  Serial.begin(115200);
  wifiConnection.connect();
  buzzer.begin();
  display.begin();
  mode.begin(5);
  mqtt.begin();

  // RFID
  scanRFID.begin();

  delay(100);
  mqtt.subscribe("attendance");
}

void loop()
{
  mode.update();
  scanRFID.scan();
  mqtt.loop();
}