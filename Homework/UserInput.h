#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "CarService.h"


class UserInput {
private:
	CarService& service;
public:
	explicit UserInput(CarService& service) : service(service) {}

	static double inputDouble();
	static int inputInt();
	static std::string inputString();

	void inputCarDetails();

};