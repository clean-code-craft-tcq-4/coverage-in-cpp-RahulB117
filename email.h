#ifndef EMAIL_H
#define EMAIL_H

//#include "temperature-operations.h"
#include "common.h"

const std::string TEMPERATURE_MESSAGE= "Hello, the temperature is ";
const std::vector<std::string> batteryTemperatureStatus = {"normal", "too_low", "too_high"};

class Email {
public:
	BreachType breachType;
	const char* recepient = "a.b@c.com";

	std::string buildmessage(BreachType breachType);

	void printEmailAlert(std::string message);
};

void alertEmail(Email email);
#endif
