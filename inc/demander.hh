#ifndef DEMANDER_HH
#define DEMANDER_HH

#include <iostream>

/*!
	\class Demander
	\brief Place for the demanded commodity
*/
class Demander
{
public:
	Demander();
	Demander(long double demandValue);
private:
	long double initDemand;
	long double	currentDemand;
public:
	long double returnInitDemand();
	long double returnCurrentDemand();
	bool changeCurrentDemand(long double subValue);
	bool changeInitDemand(long double subValue);
	void showDemander();
};
#endif
