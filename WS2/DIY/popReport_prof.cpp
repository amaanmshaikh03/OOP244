
// Workshop 2 (DIY):
// Version: 1.0
// Date: 2021/1/25
// Author: Fardad Soleimanloo
// Description:
// popReport_prof.cpp
//
///////////////////////////////////////////////////
#include "Population.h"
using namespace sdds;
int main() {
   if (load("PCpopulationsComplete.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}
