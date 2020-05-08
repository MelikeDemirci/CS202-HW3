#ifndef MAXHEAP1_H
#define MAXHEAP1_H

#include "Patient.h"
#include "Doctor.h"
#include <iostream>
#include <exception>
using namespace std;

/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : maxHeap1 Header File
*/

const int MAX_HEAP = 2000;

class maxHeap {

public:
	maxHeap();// default constructor (copy constructor and destructor are supplied by the compiler)
    bool heapIsEmpty() const;
	bool heapInsert(const Patient& newPatient);
	bool heapDelete(Patient& rootPatient);

    bool comparePatient(const Patient& p1, const Patient& p2);//compare patients priorities
    double getWaitingTime(Patient* patientQueue, const int numPatients, const int numDoc, bool print);//calculates avr waiting time for given number of doctors
    int calcNumDoc(Patient* patientQueue, const int numPatients, double maxWait);//finds the required number of doctors
    void printSimulation(Patient* patientQueue, const int numPatients, const int numDoc);//prints the simulation result
protected:
	void heapRebuild(int root);		//rebuilds the heap
private:
	Patient patients[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items
};

#endif

