#include "demander.h"

Demander::Demander()
{
	initDemand = 0;
	currentDemand = 0;
}


Demander::Demander(int demandValue)
{
	currentDemand = demandValue;
	initDemand = demandValue;
}


int Demander::returnCurrentDemand()
{
	return currentDemand;
}


int Demander::returnInitDemand()
{
	return initDemand;
}


bool Demander::changeCurrentDemand(int subValue)
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
