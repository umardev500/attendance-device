#include "WiFiManager.h"
#include <WiFi.h>

WiFiManager::WiFiManager(const char *ssid, const char *password, unsigned long timeout)
{
    _ssid = ssid;
    _password = password;
    _timeout = timeout;
}

WiFiManager &WiFiManager::connect()
{
    WiFi.begin(_ssid, _password);
    Serial.printf("Connecting to %s", _ssid);

    unsigned long startAttempTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - startAttempTime < _timeout)
    {
        Serial.print(".");
        delay(100);
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi connected!");
        if (_onConnectedCallback)
        {
            _onConnectedCallback();
        }
    }
    else
    {
        Serial.println("WiFi connection failed!");
    }

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
