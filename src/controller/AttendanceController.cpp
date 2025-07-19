#include "AttendanceController.h"
#include "env.h"
#include <ArduinoJson.h>
#include <OLEDDisplay.h>

void AttendanceController::mark(String uid)
{
    ModeManager::Mode mode = _modeManager.getMode();

    if (mode == ModeManager::Mode::MASUK)
        checkIn(uid);
    else if (mode == ModeManager::Mode::KELUAR)
        checkOut(uid);
}

void AttendanceController::checkIn(String uid)
{
    const int line2 = _textH + _verticalSpacing;
    const int line3 = _textH * 2 + _verticalSpacing * 2;

    _display.showText("Mode: Masuk", true);
    _display.showText(uid, false, 0, line2);
    _display.showText("Processing...", false, 0, line3);

    String url = String(envb::API_URL) + "/attendances/check-in";

    _http.begin(url);
    _http.addHeader("Accept", "application/json");
    _http.addHeader("Content-Type", "application/json");

    Payload data;
    data.card_uid = uid;
    data.device_id = envb::DEVICE_ID;

    JsonDocument doc;
    doc["card_uid"] = data.card_uid;
    doc["device_id"] = data.device_id;

    String jsonData;
    serializeJson(doc, jsonData);

    int httpCode = _http.POST(jsonData);

    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    _display.clearLineFrom(2, _verticalSpacing);
    if (httpCode > 0)
    {
        const uint8_t statusLine = _textH * 2 + _verticalSpacing * 2;

        switch (httpCode)
        {
        case 200:
            _display.showText("Success!", false, 0, statusLine);
            break;

        case 409:
        {
            _display.showText("Already Checked In", false, 0, statusLine);
            break;
        }

        case 404:
        {
            _display.showText("Not Found", false, 0, statusLine);
            break;
        }

        default:
            _display.showText("Check in failed", false, 0, statusLine);
            break;
        }
    }
    else
    {
        _display.showText("Failed", false, 0, line3);
    }
}

void AttendanceController::checkOut(String uid)
{
    const int line2 = _textH + _verticalSpacing;
    const int line3 = _textH * 2 + _verticalSpacing * 2;

    _display.showText("Mode: Keluar", true);
    _display.showText(uid, false, 0, line2);
    _display.showText("Processing...", false, 0, line3);

    String url = String(envb::API_URL) + "/attendances/check-out";

    _http.begin(url);
    _http.addHeader("Accept", "application/json");
    _http.addHeader("Content-Type", "application/json");

    Payload data;
    data.card_uid = uid;
    data.device_id = envb::DEVICE_ID;

    JsonDocument doc;
    doc["card_uid"] = data.card_uid;
    doc["device_id"] = data.device_id;

    String jsonData;
    serializeJson(doc, jsonData);

    int httpCode = _http.PUT(jsonData);

    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    _display.clearLineFrom(2, _verticalSpacing);
    if (httpCode > 0)
    {
        const uint8_t statusLine = _textH * 2 + _verticalSpacing * 2;

        switch (httpCode)
        {
        case 200:
            _display.showText("Success!", false, 0, statusLine);
            break;

        case 409:
        {
            _display.showText("Already Checked Out", false, 0, statusLine);
            break;
        }

        case 404:
        {
            _display.showText("Not Found", false, 0, statusLine);
            break;
        }

        default:
            Serial.println(_http.getString());
            _display.showText("Check out failed!", false, 0, statusLine);
            break;
        }
    }
    else
    {
        _display.showText("Failed", false, 0, line3);
    }

    _http.end();
}
