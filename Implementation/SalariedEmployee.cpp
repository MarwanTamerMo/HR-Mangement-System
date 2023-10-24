#include "SalariedEmployee.h"
#include <iostream>

using namespace std;

double SalariedEmployee::getSalary()
{
	return salary;
}

SalariedEmployee::SalariedEmployee()
{
	salary = 0;
}

SalariedEmployee::SalariedEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double m_salary)
{
	name = std::move(m_name);
	employeeID = m_id;
	JobTitle = std::move(m_jobTitle);
	phone = std::move(m_phone);
	email = std::move(m_email);
	salary = m_salary;
	
}

SalariedEmployee::~SalariedEmployee()
{
	
}

string SalariedEmployee::getDetails()
{
	string details = " Name: " + name + "\n";

	details += " Employee ID: " + to_string(employeeID) + "\n";
	details += " Employee type: Salaried Employee \n";
	details += " Email: " + email + "\n";
	details += " Phone: " + phone + "\n";
	details += " Salary: " + to_string(salary) + "$" + "\n";

	if(Dep)
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

int SalariedEmployee::getemployeeID()
{
	return employeeID;
}

void SalariedEmployee::setDepart(Department* department)
{
	Employee::setDepart(department);
}

void SalariedEmployee::ShowDepart()
{
	Employee::ShowDepart();
}

void SalariedEmployee::addBenefit(int c, double x)
{
	Employee::addBenefit(c, x);
}

void SalariedEmployee::setSalary(double m_salary)
{
	salary = m_salary;
}

Benefit* SalariedEmployee::getBenefit(int i)
{
	return Employee::getBenefit(i);
}






