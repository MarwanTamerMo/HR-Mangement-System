#include "DentalBenefit.h"
#include <iostream>

using namespace std;

DentalBenefit::DentalBenefit()
{

}

DentalBenefit::DentalBenefit(string m_info, double salary)
{
	info = std::move(m_info);
	this->amount = salary;
}

double DentalBenefit::calculateBenefit()
{
	return (amount * 0.1);
}

string DentalBenefit::displayBenefit()
{
	string details = "Plan type: " + info + "\n";
	details += to_string(calculateBenefit());

	return details;
}