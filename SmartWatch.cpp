#include "SmartWatch.h"
SmartWatch::SmartWatch(int id, Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge) : Watch(id, type, brand, model, colour)
{
	/**
	* This is the constructor where the id is provided
	* The object was constructed from the CSV file
	**/
	this->os = os;
	HeartRateSensors = heartratesensor;
	WirelessCharge = wirelesscharge;
}
SmartWatch::SmartWatch(Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge): Watch(type, brand, model, colour)
{
	/**
	* This is the normal constructor where id is not provided
	* Id will be assigned by the base-class constructor
	* The object was constructed from user input at run-time
	**/
	this->os = os;
	HeartRateSensors = heartratesensor;
	WirelessCharge = wirelesscharge;
}

SmartWatch::~SmartWatch()
{
}

string SmartWatch::getOs()
{
	/**
	* getter for the string os
	**/
	return os;
}

bool SmartWatch::getWireless()
{
 /**
 * getter for the bool WirelessCharge
 **/
	return WirelessCharge;
}

bool SmartWatch::getHeart()
{
	/**
 * getter for the bool HeartRateSensors
 **/
	return HeartRateSensors;
}

bool SmartWatch::isMechanic()
{
	/**
	* This function exists as it useful to know of which subclass does a specific object belong to.
	**/
	return false;
}

bool SmartWatch::isSmart()
{
	/**
	* This function exists as it useful to know of which subclass does a specific object belong to.
	**/
	return true;
}

void SmartWatch::print()
{
	/**
	* Print function that calls the base-class function and prints additionally the particular attributes of a Smart watch
	**/
	Watch::print();
	cout << ", Operating system: " << os << ", Heart rate sensor: ";
	if (HeartRateSensors == true)
		cout << "yes";
	else
		cout << "no";
	cout << ", Wireless charge: ";
	if (WirelessCharge == true)
		cout << "yes";
	else cout << "no";
	cout << "\n";
}
