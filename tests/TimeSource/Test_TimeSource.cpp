extern "C"
{
#include "TimeSource.h"
}

#include "Test_TimeSource.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(TimeSource)
{
    void setup()
    {
        TimeSource_Create();
    }

    void teardown()
    {
        TimeSource_Destroy();
    }
};

TEST(TimeSource, tick_notifies_an_observer)
{
    TimeSource_MillisecondTick();
}
