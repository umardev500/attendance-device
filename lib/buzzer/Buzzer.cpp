#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin)
{
    _pin = pin;
}

void Buzzer::begin()
{
    pinMode(_pin, OUTPUT);
}

void Buzzer::on()
{
    digitalWrite(_pin, HIGH);
}

void Buzzer::off()
{
    digitalWrite(_pin, LOW);
}

void Buzzer::beep(unsigned int duration, unsigned int count, unsigned int pause)
{
    for (int i = 0; i < count; i++)
    {
        on();
        delay(duration);
        off();
        delay(pause);
    }
}