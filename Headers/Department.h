#pragma once
#include <iostream>

using namespace std;

class Department
{
private:

	int departID;
	string departName;

public:

	Department();
	Department(int id, string name);
	virtual ~Department();
	int getdepartID();
	string getdepartName();
	void print();

};




