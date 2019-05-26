#ifndef CONFISCATOR_H
#define CONFISCATOR_H

#include "application.h"
#include "LiquidCrystal.h"
#include "UISTM.h"

extern Servo myservo;
extern LiquidCrystal lcd;
//extern NtpTime* ntpTime;

extern UISTM stm;
extern Timer DisplayTimer;
extern unsigned long unlockTargetTime;
extern bool isPreviousLocked;

#endif // CONFISCATOR_H