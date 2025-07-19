#include "MqttController.h"

void MqttController::setup()
{
    _mqtt.subscribe(MqttTopic::Attendance);
    _mqtt.onMessage([this](String topic, String message)
                    { this->handleMessage(MqttTopic::Attendance, message); });
}

void MqttController::handleMessage(MqttTopic topic, String message)
{
    // TODO: handle message
}
