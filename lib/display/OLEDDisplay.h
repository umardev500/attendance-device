#pragma once

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class OLEDDisplay
{
public:
    OLEDDisplay(uint8_t width = 128, uint8_t height = 32);
    void begin();
    void showText(const String &text, bool clear = true, int x = 0, int y = 0, int size = 1);
    void clear(unsigned long delayMs = 0);

private:
    uint8_t _width;
    uint8_t _height;
    static constexpr int OLED_RESET = -1; // No physical reset pin

    Adafruit_SSD1306 _display;
};