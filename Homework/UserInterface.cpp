#include <string> 
#include <iostream>
#include <limits>
#include "UserInterface.h"
#include "SortFunctors.h"
#include "Menu.h"
using namespace std;

UserInterface::UserInterface(CarService& service) : service(service), userInput(service) {}

void UserInterface::run()
{
    int choice = 0;
    do {
        system("clear || cls");
        Menu::displayMainMenu();
        choice = Menu::option();
        system("clear || cls");
        switch (choice) {
        case 1: {
            handleAddCar();
            system("pause");
            break;
        }
        case 2: {
            cout << "Enter the index of the car to remove: " << endl;
            size_t index = UserInput::inputSize_t();
            handleRemoveCar(index);
            system("pause");
            break;
        }
        case 3: {
            handleShowAllCars();
			system("pause");
            break;
        }
        case 4: {
            handleSortCars();
			system("pause");
            break;
        }
        case 5: {
            handleSearchCars();
			system("pause");
            break;
        }
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
	} while (choice != 0);
}

void UserInterface::handleAddCar()
{
	userInput.inputCarDetails();
}

void UserInterface::handleRemoveCar(size_t index)
{
    const auto& cars = service.getRepository().getAllCars();
    if (cars.empty()) {
        cerr << "No cars to remove.\n";
        return;
    }
    try {
        service.getRepository().removeCar(index);
        cout << "Car removed.\n";
    }
    catch (const std::out_of_range&) {
        cout << "Invalid index.\n";
    }
}

void UserInterface::handleShowAllCars()
{
    if (service.getRepository().getAllCars().empty()) {
        cout << "No cars available.\n";
    }
    else {
        service.getRepository().print();
    }

}

void UserInterface::handleSortCars()
{
    system("clear || cls");
    cout << "Sort by:" << endl;
    Menu::displayCarsMenu();
    int opt;
    opt = Menu::option();
    switch (opt) {
    case 1: {
        service.sortCars(SortByName());
        break;
    }
    case 2: {
        service.sortCars(SortByYear());
        break;
    }
    case 3: {
        service.sortCars(SortByEngineVolume());
        break;
    }
    case 4: {
        service.sortCars(SortByPrice());
        break;
    }
    default: {
        cout << "Invalid sort option.\n";
        return;
    }
    }
    cout << "Cars sorted.\n";
}

void UserInterface::handleSearchCars() const
{
    system("clear || cls");
    cout << "Search by:" << endl;
    Menu::displayCarsMenu();
    int opt = Menu::option();

    std::vector<Car> results;
    switch (opt) {
    case 1: {
        cout << "Enter car name: ";
        string name = UserInput::inputString();
        results = service.searchCars([&](const Car& c) { return c.getCarName() == name; });
        break;
    }
    case 2: {
        cout << "Enter car year: ";
        size_t year = UserInput::inputSize_t();
        results = service.searchCars([&](const Car& c) { return c.getCarYear() == year; });
        break;
    }
    case 3: {
        cout << "Enter car engine volume: ";
        double engineVolume = UserInput::inputDouble();
        results = service.searchCars([&](const Car& c) { return c.getCarEngineVolume() == engineVolume; });
        break;
    }
    case 4: {
        cout << "Enter car price: ";
        double price = UserInput::inputDouble();
        results = service.searchCars([&](const Car& c) { return c.getCarPrice() == price; });
        break;
    }
    default: {
        cout << "Invalid search option.\n";
        return;
    }
    }
    printSearchResults(results);
}



void UserInterface::printSearchResults(const std::vector<Car>& results) const
{
    if (results.empty()) {
        cout << "No matching cars found.\n";
    }
    else {
        for (auto it = results.begin(); it != results.end(); ++it) {

            it->print(); 
        }

    }
}
