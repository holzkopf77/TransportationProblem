#include "TransportProblem.hh"


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

void TransportProblem::minimalElement()
{
  int visitedElement[numberOfSuppliers][numberOfDemanders];
  int allDemand=0;
  int demand=0;//index of column
  int minusCostValue=0;

  for(auto i=0;i<numberOfSuppliers;++i)
    for(auto j=0;j<numberOfDemanders;++j)
      visitedElement[i][j]=0;

  for(auto i=0;i<listOfDemanders.size();++i)
    allDemand+=listOfDemanders[i].returnInitDemand();

  // for(int column=0,row=0;allDemand;++row)
  //   {
  //     //column=minimalMatrix;
  //   }
  // for(int supply=0;supply<listOfSuppliers.size();++supply)
  //   {
  //     demand=minimalRow(supply);
  //     visitedElement[supply][demand]=true;
  //     if(listOfSuppliers[supply].returnCurrentSupply()>listOfDemanders[demand].returnCurrentDemand())
  // 	{
  // 	  minusCostValue=listOfDemanders[demand].returnCurrentDemand;
  // 	  //SupplyZero=false;
  // 	}
  //     else 
  // 	{
  // 	  minusCostValue=listOfSuppliers[indexMinimum].returnCurrentSupply;
  // 	  //Supply=true;
  // 	}
  //     listOfSuppliers[indexMinimum].changeCurrentSupply(-minusCostValue);
  //     listOfDemanders[row].changeCurrentDemand(-minusCostValue);
      
  //     operationTable[supply][demand]=minusCostValue;
  //     visitedElement[supply][demand]=true;
  //     //Zero rest of this column
  //     if(listOfSuppliers[indexMinimum].returnCurrentSupply()==0)
  // 	for(int j=demand+1;j<listOfDemanders.size();++j){
  // 	  operationTable[supply][j]=0;
  // 	  visitedElement[supply][j]=true;
  // 	}
  //     else if(listOfDemanders[row].returnCurrentDemand()==0)
  // 	for(int a=0;demand+1;a<listOfSuppliers.size();++a)
  // 	  {
  // 	    operationTable[supply][j]=0;
  // 	    visitedElement[supply][j]=true;
  // 	  }

  //   }
 
}

int TransportProblem::minimalRow(int j)
{
  int MinimalValueCostTable=1000;
  int index=0;
  for(auto i=0;i<listOfDemanders.size();++i)
    for(auto j=0;j<listOfSuppliers.size();++j)
      if(MinimalValueCostTable>transportCostTable[i][j]){
	MinimalValueCostTable=transportCostTable[i][j];
	index=(i+1)*listOfSuppliers.size();
      }
  return index;
}



