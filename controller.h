#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "common.h"

class Controller {

public:
	BreachType breachType;
	const unsigned short header = 0xfeed;
	void printControllerAlert(BreachType breachType);
};
void alertController(Controller controller);
#endif
