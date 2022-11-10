/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 2, PART 1(LAB)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    /* TODO: read functions go here
    bool read(................) {
       return .....
    }
    bool read(................) {
       return .....
    }
    bool read(................) {
       return .....
    }
    */
    bool read(char* empname) {
        bool retval = false;
        retval = fscanf(fptr, "%[^\n]\n", empname);
        return retval;
    }
    bool read(int& empnum) {
        bool retval = false;
        retval = fscanf(fptr, "%d,", &empnum);
        return retval;
    }
    bool read(double& empsalary){
        bool retval = false;
        retval = fscanf(fptr, "%lf,", &empsalary);
        return retval;
    }
}