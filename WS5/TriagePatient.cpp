#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket){
		symptoms = nullptr;
		nextTriageTicket++;
	}
	TriagePatient::~TriagePatient() {
		delete[] symptoms;
	}
	char TriagePatient::type() const {
		return 'T';
	}
	std::istream& TriagePatient::read(std::istream& istr) {
		if (fileIO() == true) {
			csvRead(istr);
		}
		else {
			delete[] symptoms;
			Patient::read(istr);
			cout << "Symptoms: ";
			string l;
			getline(istr, l, '\n');
			symptoms = new char[strlen(l.c_str()) + 1];
			strcpy(symptoms, l.c_str());
		}
		return istr;
	}
	std::ostream& TriagePatient::csvwrite(std::ostream& ostr) const{
		Patient::csvWrite(ostr);
		ostr << "," << symptoms;
		return ostr;
	}
	std::ostream& TriagePatient::write(std::ostream& ostr) const {
		if (fileIO() == true) {
			csvWrite(ostr);
		}else{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptons: " << symptoms << endl;
		}
		return ostr;
	}
	std::istream& TriagePatient::csvRead(std::istream& istr) {
		char d;
		delete[] symptoms;
		Patient::csvRead(istr);
		istr >> d;
		symptoms = getcstr(nullptr, istr);
		nextTriageTicket = number() + 1;
		return istr;
	}
}