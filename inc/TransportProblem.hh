#ifndef TRANSPORTPROBLEM_HH
#define TRANSPORTPROBLEM_HH

#include <vector>
#include <ctime>
#include <cassert>

#include "iTransportProblem.hh"
#include "demander.hh"
#include "supplier.hh"

/*!
  \class TransportProblem
  \brief Main class for describing the transport problem.
*/
class TransportProblem 
//public iTransportProblem<int>
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
 
 //  int minimalRow(int j);
public:
  //void upLeftCorner();
  void minimalElement();
  int minimalElementInMatrix(int **tab);
  bool degenerateSolution();
  int returnNumberOfDemanders();
  int returnNumberOfSuppliers();
  //displaying
  void showTransportCostTable();
  void showOperationTable();
  void showWorkers();
};
#endif
