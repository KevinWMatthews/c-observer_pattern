#include "TimeObserver.h"
#include <stdlib.h>

typedef struct TimeObserverStruct
{
    TimeChangedNotification timeChangedNotification;
} TimeObserverStruct;

TimeObserver TimeObserver_Create(TimeChangedNotification notification)
{
    TimeObserver self = (TimeObserver)calloc( 1, sizeof(*self) );
    self->timeChangedNotification = notification;
    return self;
}

void TimeObserver_Destroy(TimeObserver self)
{
    free(self);
}

void TimeObserver_Notify(TimeObserver self, SystemTime system_time)
{
    if (self == 0)
        return;
    if (self->timeChangedNotification == 0)
        return;

    self->timeChangedNotification(self, system_time);
}
