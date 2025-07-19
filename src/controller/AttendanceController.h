#pragma once

#include "mode/ModeManager.h"

class AttendanceController
{
public:
    AttendanceController(ModeManager &modeManager) : _modeManager(modeManager) {};

    // Pusblish data to mqtt server
    void publish(String message);
    void subscribe(String message);

private:
    ModeManager &_modeManager;
};