#include "TestClass.h"

void TestClass::testControler() {
	Controler caus;
	caus.load("TestDatabase.csv");
	Types type = Mechanical;
	string brand = "Rolex", model = "Deepsea", colour = "steel", Movement = "Automatic", dialtype = "Black";
	caus.addMechanicWatch(type, brand, model, colour, Movement, dialtype);
	type = Smart;
	brand = "Apple";
	model = "Watch s3 2018";
	colour = "White";
	string os = "Ios";
	bool heart = true, wireless = true;
	caus.addSmartWatch(type, brand, model, colour, os, heart, wireless);
	vector<Watch*> result = caus.getAll();
	vector<string> verif{ "IWC", "Samsung","Rolex","Apple" };
	for (int i = 0; i < 4; i++)
		assert(result[i]->getBrand() == verif[i]);
	result = caus.filter(Smart);
	vector<string> verif2{ "Android", "Ios" };
	for (int i = 0; i < 2; i++)
		assert(result[i]->getOs() == verif2[i]);
	caus.remove(1);
	result = caus.filter(Mechanical);
	assert(result.size() == 1);
	assert(result[0]->getColour() == "steel");
	caus.undo();
	result = caus.filter(Mechanical);
	assert(result.size() == 2);
	assert(result[1]->getModel() == "Aquatimer");
	assert(result[1]->getDial() == "Baton");
	caus.savedata("TestSave.csv");
	caus.load("TestSave.csv");
	result = caus.getAll();
	vector<Types> verif3{ Smart, Smart, Mechanical, Mechanical };
	for (int i = 0; i < 4; i++) 
		assert(result[i]->getType() == verif3[i]);
	caus.savedata("TestSave.csv");   
}

void TestClass::testStack() {
	Repository rep;
	SmartWatch* p1 = new SmartWatch{ 1, Smart, "Apple", "Watch S3 2018","White","ios",true, true };
	MechanicalWatch* p2 = new  MechanicalWatch{ 2, Mechanical, "Rolex", "Deepsea", "Silver", "Automatic", "Black" };
	rep.addWatch(p1);
	rep.addWatch(p2);
	OperationTracker stk;
	stk.push( append,p1 );
	stk.push(append, p2);
	stk.undo(rep);
	assert(rep.size() == 1);
	stk.push(extract, p2);
	stk.undo(rep);
	assert(rep.getWatch(1) == p2);
	delete p1;
}

void TestClass::testRepo() {
	Repository rep;
	vector<Watch*> comp;
	SmartWatch* p1 = new SmartWatch { 1, Smart, "Apple", "Watch S3 2018","White","ios",true, true };
	MechanicalWatch* p2 = new  MechanicalWatch { 2, Mechanical, "Rolex", "Deepsea", "Silver", "Automatic", "Black" };
	rep.addWatch(p1);
	rep.addWatch(p2);
	assert(rep.isEmpty() == false);
	assert(rep.size() == 2);
	assert(rep.getWatch(1) == p2);
	rep.removeWatch(2);
	assert(rep.size() == 1);
	rep.addWatch(p2);
	vector<Watch*> tt = rep.filterM();
	comp.push_back(p2);
	assert(tt == comp);
	comp.clear();
	tt = rep.filterS();
	comp.push_back(p1);
	assert(comp == tt);
	comp.clear();
	comp.push_back(p1);
	comp.push_back(p2);
	tt = rep.getAll();
	assert(tt == comp);
	delete p1;
	delete p2;
}

void TestClass::testSmartWatch()
{
	SmartWatch w{ 1, Smart, "Apple", "Watch S3 2018","White","ios",true, true };
	assert(w.getBrand() == "Apple");
	assert(w.getColour() == "White");
	assert(w.getHeart() == true);
	assert(w.getId() == 1);
	assert(w.getModel() == "Watch S3 2018");
	assert(w.getOs() == "ios");
	assert(w.getType() == Smart);
	assert(w.getWireless() == true);
	assert(w.isMechanic() == false);
	assert(w.isSmart() == true);
}

void TestClass::testMechanicWatch() {
	MechanicalWatch w{ 2, Mechanical, "Rolex", "Deepsea", "Silver", "Automatic", "Black" };
	assert(w.getBrand() == "Rolex");
	assert(w.getModel() == "Deepsea");
	assert(w.getColour() == "Silver");
	assert(w.getDial() == "Black");
	assert(w.getMovement() == "Automatic");
	assert(w.getHeart() == false);
	assert(w.getWireless() == false);
	assert(w.isMechanic() == true);
	assert(w.isSmart() == false);
	assert(w.getId() == 2);
	assert(w.getType() == Mechanical);
}

void TestClass::testWatch() {
	testMechanicWatch();
	testSmartWatch();
}

void TestClass::testAll() {
	cout << "\n\t Testing Watch and derived classes: \n";
	testWatch();
	cout << "\t PASSED";
	cout << "\n\t Testing the Repository: \n";
	testRepo();
	cout << "\t PASSED";
	cout << "\n\t Testing the Stack: \n";
	testStack();
	cout << "\t PASSED";
	cout << "\n\t Testing the controler: \n";
	testControler();
	cout << "\t PASSED";
}