#include "demander.hh"

Demander::Demander()
{
	initDemand = 0;
	currentDemand = 0;
}


Demander::Demander(long double demandValue)
{
	currentDemand = demandValue;
	initDemand = demandValue;
}


long double Demander::returnCurrentDemand()
{
	return currentDemand;
}


long double Demander::returnInitDemand()
{
	return initDemand;
}


bool Demander::changeCurrentDemand(long double subValue)
{
	if (currentDemand <= 0)
	{
		std::cout << "Demander with init demand:" << returnInitDemand() << " is full. Can not take more supply." << std::endl;
		return false;
	}
	else
	{
		currentDemand += subValue;
		return true;
	}
}

bool Demander::changeInitDemand(long double subValue)
{
	if ( subValue < 0)
	{
		std::cout << "Init demand is smaller than 0" << std::endl;
		return false;
	}
	else
	{
		initDemand += subValue;
		return true;
	}
}

void Demander::showDemander()
{
	std::cout << "Demander, init demand: " << returnInitDemand() << " current demand: " << returnCurrentDemand() << std::endl;
}
