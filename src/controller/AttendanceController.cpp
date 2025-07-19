#include "AttendanceController.h"

void AttendanceController::mark(String uid)
{
    ModeManager::Mode mode = _modeManager.getMode();

    if (mode == ModeManager::Mode::MASUK)
    {
        _display.showText("Mode: Masuk", true);
        _display.showText(uid, false, 0, _textH + _verticalSpacing);
        _display.showText("Success", false, 0, _textH * 2 + _verticalSpacing * 2);

        // Clear the bottom half of the screen
        delay(1000);
        ScreenSize size = _display.getScreenSize();
        uint8_t fromY = _textH * 1 + _verticalSpacing * 1;
        _display.getDisplay().fillRect(0, fromY, size.width, size.height - fromY, SSD1306_BLACK);
        _display.getDisplay().display();
    }
    else if (mode == ModeManager::Mode::KELUAR)
    {
        _display.showText("Mode: Keluar", true);
        _display.showText(uid, false, 0, _textH + _verticalSpacing);
        _display.showText("Success", false, 0, _textH * 2 + _verticalSpacing * 2);

        // Clear the bottom half of the screen
        delay(1000);
        ScreenSize size = _display.getScreenSize();
        uint8_t fromY = _textH * 1 + _verticalSpacing * 1;
        _display.getDisplay().fillRect(0, fromY, size.width, size.height - fromY, SSD1306_BLACK);
        _display.getDisplay().display();
    }
}
