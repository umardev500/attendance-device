#include <Arduino.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "Button.h"

Buzzer buzzer(4);
Button button;

void setup()
{
  Serial.begin(115200);
  buzzer.begin();
  button.begin(5, []()
               { buzzer.beep(100, 1, 100); });
  delay(100);
}

void loop()
{
  button.update();
  // put your main code here, to run repeatedly:
}
