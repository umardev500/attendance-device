#include "ModeManager.h"

ModeManager::ModeManager(OLEDDisplay &display, Buzzer &buzzer)
    : _dispplay(display),
      _buzzer(buzzer)
{
}

void ModeManager::begin(u_int8_t buttonPin)
{
    _button.begin(buttonPin, [this]()
                  {
        _buzzer.beep(100);
        this->toggle(); });
}

void ModeManager::toggle()
{
    _mode = _mode == Mode::MASUK ? Mode::KELUAR : Mode::MASUK;
    updateDisplay();

    if (_callback)
        _callback(_mode);
}

ModeManager::Mode ModeManager::getMode() const
{
    return _mode;
}

void ModeManager::updateDisplay()
{
    const char *displayText = (_mode == Mode::MASUK) ? "Mode: Masuk" : "Mode: Keluar";
    _dispplay.showText(displayText);
}

void ModeManager::update()
{
    _button.update();
}
