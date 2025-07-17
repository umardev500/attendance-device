#include "OLEDDisplay.h"
#include "Button.h"
#include "Buzzer.h"

#pragma once

class ModeManager
{
public:
    enum Mode
    {
        MASUK,
        KELUAR
    };

    ModeManager(OLEDDisplay &display, Buzzer &buzzer);
    void begin(u_int8_t buttonPin);
    void update(); // Call this in loop()

    Mode getMode() const;

private:
    Mode _mode = MASUK;
    OLEDDisplay &_dispplay;
    std::function<void(Mode)> _callback;
    Button _button;
    Buzzer _buzzer;

    void updateDisplay();
    void toggle();
};