extern "C"
{
#include "SystemTime.h"
}

#include "CppUTestExt/MockSupport.h"

static int dummy_system_time;
static SystemTime system_time = (SystemTime)&dummy_system_time;

SystemTime MockSystemTime_Create(void)
{
    return system_time;
}

void MockSystemTime_Destroy(SystemTime self)
{
    return;
}

SystemTime SystemTime_GetTime(void)
{
    mock().actualCall("SystemTime_GetTime");

    return (SystemTime)mock().pointerReturnValue();
}
