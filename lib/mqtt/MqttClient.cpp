#include "MqttClient.h"

MqttClient::MqttClient(const char *server, uint16_t port)
    : _mqttServer(server), _mqttPort(port) {}

void MqttClient::begin()
{
    _client.setServer(_mqttServer, _mqttPort);
    _client.setCallback(callback);
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
}

void MqttClient::reconnect()
{
    while (!_client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        if (_client.connect("ESP32Client"))
        {
            Serial.println("connected");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(_client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void MqttClient::callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}