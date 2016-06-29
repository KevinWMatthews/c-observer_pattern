#include "TimeSource.h"

static TimeObserver observer_list;

void TimeSource_Create(void)
{
}

void TimeSource_Destroy(void)
{
}

void TimeSource_MillisecondTick(void)
{
    SystemTime system_time = NULL;
    TimeObserver_Notify(observer_list, system_time);
}

void TimeSource_RegisterMillisecondTickObserver(TimeObserver observer)
{
    observer_list = observer;
}
