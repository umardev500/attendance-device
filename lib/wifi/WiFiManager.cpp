#include "WiFiManager.h"
#include <WiFi.h>

WiFiManager::WiFiManager(const char *ssid, const char *password, unsigned long timeout)
{
    _ssid = ssid;
    _password = password;
    _timeout = timeout;
}

WiFiManager &WiFiManager::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.onEvent(std::bind(&WiFiManager::handleWiFiEvent, this, std::placeholders::_1));
    return *this;
}

void WiFiManager::handleWiFiEvent(WiFiEvent_t event)
{
    switch (event)
    {
    case SYSTEM_EVENT_STA_DISCONNECTED:
        if (_isConnected)
        {
            _isConnected = false;
            Serial.println("[WiFiManager] disconnected!");
        }
        break;

    case SYSTEM_EVENT_STA_CONNECTED:
        _isConnected = true;
        Serial.println("[WiFiManager] connected successfully!");
        break;

    default:
        break;
    }
}

WiFiManager &WiFiManager::connect()
{
    WiFi.begin(_ssid, _password);
    Serial.printf("Connecting to %s...", _ssid);

    return *this;
}

WiFiManager &WiFiManager::onConnected(std::function<void()> callback)
{
    _onConnectedCallback = callback;
    return *this;
}

WiFiManager &WiFiManager::onDisconnected(std::function<void()> callback)
{
    _onDisconnectedCallback = callback;
    return *this;
}

bool WiFiManager::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

IPAddress WiFiManager::getIP()
{
    return WiFi.localIP();
}
