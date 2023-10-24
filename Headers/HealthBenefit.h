#pragma once
#include "Benefit.h"
#include <string>

class HealthBenefit : public Benefit
{
private:

	string info;
	double amount;

public:

	HealthBenefit();
	HealthBenefit(string, double);
	virtual ~HealthBenefit();
	double calculateBenefit();
	string displayBenefit();

};

