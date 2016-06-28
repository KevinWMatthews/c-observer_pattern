extern "C"
{
#include "TimeObserver.h"
}

#include "Test_TimeObserver.h"
#include "CppUTest/TestHarness.h"

static bool is_observer_notified;
static bool is_observer2_notified;

void dummyNotification(TimeObserver observer, SystemTime system_time)
{
    is_observer_notified = 1;
}

void dummyNotification2(TimeObserver observer, SystemTime system_time)
{
    is_observer2_notified = 1;
}

TEST_GROUP(TimeObserver)
{
    TimeObserver observer;
    TimeObserver observer2;

    void setup()
    {
        observer = TimeObserver_Create(dummyNotification);
        is_observer_notified = 0;
    }

    void teardown()
    {
        TimeObserver_Destroy(observer);
    }
};

/* Test list:
 *   Create
 *   Destroy
 *   Register?
 *   Notify
 */

TEST(TimeObserver, it_can_be_created_and_destroyed)
{
}

TEST(TimeObserver, notify_a_single_observer)
{
    SystemTime system_time = NULL;

    TimeObserver_Notify(observer, system_time);

    CHECK_TRUE(is_observer_notified);
}

TEST(TimeObserver, notify_a_second_observer)
{
    observer2 = TimeObserver_Create(dummyNotification2);
    SystemTime system_time = NULL;

    TimeObserver_Notify(observer2, system_time);

    CHECK_TRUE(is_observer2_notified);
}
