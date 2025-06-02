#pragma once
#include "CarService.h"
#include "UserInput.h"

class UserInterface {
private:
    CarService& service;
    UserInput userInput;
public:
    explicit UserInterface(CarService& service);
    void run();
};