#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>

class WiFiManager
{
public:
    WiFiManager(const char *ssid, const char *password, unsigned long timeout = 10000);
    WiFiManager &begin();
    WiFiManager &connect();
    WiFiManager &onConnected(std::function<void()> callback);
    WiFiManager &onDisconnected(std::function<void()> callback);
    bool isConnected();
    IPAddress getIP();

private:
    const char *_ssid;
    const char *_password;
    unsigned long _timeout;
    bool _isConnected = false;

    std::function<void()> _onConnectedCallback = nullptr;
    std::function<void()> _onDisconnectedCallback = nullptr;

    void handleWiFiEvent(WiFiEvent_t event);
};

#endif