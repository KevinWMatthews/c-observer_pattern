extern "C"
{
#include "TimeSource.h"
}

#include "Test_TimeSource.h"
#include "CppUTest/TestHarness.h"

static bool is_observer_notified;

TEST_GROUP(TimeSource)
{
    void setup()
    {
        TimeSource_Create();
        is_observer_notified = 0;
    }

    void teardown()
    {
        TimeSource_Destroy();
    }

    static void notify_observer(void)
    {

    }
};

static void dummyNotification(TimeObserver observer, SystemTime system_time)
{
    is_observer_notified = 1;
}

TEST(TimeSource, observers_not_notified_by_default)
{
    CHECK_FALSE(is_observer_notified);
}

TEST(TimeSource, tick_notifies_an_observer)
{
    TimeObserver observer = TimeObserver_Create(dummyNotification);
    TimeSource_RegisterMillisecondTickObserver(observer);   // We're only offering one tick right now.

    TimeSource_MillisecondTick();                           // The HW or OS will call this from a timer.

    CHECK_TRUE(is_observer_notified);

    TimeObserver_Destroy(observer);
}
