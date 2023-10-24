#include "Benefit.h"
#include <iostream>

using namespace std;

Benefit::Benefit()
{
	amount = 0;
}

Benefit::Benefit(string type, double m_amount)
{
	planType = std::move(type);
	amount = m_amount;
	
}


Benefit::~Benefit()
{
	
}

double Benefit::getamount()
{
	return amount;
}

void Benefit::SetData()
{
}