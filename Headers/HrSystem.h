#pragma once
#include "Employee.h"
#include "SalariedEmployee.h"
#include "ComissionEmployee.h"
#include "ManagerEmployee.h"
#include "Department.h"
#include "Benefit.h"
#include "HourlyEmployee.h"
#include <Windows.h>
#include <iostream>

class HrSystem
{
private:

	Employee** employeeList;
	Department* departList;


	int m_size;
	int H_count;
	int C_count;
	int S_count;
	int M_count;
	int D_count; //Department count

public:

	HrSystem();
	HrSystem(int size);
	virtual ~HrSystem();
	void calcTotalPayroll();
	void addEmployee();
	void editEmployee();
	void delEmployee(int);
	void FindEmployee();
	void ShowAll();
	int getEmpCount();
	bool setEmpToDepartById(Department*, unsigned int);
	int findEmpID(int);
	int SetEmpID();
	bool MChecker(Employee* employee);
	bool SChecker(Employee* employee);
	bool HChecker(Employee* employee);
	bool CChecker(Employee* employee);
	void addBenefitToEmp();
	string getBenefitFromEmp(int);
	Employee* Cast(Employee* employee);
	Department* CreateDepart(int, string);

};





