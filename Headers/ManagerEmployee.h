#pragma once
#include "SalariedEmployee.h"

class ManagerEmployee : public SalariedEmployee
{
private:

	double bonus;

public:

	ManagerEmployee();
	ManagerEmployee(string m_name, int m_id, string m_jobTitle, string m_phone, string m_email, double m_salary, double bonus);
	virtual ~ManagerEmployee();
	void addBonus(double more_bonus);
	void setBonus(double setbonus);
	double getSalary();
	int getemployeeID();
	void setDepart(Department*) override;
	void ShowDepart() override;
	void addBenefit(int, double) override;
	void setSalary(double) override;
	Benefit* getBenefit(int) override;
	string getDetails();

};

