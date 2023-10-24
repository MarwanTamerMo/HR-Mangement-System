#pragma once
#include "Employee.h"

class SalariedEmployee : public Employee
{

protected:

	double salary;

public:

	SalariedEmployee();
	SalariedEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double m_salary);
	virtual ~SalariedEmployee();
	double getSalary();
	string getDetails();
	int getemployeeID();
	void setDepart(Department*) override;
	void ShowDepart() override;
	void addBenefit(int, double) override;
	virtual void setSalary(double);
	Benefit* getBenefit(int) override;

};

