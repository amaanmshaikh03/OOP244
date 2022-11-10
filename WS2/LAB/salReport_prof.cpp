
// Workshop 2:
// Version: 1.0
// Date: 2021/1/25
// Author: Fardad Soleimanloo
// Description:
// salReport_prof.cpp
//
///////////////////////////////////////////////////
#include "Employee.h"
using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}
