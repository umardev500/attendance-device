#pragma once

#include "RFIDReader.h"
#include "OLEDDisplay.h"
#include "Buzzer.h"
#include "mode/ModeManager.h"
#include "controller/AttendanceController.h"

class ScanRFID
{
public:
    ScanRFID(RFIDReader &reader, ModeManager &mode, OLEDDisplay &display, Buzzer &buzzer, AttendanceController &attendanceController)
        : _reader(reader), _mode(mode), _display(display), _buzzer(buzzer), _attendanceController(attendanceController) {};
    void begin();
    void scan();

private:
    RFIDReader &_reader;
    ModeManager &_mode;
    OLEDDisplay &_display;
    Buzzer &_buzzer;
    AttendanceController &_attendanceController;

    void markAttendance(ModeManager::Mode mode, String uid);
};
