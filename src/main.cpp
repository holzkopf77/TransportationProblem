#include <iostream>
#include "demander.hh"
#include "supplier.hh"
#include "TransportProblem.hh"

using namespace std;
int main()
{
	TransportProblem newProblem(5, 5, 100, 10);
	newProblem.showOperationTable();
	newProblem.showTransportCostTable();
	newProblem.minimalElement();
	newProblem.showOperationTable();
	newProblem.showWorkers();
}
