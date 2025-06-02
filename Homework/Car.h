#pragma once
#include <iostream>
#include <chrono>
#include <vector>
/*

Создайте приложение для работы автосалона. Необходимо хранить информацию о продаваемых автомобилях (название, год выпуска, объем двигателя, цену). Реализуйте интерфейс для добавления данных, удаления данных, отображения данных, сортировке данных по различным параметрам, поиску данных по различным параметрам. При реализации используйте контейнеры, функторы и алгоритмы

*/
class Car {
private:
	std::string mCarName;
	size_t mCarYear;
	double mCarEngineVolume;
	double mCarPrice;
public:
	Car() = default;
	Car(const std::string& carName, size_t carYear, double carEngineVolume, double carPrice)
		: mCarName(carName), mCarYear(carYear), mCarEngineVolume(carEngineVolume), mCarPrice(carPrice) {
	}
	Car(const Car& other) = default;
	Car(Car&& other) noexcept;

	Car& operator=(const Car& other) = default;
	Car& operator=(Car&& other) noexcept;

	const std::string& getCarName() const { return mCarName; }
	const size_t& getCarYear() const { return mCarYear; }
	const double& getCarEngineVolume() const { return mCarEngineVolume; }
	const double& getCarPrice() const { return mCarPrice; }

	void setCarName(const std::string& carName) { mCarName = carName; }
	void setCarYear(size_t carYear) { mCarYear = carYear; }
	void setCarEngineVolume(double carEngineVolume) { mCarEngineVolume = carEngineVolume; }
	void setCarPrice(double carPrice) { mCarPrice = carPrice; }

	friend std::ostream& operator<<(std::ostream& os, const Car& car) {
		os << "Car Name: " << car.mCarName << ", Year: " << car.mCarYear
		   << ", Engine Volume: " << car.mCarEngineVolume << ", Price: " << car.mCarPrice;
		return os;
	}
	
	void print() const {
		std::cout << *this << std::endl;
	}

};