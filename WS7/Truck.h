/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 7
*/
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"
namespace sdds
{
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_load;
	public:
		Truck(const char* licensePlate, int year, float capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& vehicle);
	std::istream& operator>>(std::istream& in, Truck& vehicle);
}
#endif // !SDDS_TRUCK_H__
