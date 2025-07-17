#pragma once

#include <Arduino.h>
#include <Bounce2.h>

class Button
{
public:
    Button();
    void begin(uint8_t pin, std::function<void()> onPressCallback, uint16_t debounceMs = 25);
    void update();

private:
    Bounce _debouncer;
    std::function<void()> _onPress;
    uint8_t _pin;
};
