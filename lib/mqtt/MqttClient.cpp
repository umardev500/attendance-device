#include "MqttClient.h"

const char *toTopicString(MqttTopic topic)
{
    switch (topic)
    {
    case MqttTopic::Attendance:
        return "attendance";
    default:
        return "";
    }
}

MqttClient::MqttClient(const char *server, uint16_t port)
    : _mqttServer(server), _mqttPort(port) {}

void MqttClient::begin()
{
    _client.setClient(_wifiClient);
    _client.setServer(_mqttServer, _mqttPort);
    _client.setCallback([this](char *topic, byte *payload, unsigned int length)
                        { this->callback(topic, payload, length); });
}

void MqttClient::loop()
{
    if (!_client.connected())
    {
        reconnect();
    }
    _client.loop();
}

void MqttClient::publish(MqttTopic topic, const char *payload)
{
    _client.publish(toTopicString(topic), payload);
}

void MqttClient::subscribe(MqttTopic topic)
{
    _client.subscribe(toTopicString(topic));
    _subscribedTopics.push_back(toTopicString(topic));
}

void MqttClient::reconnect()
{
    while (!_client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        if (_client.connect("ESP32Client"))
        {
            Serial.println("connected");

            for (String topic : _subscribedTopics)
            {
                Serial.print("Subscribing to topic: ");
                Serial.println(topic);
                _client.subscribe(topic.c_str());
            }

            _isConnected = true;
        }
        else
        {
            _isConnected = false;
            Serial.print("failed, rc=");
            Serial.print(_client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void MqttClient::callback(char *topic, byte *payload, unsigned int length)
{
    String message;
    for (int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }

    if (_onMessageCallback)
    {
        _onMessageCallback(String(topic), message);
    }
}

void MqttClient::onMessage(std::function<void(String topic, String message)> callback)
{
    _onMessageCallback = callback;
}