#pragma once

#include <MFRC522.h>

class RFIDReader
{
public:
    RFIDReader(uint8_t sspin, uint8_t rstpin);
    void begin();
    void update();
    void onTagScanned(std::function<void(String uid)> callback);

private:
    MFRC522 _rfid;
    std::function<void(String uid)> _onTagScannedCallback;
};