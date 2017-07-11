//PriorityQueue.h
//Author: Melissa Lee
//CMPT 225
//Singlyheaded Singly linked List
//the head is the back, tail is front of line.

#pragma once
#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Node.h"
using namespace std;

template <class ElementType>
class PriorityQueue {

private:


Node<ElementType> *head;//the head will be the end of the queue.
int elementCount;



public:

  PriorityQueue();
  ~PriorityQueue();
// Let's put our constructor(s) and destructor (if any) ***here***.

/******* Public Interface - START - *******/

   // Description: Returns the number of elements in the Priority Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
   // Time Efficiency: O(n)
   bool enqueue(const ElementType& newElement);

   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns (a copy of) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Priority Queue class.

//void printList();


}; // end PriorityQueue
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
	head = NULL;
	elementCount = 0;
	//averagetime = 0;


}


template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
	Node<ElementType> *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL){
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	//delete head;
	p = NULL;
	head = NULL;
	elementCount = 0;


}


template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const{

	return elementCount;

}


template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
	if (elementCount == 0) return true;
	return false;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){//enqueing the customer who got to the bank first (lowest time number) to the front of the line. 
	Node<ElementType> *p = new Node<ElementType>; //temporary node
	Node<ElementType> *temp = head;//temporary node
	Node<ElementType> *before;//temporary node
	bool result = false;

	if ( p != NULL ) {
	  p -> data = newElement;

	  if (elementCount==0){head = p;}
	  else if (elementCount==1){
			
			if ((head->data).getTime() > (p->data).getTime()){ //head > p
				head->next = p;}
			else{	//head < p
				p->next = head;
				head = p;
			}
	  }
	  else{
	  	while((temp->next != NULL) && (temp->data).getTime() > (p->data).getTime()){
		  before = temp;
		  temp = temp->next;
		}
		if (temp->next == NULL){
			if ((temp->data).getTime() < (p->data).getTime()){
			  p->next = temp;
			  before->next = p;
			}
			else{temp->next = p;}
		}
		else if(temp == head){
			p->next = head;
			head = p;
		}

		else{
			p->next =temp;
			before->next = p;
			}
	   }
		elementCount++;
		result = true;
	}
	return result;
}

template <class ElementType>
bool PriorityQueue<ElementType>::dequeue(){ //dequeue off the tail
	int i;
	Node<ElementType> *p = head;
	Node<ElementType> *temp;
	bool result = false;
	if(elementCount == 0) result = false;
	if(elementCount == 1){
		delete p;
		head = NULL;
		result = true;
		elementCount--;
	}
	else{
		for(i=0;i<elementCount-1;i++){
			p=p->next;
		}
		temp = p;
		p = p->next;
		delete p;
		p = NULL;
		temp->next = NULL;
		result = true;
		elementCount--;
	  }
	return result;
}

template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException){
	int i;
	if (isEmpty()) throw EmptyDataCollectionException("peek() called with empty priority queue.");

	Node<ElementType> *p = head;
	for(i=0;i<elementCount-1;i++){
			p=p->next;
		}
	return p->data;

}
/*
template <class ElementType>
void PriorityQueue<ElementType>::printList(){
  cout << "printing datas..." << endl;
	Node<ElementType> *p = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << "(";
		cout << (p -> data).getTime() << "," ;
		cout << (p -> data).getType() << ",";
		cout << (p -> data).getLength() << ","; // Print data
		cout << ")";
		p = p -> next; // Go to next Node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}" << endl; // Don't print a newline - it might not be wanted
} */
