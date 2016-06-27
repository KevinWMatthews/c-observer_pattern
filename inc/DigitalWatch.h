#ifndef DIGITAL_WATCH_INCLUDED
#define DIGITAL_WATCH_INCLUDED

#include "SystemTime.h"

typedef struct DigitalWatchStruct * DigitalWatch;

DigitalWatch DigitalWatch_Create(void);
void DigitalWatch_Destroy(DigitalWatch);

char * DigitalWatch_GetStateName(DigitalWatch);
void DigitalWatch_StopWatch(DigitalWatch);
void DigitalWatch_StartWatch(DigitalWatch);

void DigitalWatch_UpdateDisplay(DigitalWatch, SystemTime);

#include "DigitalWatchPrivate.h"

#endif
