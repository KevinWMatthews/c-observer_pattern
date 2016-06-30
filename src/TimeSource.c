#include "TimeSource.h"

static TimeObserver observer_list[MAX_OBSERVERS];
static unsigned char index_of_last_observer;

void TimeSource_Create(void)
{
    index_of_last_observer = 0;
}

void TimeSource_Destroy(void)
{
}

void TimeSource_MillisecondTick(void)
{
    SystemTime system_time = NULL;
    size_t i;
    for (i = 0; i < index_of_last_observer; i++)
    {
        TimeObserver_Notify(observer_list[i], system_time);
    }
}

int TimeSource_RegisterMillisecondTickObserver(TimeObserver observer)
{
    if (index_of_last_observer >= MAX_OBSERVERS)
    {
        return TS_TOO_MANY_OBSERVERS;
    }
    observer_list[index_of_last_observer] = observer;
    index_of_last_observer++;
    return TS_SUCCESS;
}
