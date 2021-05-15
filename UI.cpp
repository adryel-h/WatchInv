#include "UI.h"
#include <iostream>
#include <string>
#include "Controler.h"
#include <cstring>
using namespace std;

void UI::Load()
{
	string menu = "\n\t Operations:\n 1. Add a watch\n 2. Print stock\n 3. Print using filter\n 4. Remove by ID\n 5. Undo operation\n 0. Exit\n", brand, model, colour,blank;
	Types type;
	bool done;
	int operation = 1;
	Controler co;
	co.load("databases.csv");
	while (operation) {
		cout << menu;
		cin >> operation;
		getline(cin, blank);
		if (operation == 1) {
			done = false;
			while (!done) {
				try {
					cout << "\n Type in the brand: ";
					getline(cin, brand);
					for (int i = 0; i < brand.size(); i++)
					{
						if (!((brand[i] >= 'a' and brand[i] <= 'z') or (brand[i] >= 'A' and brand[i] <= 'Z') or brand[i] == ' ')) {
							throw brand[i];
						}
					}
					done = true;
				}
				catch(char chr){
					cout << "\n\t You are allowed to use only letters! \n\t you typed in the character: " << chr<<"\n";
				}
			}
			cout << "\n Type in the model: ";
			getline(cin, model);
			done = false;
			while (!done) {
				try {
					cout << "\n Type in the colour: ";
					getline(cin, colour);
					for (int i = 0; i < colour.size(); i++)
					{
						if (!((colour[i] >= 'a' and colour[i] <= 'z') or (colour[i] >= 'A' and colour[i] <= 'Z') or colour[i] == ' ')) {
							throw colour[i];
						}
					}
					done = true;
				}
				catch (char chr) {
					cout << "\n\t You are allowed to use only letters! \n\t you typed in the character: " << chr<<"\n";
				}
			}
			done = false;
			while (!done) {
				try {
					cout << "\n\t Select watch type:\n 1. Mechanical\n 2. Smartwatch\n";
					cin >> operation;
					if (operation < 1 or operation > 2)
						throw operation;
					done = true;
				}
				catch (int res) {
					cout << "\n\t Please select 1 or 2: you chose " << res << "\n";
				}
			}
			if (operation == 1) {
				type = Mechanical;
				string dialtype, movement;
				done = false;
				while (!done) {
					try {
                      cout << "\n\t Select Movement type: 1. Manual 2. Automatic 3. Quartz\n";
					cin >> operation;
					if (operation < 1 or operation >3)
						throw operation;
					done = true;
					}
					catch (int res) {
						cout << "\n\t Please select 1, 2 or 3: you chose " << res << "\n";
					}
				}
				if (operation == 1) {
					movement = "Manual";
				}
				else {
					if (operation == 2) {
						movement = "Automatic";
					}
					else
						movement = "Quartz";
				}
				getline(cin, blank);
				done = false;
				while (!done) {
					try {
						cout << "\n Type in the DialType: ";
						getline(cin, dialtype);
						for (int i = 0; i < dialtype.size(); i++)
						{
							if (!((dialtype[i] >= 'a' and dialtype[i] <= 'z') or (dialtype[i] >= 'A' and dialtype[i] <= 'Z')or dialtype[i]==' ')) {
								throw dialtype[i];
							}
						}
						done = true;
					}
					catch (char chr) {
						cout << "\n\t You are allowed to use only letters! \n\t you typed in the character: " << chr << "\n";
					}
				}
				co.addMechanicWatch(type, brand, model, colour, movement, dialtype);
			}
			else if (operation == 2) {
				type = Smart;
				string os, response;
				getline(cin, blank);
				bool heartrate = false, wirelesscharge = false;
				cout << "\n Operating system: ";
				getline(cin, os);
				done = false;
				while (!done) {
					try {
						cout << "\nDoes it have a heartrate sensor? (type yes or no): ";
						cin >> response;
						if (response != "yes" and response != "no" and response!="Yes" and response != "No")
							throw response;
						done = true;
					}
					catch (string res) {
						cout << "\n Type yes or no! you typed: " << res<<"\n";
					}
				}
				if (!response.compare("yes") or !response.compare("Yes"))
					heartrate = true;
				done = false;
				while (!done) {
					try {
						cout << "\nCan you charge it wirelessly? (type yes or no): ";
						cin >> response;
						if (response != "yes" and response != "no" and response != "Yes" and response != "No")
							throw response;
						done = true;
					}
					catch (string res) {
						cout << "\n Type yes or no! you typed: " << res << "\n";
					}
				}
				if (!response.compare("yes") or !response.compare("Yes"))
					wirelesscharge = true;
				co.addSmartWatch(type, brand, model, colour, os, heartrate, wirelesscharge);
			}
		}
		else if (operation == 2) {
		vector<Watch*> result = co.getAll();
		if (!result.empty()) {
			cout << "\n All watches in stock: \n";
			for (int i = 0; i < result.size(); i++)
				result[i]->print();
		}
		else
			cout << "\n Inventory empty! \n";
        }
		else if (operation == 4) {
		unsigned int id=0;
		string number;
		done = false;
		while (!done) {
			try {
				cout << "\n Type in the ID: ";
				cin >> number;
				for (int i = 0; i < number.size(); i++)
					if (number[i] < '0' or number[i]>'9') {
						throw number[i];
					}
					else
						id = id * 10 + (number[i] - '0');
				done = true;
			}
			catch (char wro) {
				cout << "\n You need to introduce a positive integer! You typed in the character: "<<wro<<"\n";
			}
		}
		bool done = co.remove(id);
		if (done == true)
			cout << "\n Item successfully removed\n";
		else
			cout << "\n No item removed\n";
        }
		else if (operation == 5) {
		bool happened = co.undo();
		if (happened == true)
			cout << "\n Operation reversed successfully\n";
		else
			cout << "\n No operation was reversed\n";
        }
		else if (operation == 3) {
		cout << "\n\t Choose which filter: \n";
		cout << "\n1: Mechanical watches 2: Smart watches\n";
		cin >> operation;
		if (operation == 1 || operation == 2) {
			Types r;
			if (operation == 1)
				r = Mechanical;
			else
				r = Smart;
			vector<Watch*> result = co.filter(r);
			if (!result.empty()) {
				cout << "\n Filtered watches: \n";
				for (int i = 0; i < result.size(); i++)
					result[i]->print();
			}
			else {
				cout << "\n No watches found with the specified filter\n";
			}
		}
		else cout << "\n Invalid filter \n";
		operation = 1;
        }
	}
	co.savedata("databases.csv");
}
