//test.cpp
//just a test file
//author: Melissa Lee
//will not run or compile with the assignment. this is just to test out some 

#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"

int main(){
	Event *add1 = new Event(3,'a',2);
	Event *add2 = new Event(2,'a',2);
	Event *add3 = new Event(5,'a',2);
	Event *add4 = new Event(4,'a',2);	

	cout << "queue test " << endl;
	Queue <Event> *Q = new Queue<Event>;

	if (Q->enqueue(*add1)){
		cout << "added" << endl;
	}
	
	if (Q->enqueue(*add2)){
		cout << "added" << endl;
	}
	if (Q->enqueue(*add3)){
		cout << "added" << endl;
	}
	if (Q->enqueue(*add4)){
		cout << "added" << endl;
	}
	
	Q->printList();

	cout << "priority queue test" << endl;

	PriorityQueue <Event> *PQ = new PriorityQueue<Event>;

	if (PQ->enqueue(*add1)){
		cout << "added" << endl;
	}
	if (PQ->enqueue(*add2)){
		cout << "added" << endl;
	}
	if (PQ->enqueue(*add3)){
		cout << "added" << endl;
	}
	if (PQ->enqueue(*add4)){
		cout << "added" << endl;
	}

	PQ->printList();

	delete Q;
	delete PQ;


return 0;
}
