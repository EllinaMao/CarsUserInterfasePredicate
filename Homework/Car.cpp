#include "Car.h"
using namespace std;
Car::Car(Car&& other) noexcept
{
	mCarName = move(other.mCarName);
	mCarPrice = other.mCarPrice;
	mCarYear = other.mCarYear;
	mCarEngineVolume = other.mCarEngineVolume;

	other.mCarPrice = 0.0;
	other.mCarYear = 0;
	other.mCarEngineVolume = 0.0;
	other.mCarName.clear();

}
Car& Car::operator=(Car&& other) noexcept
{
	mCarName = move(other.mCarName);
	mCarPrice = other.mCarPrice;
	mCarYear = other.mCarYear;
	mCarEngineVolume = other.mCarEngineVolume;

	other.mCarPrice = 0.0;
	other.mCarYear = 0;
	other.mCarEngineVolume = 0.0;
	other.mCarName.clear();
	
	return *this;

}
