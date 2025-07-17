#pragma once

#include <WiFi.h>
#include <PubSubClient.h>
#include <vector>

enum class MqttTopic
{
    Attendance
};

// Convert enum to topic string
const char *toTopicString(MqttTopic topic);

class MqttClient
{
public:
    MqttClient(const char *server, uint16_t port = 1883);
    void begin();
    void loop();
    void publish(MqttTopic topic, const char *payload);
    void subscribe(MqttTopic topic);
    void onMessage(std::function<void(String topic, String message)> callback);

private:
    WiFiClient _wifiClient;
    PubSubClient _client;
    const char *_mqttServer;
    uint16_t _mqttPort;
    bool _isConnected = false;

    std::vector<String> _subscribedTopics; // Store subscribed topics

    // On message callback
    std::function<void(String topic, String message)> _onMessageCallback;

    void reconnect();
    void callback(char *topic, byte *payload, unsigned int length);
};