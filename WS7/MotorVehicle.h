/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 7
*/
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>

namespace sdds {
	class MotorVehicle {
		char m_licenseplatenum[9];
		char m_address[64];
		int m_yr;
	public:
		MotorVehicle(const char* licenseNum, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}
#endif // !SDDS_MOTORVEHICLE_H__