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
	Supplier(int supplyValue);
private:
	int initSupply;
	int	currentSupply;
public:
	int returnInitSupply();
	int returnCurrentSupply();
	bool changeCurrentSupply(int subValue);
	void showSupplier();
};
#endif
