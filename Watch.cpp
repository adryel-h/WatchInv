#include "Watch.h"
#include <cstring>

int Watch::count = 0;

Watch::Watch(int id, Types type, string brand, string model, string colour) {
	/**
	* Constructor in which the id is given.
	* This watch object was read from the csv file
	**/
	if (id > count)
		count = id;
	this->brand = brand;
	this->model = model;
	this->colour = colour;
	this->type = type;
	this->id = id;
}

Watch::Watch(Types type, string brand, string model, string colour) {
	/**
	* Normal constructor where id is assigned internally
	* This watch object was given by the user at run-time
	**/
	this->brand = brand;
	this->model = model;
	this->colour = colour;
	this->type = type;
	this->id = ++count;
}

Watch::~Watch()
{
}

string Watch::getBrand()
{
	/**
	* getter for the string brand
	**/
	return brand;
}

string Watch::getModel()
{
	/**
	* getter for the string model
	**/
	return model;
}

string Watch::getColour()
{
	/**
	* getter for the string colour
	**/
	return colour;
}

Types Watch::getType()
{
	/**
	* getter for the Types type
	**/
	return type;
}

int Watch::getId()
{
	/**
	* getter for the int id
	**/
	return id;
}

string Watch::getMovement()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return string();
}

string Watch::getDial()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return string();
}

string Watch::getOs()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return string();
}

bool Watch::getWireless()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return false;
}

bool Watch::getHeart()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return false;
}

bool Watch::isSmart()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return false;
}

bool Watch::isMechanic()
{
	/**
	* Virtual method to be implemented by derived classes
	**/
	return false;
}

void Watch::print()
{
	/**
	* Virtual method that derived classes will use to print base-class attributes 
	**/
	string ty;
	if (type == Mechanical)
		ty = "Mechanical";
	else
		ty = "Smartwatch";
	cout << "\nID: " << this->id << ", Watch type: ";
	cout<< ty << ", Brand: " << brand << ", Model: " << model << ", Colour: " << colour;
}




