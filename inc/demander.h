#ifndef DEMANDER_H
#define DEMANDER_H

#include <iostream>

/*!
	\class Demander
	\brief Place for the demanded commodity
*/
class Demander
{
public:
	Demander();
	Demander(int demandValue);
private:
	int initDemand;
	int	currentDemand;
public:
	int returnInitDemand();
	int returnCurrentDemand();
	bool changeCurrentDemand(int subValue);
};
#endif
