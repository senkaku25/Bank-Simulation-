//Event.cpp
//Author: Melissa Lee
//301300968
//CMPT 225 D100


#pragma once

class Event{



private:
	int time;//time customer arrives
	char type;//arrival/departure
	int length;//length of time they take at the bank machine
public:
	Event();
	Event(int stime,char stype,int slength);

	int getTime();
	void setTime(int stime);

	int getLength();
	void setLength(int slength);

	char getType();
	void setType(char stype);



};
