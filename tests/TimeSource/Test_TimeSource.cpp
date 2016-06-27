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
    }

    void teardown()
    {
    }
};

TEST(TimeSource, it_can_fail)
{
    FAIL("Start here");
}
