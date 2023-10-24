#include "HrSystem.h"
#include "Employee.h"
#include "Department.h"
#include "Benefit.h"
#include "SalariedEmployee.h"
#include "ComissionEmployee.h"
#include "DentalBenefit.h"
#include "HealthBenefit.h"
#include "HourlyEmployee.h"
#include <iomanip>
#include "ManagerEmployee.h"
#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE dConsole = GetStdHandle(STD_OUTPUT_HANDLE);


HrSystem::HrSystem(int size)
{
	m_size = 0; // num of employees in company
	employeeList = new Employee * [size];
	departList = new Department[size];

	H_count = 0;
	S_count = 0;
	M_count = 0;
	C_count = 0;
	D_count = 1;
}

HrSystem::~HrSystem()
{
	delete[] employeeList;
	delete[] departList;
	
}

void HrSystem::calcTotalPayroll()
{
	double total = 0;

	if(m_size == 0)
	{
	
		SetConsoleTextAttribute(dConsole, 6);
		cout << " The company did not hire employees yet :(\n";
		SetConsoleTextAttribute(dConsole, 15);

	}
	else
	{
		for (int i = 0; i < m_size; ++i)
		{
			//@qursaan return pay of each employee ->getPay();
			total += employeeList[i]->getSalary();
		}
	}

	SetConsoleTextAttribute(dConsole, 11);

	cout << " The total payroll of the company is: " << total << "$" << endl;

	SetConsoleTextAttribute(dConsole, 15);

}

