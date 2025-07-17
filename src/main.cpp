#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "Button.h"
#include "OLEDDisplay.h"
#include "mode/ModeManager.h"

// State
bool attendanceMode = false;

Buzzer buzzer(4);
Button button;
OLEDDisplay display(128, 32);
ModeManager mode(display, buzzer);

void setup()
{
  Serial.begin(115200);
  buzzer.begin();
  display.begin();
  mode.begin(5);
  delay(100);
}

void loop()
{
  mode.update();
}
