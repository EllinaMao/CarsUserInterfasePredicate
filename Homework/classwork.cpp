// classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Создайте приложение для работы автосалона. Необходимо хранить информацию о продаваемых автомобилях (название, год выпуска, объем двигателя, цену). Реализуйте интерфейс для добавления данных, удаления данных, отображения данных, сортировке данных по различным параметрам, поиску данных по различным параметрам. При реализации используйте контейнеры, функторы и алгоритмы

*/
#include <iostream>
#include <vector>

#include "Car.h"
#include "CarRepository.h"
#include "CarService.h"
#include "UserInterface.h"
using namespace std;

int main() {
    CarRepository repo;
    CarService service(repo);
    UserInterface ui(service);
    try{
    ui.run();
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
	}
    return 0;
}
