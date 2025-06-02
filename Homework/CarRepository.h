#pragma once
#include "Car.h"
#include <vector>

class CarRepository {
private:
    std::vector<Car> mCars;

public:
	CarRepository() = default;
    void addCar(const Car& car) { mCars.push_back(car);}
    void removeCar(size_t index);

    void clearCars() { mCars.clear(); }
    const std::vector<Car>& getAllCars() const;

    friend std::ostream& operator<<(std::ostream& os, const CarRepository& repo) {
        for (const auto& car : repo.mCars) {
            os << car << "\n";
        }
        return os;
	}
};