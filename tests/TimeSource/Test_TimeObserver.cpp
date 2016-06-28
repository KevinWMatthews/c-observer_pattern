extern "C"
{
#include "TimeObserver.h"
}

#include "Test_TimeObserver.h"
#include "CppUTest/TestHarness.h"

void dummyNotification(TimeObserver observer, SystemTime system_time)
{
}

TEST_GROUP(TimeObserver)
{
    TimeObserver observer;

    void setup()
    {
        observer = TimeObserver_Create(dummyNotification);
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
