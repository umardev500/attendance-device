#include "WiFiConnection.h"

WiFiConnection::WiFiConnection(WiFiManager &wifiManager, Buzzer &buzzer, OLEDDisplay &display)
    : _wifiManager(wifiManager), _buzzer(buzzer), _display(display) {}

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
    _display.showText("WiFi connected!", true);
    _buzzer.beep(100, 2);
}

void WiFiConnection::onDisconnected()
{
    Serial.println("Disconnected from WiFi");
    _display.showText("WiFi disconnected!", true);
    _buzzer.beep(1000);
}