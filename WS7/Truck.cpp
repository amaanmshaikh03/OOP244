/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 7
*/#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Truck.h"
#include "MotorVehicle.h" 

using namespace std;
namespace sdds
{
	Truck::Truck(const char* licensePlate, int year, float capacity, const char* address) : MotorVehicle(licensePlate, year) {
		m_capacity = capacity;
		m_load = 0;
		MotorVehicle::moveTo(address);
	}


	bool Truck::addCargo(double cargo) {
		bool ok = false;

		if (m_load < m_capacity) {
			if ((m_load + cargo) <= m_capacity) {
				m_load += cargo;
			}
			else {
				m_load = m_capacity;
			}
			ok = true;
		}
		return ok;
	}


	bool Truck::unloadCargo() {
		bool ok = false;
		if (m_load > 0) {
			m_load = 0;
			ok = true;
		}
		return ok;
	}


	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << m_load << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_load;
		return in;
	}


	std::ostream& operator<<(std::ostream& os, const Truck& vehicle) {
		return vehicle.write(os);
	}

	std::istream& operator>>(std::istream& in, Truck& vehicle) {
		return vehicle.read(in);
	}
}