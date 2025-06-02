#include "UserInput.h"
using namespace std;

double UserInput::inputDouble()
{
    while (true) {
        string input;
        getline(cin, input);

        istringstream iss(input);
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

int UserInput::inputInt()
{
    while (true) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        int number;
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
	string input;
	getline(std::cin, input);
	if (!input.empty()) {
		return input;
	}
    else {
        cerr << "Invalid input. Please enter a non-empty name." << endl;
    }}

}

void UserInput::inputCarDetails()
{
    cout << "Enter car name: ";
    string name = inputString();

    std::cout << "Enter year: ";
    size_t year = inputInt();

    cout << "Enter engine volume: ";
    double engine = inputDouble();

    cout << "Enter price: ";
    double price = inputDouble();

    service.getRepository().addCar(Car(name, year, engine, price));
    cout << "Car added.\n";
}
