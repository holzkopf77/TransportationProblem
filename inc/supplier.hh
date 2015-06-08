#ifndef SUPLIER_HH
#define SUPLIER_HH

#include <iostream>

/*!
	\class Demander
	\brief Place for the supplied commodity
*/
class Supplier
{
public:
	Supplier();
	Supplier(long double supplyValue);
private:
	long double initSupply;
	long double	currentSupply;
public:
	long double returnInitSupply();
	long double returnCurrentSupply();
	bool changeCurrentSupply(long double subValue);
	bool changeInitSupply(long double subValue);
	void showSupplier();
};
#endif