void HrSystem::addEmployee()
{
	char choice, choice2 = 'k';
	int id = 0, departid = 0;
	double salary = 0, hours = 0, rate = 0, target = 0, bonus = 0, amount = 0;
	string name, phone, email, title, departname;
	Department* depart = nullptr;
	bool assigned, departcreated = false;


	cout << " What kind of employee you want to add: \n 1 - Salaried Employee\n 2 - Hourly Employee\n 3 - Commission Employee "
		"\n 4 - Manager Employee\n";

	cin >> choice;

	system("cls");

	cin.ignore();

	switch (choice)
	{

	case '1':
		{
			id = SetEmpID();

			cin.ignore();
			cout << " Employee name: ";
			getline(cin, name);

			cout << " Employee phone: ";
			getline(cin, phone);

			cout << " Employee job title: ";
			getline(cin, title);

			cout << " Employee email: ";
			getline(cin, email);

			cout << " Salary: ";
			cin >> salary;

			cout << " Do you want to add the employee to a department? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				departcreated = true;

				cin.ignore();
				cout << " Department name: ";
				getline(cin, departname);

				cout << " Depatement id: ";
				cin >> departid;
				cin.ignore();

				depart = CreateDepart(departid, departname);

			}

			SalariedEmployee* Snew_employee = new SalariedEmployee(name, id, title, phone, email, salary);

			employeeList[m_size++] = Snew_employee;
			S_count++;

			cout << " Do you want to add benefits to the employee? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				addBenefitToEmp();
			}

			if(departcreated)
			{
				assigned = setEmpToDepartById(depart, id);
			}

			SetConsoleTextAttribute(dConsole, 13);

			cout << " Employee is hired successfully :)\n";

			SetConsoleTextAttribute(dConsole, 15);

			break;
		}

	case '2':
		{

			id = SetEmpID();

			cin.ignore();
			cout << " Employee name: ";
			getline(cin, name);

			cout << " Employee phone: ";
			getline(cin, phone);

			cout << " Employee job title: ";
			getline(cin, title);

			cout << " Employee email: ";
			getline(cin, email);

			cout << " Hours: ";
			cin >> hours;

			cout << " Rate: ";
			cin >> rate;

			cout << " Do you want to add the employee to a department? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				departcreated = true;

				cin.ignore();
				cout << " Department name: ";
				getline(cin, departname);

				cout << " Depatement id: ";
				cin >> departid;
				cin.ignore();

				depart = CreateDepart(departid, departname);

			}

			HourlyEmployee* Hnew_employee = new HourlyEmployee(name, id, title, phone, email, hours, rate);

			employeeList[m_size++] = Hnew_employee;
			H_count++;

			cout << " Do you want to add benefits to the employee? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				addBenefitToEmp();
			}

			if (departcreated)
			{
				assigned = setEmpToDepartById(depart, id);
			}

			SetConsoleTextAttribute(dConsole, 13);

			cout << " Employee is hired successfully :)\n";

			SetConsoleTextAttribute(dConsole, 15);

			break;
		}

	case '3':
		{

			id = SetEmpID();

			cin.ignore();
			cout << " Employee name: ";
			getline(cin, name);

			cout << " Employee phone: ";
			getline(cin, phone);

			cout << " Employee job title: ";
			getline(cin, title);

			cout << " Employee email: ";
			getline(cin, email);

			cout << " Target: ";
			cin >> target;

			cout << " Rate: ";
			cin >> rate;
			cin.ignore();

			cout << " Do you want to add the employee to a department? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				departcreated = true;

				cin.ignore();
				cout << " Department name: ";
				getline(cin, departname);

				cout << " Depatement id: ";
				cin >> departid;
				cin.ignore();

				depart = CreateDepart(departid, departname);

			}
			
			ComissionEmployee* Cnew_employee = new ComissionEmployee(name, id, title, phone, email, rate, target);

			employeeList[m_size++] = Cnew_employee;
			C_count++;

			cout << " Do you want to add benefits to the employee? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				addBenefitToEmp();
			}


			if (departcreated)
			{
				assigned = setEmpToDepartById(depart, id);
			}

			SetConsoleTextAttribute(dConsole, 13);

			cout << " Employee is hired successfully :)\n";

			SetConsoleTextAttribute(dConsole, 15);

			break;
		}
	case '4':
		{

			id = SetEmpID();

			cin.ignore();
			cout << " Employee name: ";
			getline(cin, name);

			cout << " Employee phone: ";
			getline(cin, phone);

			cout << " Employee job title: ";
			getline(cin, title);

			cout << " Employee email: ";
			getline(cin, email);

			cout << " Salary: ";
			cin >> salary;

			cout << " Bonus: ";
			cin >> bonus;
			cin.ignore();

			cout << " Do you want to add the employee to a department? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				departcreated = true;

				cin.ignore();
				cout << " Department name: ";
				getline(cin, departname);

				cout << " Depatement id: ";
				cin >> departid;
				cin.ignore();

				depart = CreateDepart(departid, departname);

			}

			ManagerEmployee* Mnew_employee = new ManagerEmployee(name, id, title, phone, email, salary, bonus);

			employeeList[m_size++] = Mnew_employee;
			M_count++;

			cout << " Do you want to add benefits to the employee? (y/n): ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				addBenefitToEmp();
			}

			if (departcreated)
			{
				assigned = setEmpToDepartById(depart, id);
			}

			SetConsoleTextAttribute(dConsole, 13);

			cout << " Employee is hired successfully :)\n";

			SetConsoleTextAttribute(dConsole, 15);
			break;
		}

	default:
		{
			SetConsoleTextAttribute(dConsole, 13);
			cout << " Sorry the system doesn't have more than these options right now :(\n";
			SetConsoleTextAttribute(dConsole, 6);

		}

	}

}

