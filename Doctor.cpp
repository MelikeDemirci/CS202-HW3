/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : Doctor Implementation
*/

#include   "Doctor.h"

Doctor::Doctor(){
    this->id = 0;
    this->availableTime = 0;
    this->available = true;
}

Doctor::Doctor(int theId, int theAvailableTime, bool theAvailable):id(0),availableTime(0), available(true){
    this->id = theId;
    this->availableTime = theAvailableTime;
    this->available = theAvailable;
}

void Doctor::operator =(const Doctor &right){
    if(&right != this){
        id = right.getId();
        availableTime = right.getAvailableTime();
        available = right.isAvailable();
    }
}

void Doctor::setId( const int& theId){
    id = theId;
}


int Doctor::getId() const{
    return id;
}

void Doctor::setAvailableTime( const int& theAvailableTime){
    availableTime = theAvailableTime;
}

int Doctor::getAvailableTime() const{
    return availableTime;
}

void Doctor::setIsAvailable(const bool& theAvailable){
    available = theAvailable;
}


bool Doctor::isAvailable() const{
    return available;
}






