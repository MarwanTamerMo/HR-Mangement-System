#include "HealthBenefit.h"
#include <iostream>

using namespace std;

HealthBenefit::HealthBenefit()
{
	info = " No Info ";
	amount = 0;
}

HealthBenefit::HealthBenefit(string m_info, double m_amount)
{
	this->amount = m_amount;
	this->info = std::move(m_info);
}

HealthBenefit::~HealthBenefit()
{

}

double HealthBenefit::calculateBenefit()
{
	return (amount * 0.2);
}

string HealthBenefit::displayBenefit()
{
	string details = "Plan type: " + info + "\n";

	details += "    Coverage: " + to_string(calculateBenefit()) + "$" + "\n";

	return details;
}