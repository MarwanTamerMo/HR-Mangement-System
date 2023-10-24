#include "HourlyEmployee.h"
#include <iostream>

using namespace std;

int HourlyEmployee::Counter = 0;

HourlyEmployee::HourlyEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double hours, double m_rate)
{
	name = std::move(m_name);
	employeeID = m_id;
	JobTitle = std::move(m_jobTitle);
	phone = std::move(m_phone);
	email = std::move(m_email);
	hoursWorked = hours;
	rate = m_rate;
}

HourlyEmployee::HourlyEmployee()
{
}

HourlyEmployee::~HourlyEmployee()
{
	
}

void HourlyEmployee::addHours(int more_hours)
{
	hoursWorked += more_hours;
}

double HourlyEmployee::getSalary()
{
	return(hoursWorked * rate);
}

string HourlyEmployee::getDetails()
{
	string details = " Employee ID: " + to_string(employeeID) + "\n";

	details += " Employee type: Hourly employee \n";
	details += " Name: " + name + "\n";
	details += " Hours Worked: " + to_string(hoursWorked) + " hours" + "\n";
	details += " Email: " + email + "\n";
	details += " Phone: " + phone + "\n";
	details += " Rate: " + to_string(rate) + "\n";
	details += " Wage earned: " + to_string(getSalary()) + "$" + "\n";

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

void HourlyEmployee::setDepart(Department* department)
{
	Employee::setDepart(department);
}

int HourlyEmployee::getemployeeID()
{
	return employeeID;
}

void HourlyEmployee::ShowDepart()
{
	Employee::ShowDepart();
}

void HourlyEmployee::addBenefit(int c, double x)
{
	Employee::addBenefit(c, x);
}

void HourlyEmployee::setHours(double hrs)
{
	hoursWorked = hrs;
}

void HourlyEmployee::setRate(double rte)
{
	rate = rte;
}

Benefit* HourlyEmployee::getBenefit(int i)
{
	return Employee::getBenefit(i);
}




