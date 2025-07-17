#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "Button.h"
#include "OLEDDisplay.h"

// State
bool attendanceMode = false;

Buzzer buzzer(4);
Button button;
OLEDDisplay display(128, 32);

void setup()
{
  Serial.begin(115200);
  buzzer.begin();
  button.begin(5, []()
               {
                 buzzer.beep(100, 1, 100);
                 attendanceMode = !attendanceMode;

                 if (attendanceMode)
                 {
                  display.showText("Mode: Masuk");
                 }
                 else
                 {
                  display.showText("Mode: Keluar");
                 } });
  display.begin();
  delay(100);
}

void loop()
{
  button.update();
  // put your main code here, to run repeatedly:
}