void HrSystem::editEmployee()
{
	char choice, choice2;
	int id;

	if (m_size == 0)
	{
		SetConsoleTextAttribute(dConsole, 13);

		cout << " The system doesn't have employees to edit yet :)\n";

		SetConsoleTextAttribute(dConsole, 15);

	}
	else
	{
		bool try_again = false;

		do
		{
			try_again = false;

			cout << " What do you want to edit in the employee : \n";
			cout << " 1 - All details\n 2 - Department information\n 3 - Benefits\n 4 - Bonus (Managers)\n 5 - Wages (Hourly Employees)\n 6 - Target (Commission Employees)\n 7 - Salary (Manager - Salaried)\n";

			cin >> choice;

			do
			{
				cout << " Enter the employee ID: ";
				cin >> id;

				int empIDX = findEmpID(id);

				if (empIDX == -1)
				{
					cout << " No employee holds this ID :(\n";
					cout << " Do you wish to enter another ID? (y/n): ";
					cin >> choice2;

					if (choice2 == 'y' || choice2 == 'Y')
					{
						try_again = true;
					}
					else
					{
						break;
					}
				}
				else
				{
					switch (choice)
					{
					case '1':
						{
							if (empIDX == m_size - 1)
							{
								SetConsoleTextAttribute(dConsole, 13);
								cout << " The previous employee will be deleted after you enter the new data :)\n\n ";
								SetConsoleTextAttribute(dConsole, 15);

								addEmployee();
								m_size--;
								cout << " Do you wan to edit another employee? (y/n): ";
								cin >> choice2;

								if (choice2 == 'y' || choice2 == 'Y')
								{
									try_again = true;
								}
							}
							else
							{
								employeeList[empIDX] = employeeList[m_size - 1];
								addEmployee();
								m_size--;

							}
							break;
						}

					case '2':
						{
							SetConsoleTextAttribute(dConsole, 11);
							cout << " The old employee department information : \n";
							employeeList[empIDX]->ShowDepart();
							cout << endl;
							SetConsoleTextAttribute(dConsole, 15);


							cout << " The new department information: \n";
							Department* depart = nullptr;
							string departname;
							int departid;

							cin.ignore();
							cout << " Department name: ";
							cin >> departname;

							cout << " Department ID: ";
							cin >> departid;

							depart = CreateDepart(departid, departname);

							bool assigned = setEmpToDepartById(depart, id);

							SetConsoleTextAttribute(dConsole, 11);
							cout << " Department Information Successfully Updated :) \n";
							SetConsoleTextAttribute(dConsole, 15);

							break;
						}

					case '3':
						{
							char choice;
							int num;

							SetConsoleTextAttribute(dConsole, 11);

							cout << " The old Benefits information: \n";

							SetConsoleTextAttribute(dConsole, 15);

							string show = getBenefitFromEmp(id);
							cout << show << endl;

							SetConsoleTextAttribute(dConsole, 15);

							cout << endl;

							cout << " How many benefits you want to add (max 2) : ";
							cin >> num;

							for (int i = 0; i < num; ++i)
							{
								cout << " The new benefits information: \n 1 - Health Insurance\n 2 - Dental Benefit\n";
								cin >> choice;

								if (choice == '1')
								{
									employeeList[empIDX]->addBenefit('1', employeeList[empIDX]->getSalary());
								}
								else if (choice == '2')
								{
									employeeList[empIDX]->addBenefit('2', employeeList[empIDX]->getSalary());

								}
								else
								{
									SetConsoleTextAttribute(dConsole, 11);
									cout << " Please choose a valid benefit number (1-2) :)\n";
									SetConsoleTextAttribute(dConsole, 15);

									continue;
								}
							}

							SetConsoleTextAttribute(dConsole, 11);

							cout << " The benefits information is updated successfully :)\n";

							SetConsoleTextAttribute(dConsole, 15);

							break;
						}

					case '4':
						{

							//@qursaan

							//employeeList[empIDX].editDetails();
							if (MChecker(employeeList[empIDX]))
							{
								const auto managerEmployee = dynamic_cast<ManagerEmployee*>(employeeList[empIDX]);

								char choice3 = 'k';
								double bonus = 0;
								cout << " What do you want to do?: \n";
								cout << " 1 - Set a new bonus\n 2 - Add more bonus\n";
								cin >> choice3;

								if (choice3 == '1')
								{
									cout << " The new bonus: ";
									cin >> bonus;

									managerEmployee->setBonus(bonus);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " The new bonus is set successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);

								}
								else if (choice3 == '2')
								{
									cout << " Enter the addition: ";
									cin >> bonus;

									managerEmployee->addBonus(bonus);

									SetConsoleTextAttribute(dConsole, 11);
									cout << " The desired bonus addition was successfully done :)\n";
									SetConsoleTextAttribute(dConsole, 15);
								}
							}
							else
							{
								SetConsoleTextAttribute(dConsole, 6);
								cout << " This employee is not a manager sir.\n";
								SetConsoleTextAttribute(dConsole, 15);

							}

							break;
						}

					case '5':
						{
							if (HChecker(employeeList[empIDX]))
							{
								auto* hourlyEmployee = dynamic_cast<HourlyEmployee*>(employeeList[empIDX]);

								char choice3 = 'k';
								int hours = 0;
								double rate = 0;
								cout << " What do you want to do?: \n";
								cout << " 1 - Set a new Hours\n 2 - Add more Hours\n 3 - Set a new rate\n";
								cin >> choice3;

								if (choice3 == '1')
								{
									cout << " The new Hours: ";
									cin >> hours;

									hourlyEmployee->setHours(hours);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " Hours Changed successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);

								}
								else if (choice3 == '2')
								{
									cout << " Enter the addition of hours: ";
									cin >> hours;

									hourlyEmployee->addHours(hours);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " Addition Was Done Successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);

								}
								else if (choice3 == '3')
								{
									cout << " Enter the new rate: ";
									cin >> rate;

									hourlyEmployee->setRate(rate);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " Rate Changed Successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);

								}

							}
							else
							{
								SetConsoleTextAttribute(dConsole, 6);

								cout << " This employee is not an hourly employee sir.\n";

								SetConsoleTextAttribute(dConsole, 15);

							}

							break;
						}
					case '6':
						{
							if (CChecker(employeeList[empIDX]))
							{
								auto* CommissionEMP = dynamic_cast<ComissionEmployee*>(employeeList[empIDX]);

								char choice3 = 'k';
								double target = 0;
								double rate = 0;
								cout << " What do you want to do?: \n";
								cout << " 1 - Set a new rate\n 2 - Set a new target\n";
								cin >> choice3;

								if (choice3 == '1')
								{
									cout << " The new rate: ";
									cin >> rate;

									CommissionEMP->setRate(rate);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " The Rate Has Changed Successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);

								}
								else if (choice3 == '2')
								{
									cout << " Enter the addition of hours: ";
									cin >> target;

									CommissionEMP->setTarget(target);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " The Target Has Changed Successfully :)\n";

									SetConsoleTextAttribute(dConsole, 15);


								}
							}
							else
							{

								SetConsoleTextAttribute(dConsole, 6);

								cout << " This employee is not a commission employee sir.\n";

								SetConsoleTextAttribute(dConsole, 15);

							}

							break;
						}
					case '7':
						{
							if (SChecker(employeeList[empIDX]) || MChecker(employeeList[empIDX]))
							{
								auto* ManagerEMP = dynamic_cast<ManagerEmployee*>(employeeList[empIDX]);
								auto* SalariedEMP = dynamic_cast<SalariedEmployee*>(employeeList[empIDX]);

								double Salary = 0;

								cout << " Enter the new salary: ";
								cin >> Salary;

								if (ManagerEMP)
								{
									ManagerEMP->setSalary(Salary);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " Salary Has Changed Successfully :) \n";

									SetConsoleTextAttribute(dConsole, 15);

								}
								else if (SalariedEMP)
								{
									SalariedEMP->setSalary(Salary);

									SetConsoleTextAttribute(dConsole, 11);

									cout << " Salary Has Changed Successfully :) \n";

									SetConsoleTextAttribute(dConsole, 15);


								}

							}
							else
							{
								SetConsoleTextAttribute(dConsole, 13);

								cout << " This employee is not a manager or salaried employee sir.\n";

								SetConsoleTextAttribute(dConsole, 15);

							}

							break;
						}

					default:

						SetConsoleTextAttribute(dConsole, 13);

						cout << " The little tiny winy system doesn't have this option right now :(\n";

						SetConsoleTextAttribute(dConsole, 15);

						cout << " Do you wish to try again?(y/n) ";
						cin >> choice2;
						if (choice2 == 'y' || choice2 == 'Y')
						{
							try_again = true;
						}
						else
						{
							try_again = false;
						}
					}
				}

			}while (try_again);

			cout << " Do you wish to edit another employee?(y/n) ";
			cin >> choice2;

			if (choice2 == 'y' || choice2 == 'Y')
			{
				try_again = true;
			}
			else
			{
				try_again = false;
			}

			system("cls");

		} while (try_again);
	}
}

