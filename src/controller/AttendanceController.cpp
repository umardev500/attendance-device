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

void AttendanceController::subscribe(String message, std::function<void(MqttTopic topic, String message)> publish)
{
    // TODO: subscribe to mqtt
    publish(MqttTopic::Attendance, "from response");
}