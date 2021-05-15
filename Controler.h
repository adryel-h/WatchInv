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
	void load(string filename); //done
	void addMechanicWatch(Types type, string brand, string model, string colour, string Movement, string DialType); //done
	void addMechanicWatch(int id, Types type, string brand, string model, string colour, string Movement, string DialType); //done
	void addSmartWatch(Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge); //done
	void addSmartWatch(int id, Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge); //done
	vector<Watch*> filter(Types tp); //done
	bool remove(int id); // done
	bool undo(); // done
	vector<Watch*> getAll(); //done
	void savedata(string filename); //done
private:
	Repository stock;
	OperationTracker stack;
};

