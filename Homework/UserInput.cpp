#include "UserInput.h"
using namespace std;

double UserInput::inputDouble()
{
    while (true) {
        string userInput; 
        getline(cin, userInput);

        istringstream iss(userInput);
        double volume;
        char extra;

        if (iss >> volume && !(iss >> extra) && volume > 0) {
            return volume;
        }
        else {
            cerr << "Invalid input. Please enter a positive number." << endl;
        }
    }
}

size_t UserInput::inputSize_t()
{
    while (true) {
        string userInput; 
        getline(cin, userInput);
        istringstream iss(userInput);
        size_t number;
        char extra;
        if (iss >> number && !(iss >> extra) && number > 0) {
            return number;
        }
        else {
            cerr << "Invalid input. Please enter a positive integer." << endl;
        }
    }
}

std::string UserInput::inputString()
{
    while (true) {
        string userInput; 
        getline(std::cin, userInput);
        if (!userInput.empty()) {
            return userInput;
        }
        else {
            cerr << "Invalid input. Please enter a non-empty name." << endl;
        }
    }
}


void UserInput::inputCarDetails()
{
    cout << "Enter car name: ";
    string name = inputString();

    std::cout << "Enter year: ";
    size_t year = inputSize_t();

    cout << "Enter engine volume: ";
    double engine = inputDouble();

    cout << "Enter price: ";
    double price = inputDouble();

    service.getRepository().addCar(Car(name, year, engine, price));
    cout << "Car added.\n";
}
