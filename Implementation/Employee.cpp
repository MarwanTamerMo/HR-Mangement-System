#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee()
{
    Dep = nullptr; //@qursaan new Department;
    BenefitCounter = 0;
    MaxNumOfBenefits = 2;
    BenefitList = new Benefit*[MaxNumOfBenefits]; //@qursaan 100 -> maxnumofbenfits
}

Employee::Employee(int m_id, string m_name, string m_phone, string m_email, string m_jobTitle)
{
    //@qursaan initialize all in empty constructor
	employeeID = m_id;
	name = m_name;
	email = m_email;
	phone = m_phone;
	JobTitle = m_jobTitle;
}

Employee::~Employee()
{
    for (int i = 0; i < BenefitCounter; ++i) {
        delete BenefitList[i];
    }
    delete[] BenefitList;
}

int Employee::getemployeeID()
{
	return employeeID;
}

void Employee::setDepart(Department* depart)
{
	Dep = depart;
}

void Employee::ShowDepart()
{
    if (Dep != nullptr)
        Dep->print();
    else
        cout << "No Department" << endl;
}

void Employee::addBenefit(int type, double salary)
{
    if (BenefitCounter < MaxNumOfBenefits)
    {
        switch (type)
        {
        case 1:

            BenefitList[BenefitCounter++] = new HealthBenefit(" Health Insurance ", salary);
            break;

        case 2:

            BenefitList[BenefitCounter++] = new DentalBenefit(" Dental Benefit ", salary);
            break;
        }

    }
    else
    {
        cout << " The Employee finished his benefits :(\n";

    }
}

int Employee::getBenefitCounter()
{
    return BenefitCounter;
}

Benefit* Employee::getBenefit(int index)
{
    if (index >= 0 && index < BenefitCounter)
    {
        return BenefitList[index]; 
    }
    else
    {
        return nullptr;
    }
}
