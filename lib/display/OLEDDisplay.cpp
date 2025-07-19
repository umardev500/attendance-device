#include "OLEDDisplay.h"

OLEDDisplay::OLEDDisplay(uint8_t width, uint8_t height)
    : _width(width),
      _height(height),
      _display(width, height, &Wire, OLED_RESET)
{
}

void OLEDDisplay::begin()
{
    if (!_display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }

    _display.clearDisplay();
    _display.setTextSize(1);
    _display.setTextColor(WHITE);
    _display.setCursor(0, 0);
    _display.println(F("OLED Ready!"));
    _display.display();
}

void OLEDDisplay::showText(const String &text, bool clear, int x, int y, int size)
{
    if (clear)
    {
        _display.clearDisplay();
    }
    _display.setTextSize(size);
    _display.setTextColor(WHITE);
    _display.setCursor(x, y);
    _display.println(text);
    _display.display();
}

void OLEDDisplay::clear(unsigned long delayMs)
{
    delay(delayMs);
    _display.clearDisplay();
    _display.display();
}

void OLEDDisplay::clearLineFrom(uint8_t line, uint8_t verticalSpacing, uint8_t height)
{
    uint8_t totalHeight = height * line + verticalSpacing * line;
    _display.fillRect(0, totalHeight, _width, _height - totalHeight, BLACK);
    _display.display();
}