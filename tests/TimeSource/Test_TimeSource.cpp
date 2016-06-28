extern "C"
{
#include "TimeSource.h"
}

#include "Test_TimeSource.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(TimeSource)
{
    bool is_observer_notified;

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

IGNORE_TEST(TimeSource, tick_notifies_an_observer)
{
    // TimeObserver observer = TimeObserver_Create();   //TODO add notification

    // TimeSource_RegisterMillisecondTickObserver(observer);   // We're only offering one tick right now.

    // TimeSource_MillisecondTick();                           // The HW or OS will call this from a timer.

    // CHECK_TRUE(is_observer_notified);
}
