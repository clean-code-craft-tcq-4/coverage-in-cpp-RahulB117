#include "battery-operations.h"
#include "email.h"
#include "controller.h"
#include <assert.h>

double Battery::getBatteryTemperature()
{
	return temperatureInC;
}

void Battery::setBatteryTemperature(double value)
{
	this->temperatureInC = value;
}
BreachType inferBreach(double value, double lowerLimit, double upperLimit) //CCM = 3
{
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) //CCM = 3
{
	int lowerLimit = 0;
	int upperLimit = 0;
	Passive_Cooler passive_cooler;
	High_Active_Cooler high_Active_Cooler;
	Medium_Active_Cooler medium_Active_Cooler;

    checkPassiveCoolingType(coolingType, passive_cooler, &lowerLimit, &upperLimit);
    checkHighCoolingType(coolingType, high_Active_Cooler, &lowerLimit, &upperLimit);
    checkMediumCoolingType(coolingType, medium_Active_Cooler, &lowerLimit, &upperLimit);
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkPassiveCoolingType(CoolingType coolingType, Passive_Cooler passive_cooler, int *lowerLimit, int *upperLimit)
{
	if(coolingType == 0)
	{
		*lowerLimit = passive_cooler.lowerlimit;
		*upperLimit = passive_cooler.upperlimit;
	}
}

void checkHighCoolingType(CoolingType coolingType, High_Active_Cooler high_Active_Cooler, int *lowerLimit, int *upperLimit)
{
	if(coolingType == 2)
	{
		*lowerLimit = high_Active_Cooler.lowerlimit;
		*upperLimit = high_Active_Cooler.upperlimit;
	}
}
void checkMediumCoolingType(CoolingType coolingType, Medium_Active_Cooler medium_Active_Cooler, int *lowerLimit, int *upperLimit)
{
	if(coolingType == 1)
	{
		*lowerLimit = medium_Active_Cooler.lowerlimit;
		*upperLimit = medium_Active_Cooler.upperlimit;
	}
}
BreachType checkBatteryTemperature(Battery battery)
{
	double temperature = battery.getBatteryTemperature();
	BreachType Breach = classifyTemperatureBreach(battery.coolingType, temperature);
	return Breach;
}

void sendAlerts(Controller controller, Email email)
{
	alertController(controller);
	alertEmail(email);
}


BreachType checkAndAlert(Battery battery, Controller controller, Email email, int temperatureinC, CoolingType coolingType)
{

	battery.setBatteryTemperature(temperatureinC);
	battery.coolingType = coolingType;
	controller.breachType = checkBatteryTemperature(battery);
	email.breachType = controller.breachType;
	sendAlerts(controller, email);
	return controller.breachType;
}
