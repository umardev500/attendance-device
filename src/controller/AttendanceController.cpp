#include "AttendanceController.h"

void AttendanceController::publish(String message)
{
    ModeManager::Mode mode = _modeManager.getMode();

    if (mode == ModeManager::Mode::MASUK)
    {
        // TODO: publish to mqtt
        Serial.print("Masuk: ");
        Serial.println(message);
    }
    else if (mode == ModeManager::Mode::KELUAR)
    {
        // TODO: publish to mqtt
        Serial.print("Keluar: ");
        Serial.println(message);
    }
}

void AttendanceController::subscribe(String message)
{
    // TODO: subscribe to mqtt
}