#pragma once  
#include <iostream>  

struct Menu {
public:
static void clearInputBuffer() {  
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
}  

static void displayMainMenu() {  
    std::cout << "\n=== Car Dealership Menu ===\n";  
    std::cout << "1. Add car\n";  
    std::cout << "2. Remove car\n";  
    std::cout << "3. Show all cars\n";  
    std::cout << "4. Sort cars\n";  
    std::cout << "5. Search cars\n";  
    std::cout << "0. Exit\n";      
}

static void displayCarsMenu() {
    std::cout << "1. By name\n";
    std::cout << "2. By year\n";
    std::cout << "3. By engine volume\n";
    std::cout << "4. By price\n";
    std::cout << "0. Back to main menu\n";
}

static int option() {
    std::cout << "Select option: ";
	int option;
	std::cin >> option;
    clearInputBuffer();

	return option;
}

};