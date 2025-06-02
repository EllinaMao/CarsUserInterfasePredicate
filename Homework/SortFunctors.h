#pragma once
#include "Car.h"

struct SortByName {
    bool operator()(const Car& a, const Car& b) const {
        return a.getCarName() < b.getCarName();
    }
};

struct SortByYear {
    bool operator()(const Car& a, const Car& b) const {
        return a.getCarYear() < b.getCarYear();
    }
};

struct SortByEngineVolume {
    bool operator()(const Car& a, const Car& b) const {
        return a.getCarEngineVolume() < b.getCarEngineVolume();
    }
};

struct SortByPrice {
    bool operator()(const Car& a, const Car& b) const {
        return a.getCarPrice() < b.getCarPrice();
    }
};