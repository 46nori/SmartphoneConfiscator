#include "EventManager.h"
#include "Confiscator.h"
#include "UISTM.h"

//
// Generic Timer 
//
static void GenericTimerHandler();
Timer GenericTimer(5000, GenericTimerHandler);
static volatile bool GenericTimerExpired = false;
static void GenericTimerHandler()
{
    GenericTimerExpired = true;
}

//
// Tick Timer (every 500ms)
//
static void TickTimerHandler();
static Timer TickTimer(500, TickTimerHandler);
static volatile bool TickTimerExpired = false;
static void TickTimerHandler()
{
    TickTimerExpired = true;
}

//
// Key sense
//
static const int NumOfKeys = 4;
static struct key {
    int port;
    int polarity;
    unsigned char val;
    unsigned int count;
    bool state;
} key[NumOfKeys] = {
    {A0,  LOW, 0, 0, false},   // UP
    {A1,  LOW, 0, 0, false},   // DOWN
    {A2,  LOW, 0, 0, false},   // MODE
    {A3, HIGH, 0, 0, false}    // SET
};
static void KeysenseTimerHandler() {
    for (int i = 0; i < NumOfKeys; i++) {
        if (digitalRead(key[i].port) == key[i].polarity) {
            key[i].val <<= 1;
            if (digitalRead(key[i].port) == key[i].polarity) {
                key[i].val |= 1;
            }
        } else {
            key[i].val <<= 1;
        }
        if (key[i].val == 0x7f) {
            // check if button is pushed for 7 periods.
            key[i].state = true;
            // remember rising edge for 50 period. 
            key[i].count = 50;
        } else if (key[i].val == 0) {
            // check if button is released for 8 periods.
            key[i].state = false;
        }
        if (key[i].count > 0) {
            --key[i].count;
        }
    }
}
static Timer KeySenseTimer(10, KeysenseTimerHandler);
bool IsPushed(int name) {
    if (key[name].count > 0) {
        key[name].count = 0;
        return true;
    } else {
        return false;
    }
}


//
//  Event Manager
//
EventManager::EventManager()
{
    isForceUnlock = false;
}

EventManager::~EventManager()
{
}

EventManager::EventManager(UISTM* p)
{
    EventManager();
    stm = p;
    stm->Initialize();
}

void EventManager::Initialize()
{
    stm->SendEvent(&stm->UISTM::E_INITIALIZED);
    TickTimer.start();
    KeySenseTimer.start();
}

void EventManager::ForceUnlock()
{
    isForceUnlock = true;
}

void EventManager::Run()
{
    if (IsPushed(0)) {
        Log.trace("*** UP ***");
        stm->SendEvent(&stm->UISTM::E_BUTTON_UP);
    } else 
    if (IsPushed(1)) {
        Log.trace("*** DOWN ***");
        stm->SendEvent(&stm->UISTM::E_BUTTON_DOWN);
    } else 
    if (IsPushed(2)) {
        Log.trace("*** MODE ***");
        stm->SendEvent(&stm->UISTM::E_BUTTON_MODE);
    } else 
    if (IsPushed(3)) {
        Log.trace("*** SET ***");
        stm->SendEvent(&stm->UISTM::E_BUTTON_SET);
    } else
    if (isPreviousLocked && (Time.now() >= unlockTargetTime)) {
        Log.trace("*** CASE_UNLOCK ***");
        stm->SendEvent(&stm->UISTM::E_CASE_UNLOCK);
    } else 
    if (isPreviousLocked && isForceUnlock) {
        Log.trace("*** CASE_UNLOCK ***");
        stm->SendEvent(&stm->UISTM::E_CASE_UNLOCK);
        isForceUnlock = false;
    } else 
    if (TickTimerExpired == true) {
        TickTimerExpired = false;
        Log.trace("### TICK ###");
        stm->SendEvent(&stm->UISTM::E_TICK);
    } else 
    if (GenericTimerExpired == true) {
        GenericTimerExpired = false;
        Log.trace("### TIMEOUT ###");
        stm->SendEvent(&stm->UISTM::E_TIMEOUT);
    }
}