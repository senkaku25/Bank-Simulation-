//Node.h
//Author:Melissa Lee 301300968
//CMPT 225 D100
//holds the element type information

#pragma once

#include <iostream>
#include <string.h>
using namespace std;

template <class ElementType>
class Node {



public:
  ElementType data;
  Node*next;
  Node();
  ~Node();
  Node(ElementType Sdata);
  Node(ElementType Sdata, Node*nextNode);



};


template <class ElementType>
Node<ElementType>::Node(){
	//not setting data because we don't know the element type
	next = NULL;
}

template <class ElementType>
Node<ElementType>::~Node(){
	//everything should auto delete when the node is deleted.
}



template <class ElementType>
Node<ElementType>::Node(ElementType Sdata){
	data = Sdata;
	next = NULL;

}

template <class ElementType>
Node<ElementType>::Node(ElementType Sdata, Node *nextNode){
	data = Sdata;
	next = nextNode;

}
