#pragma once

#include "MqttClient.h"

class MqttController
{
public:
    MqttController(MqttClient &mqtt)
        : _mqtt(mqtt) {}

    void setup();

private:
    MqttClient &_mqtt;

    void handleMessage(MqttTopic topic, String message);
};