extern "C"
{
#include "Lcd.h"
}

#include "CppUTestExt/MockSupport.h"

void Lcd_UpdateDisplay(SystemTime time)
{
    mock().actualCall("Lcd_UpdateDisplay")
        .withParameter("time", time);
}
