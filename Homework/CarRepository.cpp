#include "CarRepository.h"

void CarRepository::removeCar(size_t index) {
    if (index >= mCars.size()) {
        throw std::out_of_range("Index out of range");
    }
    mCars.erase(mCars.begin() + index);
}


const std::vector<Car>& CarRepository::getAllCars() const
{
		return mCars;
}

