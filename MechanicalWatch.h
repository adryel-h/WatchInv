#pragma once
#include "Watch.h"

class MechanicalWatch: public Watch
{
	/**
	* This is the Mechanical watch class. Subclass of Watch.
	**/
public:
	MechanicalWatch(int id, Types type, string brand, string model, string colour, string Movement, string DialType);
	MechanicalWatch(Types type, string brand, string model, string colour, string Movement, string DialType);
	~MechanicalWatch();
	 string getMovement();
	 string getDial();
	 void print();
	 bool isMechanic();
	 bool isSmart();
protected:
	string Movement;
	string DialType;
};

