#include "Confiscator.h""
#include "UISTM.h"
#include "UISTMBridge.h"
#include "EventManager.h"

//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
SerialLogHandler logHandler(LOG_LEVEL_TRACE);
#endif

// pinout on LCD [RS, EN, D4, D5, D6, D7];
// Spark Photon  [D0, D1, D2, D3, D4, D5];
LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

// Servo Motor object
Servo myservo;

// UI State Machine
UISTMBridge bridge;
UISTM stm(&bridge);
EventManager evtman(&stm);
int Confiscator(String command);


void setup()
{
    // Setup GPIO
    pinMode(A0, INPUT);     // set A0 as an input for UP   button
    pinMode(A1, INPUT);     // set A1 as an input for DOWN button
    pinMode(A2, INPUT);     // set A2 as an input for MODE button
    pinMode(A3, INPUT);     // set A3 as an input for SET  button
    pinMode(A4, INPUT);     // set A4 as an input to sense photo reflector
    pinMode(D6, OUTPUT);    // set D6 as an output to enable LED of photo reflector
    pinMode(D7, OUTPUT);    // set D7 as an output to flash the onboard LED
    
    // Setup Servo Motor
    myservo.attach(WKP);    // attach the servo on the WKP pin to the servo object

#ifdef ENABLE_DEBUG
    // for Debug
    Serial.begin(9600);
    myservo.write(0);       // reset position
    isPreviousLocked = false; // remove this after debug
    unlockTargetTime = 0;
#endif

    // Setup LCD
    lcd.begin(16,2);        // set up the LCD's number of columns and rows. 

    // Setup NTP
    Time.zone(+9);          // Timezone : Japan

    // Initialize event manager
    evtman.Initialize();
    
    // Setup Particle function
    Particle.function("Confiscator", Confiscator);
}

// Emergency Unlock via Particle service
int Confiscator(String command)
{
    if (command == "Unlock") {
        evtman.ForceUnlock();
        return 1;
    }  else {
        return -1;
    }
}

void loop()
{
    evtman.Run();
}
