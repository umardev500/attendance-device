#pragma once

#include "MqttClient.h"
#include "controller/AttendanceController.h"

class MqttController
{
public:
    MqttController(MqttClient &mqtt, AttendanceController &attendanceController)
        : _mqtt(mqtt), _attendanceController(attendanceController) {}

    void setup();

private:
    MqttClient &_mqtt;
    AttendanceController &_attendanceController;

    void handleMessage(MqttTopic topic, String message);
};