#include "CarRepository.h"

void CarRepository::removeCar(size_t index)

{
    if (index < mCars.size())
        mCars.erase(mCars.begin() + index);
}


const std::vector<Car>& CarRepository::getAllCars() const
{
		return mCars;
}
