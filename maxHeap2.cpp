/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : maxHeap2 Implementation
*/

#include "maxHeap2.h"
#include <string>
#include <iostream>
#include <fstream>

// Default constructor
maxHeap::maxHeap(): numPatients(0), size(0) {
    patients = NULL;
}

maxHeap::~maxHeap(){
    if(patients)
        delete [] patients;

}
bool maxHeap::heapIsEmpty() const {
	return (numPatients == 0);
}

bool maxHeap::heapInsert(const Patient& newPatient) {
    if(numPatients == size){
        if(patients == NULL){//when the patients array didn't constructed
            size = 10;
            patients = new Patient[size];
        }
        else{//when the size is not enough
            size = size*2;//double the size
            Patient* temp = patients;
            patients = new Patient[size];//new array with size*2
            for(int i = 0; i < numPatients; i++)//copy items from old item
                patients[i] = temp[i];
            delete [] temp;//deallocate old array
        }
    }
	// Place the new item at the end of the heap
	patients[numPatients] = newPatient;
	// Trickle new item up to its proper position
	int place = numPatients;
	int parent = (place - 1)/2;
	while ( (place > 0) && (comparePatient(patients[place],patients[parent]))) {
		Patient temp = patients[parent];
		patients[parent] = patients[place];
		patients[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++numPatients;
 	return true;
}

bool maxHeap::heapDelete(Patient& rootPatient){
	if (heapIsEmpty()){
		cout<<("Heap empty");
		return false;
    }
    else
    {
		rootPatient = patients[0];
		patients[0] = patients[--numPatients];
		heapRebuild(0);
	}

	if(numPatients < (int)(size/2)){//number of patients less than half of the array size
        size = (int)size/2;
        Patient* temp = patients;
        patients = new Patient[size];//create new array with size/2
        for(int i = 0; i < numPatients; i++)//copy items from old array
            patients[i] = temp[i];
        delete [] temp;//deallocate old array
    }
	return true;
}

void maxHeap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < numPatients ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < numPatients) && (comparePatient(patients[rightChild],patients[child]) ))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( comparePatient(patients[child],patients[root]) ) {
			Patient temp = patients[root];
			patients[root] = patients[child];
			patients[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}

bool maxHeap::comparePatient(const Patient& p1, const Patient& p2){
    if(p1.getPriorNum() > p2.getPriorNum())
        return true;
    else if(p1.getPriorNum() == p2.getPriorNum())//if priorities are same
        return p1.getArrTime() < p2.getArrTime();//the one who came first will be more prior
    else
        return false;
}

double maxHeap::getWaitingTime(Patient* patientQueue, const int numP, const int numDoc, bool print){
    Doctor docs[numDoc];
    int wTime = 0;
    double avrTime = 0.;
    bool finish = false;
    int pFinish = 0;
    int time = 0;
    //create doctors
    for(int i = 0; i < numDoc; i++){
        docs[i].setId(i);
        docs[i].setAvailableTime(0);
        docs[i].setIsAvailable(true);
    }

    while(!finish){
        for(int m = 0; m < numP; m++){
            if(patientQueue[m].getArrTime() == time){
                heapInsert(patientQueue[m]);//insert arriving patients to the heap
            }
        }
        for( int k = 0; k < numDoc; k++){
            //update doctors
            if(docs[k].getAvailableTime() == time)
                    docs[k].setIsAvailable(true);
            //update patients
            if(!heapIsEmpty()&&(patients[0].getArrTime()<= time)&&(docs[k].isAvailable()))
            {
                docs[k].setAvailableTime(time+ patients[0].getExTime());//update doctor according to the patient exTime
                docs[k].setIsAvailable(false);//doctor[k] is not available anymore
                wTime = (time - patients[0].getArrTime());//calculate waiting time
                avrTime += (double)wTime;
                if(print)
                    cout<< "Doctor " << k << " takes patient " << patients[0].getId() << " at minute " << time <<" (wait: " << wTime <<" mins)"<<endl;
                pFinish++;//increment the number of patients that has seen doctor

                heapDelete(patients[0]);//delete patient from the heap
            }
        }
        if(pFinish == numP){//when all the patients done get out from loop
            finish = true;
        }
        time++;//increment time
    }
    return (avrTime/numP);
}
int maxHeap::calcNumDoc(Patient* patientQueue, const int numPatients, double maxWait){
    double wTime = 0.;
    for(int i = 1; i < numPatients; i++ ){//loop until finding proper waiting time
        wTime = getWaitingTime(patientQueue, numPatients, i, false);
        if(wTime <= maxWait){
            return i;
        }
    }
    return -1;//error
}

void maxHeap::printSimulation(Patient* patientQueue, const int numPatients, const int numDoc){
    cout << "Simulation with "<< numDoc << " doctors:" <<endl;
    double wTime = getWaitingTime(patientQueue, numPatients, numDoc, true);
    cout << "Average Waiting Time : " << wTime << " minutes." << endl;
}

