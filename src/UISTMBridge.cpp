#include "UISTMBridge.h"
#include "Confiscator.h"

// Enable Retained SRAM
STARTUP(System.enableFeature(FEATURE_RETAINED_MEMORY));
retained unsigned long unlockTargetTime = 0;
retained bool isPreviousLocked = false;

UISTMBridge::UISTMBridge(){

}


UISTMBridge::~UISTMBridge(){

}


void UISTMBridge::CaseLock(){

    // Lock
    Log.trace(__FUNCTION__);
    myservo.write(90);
    ::isPreviousLocked = true;
}


void UISTMBridge::CaseUnlock(){

    // Unlock
    Log.trace(__FUNCTION__);
    myservo.write(0);
    ::isPreviousLocked = false;
}


void UISTMBridge::CDMHourPlus(int val){

    Log.trace(__FUNCTION__);

    cdm.addHour(val);
}


void UISTMBridge::CDMMinutePlus(int val){

    Log.trace(__FUNCTION__);

    cdm.addMinute(val);
}


void UISTMBridge::Entry_Initializing(){

    Log.trace(__FUNCTION__);
    lcd.clear();
}


void UISTMBridge::Exit_Initializing(){

    Log.trace(__FUNCTION__);
    lcd.clear();
}


void UISTMBridge::Entry_Setting(){

    Log.trace(__FUNCTION__);

    // Init countdown time
    cdm.hour   = 0;
    cdm.minute = 0;

    lcd.setCursor(0, 0);
    lcd.print("   Set Timer    ");
}


void UISTMBridge::Exit_Setting(){

	Log.trace(__FUNCTION__);
}


void UISTMBridge::Entry_CDM_Hour(){

    Log.trace(__FUNCTION__);

    static bool blink = true;
    lcd.setCursor(0, 1);
    if (blink) {
        lcd.print(String::format("      h %02dm      ", cdm.minute).c_str());
    } else {
        lcd.print(String::format("    %02dh %02dm      ", cdm.hour, cdm.minute).c_str());
    }
    blink = !blink;
}


void UISTMBridge::Exit_CDM_Hour(){

    Log.trace(__FUNCTION__);
}


void UISTMBridge::Entry_CDM_Minute(){

    Log.trace(__FUNCTION__);

    static bool blink = true;
    lcd.setCursor(0, 1);
    if (blink) {
        lcd.print(String::format("    %02dh   m      ", cdm.hour).c_str());
    } else {
        lcd.print(String::format("    %02dh %02dm      ", cdm.hour, cdm.minute).c_str());
    }
    blink = !blink;
}


void UISTMBridge::Exit_CDM_Minute(){

    Log.trace(__FUNCTION__);
}


void UISTMBridge::Entry_Confirming(){

    Log.trace(__FUNCTION__);

    lcd.setCursor(0, 0);    lcd.print("  Start  => A   ");
    lcd.setCursor(0, 1);    lcd.print("  Cancel => B  ");
}


void UISTMBridge::Exit_Confirming(){

    Log.trace(__FUNCTION__);
    unlockTargetTime = Time.now() + cdm.hour*3600 + cdm.minute*60;
}


void UISTMBridge::Entry_Locking(){

    Log.trace(__FUNCTION__);
}


void UISTMBridge::Exit_Locking(){

    Log.trace(__FUNCTION__);
}


void UISTMBridge::Entry_Locked(){

    Log.trace(__FUNCTION__);
    
    static bool blink = true;
    String s;
    lcd.setCursor(0, 1);
    if (blink) {
        lcd.setCursor(0, 0);    lcd.print(" *** Locked *** ");
    } else {
        lcd.setCursor(0, 0);    lcd.print(" ***        *** ");
    }
    blink = !blink;
    lcd.print(s.c_str());

    unsigned long togo;
    unsigned long now = Time.now();
    if (unlockTargetTime >= now) {
        togo = unlockTargetTime - now;
    }
    lcd.setCursor(0, 1);
    lcd.print(String::format("%4dh %02dm %02ds", togo/3600, (togo%3600)/60, togo%60));
}


void UISTMBridge::Exit_Locked(){

    Log.trace(__FUNCTION__);
}


void UISTMBridge::Initialize(){

    Log.trace(__FUNCTION__);
}


bool UISTMBridge::IsCaseClosed(){

    // TODO: check sensor
    Log.trace(__FUNCTION__);
	return true;
}


bool UISTMBridge::IsPreviousLocked(){

    Log.trace(__FUNCTION__);
	return isPreviousLocked;
}


void UISTMBridge::TimerCancel(){

    Log.trace(__FUNCTION__);
    ::DisplayTimer.stop();
}


void UISTMBridge::TimerSet(unsigned int timeout){

    Log.trace(__FUNCTION__);
    ::DisplayTimer.changePeriod(timeout);
}


const char* UISTMBridge::GetDateTimeString(String& s)
{
    s = String::format("%4i/%02i/%02i %02i:%02i",   Time.year(),
                                                    Time.month(),
                                                    Time.day(),
                                                    Time.hour(),
                                                    Time.minute());
    return s.c_str();
}


void UISTMBridge::TRACE(const char* s){

    Log.trace(s);
}


void UISTMBridge::TRACE_STATE(const char* state, int command){

	const char* c;
	switch(command) {
		case 0:  c = "Do   "; break;
		case 1:  c = "Entry"; break;
		case 2:  c = "Exit "; break;
		default: c = "?????"; break;
	}
	Log.trace("State[%s]: %s", c, state);
}


void UISTMBridge::TRACE_TRANS(const char* trans){

    Log.trace("  Transition: %s", trans);
}





UISTMBridge::dateTime::dateTime(){

	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
}

UISTMBridge::dateTime::~dateTime(){

}


void UISTMBridge::dateTime::addDay(int val){

	day += val;
	if (day > 31) {
		day = 0;
	} else if (day < 0) {
		day = 31;
	}
}


void UISTMBridge::dateTime::addHour(int val){

	hour += val;
	if (hour > 24) {
		hour = 0;
	} else if (hour < 0) {
		hour = 24;
	}
}


void UISTMBridge::dateTime::addMinute(int val){

	minute += val;
	if (minute > 59) {
		minute = 0;
	} else if (minute < 0) {
		minute = 59;
	}
	
}


void UISTMBridge::dateTime::addMonth(int val){

	month += val;
	if (month > 12) {
		month = 1;
	} else if (month < 1) {
		month = 12;
	}
}


void UISTMBridge::dateTime::addYear(int val){

	year += val;
	if (year > 2030) {
		year = 2019;
	} else if (year < 2019) {
		year = 2030;
	}
}


unsigned long UISTMBridge::dateTime::GetSecondsFromUnixEpoch(){

	// elapsed time from UNIX epoch time calculated by Fairfield formula
	const unsigned int unix_epoch = 719161;
	return (365*year + year/4 - year/100 + year/400 + 306*(month+1)/10 - 428 + day - unix_epoch) * 24 * 60 * 60;
}