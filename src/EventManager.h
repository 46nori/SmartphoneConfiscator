#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "UISTM.h"

class EventManager
{
private:
	UISTM *stm;
	bool isForceUnlock;

public:
	EventManager();
	EventManager(UISTM* p);
	virtual ~EventManager();

	void Initialize();
	void Run();
	void ForceUnlock();
};
#endif
