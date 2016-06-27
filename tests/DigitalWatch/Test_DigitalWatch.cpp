extern "C"
{
#include "DigitalWatch.h"
}

#include "Test_DigitalWatch.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(DigitalWatch)
{
    DigitalWatch watch;
    int dummySystemTimeStruct;
    SystemTime newTime;

    void setup()
    {
        mock().strictOrder();
        watch = DigitalWatch_Create();
        newTime = (SystemTime)(&dummySystemTimeStruct);
    }

    void teardown()
    {
        DigitalWatch_Destroy(watch);
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(DigitalWatch, it_is_stopped_after_create)
{
    STRCMP_EQUAL( "Stopped", DigitalWatch_GetStateName(watch) );
}

TEST(DigitalWatch, it_can_be_started)
{
    DigitalWatch_StartWatch(watch);
    STRCMP_EQUAL( "Started", DigitalWatch_GetStateName(watch) );
}

TEST(DigitalWatch, it_can_be_stopped)
{
    DigitalWatch_StartWatch(watch);
    DigitalWatch_StopWatch(watch);
    STRCMP_EQUAL( "Stopped", DigitalWatch_GetStateName(watch) );
}

TEST(DigitalWatch, stopping_twice_does_not_change_state)
{
    DigitalWatch_StopWatch(watch);
    DigitalWatch_StopWatch(watch);
    STRCMP_EQUAL( "Stopped", DigitalWatch_GetStateName(watch) );
}

TEST(DigitalWatch, GetStateName_can_handle_null_pointer)
{
    STRCMP_EQUAL( "Null digital watch", DigitalWatch_GetStateName(NULL) );
}

TEST(DigitalWatch, StartWatch_can_handle_null_pointer)
{
    DigitalWatch_StartWatch(NULL);
}

TEST(DigitalWatch, StopWatch_can_handle_null_pointer)
{
    DigitalWatch_StopWatch(NULL);
}

TEST(DigitalWatch, UpdateDisplaySendsCommandToLcd)
{
    mock().expectOneCall("Lcd_UpdateDisplay")
        .withParameter("time", newTime);

    DigitalWatch_UpdateDisplay(watch, newTime);
}
