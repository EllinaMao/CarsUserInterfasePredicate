#pragma once  
#include <iostream>  

class Menu {

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
    std::cout << "Select option: ";  
}

static void displayCarsMenu() {
    std::cout << "1. By price\n";
    std::cout << "2. By year\n";
    std::cout << "3. By brand\n";
    std::cout << "0. Back to main menu\n";
    std::cout << "Select option: ";
}



};