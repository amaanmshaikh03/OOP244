/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 6, PART 2(DIY)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Stats.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	void Stats::setEmpty() {
			zero = 0;
			delete[] s_num;
			s_num = nullptr;
			delete[] s_filename;
			s_filename = nullptr;
			s_noofnums = 0;
	}
	void Stats::setFilename(const char* fname, bool isCopy) {
		delete[] s_filename;
		s_filename = nullptr;
		if (isCopy == false) {
			s_filename = new char[strLen(fname) + 1];
			strCpy(s_filename, fname);
		}
		else {
			s_filename = new char[strLen(fname) + 3];
			strCpy(s_filename, "C_");
			strCat(s_filename, fname);
		}
	}
	void Stats::setNoOfNums() {
		ifstream fin;
		fin.open(name());
		string l;
		if (fin.is_open()) {
			do {
				s_noofnums++;
			} while (getline(fin, l, ','));
		}
		else {
			setEmpty();
		}
		fin.close();
	}
	void Stats::loadnum() {
		int a = 0;
		if (s_filename != nullptr) {
			delete[] s_num;
			s_num = nullptr;
			s_num = new double[size()] ;
			ifstream fin;
			fin.open(name());
			while (fin >> s_num[a]) {
				fin.ignore(3000, ',');
				a++;
			}
			s_noofnums = a;
			fin.close();
		}
	}
	void Stats::saveAs(const char* fileName)const {
		ofstream fin;
		fin.open(fileName);
		int precision = 4;
		if (s_precision != 0) {
			precision = s_precision;
		}
		for (unsigned i = 0; i < size(); i++) {
			if ((i + 1) < size()) {
				fin << fixed;
				fin << setprecision(4) << s_num[i] << ",";
			}
			else {
				fin << setprecision(precision) << s_num[i];
			}
		}
		fin.close();
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		zero = 0;
		s_num = nullptr;
		s_filename = nullptr;
		s_noofnums = 0;
		s_noofcol = noOfColumns;
		s_precision = precision;
		s_columnwidth = columnWidth;
	}
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		zero = 0;
		s_num = nullptr;
		s_filename = nullptr;
		s_noofnums = 0;
		s_noofcol = noOfColumns;
		s_precision = precision;
		s_columnwidth = columnWidth;
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfNums();
			loadnum();
		}
	}
	Stats::Stats(const Stats& incomingfile) {
		zero = 0;
		s_columnwidth = incomingfile.s_columnwidth;
		s_noofcol = incomingfile.s_noofcol;
		s_precision = incomingfile.s_precision;
		s_filename = nullptr;
		s_num = nullptr;
		s_noofnums = 0;
		if (incomingfile.s_filename != nullptr) {
			setFilename(incomingfile.name(), true);
			incomingfile.saveAs(name());
			setNoOfNums();
			loadnum();
		}
	} 
	Stats& Stats::operator=(const Stats& incomingfile) {
		s_precision = incomingfile.s_precision;
		s_columnwidth = incomingfile.s_columnwidth;
		s_noofcol = incomingfile.s_noofcol;
		if (incomingfile.operator bool() && bool() == false) {
			delete[] s_num;
			s_num = nullptr;
			incomingfile.saveAs(name());
			setNoOfNums();
			loadnum();
		}
		return *this;
	}
	Stats::~Stats() {
		delete[] s_num;
		s_num = nullptr;
		delete[] s_filename;
		s_filename = nullptr;
	}
	Stats::operator bool()const {
		bool ok = false;
		if (s_num != nullptr) {
			ok = true;
		}
		return ok;
	}
	const char* Stats::name()const {
		return s_filename;
	}
	unsigned Stats::size()const {
		return  s_noofnums;
	}
	unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
		unsigned i = 0;
		int a = 0;
		unsigned noofcol = 0;
		if (bool() == false && s_filename != nullptr){
			ostr << endl;
			while (i < size()){
				for (i = i; i < size(); i++){
					if (s_num[i] >= min && s_num[i] <= max){
						a++;
						noofcol++;
						ostr << fixed << setw(s_columnwidth) << setprecision(s_precision) << s_num[i];
						if (noofcol == s_noofcol){
							ostr << endl;
							noofcol = 0;
						}
					}
				}
				ostr << endl;
			}
			ostr << "Total of " << a << " numbers are between -12345 and 31343" << endl;
		}
		return a;
	}
	std::ostream& Stats::view(std::ostream& ostr)const {
		unsigned a = 0;
		if (bool() == false && s_filename != nullptr) {
			ostr << s_filename << endl << setw(strLen(name())) << setfill('=') << '=' << endl << endl;
			ostr << setfill(' ');
			while (a < size()) {
				for (unsigned i = 0; i < s_noofcol && a < size(); i++) {
					ostr << fixed << setw(s_columnwidth) << setprecision(s_precision) << s_num[a]; 
					a++;
				}
				cout << endl;
			}
			ostr << "Total of " << a << " listed!" << std::endl;
		}
		return ostr;
	}
	
	std::istream& Stats::getFile(std::istream& istr) {
		delete[] s_filename;
		s_filename = nullptr;
		delete[] s_num;
		s_num = nullptr;
		string input;
		istr >> input;
		cin.ignore();
		setFilename(input.c_str());
		setNoOfNums();
		loadnum();
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Stats& text) {
		text.view(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Stats& text) {
		text.getFile(istr);
		return istr;
	}
	double& Stats::operator[](unsigned idx){
		double* a = &zero;
		if (*this) {
			a = &s_num[idx % size()];
		}
		return *a;
	}
	double Stats::operator[](unsigned idx) const{
		double a = 0;
		if (*this) {
			a = s_num[idx % size()];
		}
		return a;
	}
	void Stats::sort(bool ascending)
	{
		double a;
		if (ascending == true){
			for (unsigned i = 0; i < size(); i++){
				for (unsigned j = i + 1; j < size(); j++){
					if (s_num[i] > s_num[j]){
						a = s_num[i];
						s_num[i] = s_num[j];
						s_num[j] = a;
					}
				}
			}
		}
		else{
			for (unsigned i = 0; i < size(); i++){
				for (unsigned j = i + 1; j < size(); j++){
					if (s_num[j] > s_num[i]){
						a = s_num[i];
						s_num[i] = s_num[j];
						s_num[j] = a;
					}
				}
			}
		}
	}
}