#include "Department.h"
#include <iostream>
#include <string>


using namespace std;

void Department::print()
{
	cout << " Department Name: " << departName << endl;
	cout << " Department ID: " << to_string(departID) <<endl;
}

Department::Department()
{
	departID = 0;
	departName = "No department";
}

Department::Department(int id, string name)
{
	departID = id;
	departName = std::move(name);

}

Department::~Department()
{

}


int Department::getdepartID()
{
	return departID;
}

string Department::getdepartName()
{
	return departName;
}