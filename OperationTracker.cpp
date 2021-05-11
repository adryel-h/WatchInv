#include "OperationTracker.h"

void OperationTracker::push(OpTypes op, Watch* po)
{
	/**
	* this function add to the end a pair of OpTypes and Watch* to the end of the stack
	**/
	stak.push({ op,po });
}

bool OperationTracker::undo(Repository& rep) {
	/**
	* This function takes as paramater a Repository with reference
	* It extracts the top element of the stack and verifies if it's OpType
	* Depending on the OpTypes value, it will either add or remove an element from rep
	* It returns true if the stack was not empty and false eitherwise
	**/
	if (!stak.empty()) {
		pair<OpTypes, Watch*> aux = stak.top();
		if (aux.first == append)
		{
			rep.removeWatch(aux.second->getId());
			delete aux.second;
		}
		else
		{
			rep.addWatch(aux.second);
		}
		stak.pop();
		return true;
	}
	else
		return false;
}

void OperationTracker::release() {
	/**
	* This function is called in the Destructor of the Controler object.
	* It deletes all the dynamically allocated watches that the controler will not
	**/
	while (!stak.empty()) {
		pair<OpTypes, Watch*> aux = stak.top();
		stak.pop();
		if (aux.first == extract) {
			delete aux.second;
		}
	}
}
