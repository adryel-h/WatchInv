#include "Repository.h"


bool Repository::isEmpty()
{
	/**
	* Returns true if the repo is empty
	**/
	if (repo.size() == 0)
		return true;
	else return false;
}

void Repository::addWatch(Watch* w)
{
	/**
	* Appends the pointer w to the vector repo
	**/
	repo.push_back(w);
}

int Repository::size() {
	/**
	* Returns the size of the repo
	**/
	return repo.size();
}

Watch* Repository::getWatch(unsigned int pos)
{
	/**
	* Returns the Watch pointer situated at position pos in the repo
	* If the position is invalid it returns the nullptr
	**/
	if (pos >= repo.size())
		return nullptr;
	else
		return repo[pos];
}

Watch* Repository::removeWatch(int id)
{
	/**
	* Deletes from the repository the Watch pointer pointing to an object having specified id
	* Returns the Watch pointer if such object existed in the repo otherwise it returns the nullptr
	**/
	Watch* result;
	for (int i = 0; i < repo.size(); i++) {
		if (repo[i]->getId() == id) {
			result = repo[i];
			repo[i] = repo[repo.size() - 1];
			repo.pop_back();
			return result;
		}
	}
	return nullptr;
}

vector<Watch*> Repository::filterM() {
	/**
	* Returns a vector of Watch pointers having the property that all point to Watch objects that are of subclass MechanicalWatch
	**/
	vector<Watch*> result(repo.size());
	auto it = copy_if(repo.begin(), repo.end(), result.begin(), [](Watch* po) {return po->isMechanic(); });
	result.resize(distance(result.begin(), it));
	return result;
}

vector<Watch*> Repository::filterS() {
	/**
	* Returns a vector of Watch pointers having the property that all point to Watch objects that are of subclass SmartWatch
	**/
	vector<Watch*> result(repo.size());
	auto it = copy_if(repo.begin(), repo.end(), result.begin(), [](Watch* po) {return po->isSmart(); });
	result.resize(distance(result.begin(), it));
	return result;
}

vector<Watch*> Repository::getAll()
{
	/**
	* Returns the repo as a vector of Watch pointers
	**/
	return repo;
}
