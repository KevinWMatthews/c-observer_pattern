extern "C"
{
#include "TimeSource.h"
}

#include "MockSystemTime.h"
#include "Test_TimeSource.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

void MockObserver_Notify(TimeObserver observer, SystemTime system_time)
{
    mock().actualCall("MockObserver_Notify")
        .withParameter("observer", observer)
        .withParameter("system_time", system_time);
}

TEST_GROUP(TimeSource)
{
    TimeObserver mock_observer;
    TimeObserver mock_observer2;
    SystemTime system_time;

    void setup()
    {
        mock_observer = TimeObserver_Create(MockObserver_Notify);
        mock_observer2 = TimeObserver_Create(MockObserver_Notify);
        TimeSource_Create();
        system_time = MockSystemTime_Create();
    }

    void teardown()
    {
        TimeObserver_Destroy(mock_observer);
        TimeObserver_Destroy(mock_observer2);
        TimeSource_Destroy();
        MockSystemTime_Destroy(system_time);
        mock().checkExpectations();
        mock().clear();
    }

    void expectGetSystemTime(SystemTime time)
    {
        mock().expectOneCall("SystemTime_GetTime")
            .andReturnValue(time);
    }

    void expectObserverNotify(TimeObserver observer, SystemTime time)
    {
        mock().expectOneCall("MockObserver_Notify")
            .withParameter("observer", observer)
            .withParameter("system_time", time);
    }
};

/* Test List:
 *   Notify max observers.
 */

TEST(TimeSource, can_register_an_observer)
{
    LONGS_EQUAL( TS_SUCCESS, TimeSource_RegisterMillisecondTickObserver(mock_observer) );
}

TEST(TimeSource, can_not_register_too_many_observers)
{
    for (size_t i = 0; i < MAX_OBSERVERS; i++)
    {
        LONGS_EQUAL( TS_SUCCESS, TimeSource_RegisterMillisecondTickObserver(mock_observer) );
    }
    LONGS_EQUAL( TS_TOO_MANY_OBSERVERS, TimeSource_RegisterMillisecondTickObserver(mock_observer) );
}

TEST(TimeSource, tick_can_notify_no_observers)
{
    expectGetSystemTime(system_time);

    TimeSource_MillisecondTick();
}

TEST(TimeSource, tick_notifies_an_observer)
{
    expectGetSystemTime(system_time);
    expectObserverNotify(mock_observer, system_time);
    TimeSource_RegisterMillisecondTickObserver(mock_observer);   // We're only offering one tick right now

    TimeSource_MillisecondTick();                           // The HW or OS will call this from a timer.
}

TEST(TimeSource, tick_notifies_several_observers)
{
    expectGetSystemTime(system_time);
    expectObserverNotify(mock_observer, system_time);
    expectObserverNotify(mock_observer2, system_time);
    TimeSource_RegisterMillisecondTickObserver(mock_observer);
    TimeSource_RegisterMillisecondTickObserver(mock_observer2);

    TimeSource_MillisecondTick();
}
