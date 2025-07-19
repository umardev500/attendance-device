#include "ScanRFID.h"

void ScanRFID::begin()
{
    _reader.begin();
    _reader.onTagScanned([this](String uid)
                         {
                             _buzzer.beep(100);
                             markAttendance(_mode.getMode(), uid);
                         });
}

void ScanRFID::scan()
{
    _reader.update();
}

void ScanRFID::markAttendance(ModeManager::Mode mode, String uid)
{
    _attendanceController.mark(uid);
}