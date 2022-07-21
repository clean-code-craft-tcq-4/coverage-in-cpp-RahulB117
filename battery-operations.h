#ifndef BATTERY_OPERATIONS_H
#define BATTERY_OPERATIONS_H

#include "common.h"
#include "controller.h"
#include "email.h"

class Battery {

	double temperatureInC;
public:
	CoolingType coolingType;
	char brand[48];
	double getBatteryTemperature();
	void setBatteryTemperature(double value);
};

class CoolerType {
public:
	int upperlimit = 0;
	int lowerlimit = 0;
};

class Passive_Cooler:public CoolerType {
public:
	int upperlimit = 35;
	int lowerlimit = 0;
};

class High_Active_Cooler:public CoolerType {
public:
	int upperlimit = 45;
	int lowerlimit = 0;
};

class Medium_Active_Cooler:public CoolerType {
public:
	int upperlimit = 40;
	int lowerlimit = 0;
};

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
void checkPassiveCoolingType(CoolingType coolingType, Passive_Cooler passive_cooler, int *lowerLimit, int *upperLimit);
void checkHighCoolingType(CoolingType coolingType, High_Active_Cooler high_Active_Cooler, int *lowerLimit, int *upperLimit);
void checkMediumCoolingType(CoolingType coolingType, Medium_Active_Cooler medium_Active_Cooler, int *lowerLimit, int *upperLimit);

#endif
