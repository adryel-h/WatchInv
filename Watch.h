#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

enum Types {
	/**
	* This enum is used to differentiate between mechanical and smart watches
	**/
	Mechanical, Smart
};

enum OpTypes {
	append, extract
};

class Watch
{
/**
* This is the main Watch class
**/
public:
	Watch(int id, Types type, string brand, string model, string colour);
	Watch(Types type, string brand, string model, string colour);
	virtual ~Watch();
	string getBrand();
	string getModel();
	string getColour();
	Types getType();
	int getId();
	virtual string getMovement();
	virtual string getDial();
	virtual string getOs();
	virtual bool getWireless();
	virtual bool getHeart();
	virtual bool isSmart();
	virtual bool isMechanic();
	virtual void print();
	static int count;
protected:
	string brand;
	string model;
	string colour;
	Types type;
	int id;
};
