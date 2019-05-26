#ifndef _UISTM_H_
#define _UISTM_H_

#include "UISTMBridge.h"

class UISTM
{

public:
	UISTM();
	virtual ~UISTM();
	bool E_BUTTON_DOWN;
	bool E_BUTTON_MODE;
	bool E_BUTTON_SET;
	bool E_BUTTON_UP;
	bool E_CASE_LOCK;
	bool E_CASE_UNLOCK;
	bool E_INITIALIZED;
	bool E_TICK;
	bool E_TIMEOUT;

	UISTM(UISTMBridge* p);
	void Initialize();
	void SendEvent(bool* event);

private:
	UISTMBridge *bridge;

	void BR_CaseLock();
	void BR_CaseUnlock();
	void BR_CDMHourPlus(int val);
	void BR_CDMMinutePlus(int val);
	bool BR_IsCaseClosed();
	bool BR_IsPreviousLocked();
	void BR_TimerCancel();
	void BR_TimerSet(unsigned int timeout);
	void BR_TRACE(const char* s);
	void BR_TRACE_STATE(const char* state, int command);
	void BR_TRACE_TRANS(const char* trans);
	void ClearEvents();
	void Entry_CDM_Hour();
	void Entry_CDM_Minute();
	void Entry_Confirming();
	void Entry_Initializing();
	void Entry_Locked();
	void Entry_Locking();
	void Entry_Setting();
	void Entry_Unlocked();
	void Exit_CDM_Hour();
	void Exit_CDM_Minute();
	void Exit_Confirming();
	void Exit_Initializing();
	void Exit_Locked();
	void Exit_Locking();
	void Exit_Setting();
	void Exit_Unlocked();

	/* Begin - EA generated code for StateMachine */


	enum StateType
	{
		StateMachine_Confirming,
		StateMachine_Setting,
		StateMachine_Setting_CDM_Minute,
		StateMachine_Setting_CDM_Hour,
		StateMachine_Initializing,
		StateMachine_Locked,
		ST_NOSTATE
	};
	enum TransitionType
	{
		StateMachine_Confirming_to_StateMachine_Locked_with_FE5DB92292324f079D12A893A0FF1F2C,
		StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_BC20F02C7B6D4031A4E6670E9E3C8420,
		StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_B6C64D4284C343a09F8A2D7411FD9CAD,
		StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_89A0F3F3D42749729B897917B61679F8,
		StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_83111AAFEA5340ab95E42A99B9F7154E,
		StateMachine_Locked_to_StateMachine_Setting_CDM_Hour_with_972C2F4A79E440e682674AE8561C8D96,
		TT_NOTRANSITION
	};
	enum CommandType
	{
		Do, 
		Entry, 
		Exit 
	};
private:
	StateType currState;
	StateType nextState;
	TransitionType currTransition;
	bool transcend;
	bool bStayInCurrentState; 
	StateType StateMachine_history;
	StateType StateMachine_Setting_history;
	void stateMachine_Confirming(CommandType command);

	void stateMachine_Setting(CommandType command);
	void stateMachine_Setting_CDM_Minute(CommandType command);

	void stateMachine_Setting_CDM_Hour(CommandType command);

	void stateMachine_Initializing(CommandType command);

	void stateMachine_Locked(CommandType command);
	void StatesProc(StateType currState, CommandType command);
	void TransitionsProc(TransitionType transition);
};
#endif
