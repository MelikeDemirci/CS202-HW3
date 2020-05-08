/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : Patient Header File
*/

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
using namespace std;

class Patient {
private:
	int id;
	int priorNum;
	int arrTime;
	int exTime;

public:
	Patient();
    Patient(int theId, int thePriorNum, int theArrTime, int theExTime);
    void operator=(const Patient &right);

    void setId( const int& theId);
    int getId() const ;

    void setPriorNum( const int& thePriorNum);
    int getPriorNum() const ;

    void setArrTime(const int& theArrTime);
    int getArrTime() const ;

    void setExTime( const int& theExTime);
    int getExTime() const ;

};
#endif

