/*
Name: Mohammedamaan Shaikh
StudentID: 157304197
Email: mishaikh3@myseneca.ca
Workshop 2 DIY
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {

    int numbers;
    Population* populations;
    void sort()
    {
        int i, j;
        Population temp;
        for (i = numbers - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (populations[j].noofpopulation > populations[j + 1].noofpopulation)
                {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }
        bool load(Population& populations) {
        bool ok = false;
        char code[10];
        code[3] = '\0';
        int totalnumpop = 0;
        int m = 0;
                if (read(code) && read(totalnumpop)) {
                    m = strLen(code) + 1;
                    populations.code = new char[m];
                    strCpy(populations.code, code);
                    populations.noofpopulation = totalnumpop;
                    ok = true;
                }
        return ok;
    }
    bool load(const char* filename) {
        bool ok = false;
        if (openFile(filename)) {
            numbers = noOfRecords() + 1;          
            populations = new Population[numbers];
            for (int i = 0;i < numbers;i++) {
                if (load(populations[i]) == false) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                    break;
                }
                else {
                    ok = true;
                }
            }
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        closeFile();
        return ok;
    }
    int display(const Population& populations){
        cout << populations.code << ":  " << populations.noofpopulation << endl;
        int a = populations.noofpopulation;
        return a;
    }

    void display()
    {
        int total = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < numbers; i++)
        {
            cout << i + 1 << "- ";
            
            total = total + display(populations[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }
    void deallocateMemory() {
        delete[] populations;
    }
       
}
