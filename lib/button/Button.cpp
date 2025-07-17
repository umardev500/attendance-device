#include "Button.h"
#include <Bounce2.h>

Button::Button()
{
}

void Button::begin(uint8_t pin, std::function<void()> onPressCallback, uint16_t debounceMs)
{
    _pin = pin;
    _onPress = onPressCallback;

    pinMode(_pin, INPUT_PULLUP);
    _debouncer.attach(_pin);
    _debouncer.interval(debounceMs);
}

void Button::update()
{
    _debouncer.update();
    if (_debouncer.fell())
    {
        _onPress();
    }
}