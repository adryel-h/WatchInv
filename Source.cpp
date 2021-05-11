#include <iostream>
#include "UI.h"
#include <crtdbg.h>
#include "TestClass.h"
#define _CRTDBG_MAP_ALLOC
using namespace std;
int main() {
	{
		UI ui;
		ui.Load();
		TestClass obj;
		obj.testAll();
	}
	_CrtDumpMemoryLeaks();
	return 0;
} 