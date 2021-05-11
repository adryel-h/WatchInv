#pragma once
#include <stack>
#include <utility>
#include "Watch.h"
#include "Repository.h"
using namespace std;

class OperationTracker
{
	/**
	* This is the class containg the stack that is used for undo-redo
	**/
public:
	void push(OpTypes op, Watch* po);
	bool undo(Repository& rep);
	void release();
private:
	stack<pair<OpTypes, Watch*>> stak;
};

