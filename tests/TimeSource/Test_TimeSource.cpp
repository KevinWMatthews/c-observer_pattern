extern "C"
{
#include "TimeSource.h"
}

#include "Test_TimeSource.h"
#include "CppUTest/TestHarness.h"

static bool is_observer_notified;
static bool is_observer2_notified;

static void dummyNotification(TimeObserver observer, SystemTime system_time)
{
    is_observer_notified = 1;
}

static void dummyNotification2(TimeObserver observer, SystemTime system_time)
{
    is_observer2_notified = 1;
}

TEST_GROUP(TimeSource)
{
    TimeObserver observer;
    TimeObserver observer2;

    void setup()
    {
        observer = TimeObserver_Create(dummyNotification);
        observer2 = TimeObserver_Create(dummyNotification2);
        TimeSource_Create();
        is_observer_notified = 0;
        is_observer2_notified = 0;
    }

    void teardown()
    {
        TimeObserver_Destroy(observer);
        TimeObserver_Destroy(observer2);
        TimeSource_Destroy();
    }
};

/* Test List:
 *   Notify max observers.
 */

TEST(TimeSource, observers_not_notified_by_default)
{
    CHECK_FALSE(is_observer_notified);
    CHECK_FALSE(is_observer2_notified);
}

TEST(TimeSource, can_register_an_observer)
{
    LONGS_EQUAL( TS_SUCCESS, TimeSource_RegisterMillisecondTickObserver(observer) );
}

TEST(TimeSource, can_not_register_too_many_observers)
{
    for (size_t i = 0; i < MAX_OBSERVERS; i++)
    {
        LONGS_EQUAL( TS_SUCCESS, TimeSource_RegisterMillisecondTickObserver(observer) );
    }
    LONGS_EQUAL( TS_TOO_MANY_OBSERVERS, TimeSource_RegisterMillisecondTickObserver(observer) );
}

TEST(TimeSource, tick_can_notify_no_observers)
{
    TimeSource_MillisecondTick();
}

TEST(TimeSource, tick_notifies_an_observer)
{
    TimeSource_RegisterMillisecondTickObserver(observer);   // We're only offering one tick right now.

    TimeSource_MillisecondTick();                           // The HW or OS will call this from a timer.

    CHECK_TRUE(is_observer_notified);
}

TEST(TimeSource, tick_notifies_several_observers)
{
    TimeSource_RegisterMillisecondTickObserver(observer);
    TimeSource_RegisterMillisecondTickObserver(observer2);

    TimeSource_MillisecondTick();

    CHECK_TRUE(is_observer_notified);
    CHECK_TRUE(is_observer2_notified);
}
