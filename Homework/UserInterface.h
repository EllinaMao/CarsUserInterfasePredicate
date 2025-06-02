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
    void handleAddCar();
    void handleRemoveCar(size_t index);
    void handleShowAllCars();
    void handleSortCars();
    void handleSearchCars() const;
};