void HrSystem::delEmployee(int id)
{
	bool deleted = false;
	bool try_again = false;
	char choice;
	int IDX = findEmpID(id);

	do
	{

		if (m_size == 0)
		{
			SetConsoleTextAttribute(dConsole, 13);

			cout << " The system doesn't have employees to delete yet :)\n";

			SetConsoleTextAttribute(dConsole, 15);

			break;
		}

		if (IDX == -1)
		{
			SetConsoleTextAttribute(dConsole, 11);

			cout << " No employee holds this ID :)\n";

			SetConsoleTextAttribute(dConsole, 15);

			cout << " Do you want to try again? (y/n)";
			cin >> choice;

			if (choice == 'y' || choice == 'Y')
			{
				try_again = true;
			}
		}

		

		else
		{
			for (int i = 0; i < m_size; ++i)
			{
				if (employeeList[i] == employeeList[m_size - 1])
				{
					m_size--;
					deleted = true;
				}
				else
				{
					employeeList[i] = employeeList[m_size - 1];
					m_size--;
					deleted = true;
					break;
				}
			}

			if (deleted)
			{
				SetConsoleTextAttribute(dConsole, 11);

				cout << " The employee was fired succesfully. I'll miss his him :(\n";

				SetConsoleTextAttribute(dConsole, 15);

				cout << " Do you want to fire another employee? (y/n)";
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					try_again = true;
				}

			}
			else
			{
				SetConsoleTextAttribute(dConsole, 11);

				cout << " The employee wasn't fired due to some confliction happened in the system :). I'm not gonna miss him anymore\n";

				SetConsoleTextAttribute(dConsole, 15);

				cout << " Do you want to try again? (y/n)";
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					try_again = true;
				}
			}
		}
	} while (try_again);
	
}

