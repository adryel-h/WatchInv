#pragma once
#include "Watch.h"
class SmartWatch: public Watch
{
public:
	SmartWatch(int id, Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge);
	SmartWatch(Types type, string brand, string model, string colour, string os, bool heartratesensor, bool wirelesscharge);
	~SmartWatch();
	string getOs();
	bool getWireless();
	bool getHeart();
	bool isMechanic();
	bool isSmart();
	void print();
protected:
	string os;
	bool HeartRateSensors;
	bool WirelessCharge;
};

