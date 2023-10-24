#include "ComissionEmployee.h"
#include <iostream>

using namespace std;


ComissionEmployee::ComissionEmployee()
{
	//@qursaan
	rate = 0;
	target = 0;
}

ComissionEmployee::ComissionEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, 
	double m_rate, double m_target) : Employee(m_id,m_name,m_phone,m_email,m_jobTitle)
{
	//name = std::move(m_name);
//	employeeID = m_id;
	//JobTitle = std::move(m_jobTitle);
	//phone = std::move(m_phone);
	//email = std::move(m_email);
	rate = m_rate;
	target = m_target;
}

ComissionEmployee::~ComissionEmployee()
{
	
}

void ComissionEmployee::setRate(double m_rate)
{
	rate = m_rate;
}

double ComissionEmployee::getSalary()
{
	return (rate * target);
}

string ComissionEmployee::getDetails()
{
	string details = " Name: " + name + "\n";

	details += " Employee ID: " + to_string(employeeID) + "\n";
	details += " Employee type: Commission Employee \n";
	details += " Email: " + email + "\n";
	details += " Phone: " + phone + "\n";
	details += " Rate: " + to_string(rate) + "\n";
	details += " Pay: " + to_string(getSalary()) + "\n";

	if (Dep)
	{
		details += " Department Name: " + Dep->getdepartName() + "\n";
		details += " Department ID: " + to_string(Dep->getdepartID()) + "\n";
	}
	else
	{
		details += "";
	}

	return details;
}

void ComissionEmployee::setDepart(Department* department)
{
	Employee::setDepart(department);
}

int ComissionEmployee::getemployeeID()
{
	return employeeID;
}

void ComissionEmployee::ShowDepart()
{
	Employee::ShowDepart();
}

void ComissionEmployee::addBenefit(int c, double x)
{
	Employee::addBenefit(c, x);
}

void ComissionEmployee::setTarget(double m_target)
{
	target = m_target;
}

Benefit* ComissionEmployee::getBenefit(int i)
{
	return Employee::getBenefit(i);
}