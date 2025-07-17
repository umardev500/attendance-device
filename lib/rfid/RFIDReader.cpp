#include "RFIDReader.h"

RFIDReader::RFIDReader(uint8_t sspin, uint8_t rstpin)
    : _rfid(sspin, rstpin)
{
}

void RFIDReader::begin()
{
    SPI.begin();
    _rfid.PCD_Init();
}

void RFIDReader::update()
{
    if (!_rfid.PICC_IsNewCardPresent() || !_rfid.PICC_ReadCardSerial())
        return;

    String uid = "";
    for (byte i = 0; i < _rfid.uid.size; i++)
    {
        uid += String(_rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    if (_onTagScannedCallback)
        _onTagScannedCallback(uid);

    _rfid.PICC_HaltA();
}

void RFIDReader::onTagScanned(std::function<void(String uid)> callback)
{
    _onTagScannedCallback = callback;
}