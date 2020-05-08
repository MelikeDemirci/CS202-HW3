/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : Doctor Header File
*/

#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
using namespace std;

class Doctor {
private:
	int id;
	int availableTime;
	bool available;

public:
	Doctor();
    Doctor(int theId, int theAvailableTime, bool isAvailable);
    void operator=(const Doctor &right);

    void setId( const int& theId);
    int getId() const ;

    void setAvailableTime( const int& theAvailableTime);
    int getAvailableTime() const ;

    void setIsAvailable( const bool& theIsAvailable);
    bool isAvailable() const ;

};
#endif


