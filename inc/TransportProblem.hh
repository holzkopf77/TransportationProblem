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
  std::vector<int> potencialsV;
  std::vector<int> potencialsU;
 //  int minimalRow(int j);
public:
  void minimalElement();
  int minimalElementInMatrix(int **tab);
  bool degenerateSolution();
  void ePerturbation();
  bool checkPotencials();
  int returnNumberOfDemanders();
  int returnNumberOfSuppliers();
  
  //displaying
  void showTransportCostTable();
  void showOperationTable();
  void showPotencials();
  void showWorkers();
};
#endif
