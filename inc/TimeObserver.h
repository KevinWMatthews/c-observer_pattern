#ifndef TIME_OBSERVER_INCLUDED
#define TIME_OBSERVER_INCLUDED

#include "SystemTime.h"

typedef struct TimeObserverStruct * TimeObserver;

typedef void (*TimeChangedNotification)(TimeObserver, SystemTime);

TimeObserver TimeObserver_Create(TimeChangedNotification);
void TimeObserver_Destroy(TimeObserver);

void TimeObserver_Notify(TimeObserver, SystemTime);

#endif
