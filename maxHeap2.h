/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : maxHeap2 Header File
*/
#ifndef MAXHEAP2_H
#define MAXHEAP2_H

#include "Patient.h"
#include "Doctor.h"
#include <iostream>
#include <exception>
using namespace std;

class maxHeap {

public:
	maxHeap();	// default constructor
    ~maxHeap(); //destructor
	bool heapIsEmpty() const;
	bool heapInsert(const Patient& newPatient);
	bool heapDelete(Patient& rootPatient);

    bool comparePatient(const Patient& p1, const Patient& p2);//compare patients priorities
    double getWaitingTime(Patient* patientQueue, const int numPatients, const int numDoc, bool print);//calculates avr waiting time for given number of doctors
    int calcNumDoc(Patient* patientQueue, const int numPatients, double maxWait);//finds the required number of doctors
    void printSimulation(Patient* patientQueue, const int numPatients, const int numDoc);//prints the simulation result
protected:
	void heapRebuild(int root);		//rebuilds heap
private:
	Patient* patients;	// array of heap items
	int      numPatients;   // number of heap items
	int          size;      //size of the heap array
};

#endif


