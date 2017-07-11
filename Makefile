all: sApp

sApp: Queue.h Node.h PriorityQueue.h EmptyDataCollectionException.o Event.o Simulation.o
	g++ -Wall -std=c++11 -o sApp EmptyDataCollectionException.o Event.o Simulation.o

test.o: test.cpp 
	g++ -c test.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

Simulation.o: Simulation.cpp
	g++ -c Simulation.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f sApp *.o
