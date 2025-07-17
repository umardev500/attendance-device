#include "MqttController.h"

MqttController::MqttController(MqttClient &client)
    : _mqtt(client) {}

void MqttController::setup()
{
    _mqtt.subscribe(MqttTopic::Attendance);
    _mqtt.onMessage([this](String topic, String message)
                    { this->handleMessage(MqttTopic::Attendance, message); });
}

void MqttController::handleMessage(MqttTopic topic, String message)
{
    if (topic == MqttTopic::Attendance)
    {
        Serial.println(message);
        // TODO: handle message
    }
    else
    {
        // TODO: handle message
    }
}
