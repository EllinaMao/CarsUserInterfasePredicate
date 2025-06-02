#pragma once
#include "CarRepository.h"
#include <functional>
#include <vector>

class CarService {
private:
    CarRepository& repository;
public:
    explicit CarService(CarRepository& repo);

    void sortCars(std::function<bool(const Car&, const Car&)> comparator);
    std::vector<Car> searchCars(std::function<bool(const Car&)> predicate) const;
    const std::vector<Car>& getAllCars() const;
    CarRepository& getRepository() { return repository; }
    const CarRepository& getRepository() const { return repository; }
};