#ifndef _UISTMBRIDGE_H_
#define _UISTMBRIDGE_H_

#include "application.h""

class UISTMBridge
{

public:
	UISTMBridge();
	virtual ~UISTMBridge();

	void CaseLock();
	void CaseUnlock();
	void CDMHourPlus(int val);
	void CDMMinutePlus(int val);

	void Entry_CDM_Hour();
	void Exit_CDM_Hour();

	void Entry_CDM_Minute();
	void Exit_CDM_Minute();

	void Entry_Confirming();
	void Exit_Confirming();

	void Entry_Initializing();
	void Exit_Initializing();

	void Entry_Locked();
	void Exit_Locked();

	void Entry_Locking();
	void Exit_Locking();

	void Entry_PromptingSetKey();
	void Exit_PromptingSetKey();

	void Entry_Setting();
	void Exit_Setting();

	void Entry_Unlocked();
	void Exit_Unlocked();

	void Initialize();
	bool IsCaseClosed();
	bool IsPreviousLocked();
	void TimerCancel();
	void TimerSet(unsigned int timeout);

	void TRACE(const char* s);
	void TRACE_STATE(const char* state, int command);
	void TRACE_TRANS(const char* trans);

private:
	class dateTime
	{

	public:
		int day;
		int hour;
		int minute;
		int month;
		int year;

		dateTime();
		virtual ~dateTime();
		void addDay(int val);
		void addHour(int val);
		void addMinute(int val);
		void addMonth(int val);
		void addYear(int val);
		unsigned long GetSecondsFromUnixEpoch();

	};

	//Countdown mode time
	UISTMBridge::dateTime cdm;

	const char* GetDateTimeString(String& s);

};
#endif
