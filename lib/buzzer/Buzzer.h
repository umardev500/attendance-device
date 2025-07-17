#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer
{
public:
    Buzzer(uint8_t pin);
    void begin();
    void on();
    void off();
    void beep(unsigned int duration, unsigned int count = 1, unsigned int pause = 100);

private:
    uint8_t _pin;
};

#endif