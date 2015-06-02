#include "demander.h"
#include "supplier.h"
#include "TransportProblem.h"

int main()
{
	TransportProblem newProblem(5, 5, 100, 10);
	newProblem.showOperationTable();
	newProblem.showTransportCostTable();
	newProblem.showWorkers();
	system("pause");

}