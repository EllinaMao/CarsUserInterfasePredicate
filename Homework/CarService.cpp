#include "CarService.h"
#include <algorithm>
using namespace std;

CarService::CarService(CarRepository& repo) : repository(repo) {}

void CarService::sortCars(function<bool(const Car&, const Car&)> comparator) {
    auto& cars = const_cast<vector<Car>&>(repository.getAllCars());
    sort(cars.begin(), cars.end(), comparator);
}

vector<Car> CarService::searchCars(function<bool(const Car&)> predicate) const {
    vector<Car> result;
    const auto& cars = repository.getAllCars();
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (predicate(*it)) {
            result.push_back(*it);
        }
    }
    return result;
}
const vector<Car>& CarService::getAllCars() const {
    return repository.getAllCars();
}

