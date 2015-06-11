#include "TransportProblem.hh"


TransportProblem::TransportProblem()
{
		//balanced case of transportation problem
		int totalSupply = 100;

		numberOfDemanders = 5;
		numberOfSuppliers =4;

		std::vector<int>demandsToAssing{ 10, 15, 30, 10, 35 };
		std::vector<int>suppliesToAssing{ 20, 30, 10, 40 };

		//create all demanders
		for (int i = 0; i < numberOfDemanders; i++)
		{
			Demander newDemander(demandsToAssing[i]);
			listOfDemanders.push_back(newDemander);
		}

		//create all suppliers
		for (int i = 0; i < numberOfSuppliers; i++)
		{
			Supplier newSupply(suppliesToAssing[i]);
			listOfSuppliers.push_back(newSupply);
		}

		//memory allocation for cost table
		transportCostTable = new int*[numberOfDemanders];
		for (int i = 0; i < numberOfDemanders; i++)
		{
			transportCostTable[i] = new int[numberOfSuppliers];
		}

		transportCostTable[0][0] = 5;
		transportCostTable[0][1] = 2;
		transportCostTable[0][2] = 1;
		transportCostTable[0][3] = 5;
	
		transportCostTable[1][0] = 3;
		transportCostTable[1][1] = 1;
		transportCostTable[1][2] = 1;
		transportCostTable[1][3] = 4;

		transportCostTable[2][0] = 1;
		transportCostTable[2][1] = 1;
		transportCostTable[2][2] = 2;
		transportCostTable[2][3] = 3;

		transportCostTable[3][0] = 2;
		transportCostTable[3][1] = 1;
		transportCostTable[3][2] = 5;
		transportCostTable[3][3] = 1;

		transportCostTable[4][0] = 2;
		transportCostTable[4][1] = 1;
		transportCostTable[4][2] = 2;
		transportCostTable[4][3] = 6;

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
		int T[5][4] {{0, 0, 10, 0},{ 0, 15, 0, 0 },{ 20, 10, 0, 0 },{ 0, 5, 0, 5 },{ 0, 0, 0, 35 }};
		for (int i = 0; i < 5;i++)
			for (int j = 0; j < 4; j++)
				tabTestowa[i][j] = T[i][j];
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
	
	for (int i = 0; i < numberOfDemanders; i++)
		potencialsU.push_back(0);
	for (int i = 0; i < numberOfSuppliers; i++)
		potencialsV.push_back(0);

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


void TransportProblem::showTransportCostTableTest()
{
	std::cout << "<------------------------Tabela kosztow----------------------->" << std::endl;
	for (int i = 0; i < numberOfDemanders; i++)
	{
		for (int j = 0; j < numberOfSuppliers; j++)
		{
			std::cout << transportCostTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void TransportProblem::showOperationTable()
{
	std::cout << "<------------------------Tabela operacji--------------------->" << std::endl;
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			std::cout << operationTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TransportProblem::showPotencials()
{
	std::cout << "Potencials table:" << std::endl;
	for (auto V : potencialsV)
		std::cout <<"   "<< V << " ";
	std::cout << std::endl;
	for (auto U : potencialsU)
		std::cout << U << std::endl;
}

void TransportProblem::showTransportCostTable()
{
	std::cout << "<------------------------Tabela kosztow---------------------->" << std::endl;
	for (int i = 0; i < numberOfSuppliers; i++)
	{
		for (int j = 0; j < numberOfDemanders; j++)
		{
			std::cout << transportCostTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void TransportProblem::showWorkers()
{
	//show all demanders
	std::cout << "SPIS ODBIORCOW" << std::endl;
	std::cout << std::endl;
	for (auto i : listOfDemanders)
		i.showDemander();
	//show all suppliers
	std::cout << std::endl;
	std::cout << "SPIS MAGAZYNOW" << std::endl;
	std::cout << std::endl;
	for (auto i : listOfSuppliers)
		i.showSupplier();
}

void TransportProblem::minimalElement()
{
  int **visitedElement=new int*[numberOfSuppliers];
  for(int i=0;i<numberOfSuppliers;++i)visitedElement[i]=new int[numberOfDemanders];
  int allDemand=0;
  int minusCostValue=0;
  int index=0;
  int s=0,d=0;

  for(int i=0;i<numberOfSuppliers;++i)
    for(int j=0;j<numberOfDemanders;++j)
      visitedElement[i][j]=0;

  for(unsigned int i=0;i<listOfDemanders.size();++i)
    allDemand+=listOfDemanders[i].returnInitDemand();

  while(allDemand)
    {
      //assignment to x and y specific value index in 2D matrix from 1D
      index=minimalElementInMatrix(visitedElement);
      s=index/listOfDemanders.size();
      d=index%listOfDemanders.size();
      if(listOfDemanders[d].returnCurrentDemand()<listOfSuppliers[s].returnCurrentSupply())
	{
	  minusCostValue=listOfDemanders[d].returnCurrentDemand();
	  operationTable[s][d]=minusCostValue;
	  allDemand-=minusCostValue;
	  listOfDemanders[d].changeCurrentDemand(-minusCostValue);
	  listOfSuppliers[s].changeCurrentSupply(-minusCostValue);
	}
      else 
	{
	  minusCostValue=listOfSuppliers[s].returnCurrentSupply();
	  operationTable[s][d]=minusCostValue;
	  allDemand-=minusCostValue;
	  listOfDemanders[d].changeCurrentDemand(-minusCostValue);
	  listOfSuppliers[s].changeCurrentSupply(-minusCostValue);
	}
      if(!listOfDemanders[d].returnCurrentDemand())
	for(unsigned int i=0;i<listOfSuppliers.size();++i)visitedElement[i][d]=1;
      if(!listOfSuppliers[s].returnCurrentSupply())
	for(unsigned int i=0;i<listOfDemanders.size();++i)visitedElement[s][i]=1;
    }
  for(int i=0;i<numberOfSuppliers;++i)delete [] visitedElement[i];
  delete visitedElement;
}

int TransportProblem::minimalElementInMatrix(int **tab)
{
  int MinimalValueCostTable=1000;
  int index=0;
  for(unsigned int i=0;i<listOfSuppliers.size();++i)
    for(unsigned int  j=0;j<listOfDemanders.size();++j)
      {
	if(tab[i][j])continue;
	if(MinimalValueCostTable>transportCostTable[i][j]){
	  MinimalValueCostTable=transportCostTable[i][j];
	  index=i*listOfDemanders.size()+j;
	}
      }
  return index;
}

 bool TransportProblem::degenerateSolution()
 {
   int BasisElements=0;
   for(unsigned int i=0;i<listOfSuppliers.size();++i)
     for(unsigned int j=0;j<listOfDemanders.size();++j)
       if(operationTable[i][j])BasisElements+=1;
   if(BasisElements!=(numberOfDemanders+numberOfSuppliers-1))
     {
       std::cout<<"Rozwiazanie niezdegenerowane"<<std::endl;
       return false;
     }
   return true;
 }

 void TransportProblem::ePerturbation()
 {
	 //for n - 1 demanders add small numeber eta
	 int i = 0;
	 for (i = 0; i < listOfDemanders.size(); i++)
	 {
		 listOfDemanders[i].changeInitDemand(0.000000001);
	 }
	 //for the last supplier add small number eta * number of demanders
	 listOfSuppliers[i].changeInitSupply(000000001 * returnNumberOfDemanders());
 }
 void TransportProblem::showOperationTableTest()
 {
	 std::cout << "<------------------------Tabela operacji--------------------->" << std::endl;
	 for (int i = 0; i <numberOfDemanders; i++)
	 {
		 for (int j = 0; j < numberOfSuppliers; j++)
		 {
			 std::cout << tabTestowa[i][j] << " ";
		 }
		 std::cout << std::endl;
	 }
	 std::cout << std::endl;
 }

 bool TransportProblem::checkPotencials()
 {
	 //temporary table for checking potencials (memory allocation)
	 int** tempPotencialsTable = new int*[numberOfSuppliers];
	 for (int i = 0; i < numberOfSuppliers; i++)
	 {
		 tempPotencialsTable[i] = new int[numberOfDemanders];
	 }
	 
	 //assign 0 to all poles
	 for (int i = 0; i < numberOfSuppliers; i++)
		 for (int j = 0; j < numberOfDemanders; j++)
			 tempPotencialsTable[i][j] = 0;

	 //assign correct value inside the potencials table;
	 for (int i = 0; i < numberOfSuppliers; i++)
	 {
		 for (int j = 0; j < numberOfDemanders; j++)
		 {
			 if (operationTable[i][j] != 0)
				 tempPotencialsTable[i][j] = transportCostTable[i][j];
		 }
	 }
	 //find potencials
	 // check signs

	 /*show TEMPORARY TABLE*/
	 /*
	 for (int i = 0; i < numberOfSuppliers; i++)
	 {
		 std::cout << std::endl;
		 for (int j = 0; j < numberOfDemanders; j++)
		 {
			 std::cout << tempPotencialsTable[i][j] <<" ";
		 }
	 }
	 */
	 return true;
 }