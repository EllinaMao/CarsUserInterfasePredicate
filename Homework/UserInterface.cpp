#include <string> 
#include <iostream>
#include <limits>
#include "UserInterface.h"
#include "SortFunctors.h"
#include "Menu.h"
using namespace std;


UserInterface::UserInterface(CarService& service) : service(service), userInput(service) {}

void UserInterface::run() {
    int choice = 0;
    do {
		Menu::displayMainMenu();

        switch (choice) {
        case 1: {
            userInput.inputCarDetails();
            break;
        }
        case 2: {
            const auto& cars = service.getRepository().getAllCars();
            if (cars.empty()) {
                cout << "No cars to remove.\n";
                break;
            }
            for (size_t i = 0; i < cars.size(); ++i) {
                cout << i << ": ";
                cars[i].print();
            }
            cout << "Enter index to remove: ";
            size_t idx;
            cin >> idx;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (idx < cars.size()) {
                service.getRepository().removeCar(idx);
                cout << "Car removed.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
            break;
        }
        case 3: {
            const auto& cars = service.getRepository().getAllCars();
            if (cars.empty()) {
                cout << "No cars available.\n";
            }
            else {
                for (size_t i = 0; i < cars.size(); ++i) {
                    cout << i << ": ";
                    cars[i].print();
                }
            }
            break;
        }
        case 4: {
            cout << "Sort by: 1-Name 2-Year 3-Engine 4-Price: ";
            int opt;
            cin >> opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (opt) {
            case 1: service.sortCars(SortByName()); break;
            case 2: service.sortCars(SortByYear()); break;
            case 3: service.sortCars(SortByEngineVolume()); break;
            case 4: service.sortCars(SortByPrice()); break;
            default: cout << "Invalid sort option.\n"; continue;
            }
            cout << "Cars sorted.\n";
            break;
        }
        case 5: {
            cout << "Search by: 1-Name 2-Year 3-Engine 4-Price: ";
            int opt;
            cin >> opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt == 1) {
                string name;
                cout << "Enter name: ";
                getline(cin, name);
                auto results = service.searchCars([&](const Car& c) { return c.getCarName() == name; });
                for (const auto& car : results) car.print();
            }
            else if (opt == 2) {
                size_t year;
                cout << "Enter year: ";
                cin >> year;
                auto results = service.searchCars([&](const Car& c) { return c.getCarYear() == year; });
                for (const auto& car : results) car.print();
            }
            else if (opt == 3) {
                double engine;
                cout << "Enter engine volume: ";
                cin >> engine;
                auto results = service.searchCars([&](const Car& c) { return c.getCarEngineVolume() == engine; });
                for (const auto& car : results) car.print();
            }
            else if (opt == 4) {
                double price;
                cout << "Enter price: ";
                cin >> price;
                auto results = service.searchCars([&](const Car& c) { return c.getCarPrice() == price; });
                for (const auto& car : results) car.print();
            }
            else {
                cout << "Invalid search option.\n";
            }
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