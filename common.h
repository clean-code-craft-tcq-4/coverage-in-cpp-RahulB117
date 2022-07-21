#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>

typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum
{
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

#endif
