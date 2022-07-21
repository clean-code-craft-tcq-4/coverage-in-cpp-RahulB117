#include <iostream>
#include "email.h"

void alertEmail(Email email)
{
	std::string message = email.buildmessage(email.breachType);
	email.printEmailAlert(message);
}

std::string Email::buildmessage(BreachType breachType)
{
	std::string output = TEMPERATURE_MESSAGE + batteryTemperatureStatus[breachType];
	return output;

}
void Email::printEmailAlert(std::string message)
{
	std::cout << message <<std::endl;
}


