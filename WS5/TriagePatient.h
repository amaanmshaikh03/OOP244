
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* symptoms;
	public:
		TriagePatient();
		~TriagePatient();
		char type() const;
		std::istream& read(std::istream& istr);
		std::ostream& csvwrite(std::ostream& istr) const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& csvRead(std::istream& istr);
	};
}
#endif // !SDDS_TRIAGEPATIENT_H

