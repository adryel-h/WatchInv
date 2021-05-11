#pragma once
#include "Repository.h"
#include "SmartWatch.h"
#include "MechanicalWatch.h"
#include "OperationTracker.h"
#include <fstream>
#include <string>
using namespace std;

class Controler
{
	/**
	* This is the controller class
	**/
public:
	void load();
	void addMechanicWatch(Types type, string brand, string model, string colour, string Movement, string DialType);
	void addMechanicWatch(int id, Types type, string brand, string model, string colour, string Movement, string DialType);
	void addSmartWatch(Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge);
	void addSmartWatch(int id, Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge);
	vector<Watch*> filter(Types tp);
	bool remove(int id);
	bool undo();
	vector<Watch*> getAll();
	void savedata();
private:
	Repository stock;
	OperationTracker stack;
};

