#include "UserInput.h"

double UserInput::inputCarEngineVolume()
{
	while(true){
		std::cout << "Enter the car engine volume in liters: ";
		double volume;
		std::cin >> abc.volume;
		if (std::cin.fail() || volume <= 0) {
			std::cin.clear(); // Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input. Please enter a positive number." << std::endl;
		} else {
			return volume; // Valid input, return the volume
		}
	}

}
