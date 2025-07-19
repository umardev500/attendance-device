#pragma once

#include "mode/ModeManager.h"
#include "MqttClient.h"

class AttendanceController
{
public:
    AttendanceController(ModeManager &modeManager) : _modeManager(modeManager) {};

    // Pusblish data to mqtt server
    void publish(String message);
    void subscribe(
        String message,
        std::function<void(MqttTopic topic, String message)> publish = nullptr);

private:
    ModeManager &_modeManager;
};