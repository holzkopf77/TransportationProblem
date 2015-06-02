#include <iostream>
#include "demander.hh"
#include "supplier.hh"
#include "TransportProblem.hh"

using namespace std;
int main()
{
	TransportProblem newProblem(5, 2, 100, 10);
	newProblem.showOperationTable();
	newProblem.showTransportCostTable();
	cout<<newProblem.minimalRow(0)<<endl;
	newProblem.minimalElement();
	newProblem.showWorkers();
}
