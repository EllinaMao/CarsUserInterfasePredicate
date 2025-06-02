#pragma once
#include <iostream>
#include <string>
#include <limits>

class UserInput {
	public:

	static double inputCarEngineVolume();
	static double inputCarPrice();
	static std::string inputCarName();
	static void clearInputBuffer();

	std::string mCarName;
	size_t mCarYear;
	double mCarEngineVolume;
	double mCarPrice;
};