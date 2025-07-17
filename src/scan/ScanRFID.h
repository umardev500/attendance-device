#pragma once

#include "RFIDReader.h"
#include "OLEDDisplay.h"
#include "Buzzer.h"
#include "mode/ModeManager.h"

class ScanRFID
{
public:
    ScanRFID(RFIDReader &reader, ModeManager &mode, OLEDDisplay &display, Buzzer &buzzer);
    void begin();
    void scan();

private:
    RFIDReader &_reader;
    ModeManager &_mode;
    OLEDDisplay &_display;
    Buzzer &_buzzer;

    void markAttendance(ModeManager::Mode mode, String uid);
};
