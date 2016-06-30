#ifndef TIME_SOURCE_INCLUDED
#define TIME_SOURCE_INCLUDED

#include "TimeObserver.h"

void TimeSource_Create(void);
void TimeSource_Destroy(void);

#define MAX_OBSERVERS 10
enum
{
    TS_TOO_MANY_OBSERVERS = -1,
    TS_SUCCESS = 0
};
int TimeSource_RegisterMillisecondTickObserver(TimeObserver);
void TimeSource_MillisecondTick(void);

#endif
