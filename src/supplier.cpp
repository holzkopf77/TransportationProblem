#include "supplier.h"

Supplier::Supplier()
{
	initSupply = 0;
	currentSupply = 0;
}


Supplier::Supplier(int supplyValue)
{
	initSupply = supplyValue;
		currentSupply = supplyValue;
}


int Supplier::returnInitSupply()
{
	return initSupply;
}


int Supplier::returnCurrentSupply()
{
	return currentSupply;
}


bool Supplier::changeCurrentSupply(int subValue)
{
	if (currentSupply <= 0)
	{
		std::cout << "Supplier with init supply:" << returnInitSupply() << " is empty. Can not send more supply." << std::endl;
		return false;
	}
	else
	{
		currentSupply += subValue;
		return true;
	}
}

void Supplier::showSupplier()
{
	std::cout << "Supplier, init supply: " << returnInitSupply() << " current demand: " << returnCurrentSupply() << std::endl;
}