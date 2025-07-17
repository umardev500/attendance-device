#pragma once

#include <WiFi.h>
#include "WiFiManager.h"
#include "Buzzer.h"
#include "OLEDDisplay.h"

class WiFiConnection
{
public:
    WiFiConnection(WiFiManager &wifiManager, Buzzer &buzzer, OLEDDisplay &display);

    void connect();

private:
    WiFiManager &_wifiManager;
    Buzzer &_buzzer;
    OLEDDisplay &_display;

    void onConnected();
    void onDisconnected();
};