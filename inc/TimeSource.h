#ifndef TIME_SOURCE_INCLUDED
#define TIME_SOURCE_INCLUDED

#include "TimeObserver.h"

void TimeSource_Create(void);
void TimeSource_Destroy(void);

void TimeSource_RegisterMillisecondTickObserver(TimeObserver);
void TimeSource_MillisecondTick(void);

#endif
