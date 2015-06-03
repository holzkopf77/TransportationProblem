#include "TransportProblem.h"


TransportProblem::TransportProblem()
{
	numberOfDemanders = 0;
	numberOfSuppliers = 0;

}


TransportProblem::TransportProblem(int nrDemanders, int nrSuppliers,int totalDemand, int costRange)
{
	//garbage value for division
	int moduloValue;
	srand(time(NULL));

	int insertedDemandValue = 0; 
	int insertedSupplyValue = 0;

	//balanced case of transportation problem
	int totalSupply = totalDemand;

	numberOfDemanders = nrDemanders;
	numberOfSuppliers = nrSuppliers;

	std::vector<int>demandsToAssing;
	std::vector<int>suppliesToAssing;

	for (int i = 0; i < numberOfDemanders; i++)
		demandsToAssing.push_back(0);
	for (int i = 0; i < numberOfSuppliers; i++)
		suppliesToAssing.push_back(0);
	

	while (totalDemand > 0)
	{
		//find value of a demand
		for (int i = 0; i < numberOfDemanders; i++)
		{
			if (totalDemand != 0)
			{
				moduloValue = rand() % totalDemand;
				if (moduloValue == 0)
					insertedDemandValue = 0;
				else
					insertedDemandValue = totalDemand / (moduloValue);
			}
			else
			{
				insertedDemandValue = 0;
			}

			totalDemand -= insertedDemandValue;
			demandsToAssing[i] = demandsToAssing[i] + insertedDemandValue;
		}
	}

	//create all demanders
	for (int i = 0; i < numberOfDemanders; i++)
	{
		Demander newDemander(demandsToAssing[i]);
		listOfDemanders.push_back(newDemander);
	}

	while (totalSupply > 0)
	{
		//find value of a supply
		for (int j = 0; j < numberOfSuppliers; j++)
		{
			if (totalSupply != 0)
			{
				moduloValue = rand() % totalSupply;
				if (moduloValue == 0)
					insertedSupplyValue = 0;
				else
					insertedSupplyValue = totalSupply / (moduloValue);
			}
			else
			{
				insertedSupplyValue = 0;
			}

			totalSupply -= insertedSupplyValue;
			suppliesToAssing[j] = suppliesToAssing[j] + insertedSupplyValue;
		}
	}
	//create all suppliers
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		Supplier newSupply(suppliesToAssing[i]);
		listOfSuppliers.push_back(newSupply);
	}

	//memory allocation for cost table
	transportCostTable = new int*[numberOfSuppliers];
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		transportCostTable[i] = new int[numberOfDemanders];
	}

	//generate random costs from all paths
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			transportCostTable[i][j] = rand() % costRange;
		}
	}

	//memory allocation for operation table
	operationTable = new int*[numberOfSuppliers];
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		operationTable[i] = new int[numberOfDemanders];
	}

	//init 0 for all operations inside operation table
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			operationTable[i][j] = 0;
		}
	}
}


TransportProblem::~TransportProblem()
{
	//free all memory
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		delete[] operationTable[i];
		delete[] transportCostTable[i];
	}
	delete[] operationTable;
	delete[] transportCostTable;
}


int TransportProblem::returnNumberOfDemanders()
{
	return numberOfDemanders;
}


int TransportProblem::returnNumberOfSuppliers()
{
	return numberOfSuppliers;
}


void TransportProblem::showTransportCostTable()
{
	std::cout << "Transport costs table:" << std::endl;
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			std::cout << transportCostTable[i][j] << " ";
		}
		std::cout << std::endl;
	}

}


void TransportProblem::showOperationTable()
{
	std::cout << "Operation table:" << std::endl;
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			std::cout << operationTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void TransportProblem::showWorkers()
{
	//show all demanders
	for (auto i : listOfDemanders)
		i.showDemander();
	//show all suppliers
	for (auto i : listOfSuppliers)
		i.showSupplier();
}

void TransportProblem::upLeftCorner()
{
	for (int i = 0; i < returnNumberOfSuppliers(); )
	{
		for (int j = 0; j < returnNumberOfDemanders(); )
		{
			if (listOfSuppliers[i].returnCurrentSupply() >= listOfDemanders[j].returnCurrentDemand())
			{
				operationTable[i][j] = listOfDemanders[j].returnCurrentDemand();
				listOfSuppliers[i].changeCurrentSupply(-listOfDemanders[j].returnCurrentDemand());
				listOfDemanders[j].changeCurrentDemand(-listOfDemanders[j].returnCurrentDemand());
				j++;
			}
			else if (listOfSuppliers[i].returnCurrentSupply() < listOfDemanders[j].returnCurrentDemand())
			{
				if (listOfSuppliers[i].returnCurrentSupply() == 0)
				{
					i++;
				}
				else
				{
					operationTable[i][j] = listOfSuppliers[i].returnCurrentSupply();
					listOfSuppliers[i].changeCurrentSupply(-listOfSuppliers[i].returnCurrentSupply());
					listOfDemanders[j].changeCurrentDemand(-listOfSuppliers[i].returnCurrentSupply());
					i++;
				}
			else

			}
		}
	
	}
}