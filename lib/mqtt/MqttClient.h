#pragma once

#include <WiFi.h>
#include <PubSubClient.h>
#include <vector>

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
    bool _isConnected = false;

    std::vector<String> _subscribedTopics; // Store subscribed topics

    void reconnect();
    static void callback(char *topic, byte *payload, unsigned int length);
};