void HrSystem::ShowAll()
{
	cout << endl;

	for (int i = 0; i < m_size; ++i)
	{
		string show = employeeList[i]->getDetails();

		cout << setw(40) << setfill('-') << endl;

		cout << show << endl;

		SetConsoleTextAttribute(dConsole, 7);

		cout << setw(40) << setfill('-') << endl;

		SetConsoleTextAttribute(dConsole, 15);

	}

	cout << "\n You have " << S_count << SetConsoleTextAttribute(dConsole, 11) << " Salaried employees\n";
	cout << " You have " << H_count/*HourlyEmployee::Counter*/ << SetConsoleTextAttribute(dConsole, 13) << " Hourly employees\n";
	cout << " You have " << C_count << SetConsoleTextAttribute(dConsole, 8) << " Commission employees\n";
	cout << " You have " << M_count << SetConsoleTextAttribute(dConsole, 6) << " Manager employees\n";

	SetConsoleTextAttribute(dConsole, 15);


}

int HrSystem::getEmpCount()
{
	return m_size;
}

bool HrSystem::setEmpToDepartById(Department* dep, unsigned int empID)
{
	int empIDX = findEmpID(empID);

	if(empIDX == -1)
	{
		return false;
	}
	else
	{
		Employee* tempP = employeeList[empIDX];

		tempP->setDepart(dep);
	}

	return true;
}

int HrSystem::findEmpID(int empID)
{
	for(auto i = 0; i < m_size; ++i)
	{
		if(employeeList[i]->getemployeeID() == empID)
		{
			return i;
		}
	}

	return -1;
}

int HrSystem::SetEmpID()
{
	bool idExists = true;
	int id;

	do
	{
		idExists = false;

		cout << " Employee ID: ";
		cin >> id;

		for (int i = 0; i < m_size; ++i)
		{
			if (employeeList[i]->getemployeeID() == id)
			{
				SetConsoleTextAttribute(dConsole, 6);
				cout << " Please try again as this ID is linked to another employee :)\n";
				SetConsoleTextAttribute(dConsole, 15);

				idExists = true;
				break;
			}
		}

	} while (idExists == true);

	return id;
}

