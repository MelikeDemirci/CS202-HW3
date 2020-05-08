all: 
	g++ -std=c++1y -DM simulator.cpp maxHeap1.cpp Patient.cpp Doctor.cpp -o simulator_Q1
	g++ -std=c++1y simulator.cpp maxHeap2.cpp Patient.cpp Doctor.cpp -o simulator_Q2


