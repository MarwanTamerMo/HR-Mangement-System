#pragma once
#include <string>

using namespace std;

class Benefit
{
protected:

	string planType;
	double amount;

public:

	Benefit();
	Benefit(string type, double m_amount);
	virtual ~Benefit();
	virtual double calculateBenefit() = 0;
	double getamount();
	virtual string displayBenefit() = 0;
	virtual void SetData();

};

