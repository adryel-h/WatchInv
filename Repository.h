#pragma once
#include <iostream>
#include "Watch.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Repository
{
    /**
    * This is the repository class where all the addresses of the Watch objects are stored
    **/
public:
    bool isEmpty();
    void addWatch(Watch* w);
    int size();
    Watch* getWatch(unsigned int pos);
    Watch* removeWatch(int id);
    vector<Watch*> filterM();
    vector<Watch*> filterS();
    vector<Watch*> getAll();
    void clear();
private:
    vector<Watch*>repo;
};

