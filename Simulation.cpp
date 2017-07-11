//Author: Melissa Lee 301300968
//CMPT 225 D100
//Simulation.cpp

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"
using namespace std;


bool arrival(Event *aEvent, PriorityQueue<Event> *events, Queue<Event> *line, bool available, int currentTime, Queue<int> *waitTimes){ //this function deals with the arrival of people
	events->dequeue();
	if (line->isEmpty() && available){ //if the line is empty and the teller is available we add a departure event.
	  int departTime = currentTime + (aEvent->getLength());
	  Event *newDepart = new Event(departTime, 'd', 0); //it takes no time to depart.
	  events->enqueue(*newDepart);
	  delete newDepart;//since event was copied and enqueue'd into events we delte this new event.
	  available = false;
	  return false;
	}
	else{ //if there is a bank line
	  line->enqueue(*aEvent); // we add this next person to the line
	  waitTimes->enqueue(currentTime);
	}
	return available;
	

}

bool departure(PriorityQueue<Event> *events, Queue<Event> *line, bool available, int currentTime, Queue<int> *waitTimes, float*waitPtr){
	events->dequeue();
	if(!(line->isEmpty())){ //if the line isn't empty

        try {//trying and catching to see if it throws an exception before peeking
          line->peek();
        }catch(EmptyDataCollectionException& e) {
          cout << "MyException caught: " << endl;
          cout << e.what() << endl;
        }
	  Event customer = line->peek();
	  line->dequeue();
	  int departTime = currentTime + (customer.getLength());//when will they depart
	  Event *newDepart = new Event(departTime, 'd', 0); //takes no time to depart
	  events->enqueue(*newDepart);
	  delete newDepart;
		
          try {//trying and catching to see if it throws an exception before peeking
             waitTimes->peek();
          }catch(EmptyDataCollectionException& e) {
            cout << "MyException caught: " << endl;
            cout << e.what() << endl;
          }

	  int prevTime = waitTimes->peek();//adding the time the customer spent in the line to the wait time variable.
	  waitTimes->dequeue();
 	  int timeInLine = currentTime - prevTime;
	  *waitPtr = *waitPtr+timeInLine;
	  return available;
	}
	else{return true;}

}


int main(){
  float wait = 0; //will hold the collective wait times of everyone in the line then will be divided by the amount of people for an average wait time
  float *waitPtr = &wait; //pointer to pass through functions to add more people's wait time
  int people = 0; //amount of people who arrive at the bank
  unsigned int i; //index variable
  bool available = true; //to tell if the bank teller is available or not
  int currentTime = 0; //keeps time

  Queue <Event> *line = new Queue<Event>; //queue of people in the bank line waiting for a teller
  PriorityQueue <Event> *events = new PriorityQueue<Event>; //priority queue of events
  Queue <int> *waitTimes = new Queue<int>; //queue of times that people arrive in the bank line and will be used to calculate wait times.


  while(true){
	if (cin.eof()){ break;}
	int n = 0;
	int r = 0;
	bool isSpace = false;
	string input = "";
	string inTime = "00";
	string inLen = "00";
	int time;
	int length;
	
	getline(cin >> ws, input);//dealing with input of arriving customers
	if (cin.eof()){ break;}
	for(i=0; i<input.length(); i++){
	  if(input[i]  == ' '){isSpace = true;}

	  else{
	    if (!isSpace){inTime[n++] = input[i];}
	    else{ inLen[r++] = input[i];}
	  }
	}

	if (n==1) time = inTime[0] - '0'; //this is so we don't tap into uninitialized parts of the string
	else{time = atoi(inTime.c_str());}

	if (r==1) length = inLen[0] - '0';
	else{length = atoi(inLen.c_str());}

	Event *newarrival = new Event(time, 'a', length);
	events->enqueue(*newarrival);
	delete newarrival;

	people++;

	//cout << "enqued arrival event" << endl;
	//events->printList();
	if (cin.eof()){ break;}//dealing with end of file

  }
	cout << "Simulation Begins" << endl;

  while(!(events->isEmpty())){//while there are people still arriving and departing from bank

   try {//trying and catching to see if it throws an exception before peeking
      events->peek();
   }catch(EmptyDataCollectionException& e) {
      cout << "MyException caught: " << endl;
      cout << e.what() << endl;
   }

    Event newEvent = events->peek(); //getting next event
    currentTime = (newEvent.getTime());

    if(newEvent.getType() == 'a'){ //dealing with an arrival event
        cout << "Processing an arrival event at time:     " << newEvent.getTime() << endl;
	if ((arrival(&newEvent, events, line, available, currentTime, waitTimes))){available = true;}
	else{ available = false;}
		}

    else if (newEvent.getType() == 'd'){//dealing with a departure event
	cout << "Processing a departure event at time:    " << newEvent.getTime() << endl;
	if ((departure(events, line, available, currentTime, waitTimes, waitPtr))){available = true;}
	else{ available = false;}
	}	
  }

  wait = wait/people;//dividing the total wait time of the customers by the amount of customers

  cout << "Simulation Ends" << endl;
  cout << endl;
  cout << endl;
  cout << "Final Statistics: " << endl;
  cout << "Total number of people processed:  " << people << endl;
  cout << "Average amount of time spent waiting:  " << wait << endl;

  delete line;//calling destructors for my queues
  delete events;
  delete waitTimes;

  return 0;
}










