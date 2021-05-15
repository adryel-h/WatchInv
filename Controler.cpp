#include "Controler.h"

void Controler::load(string filename) {
	/**
	* This is the function that loads the data from the databases.csv file into the repository
	**/
	ifstream f(filename);
	string line;
	vector<string>helper;
	while (getline(f, line)) {
		int pos, i = 1, id = 0;
		Types typ = Mechanical;
		string token = line.substr(0, line.find(','));
		for (int i = 0; i < token.size(); i++)
			id = id * 10 + (token[i] - '0');
		line.erase(0, line.find(',') + 1);
		if (line[0] == '1')
			typ = Smart;
		line.erase(0, 2);
		while (i <= 3) {
			pos = line.find(',');
			string token = line.substr(0, pos);
			helper.push_back(token);
			line.erase(0, pos + 1);
			i++;
		}
		if (typ == Mechanical) {

			pos = line.find(',');
			string token = line.substr(0, pos);
			helper.push_back(token);
			line.erase(0, pos + 1);
			helper.push_back(line);
			addMechanicWatch(id, typ, helper[0], helper[1], helper[2], helper[3], helper[4]);
		}
		else {
			i = 1;
			while (i <= 2) {
				pos = line.find(',');
				string token = line.substr(0, pos);
				helper.push_back(token);
				line.erase(0, pos + 1);
				i++;
			}
			helper.push_back(line);
			bool heart = false, wireless = false;
			if (helper[4] == "1")
				heart = true;
			if (helper[5] == "1")
				wireless = true;
			addSmartWatch(id, typ, helper[0], helper[1], helper[2], helper[3], heart, wireless);
		}
		helper.clear();
	}
	f.close();
}

void Controler::addMechanicWatch(int id, Types type, string brand, string model, string colour, string Movement, string DialType) {
	/**
	* function adds a mechanical watch to the repository
	**/
	MechanicalWatch* po = new MechanicalWatch(id, type, brand, model, colour, Movement, DialType);
	stock.addWatch(po);
}

void Controler::addMechanicWatch(Types type, string brand, string model, string colour, string Movement, string DialType) {
	/**
	* function adds a mechanical watch to the repository
	**/
	MechanicalWatch* po = new MechanicalWatch(type, brand, model, colour, Movement, DialType);
	stock.addWatch(po);
	stack.push(append, po);
}

void Controler::addSmartWatch(Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge)
{
	/**
	* function adds a smart watch to the repository
	**/
	SmartWatch* po = new SmartWatch(type, brand, model, colour, os, heartratesensor, wirelesscharge);
	stock.addWatch(po);
	stack.push(append, po);
}

void Controler::addSmartWatch(int id, Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge)
{
	/**
	* function adds a smart watch to the repository
	**/
	SmartWatch* po = new SmartWatch(id, type, brand, model, colour, os, heartratesensor, wirelesscharge);
	stock.addWatch(po);
}

bool Controler::remove(int id)
{
	/**
	* this function removes a watch from the repository having given id
	* returns true if it removed a watch or false otherwise
	**/
	Watch* result = stock.removeWatch(id);
	if (result != nullptr) {
		stack.push(extract, result);
		return true;
	}
	else
		return false;
}

bool Controler::undo()
{
	/**
	* This function calls the undo operation of the stack which reverses the last operation on the repository
	**/
	return stack.undo(stock);
}

vector<Watch*> Controler::getAll()
{
	/**
	* This function returns a vector of Watch pointers that represent the repository
	**/
	return stock.getAll();
}

void Controler::savedata(string filename) {
	/**
	* After the user ends the program, this function is called. It saves the contents of the repository in the
	* database.csv file overwritting it's contents.
	**/
	ofstream g(filename);
	for (int i = 0; i < stock.size(); i++) {
		int id = stock.getWatch(i)->getId();
		g << id<<",";
		Types t = stock.getWatch(i)->getType();
		g << t;
		string brand = stock.getWatch(i)->getBrand(), model = stock.getWatch(i)->getModel(), colour = stock.getWatch(i)->getColour();
		g << "," << brand << "," << model << "," << colour;
		if (t == Mechanical) {
			string movement = stock.getWatch(i)->getMovement(), dial = stock.getWatch(i)->getDial();
			g << "," << movement << "," << dial;
		}
		else {
			string os = stock.getWatch(i)->getOs();
			bool heart = stock.getWatch(i)->getHeart(), wireless = stock.getWatch(i)->getHeart();
			int h = 0, w = 0;
			if (heart == true)
				h = 1;
			if (wireless == true)
				w = 1;
			g << "," << os << "," << h << "," << w;
		}
		g << "\n";
		delete stock.getWatch(i);
	}
	g.close();
	stack.release();
	stock.clear();
}

vector<Watch*> Controler::filter(Types t) {
	/**
	* This function returns a vector of Watch pointers all pointing to objects of type t
	**/
	vector<Watch*> result;
	if (t == Mechanical) {
		result = stock.filterM();
	}
	else if (t == Smart) {
		result = stock.filterS();
	}
	return result;
}