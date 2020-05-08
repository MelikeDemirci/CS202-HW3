/**
* Title : HW3
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 3
* Description : simulator.cpp
*/

#if defined(M)
    #include "maxHeap1.h"
#else
    #include "maxHeap2.h"
#endif // defined

#include <iostream>
#include <fstream>
using namespace std;

void simulate( const string fileName, const int avrTime) {
    Patient* pArr;
    int id = 0;
    int pNum = 0;
    int arrTime = 0;
    int exTime = 0;
    int numP = 0;

    ifstream inFile;
    inFile.open((fileName).c_str());
    if (!inFile) {
        cout << "Unable to open file";
    }
    else{
        inFile >> numP;
        pArr = new Patient[numP];
        for (int i=0; i < numP; i ++){
            inFile >> id;
            inFile >> pNum;
            inFile >> arrTime;
            inFile >> exTime;
            Patient p(id, pNum, arrTime, exTime);
            pArr[i] = p;
        }
    }

    maxHeap h1; //create maxHeap
    const int numDoc = h1.calcNumDoc(pArr,numP, avrTime); //calculate required number of doctors for given max avr waiting time

    if(numDoc == -1){
        cout << "Error Occured" << endl;
    }
    else{
        cout<<"Minimum number of doctors required: " << numDoc<< endl;
        h1.printSimulation(pArr, numP, numDoc);//print simulation result
    }

    delete [] pArr;//deallocation of pArr
}
int main(int argc, char* argv[]){
    int avrTime = stoi(argv[2], 0, 10);
	simulate(argv[1], avrTime);
    return 0;
}




