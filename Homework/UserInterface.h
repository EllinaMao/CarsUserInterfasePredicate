#pragma once
#include "CarService.h"

class UserInterface {
private:
    CarService& service;
public:
    explicit UserInterface(CarService& service);
    void run();
};