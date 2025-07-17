#pragma once

#include <WiFi.h>
#include "WiFiManager.h"

class WiFiConnection
{
public:
    WiFiConnection(WiFiManager &wifiManager);

    void connect();

private:
    WiFiManager &_wifiManager;

    void onConnected();
    void onDisconnected();
};