#pragma once
#include "Benefit.h"
#include <string>

class DentalBenefit : public Benefit
{
private:

	string info;

public:

	DentalBenefit();
	DentalBenefit(string, double);
	double calculateBenefit();
	string displayBenefit();

};

