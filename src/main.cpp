#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "Button.h"
#include "OLEDDisplay.h"
#include "mode/ModeManager.h"
#include "scan/ScanRFID.h"
#include "RFIDReader.h"

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

void setup()
{
  Serial.begin(115200);
  buzzer.begin();
  display.begin();
  mode.begin(5);

  // RFID
  scanRFID.begin();

  delay(100);
}

void loop()
{
  mode.update();
  scanRFID.scan();
}
