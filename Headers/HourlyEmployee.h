#pragma once
#include "Employee.h"
#include <string>

class HourlyEmployee : public Employee
{
private:

	double hoursWorked;
	double rate;

public:
	static int Counter;

	HourlyEmployee();
	HourlyEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double hours, double rate);
	virtual ~HourlyEmployee();
	void addHours(int more_hours);
	double getSalary();
	void setDepart(Department*) override;
	int getemployeeID();
	void ShowDepart() override;
	void addBenefit(int, double) override;
	void setHours(double);
	void setRate(double);
	Benefit* getBenefit(int) override;
	string getDetails();

};

