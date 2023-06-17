// file header chua all properties and method
// file header chi khai bao function

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
public:
	Vehicle(string name);
	virtual void run();
protected:
	const string modeName;
	string ownerName;
	string license;
};

