#pragma once
#include <iostream>
#include"Benefit.h"
#include "HealthBenefit.h"
#include "DentalBenefit.h"
#include "Department.h"
#include <iostream>

using namespace std;

class Employee
{
protected:

	int employeeID;
	int BenefitCounter;
	string name;
	string phone;
	string email;
	string JobTitle;
	Benefit** BenefitList;
	Department* Dep;

public:

	int departID;
	int MaxNumOfBenefits;
	string departName;
	Employee();
	Employee(int id, string name, string phone, string email, string jobTitle);
	virtual ~Employee();
	virtual int getemployeeID() = 0;
	//@qursaan add this function to edit all data inside each class
	//virtual void editDetails() = 0;
	virtual string getDetails() = 0;
	virtual double getSalary() = 0;
	//@qursaan add calc pay to get salary+sum of benefits
	//virtual double getPay() = 0;
	virtual void setDepart(Department*);
	virtual void ShowDepart();
	virtual void addBenefit(int, double);
	int getBenefitCounter();
	virtual Benefit* getBenefit(int);
};
