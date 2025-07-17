#include "MqttClient.h"

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

void MqttClient::publish(const char *topic, const char *payload)
{
    _client.publish(topic, payload);
}

void MqttClient::subscribe(const char *topic)
{
    _client.subscribe(topic);
    _subscribedTopics.push_back(String(topic));
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