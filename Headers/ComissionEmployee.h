#pragma once
#include "Employee.h"
#include <string>
#include <iostream>

class ComissionEmployee : public Employee
{
private:

	double target;
	double rate;

public:

	ComissionEmployee();
	ComissionEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double m_rate, double m_target);
	void setRate(double);
	virtual ~ComissionEmployee();
	double getSalary();
	void setDepart(Department*) override;
	int getemployeeID();
	void ShowDepart() override;
	void addBenefit(int, double) override;
	void setTarget(double);
	Benefit* getBenefit(int) override;
	string getDetails();

};

