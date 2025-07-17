#include "WiFiConnection.h"

WiFiConnection::WiFiConnection(WiFiManager &wifiManager)
    : _wifiManager(wifiManager) {}

void WiFiConnection::connect()
{
    _wifiManager
        .onConnected([this]()
                     { this->onConnected(); })
        .onDisconnected([this]()
                        { this->onDisconnected(); })
        .connect();
}

void WiFiConnection::onConnected()
{
    Serial.println("Connected to WiFi");
}

void WiFiConnection::onDisconnected()
{
    Serial.println("Disconnected from WiFi");
}