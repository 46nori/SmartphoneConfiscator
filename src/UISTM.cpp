#include "UISTM.h"

UISTM::UISTM(){

}


UISTM::~UISTM(){

}


UISTM::UISTM(UISTMBridge* p){

	bridge = p;
	bStayInCurrentState = false;
	ClearEvents();
}


void UISTM::BR_CaseLock(){

	bridge->CaseLock();
}


void UISTM::BR_CaseUnlock(){

	bridge->CaseUnlock();
}


void UISTM::BR_CDMHourPlus(int val){

	bridge->CDMHourPlus(val);
}


void UISTM::BR_CDMMinutePlus(int val){

	bridge->CDMMinutePlus(val);
}


bool UISTM::BR_IsCaseClosed(){

	return bridge->IsCaseClosed();
}


bool UISTM::BR_IsPreviousLocked(){

	return bridge->IsPreviousLocked();
}


void UISTM::BR_TimerCancel(){

	bridge->TimerCancel();
}


void UISTM::BR_TimerSet(unsigned int timeout){

	bridge->TimerSet(timeout);
}


void UISTM::BR_TRACE(const char* s){

	bridge->TRACE(s);
}


void UISTM::BR_TRACE_STATE(const char* state, int command){

	bridge->TRACE_STATE(state, command);
}


void UISTM::BR_TRACE_TRANS(const char* trans){

	bridge->TRACE_TRANS(trans);
}


void UISTM::ClearEvents(){

	E_BUTTON_DOWN = false;
	E_BUTTON_MODE = false;
	E_BUTTON_SET = false;
	E_BUTTON_UP = false;
	E_CASE_LOCK = false;
	E_CASE_UNLOCK = false;
	E_INITIALIZED = false;
	E_TICK = false;
	E_TIMEOUT = false;
}


void UISTM::Entry_CDM_Hour(){

	bridge->Entry_CDM_Hour();
}


void UISTM::Entry_CDM_Minute(){

	bridge->Entry_CDM_Minute();
}


void UISTM::Entry_Confirming(){

	bridge->Entry_Confirming();
}


void UISTM::Entry_Initializing(){

	bridge->Entry_Initializing();
}


void UISTM::Entry_Locked(){

	bridge->Entry_Locked();
}


void UISTM::Entry_Locking(){

	bridge->Entry_Locking();
}


void UISTM::Entry_Setting(){

	bridge->Entry_Setting();
}


void UISTM::Entry_Unlocked(){

	bridge->Entry_Unlocked();
}


void UISTM::Exit_CDM_Hour(){

	bridge->Exit_CDM_Hour();
}


void UISTM::Exit_CDM_Minute(){

	bridge->Exit_CDM_Minute();
}


void UISTM::Exit_Confirming(){

	bridge->Exit_Confirming();
}


void UISTM::Exit_Initializing(){

	bridge->Exit_Initializing();
}


void UISTM::Exit_Locked(){

	bridge->Exit_Locked();
}


void UISTM::Exit_Locking(){

	bridge->Exit_Locking();
}


void UISTM::Exit_Setting(){

	bridge->Exit_Setting();
}


void UISTM::Exit_Unlocked(){

	bridge->Exit_Unlocked();
}


void UISTM::Initialize(){

	ClearEvents();
	currState = StateMachine_Initializing;
	nextState = currState;
	StatesProc(currState, Entry);
}


void UISTM::SendEvent(bool* event){

	if (event != (void*)0) {
	    *event = true;
	}
	
	do {
	    currTransition = TT_NOTRANSITION;
	    StatesProc(currState, Do);
	//    if (currState != nextState) {
	        StatesProc(currState, Exit);
	        if (currTransition != TT_NOTRANSITION ) {
	            TransitionsProc(currTransition);
	        }
	        if (nextState == ST_NOSTATE) {
	            break;
	        }
	        StatesProc(nextState, Entry);
	        currState = nextState ;
	//    }
	} while (0);
	
	ClearEvents();
}


/* Begin - EA generated code for StateMachine */



void UISTM::stateMachine_Confirming(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_BUTTON_MODE == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				transcend = true;
				StateMachine_history = currState;
			}
			else if((E_BUTTON_SET == true) && (BR_IsCaseClosed() == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Locked;
				currTransition = StateMachine_Confirming_to_StateMachine_Locked_with_FE5DB92292324f079D12A893A0FF1F2C;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			//Entry Behaviors..
			Entry_Confirming();
			break;
		}
		case Exit:
		{
			//Exit Behaviors..
			Exit_Confirming();
			break;
		}
		default:
		{
			break;
		}
	}
}

void UISTM::stateMachine_Setting(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_BUTTON_SET == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Confirming;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			//Entry Behaviors..
			Entry_Setting();
			break;
		}
		case Exit:
		{
			//Exit Behaviors..
			Exit_Setting();
			break;
		}
		default:
		{
			break;
		}
	}
}

void UISTM::stateMachine_Setting_CDM_Minute(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	//bool tmp = bStayInCurrentState;
	if (transcend == true || command == Do) {
		stateMachine_Setting(command);
		if (currState != nextState) {
			transcend == true;
		}
	}
	//bStayInCurrentState = tmp;
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_BUTTON_DOWN == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Minute;
				currTransition = StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_BC20F02C7B6D4031A4E6670E9E3C8420;
				transcend = false;
			}
			else if((E_BUTTON_UP == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Minute;
				currTransition = StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_B6C64D4284C343a09F8A2D7411FD9CAD;
				transcend = false;
			}
			else if((E_BUTTON_MODE == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			if ( transcend )
			{
				Entry_Setting();
			}
			//Entry Behaviors..
			Entry_CDM_Minute();
			break;
		}
		case Exit:
		{
			if ( transcend )
			{
				Exit_Setting();
			}
			//Exit Behaviors..
			Exit_CDM_Minute();
			break;
		}
		default:
		{
			break;
		}
	}
}

