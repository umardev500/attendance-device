#pragma once

#include "mode/ModeManager.h"
#include "MqttClient.h"
#include "OLEDDisplay.h"

class AttendanceController
{
public:
    AttendanceController(ModeManager &modeManager, OLEDDisplay &display) : _modeManager(modeManager), _display(display) {};

    // Pusblish data to mqtt server
    void mark(String message);

private:
    ModeManager &_modeManager;
    OLEDDisplay &_display;
    uint8_t _textH = 8;
    uint8_t _verticalSpacing = 4;
};