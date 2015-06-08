#include "supplier.hh"

Supplier::Supplier()
{
	initSupply = 0;
	currentSupply = 0;
}


Supplier::Supplier(long double supplyValue)
{
	initSupply = supplyValue;
		currentSupply = supplyValue;
}


long double Supplier::returnInitSupply()
{
	return initSupply;
}


long double Supplier::returnCurrentSupply()
{
	return currentSupply;
}


bool Supplier::changeCurrentSupply(long double subValue)
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

bool Supplier::changeInitSupply(long double subValue)
{
	if (subValue < 0)
	{
		std::cout << "Init supply is less than 0" << std::endl;
		return false;
	}
	else
	{
		initSupply += subValue;
		return true;
	}
}

void Supplier::showSupplier()
{
	std::cout << "Supplier, init supply: " << returnInitSupply() << " current supply: " << returnCurrentSupply() << std::endl;
}
