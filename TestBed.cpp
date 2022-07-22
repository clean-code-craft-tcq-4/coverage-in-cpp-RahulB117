#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "battery-operations.h"
#include <iostream>


Battery battery;
Controller controller;
Email email;
BreachType breachtype;

TEST_CASE("High Active cooling tests"){
	breachtype = checkAndAlert(battery, controller, email, 50, HI_ACTIVE_COOLING);
	REQUIRE(breachtype == TOO_HIGH);

	breachtype = checkAndAlert(battery, controller, email, -10, HI_ACTIVE_COOLING);
	REQUIRE(breachtype == TOO_LOW);

	breachtype = checkAndAlert(battery, controller, email, 10, HI_ACTIVE_COOLING);
	REQUIRE(breachtype == NORMAL);
}

TEST_CASE("Passive cooling tests"){
	breachtype = checkAndAlert(battery, controller, email, 50, PASSIVE_COOLING);
	REQUIRE(breachtype == TOO_HIGH);

	breachtype = checkAndAlert(battery, controller, email, -10, PASSIVE_COOLING);
	REQUIRE(breachtype == TOO_LOW);

	breachtype = checkAndAlert(battery, controller, email, 10, PASSIVE_COOLING);
	REQUIRE(breachtype == NORMAL);
}

TEST_CASE("Medium active cooling tests"){
	breachtype = checkAndAlert(battery, controller, email, 50, MED_ACTIVE_COOLING);
	REQUIRE(breachtype == TOO_HIGH);

	breachtype = checkAndAlert(battery, controller, email, -10, MED_ACTIVE_COOLING);
	REQUIRE(breachtype == TOO_LOW);

	breachtype = checkAndAlert(battery, controller, email, 10, MED_ACTIVE_COOLING);
	REQUIRE(breachtype == NORMAL);
}
TEST_CASE("High Active cooling tests on classifyTemperatureBreach"){
	breachtype = classifyTemperatureBreach(HI_ACTIVE_COOLING, 50);
	REQUIRE(breachtype == TOO_HIGH);
}



