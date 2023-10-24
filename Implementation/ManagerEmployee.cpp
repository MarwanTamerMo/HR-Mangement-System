#include "ManagerEmployee.h"
#include <iostream>
#include<string>

using namespace std;

double ManagerEmployee::getSalary()
{
	return (salary + bonus);
}

string ManagerEmployee::getDetails()
{
	string details = " Name: " + name + "\n";

	details += " Employee ID: " + to_string(employeeID) + "\n";
	details += " Employee type: Manager \n";
	details += " Email: " + email + "\n";
	details += " Phone: " + phone + "\n";
	details += " Salary: " + to_string(salary) + "$" + "\n";
	details += " Bonus: " + to_string(bonus) + "$" + "\n";

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

int ManagerEmployee::getemployeeID()
{
	return employeeID;
}

void ManagerEmployee::setDepart(Department* department)
{
	SalariedEmployee::setDepart(department);
}

void ManagerEmployee::ShowDepart()
{
	SalariedEmployee::ShowDepart();
}



void ManagerEmployee::addBenefit(int c, double x)
{
	SalariedEmployee::addBenefit(c, x);
}

void ManagerEmployee::setSalary(double x)
{
	SalariedEmployee::setSalary(x);
}

Benefit* ManagerEmployee::getBenefit(int i)
{
	return SalariedEmployee::getBenefit(i);
}

void ManagerEmployee::addBonus(double more_bonus)
{
	bonus += more_bonus;
}

void ManagerEmployee::setBonus(double setbonus)
{
	bonus = setbonus;
}

ManagerEmployee::ManagerEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double m_salary, double m_bonus)
{
	name = std::move(m_name);
	employeeID = m_id;
	JobTitle = std::move(m_jobTitle);
	phone = std::move(m_phone);
	email = std::move(m_email);
	salary = m_salary;
	bonus = m_bonus;
}

ManagerEmployee::~ManagerEmployee()
{
	
}

ManagerEmployee::ManagerEmployee()
{
	bonus = 0;
}


