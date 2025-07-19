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
#include "mqtt/MqttController.h"
#include "env.h"
#include "controller/AttendanceController.h"

// Mqtt
const char *mqttServer = envb::MQTT_SERVER;

// WiFi creds
const char *ssid = envb::WIFI_SSID;
const char *password = envb::WIFI_PASSWORD;

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
AttendanceController attendanceController(mode, display);
ScanRFID scanRFID(rfid, mode, display, buzzer, attendanceController);
WiFiManager wifiManager(ssid, password);
WiFiConnection wifiConnection(wifiManager, buzzer, display);
MqttClient mqtt(mqttServer);

MqttController mqttController(mqtt);

void setup()
{
  Serial.begin(115200);
  Serial.println("running");
  Serial.println(mqttServer);
  wifiConnection.connect();
  buzzer.begin();
  mode.begin(5);
  display.begin();
  mqtt.begin();

  // RFID
  scanRFID.begin();

  delay(100);

  // Mqtt
  mqttController.setup();
}

void loop()
{
  mode.update();
  scanRFID.scan();
  mqtt.loop();
}