#ifndef MOCK_SYSTEM_TIME_INCLUDED
#define MOCK_SYSTEM_TIME_INCLUDED

#include "SystemTime.h"

SystemTime MockSystemTime_Create(void);
void MockSystemTime_Destroy(SystemTime);

#endif