void HrSystem::FindEmployee()
{
	bool try_again = false;
	int id;
	int choice;

	if(m_size == 0)
	{
		cout << " The system doesn't have employees to find yet :)\n";
	}
	else
	{
		do
		{
			cout << " What is the type of employee you want to find?:\n 1 - Salaried employee\n 2 - Manager employee\n 3 - Commission employee\n 4 - Hourly employee\n";
			cin >> choice;

			if (choice == 1)
			{
				if (S_count == 0)
				{
					SetConsoleTextAttribute(dConsole, 6);

					cout << " No salaried employees found :(\n";

					SetConsoleTextAttribute(dConsole, 15);


					cout << " Do  you want to try again? (y/n): ";
					char choice2;
					cin >> choice2;

					if (choice2 == 'y' || choice2 == 'Y')
					{
						try_again = true;
					}
					else
					{
						break;
					}
				}
				else
				{
					cout << " Enter the employee ID: ";
					cin >> id;

					int IDX = findEmpID(id);

					if (IDX == -1)
					{
						SetConsoleTextAttribute(dConsole, 6);

						cout << " No employee holds this ID :(\n";

						SetConsoleTextAttribute(dConsole, 15);

					}

					else {
						for (int i = 0; i < m_size; ++i)
						{
							if (id == employeeList[i]->getemployeeID())
							{
								SetConsoleTextAttribute(dConsole, 11);

								cout << " Employee found :)\n";

								SetConsoleTextAttribute(dConsole, 15);

								cout << setw(40) << setfill('-') << endl;

								string show = employeeList[i]->getDetails();
								show += getBenefitFromEmp(id);
								cout << show << endl;

							}
						}
					}
				}
			}

			if (choice == 2)
			{
				if (M_count == 0)
				{
					SetConsoleTextAttribute(dConsole, 6);

					cout << " No Manager employees found :(\n";

					SetConsoleTextAttribute(dConsole, 15);


					cout << " Do  you want to try again? (y/n): ";
					char choice2;
					cin >> choice2;

					if (choice2 == 'y' || choice2 == 'Y')
					{
						try_again = true;

					}
					else
					{
						break;
					}
				}
				else {
					cout << " Enter the employee ID: ";
					cin >> id;

					const int IDX = findEmpID(id);

					if (IDX == -1)
					{
						SetConsoleTextAttribute(dConsole, 6);

						cout << " No employee holds this ID :(\n";

						SetConsoleTextAttribute(dConsole, 15);


					}
					else
					{
						for (int i = 0; i < M_count; ++i)
						{
							if (id == employeeList[i]->getemployeeID())
							{
								SetConsoleTextAttribute(dConsole, 11);

								cout << " Employee found :)\n";

								SetConsoleTextAttribute(dConsole, 15);

								cout << setw(40) << setfill('-') << endl;

								string show = employeeList[i]->getDetails();
								show += getBenefitFromEmp(id);
								cout << show << endl;

							}
						}
					}
				}
			}

			if (choice == 3)
			{
				if (C_count == 0)
				{
					SetConsoleTextAttribute(dConsole, 6);

					cout << " No Commission employees found :(\n";

					SetConsoleTextAttribute(dConsole, 15);


					cout << " Do  you want to try again? (y/n): ";
					char choice2;
					cin >> choice2;

					if (choice2 == 'y' || choice2 == 'Y')
					{
						try_again = true;
					}
					else
					{
						break;
					}
				}
				else {
					cout << " Enter the employee ID: ";
					cin >> id;

					int IDX = findEmpID(id);

					if (IDX == -1)
					{
						SetConsoleTextAttribute(dConsole, 6);

						cout << " No employee holds this ID :(\n";

						SetConsoleTextAttribute(dConsole, 15);


					}
					else
					{
						for (int i = 0; i < m_size; ++i)
						{
							if (id == employeeList[i]->getemployeeID())
							{
								SetConsoleTextAttribute(dConsole, 11);

								cout << " Employee found :)\n";

								SetConsoleTextAttribute(dConsole, 15);

								cout << setw(40) << setfill('-') << endl;

								string show = employeeList[i]->getDetails();
								show += getBenefitFromEmp(id);
								cout << show << endl;


							}
						}
					}
				}

			}
			if (choice == 4)
			{
				if (H_count == 0)
				{
					SetConsoleTextAttribute(dConsole, 6);

					cout << " No Hourly employees found :(\n";

					SetConsoleTextAttribute(dConsole, 15);


					cout << " Do  you want to try again? (y/n): ";
					char choice2;
					cin >> choice2;

					if (choice2 == 'y' || choice2 == 'Y')
					{
						try_again = true;
					}
					else
					{
						break;
					}
				}
				else {
					cout << " Enter the employee ID: ";
					cin >> id;


					int IDX = findEmpID(id);

					if (IDX == -1)
					{
						SetConsoleTextAttribute(dConsole, 6);

						cout << " No employee holds this ID :(\n";

						SetConsoleTextAttribute(dConsole, 15);

					}
					else
					{
						for (int i = 0; i < S_count; ++i)
						{
							if (id == employeeList[i]->getemployeeID())
							{
								SetConsoleTextAttribute(dConsole, 11);

								cout << " Employee found :)\n";

								SetConsoleTextAttribute(dConsole, 15);

								cout << setw(20) << setfill('-') << endl;

								string show = employeeList[i]->getDetails();
								show += getBenefitFromEmp(id);
								cout << show << endl;


							}
						}
					}
				}
			}
		} while (try_again);
	}
}

