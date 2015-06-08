#include <iostream>
#include "demander.hh"
#include "supplier.hh"
#include "TransportProblem.hh"

using namespace std;
int main()
{
	TransportProblem newProblem(5, 4, 100, 10);
	
	newProblem.showOperationTable();
	newProblem.showTransportCostTable();
	newProblem.minimalElement();
	newProblem.showOperationTable();
	newProblem.showPotencials();
	//while the problem is degenerated
	while (!newProblem.degenerateSolution())
	{
		newProblem.ePerturbation();
		newProblem.minimalElement();
	}
	newProblem.checkPotencials();
	newProblem.showWorkers();
	newProblem.showPotencials();
	cin.get();
}
