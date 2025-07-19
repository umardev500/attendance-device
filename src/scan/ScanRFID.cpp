#include "ScanRFID.h"

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

    _attendanceController.publish(uid);
}