//Event.cpp
//Author: Melissa Lee
//301300968
//CMPT 225 D100

#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Event.h"
using namespace std;

	Event::Event(){
		time = 0;
		type = 'a';
		length = 0;
		

	}
	Event::Event(int stime,char stype,int slength){
		time = stime;
		type = stype;
		length = slength;
	}	

	int Event::getTime(){
		return time;
	}
	void Event::setTime(int stime){
		time = stime;
	}

	int Event::getLength(){
		return length;
	}
	void Event::setLength(int slength){
		length = slength;
	}

	char Event::getType(){
		return type;
	}
	void Event::setType(char stype){
		type = stype;
	}