void UISTM::stateMachine_Setting_CDM_Hour(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	//bool tmp = bStayInCurrentState;
	if (transcend == true || command == Do) {
		stateMachine_Setting(command);
		if (currState != nextState) {
			transcend == true;
		}
	}
	//bStayInCurrentState = tmp;
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_BUTTON_DOWN == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				currTransition = StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_89A0F3F3D42749729B897917B61679F8;
				transcend = false;
			}
			else if((E_BUTTON_UP == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				currTransition = StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_83111AAFEA5340ab95E42A99B9F7154E;
				transcend = false;
			}
			else if((E_BUTTON_MODE == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Minute;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			if ( transcend )
			{
				Entry_Setting();
			}
			//Entry Behaviors..
			Entry_CDM_Hour();
			break;
		}
		case Exit:
		{
			if ( transcend )
			{
				Exit_Setting();
			}
			//Exit Behaviors..
			Exit_CDM_Hour();
			break;
		}
		default:
		{
			break;
		}
	}
}

void UISTM::stateMachine_Initializing(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_INITIALIZED == true) && (BR_IsPreviousLocked() == false))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				transcend = true;
				StateMachine_history = currState;
			}
			else if((E_INITIALIZED == true) && (BR_IsPreviousLocked() == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Locked;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			//Entry Behaviors..
			Entry_Initializing();
			break;
		}
		case Exit:
		{
			//Exit Behaviors..
			Exit_Initializing();
			break;
		}
		default:
		{
			break;
		}
	}
}

void UISTM::stateMachine_Locked(CommandType command)
{
////////////////////////////////////////////////////////////////	
	BR_TRACE_STATE(__FUNCTION__, command);
	
////////////////////////////////////////////////////////////////
	switch(command)
	{
		case Do:
		{
			if(!bStayInCurrentState)
			{
				// Do Behaviors..
			}			
			bStayInCurrentState = true;
			
			// State's Transitions
			if((E_CASE_UNLOCK == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Setting_CDM_Hour;
				currTransition = StateMachine_Locked_to_StateMachine_Setting_CDM_Hour_with_972C2F4A79E440e682674AE8561C8D96;
				transcend = true;
				StateMachine_history = currState;
			}
			else if((E_TICK == true))
			{
				bStayInCurrentState = false; 

				nextState = StateMachine_Locked;
				transcend = false;
			}			
			break;
		}
		case Entry:
		{
			//Entry Behaviors..
			Entry_Locked();
			break;
		}
		case Exit:
		{
			//Exit Behaviors..
			Exit_Locked();
			break;
		}
		default:
		{
			break;
		}
	}
}
void UISTM::StatesProc(StateType currState, CommandType command)
{
	switch(currState)
	{
			case StateMachine_Confirming:
			{
				stateMachine_Confirming(command);
				break;
			}

			case StateMachine_Setting:
			{
				stateMachine_Setting(command);
				break;
			}

			case StateMachine_Setting_CDM_Minute:
			{
				stateMachine_Setting_CDM_Minute(command);
				break;
			}

			case StateMachine_Setting_CDM_Hour:
			{
				stateMachine_Setting_CDM_Hour(command);
				break;
			}

			case StateMachine_Initializing:
			{
				stateMachine_Initializing(command);
				break;
			}

			case StateMachine_Locked:
			{
				stateMachine_Locked(command);
				break;
			}
		default:
			break;
	}
}
void UISTM::TransitionsProc(TransitionType transition)
{
	switch(transition)
	{
			case StateMachine_Confirming_to_StateMachine_Locked_with_FE5DB92292324f079D12A893A0FF1F2C:
			{
				BR_TRACE_TRANS("StateMachine_Confirming_to_StateMachine_Locked_with_FE5DB92292324f079D12A893A0FF1F2C");
				BR_CaseLock();
				break;
			}
			case StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_BC20F02C7B6D4031A4E6670E9E3C8420:
			{
				BR_TRACE_TRANS("StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_BC20F02C7B6D4031A4E6670E9E3C8420");
				BR_CDMMinutePlus(-1);
				break;
			}
			case StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_B6C64D4284C343a09F8A2D7411FD9CAD:
			{
				BR_TRACE_TRANS("StateMachine_Setting_CDM_Minute_to_StateMachine_Setting_CDM_Minute_with_B6C64D4284C343a09F8A2D7411FD9CAD");
				BR_CDMMinutePlus(1);
				break;
			}
			case StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_89A0F3F3D42749729B897917B61679F8:
			{
				BR_TRACE_TRANS("StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_89A0F3F3D42749729B897917B61679F8");
				BR_CDMHourPlus(-1);
				break;
			}
			case StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_83111AAFEA5340ab95E42A99B9F7154E:
			{
				BR_TRACE_TRANS("StateMachine_Setting_CDM_Hour_to_StateMachine_Setting_CDM_Hour_with_83111AAFEA5340ab95E42A99B9F7154E");
				BR_CDMHourPlus(1);
				break;
			}
			case StateMachine_Locked_to_StateMachine_Setting_CDM_Hour_with_972C2F4A79E440e682674AE8561C8D96:
			{
				BR_TRACE_TRANS("StateMachine_Locked_to_StateMachine_Setting_CDM_Hour_with_972C2F4A79E440e682674AE8561C8D96");
				BR_CaseUnlock();
				break;
			}
		default:
			break;
	}
}
