#pragma once

#include <WiFi.h>
#include <PubSubClient.h>

class MqttClient
{
public:
    MqttClient(const char *server, uint16_t port = 1883);
    void begin();
    void loop();
    void publish(const char *topic, const char *payload);
    void subscribe(const char *topic);

private:
    WiFiClient _wifiClient;
    PubSubClient _client;
    const char *_mqttServer;
    uint16_t _mqttPort;

    void reconnect();
    static void callback(char *topic, byte *payload, unsigned int length);
};