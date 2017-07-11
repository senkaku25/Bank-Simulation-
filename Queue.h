//Author: Melissa Lee
//Queue.h
//head is back, tail is front of the line

#pragma once
#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Node.h"
using namespace std;

template <class ElementType>
class Queue {

private:


Node<ElementType> *head;//the head will be the end of the queue.
int elementCount;


public:

  Queue();
  ~Queue();


// Let's put our constructor(s) and destructor (if any) ***here***.

/******* Public Interface - START - *******/

   // Description: Returns the number of elements in the Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Adds newElement to the "back" of this Queue
   //              (not necessarily the "back" of its data structure) and
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const ElementType& newElement);

   // Description: Removes the element at the "front" of this Queue
   //              (not necessarily the "front" of its data structure) and
   //              returns "true" if successful, otherwise "false".
   // Precondition: This Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns (a copy of) the element located at the "front" of this Queue.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Queue class.

//void printList();

}; // end Queue
template <class ElementType>
Queue<ElementType>::Queue(){
	head = NULL;
	elementCount = 0;
	


}


template <class ElementType>
Queue<ElementType>::~Queue(){
	Node<ElementType> *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL){
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	head = NULL;
	elementCount = 0;


}


template <class ElementType>
int Queue<ElementType>::getElementCount() const{

	return elementCount;

}


template <class ElementType>
bool Queue<ElementType>::isEmpty() const{
	if (elementCount == 0) return true;
	return false;
}

template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement){//i'm appending to the head (end of the line)
	Node<ElementType> *p = new Node<ElementType>; //temporary node
	bool result = false;

	if ( p != NULL ) {
		// Assign appropriate values to the new node
		p -> data = newElement;
		//p -> transaction = newElement.transaction;
		p -> next = head;
		// Make the head point to the new node
		head = p;
		elementCount++;
		result = true;
	}
	return result;
}

template <class ElementType>
bool Queue<ElementType>::dequeue(){ //dequeue off the tail
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
		temp->next = NULL;
		result = true;
		elementCount--;
	  }
	return result;
}

template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException){
	int i;
	if (isEmpty()) throw EmptyDataCollectionException("peek() called with empty queue.");
	Node<ElementType> *p = head;
	for(i=0;i<elementCount-1;i++){
			p=p->next;
		}
	return p->data;

}
/*
template <class ElementType>
void Queue<ElementType>::printList(){
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
