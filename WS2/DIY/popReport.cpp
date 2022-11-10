// Workshop 2: 
// Version: 0.9
// Date: 2021/01/23
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
/////////////////////////////////////////////
/*
Name: Mohammedamaan Shaikh
StudentID: 157304197
Email: mishaikh3@myseneca.ca
Workshop 2 DIY
*/

#include "Population.h"
using namespace sdds;
int main() {
    if (load("PCpopulations.csv")) {
        display();
    }
    deallocateMemory();
    return 0;
}