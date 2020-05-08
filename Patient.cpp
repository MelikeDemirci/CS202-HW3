/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : Patient Implementation
*/

#include   "Patient.h"

Patient::Patient(){
    this->id = 0;
    this->priorNum = 0;
    this->arrTime = 0;
    this->exTime = 0;
}

Patient::Patient(int theId, int thePriorNum, int theArrTime, int theExTime):id(0),priorNum(0), arrTime(0), exTime(0){
    this->id = theId;
    this->priorNum = thePriorNum;
    this->arrTime = theArrTime;
    this->exTime = theExTime;
}

void Patient::operator =(const Patient &right){
    if(&right != this){
        id = right.getId();
        priorNum = right.getPriorNum();
        arrTime = right.getArrTime();
        exTime = right.getExTime();
    }
}

void Patient::setId( const int& theId){
    id = theId;
}


int Patient::getId() const{
    return id;
}

void Patient::setPriorNum( const int& thePriorNum){
    priorNum = thePriorNum;
}


int Patient::getPriorNum() const{
    return priorNum;
}

void Patient::setArrTime(const int& theArrTime){
    arrTime = theArrTime;
}


int Patient::getArrTime() const{
    return arrTime;
}

void Patient::setExTime( const int& theExTime){
    exTime = theExTime;
}


int Patient::getExTime() const{
    return exTime;
}



