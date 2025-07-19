#pragma once

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

struct ScreenSize
{
    uint8_t width;
    uint8_t height;
};

class OLEDDisplay
{
public:
    OLEDDisplay(uint8_t width = 128, uint8_t height = 32);
    void begin();
    void showText(const String &text, bool clear = true, int x = 0, int y = 0, int size = 1);
    void clear(unsigned long delayMs = 0);
    void clearLineFrom(uint8_t line, uint8_t verticalSpacing = 0, uint8_t height = 8);
    Adafruit_SSD1306 &getDisplay() { return _display; }
    ScreenSize getScreenSize() { return {_width, _height}; }

private:
    uint8_t _width;
    uint8_t _height;
    static constexpr int OLED_RESET = -1; // No physical reset pin

    Adafruit_SSD1306 _display;
};