Department* HrSystem::CreateDepart(int id, string name)
{
	Department* depart = nullptr;
	
	for (int i = 0; i < D_count; i++) {

		if (departList[i].getdepartID() == id)
		{
			return &departList[i]; //@qursaan return direct existing address
		}
	}
	//@qursaan if not existing create new one
	depart = new Department(id, name);

	//@qursaan add it to list
	departList[D_count++] = *depart;

	return depart;
}

bool HrSystem::MChecker(Employee* employee)
{
	const auto managerEmployee = dynamic_cast<ManagerEmployee*>(employee);

	if (managerEmployee)
	{
		return true;
	}

	return false;

}

bool HrSystem::SChecker(Employee* employee)
{
	const auto SalariedEMP = dynamic_cast<SalariedEmployee*>(employee);

	if (SalariedEMP)
	{
		return true;
	}

	return false;
}

bool HrSystem::HChecker(Employee* employee)
{
	const auto HourlyEMP = dynamic_cast<HourlyEmployee*>(employee);

	if (HourlyEMP)
	{
		return true;
	}

	return false;
}

bool HrSystem::CChecker(Employee* employee)
{
	const auto CommissionEMP = dynamic_cast<ComissionEmployee*>(employee);

	if (CommissionEMP)
	{
		return true;
	}

	return false;
}

Employee* HrSystem::Cast(Employee* employee)
{
	const auto managerEmployee = dynamic_cast<ManagerEmployee*>(employee);

	if (managerEmployee)
	{
		return managerEmployee;
	}
	else
	{
		return nullptr;
	}
	
}

void HrSystem::addBenefitToEmp()
{
	int benefitC;

		if (m_size > 0)
		{
			int IDX = -1;

			do
			{
				int id;
				cout << "Enter Employee's ID : ";
				cin >> id;
				IDX = findEmpID(id);

				if (IDX == -1)
				{
					cout << " There's no Employee holds this ID enter a valid ID :)\n";

				}
				else
				{
					break;

				}

			} while (true);

			char choice;
			bool flag = false;
			do
			{
				cout << " How many benefits you wan to add? max(2):";
				cin >> benefitC;

				if(benefitC > 2)
				{
					cout << " Please maximum 2 benefits for each employee :)\n";
					flag = true;
				}

			} while (flag == true);

			for (int i = 0; i < benefitC; ++i)
			{
				cout << " Enter benefit type [1] Health , [2] Dental \n";
				cin >> choice;

				switch (choice)
				{
				case '1':

					employeeList[IDX]->addBenefit(1, employeeList[IDX]->getSalary());
					break;

				case '2':

					employeeList[IDX]->addBenefit(2, employeeList[IDX]->getSalary());
					break;

				default:

					cout << " The little tiny winy system has only two options 1 or 2 :)\n";
					cout << " Do you wish to try again? (y/n): ";
					cin >> choice;

					if (choice == 'y' || choice == 'Y')
					{
						--i;
						break;
					}
				}
			}
			
		}
		else
		{
			cout << "\nThere is no employee to add a benefit :(\n";

		}

}

string HrSystem::getBenefitFromEmp(int id)
{
	int IDX = findEmpID(id);

	do
	{
		if (IDX == -1)
		{
			cout << " There's no Employee holds this ID enter a valid ID :)\n";

		}
		else
		{
			string details = " Benefits for Employee ID " + to_string(id) + ":\n";
			Employee* emp = employeeList[IDX];

			for (int i = 0; i < emp->getBenefitCounter(); i++) {

				details += " Benefit No." + to_string(++i) + " " + emp->getBenefit(i)->displayBenefit();

			}
			return details;
		}

	} while (true);

}