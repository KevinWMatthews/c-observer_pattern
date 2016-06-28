#include "TimeObserver.h"

typedef struct TimeObserverStruct
{
    TimeChangedNotification timeChangedNotification;
} TimeObserverStruct;

static TimeObserverStruct observerStruct;
static TimeObserver observer;

TimeObserver TimeObserver_Create(TimeChangedNotification notification)
{
    observer = &observerStruct;
    observer->timeChangedNotification = notification;
    return observer;
}

void TimeObserver_Destroy(TimeObserver self)
{
}

void TimeObserver_Notify(TimeObserver self, SystemTime system_time)
{
    if (self == 0)
        return;
    if (self->timeChangedNotification == 0)
        return;

    self->timeChangedNotification(self, system_time);
}
