#include "MechanicalWatch.h"

MechanicalWatch::MechanicalWatch(int id, Types type, string brand, string model, string colour, string Movement, string DialType) : Watch(id, type, brand, model, colour)
{
	/**
	* This is the constructor where the id is provided
	* The object was constructed from the CSV file
	**/
	this->Movement = Movement;
	this->DialType = DialType;
}

MechanicalWatch::MechanicalWatch(Types type, string brand, string model, string colour, string Movement, string DialType): Watch (type, brand,  model, colour)
{
	/**
	* This is the normal constructor where id is not provided
	* Id will be assigned by the base-class constructor
	* The object was constructed from user input at run-time
	**/
	this->Movement = Movement;
	this->DialType = DialType;
}

MechanicalWatch::~MechanicalWatch()
{
}

string MechanicalWatch::getMovement()
{
	/**
	* getter for the string movement
	**/
	return Movement;
}

string MechanicalWatch::getDial()
{
	/**
	* getter for the string DialType
	**/
	return DialType;
}

void MechanicalWatch::print()
{
	/**
	* Print function that calls the base-class function and prints additionally the particular attributes of a Mechanical watch
	**/
	Watch::print();
	cout << ", Movement: " << Movement << ", Dial type: " << DialType<<"\n";
}

bool MechanicalWatch::isMechanic()
{
	/**
	* This function exists as it useful to know of which subclass does a specific object belong to.
	**/
	return true;
}

bool MechanicalWatch::isSmart()
{
	/**
	* This function exists as it useful to know of which subclass does a specific object belong to.
	**/
	return false;
}

