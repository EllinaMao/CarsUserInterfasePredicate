// classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Создайте приложение для работы автосалона. Необходимо хранить информацию о продаваемых автомобилях (название, год выпуска, объем двигателя, цену). Реализуйте интерфейс для добавления данных, удаления данных, отображения данных, сортировке данных по различным параметрам, поиску данных по различным параметрам. При реализации используйте контейнеры, функторы и алгоритмы
Step-by-step Plan
1.	Define Car class (SRP)
•	Fields: name, year, engineVolume, price.
•	Methods: getters/setters, operator overloads if needed.


2.	Create CarRepository (SRP)
•	Uses std::vector<Car> for storage.
•	Methods: addCar, removeCar, getAllCars.


3.	Implement sorting/searching functors/strategies (OCP, ISP)
•	Functors for sorting by name, year, engine volume, price.
•	Functors for searching by parameters.


4.	Create CarService (SRP, DIP)
•	Methods: sortCars, searchCars.
•	Accepts sorting/searching strategies as parameters.


5.	Design UserInterface (SRP)
•	Menu for add, remove, display, sort, search.
•	Interacts with CarService and CarRepository.


6.	Connect everything in main()
•	Loop for user interaction.
*/
#include <iostream>
#include <vector>
using namespace std;

#include "Car.h"
#include "CarRepository.h"
#include "CarService.h"
#include "UserInterface.h"

int main() {
    CarRepository repo;
    CarService service(repo);
    UserInterface ui(service);
    ui.run();
    return 0;
}
