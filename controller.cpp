#include "controller.h"

void Controller::printControllerAlert(BreachType breachType)
{
	std::cout << std::hex << header<<":"<< std::hex << breachType << std::endl;
}

void alertController(Controller controller)
{
	controller.printControllerAlert(controller.breachType);
}
