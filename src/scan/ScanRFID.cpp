#include "ScanRFID.h"

ScanRFID::ScanRFID(RFIDReader &reader, ModeManager &mode, OLEDDisplay &display, Buzzer &buzzer)
    : _reader(reader), _mode(mode), _display(display), _buzzer(buzzer) {}

void ScanRFID::begin()
{
    _reader.begin();
    _reader.onTagScanned([this](String uid)
                         { markAttendance(_mode.getMode(), uid); });
}

void ScanRFID::scan()
{
    _reader.update();
}

void ScanRFID::markAttendance(ModeManager::Mode mode, String uid)
{
    // Display a message
    _display.showText("UID: " + uid);

    // Buzzer
    _buzzer.beep(100);

    if (mode == ModeManager::Mode::MASUK)
    {
        // TODO: publish to mqtt
    }
    else if (mode == ModeManager::Mode::KELUAR)
    {
        // TODO: publish to mqtt
    }
}