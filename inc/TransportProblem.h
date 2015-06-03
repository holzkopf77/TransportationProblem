#ifndef TRANSPORTPROBLEM_H
#define TRANSPORTPROBLEM_H

#include <vector>
#include <ctime>
#include <cassert>

#include "iTransportProblem.hh"
#include "demander.h"
#include "supplier.h"

/*!
	\class TransportProblem
	\brief Main class for describing the transport problem.
*/
class TransportProblem:
	public iTransportProblem<int>
{
public:
	TransportProblem();
	TransportProblem(int nrDemanders, int nrSuppliers, int totalDemand, int costRange);
	~TransportProblem();
private:
	int numberOfDemanders;
	int numberOfSuppliers;
	std::vector<Demander> listOfDemanders;
	std::vector<Supplier> listOfSuppliers;
	int** transportCostTable;
	int** operationTable;
public:
	void upLeftCorner();
	int returnNumberOfDemanders();
	int returnNumberOfSuppliers();
	//displaying
	void showTransportCostTable();
	void showOperationTable();
	void showWorkers();
};
#endif
