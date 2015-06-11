#include <iostream>
#include "demander.hh"
#include "supplier.hh"
#include "TransportProblem.hh"

int main()
{
	std::cout << "   Projektowanie Algorytmow i Metod Sztucznej Inteligencji    " << std::endl;
	std::cout << "<--------------------PROBLEM TRANSPORTOWY-------------------->" << std::endl;
	std::cout << std::endl;
	std::cout << "         Autorzy: Filip Chodorowski, Daniel Budynski          " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//demanders,suppliers,total demand, range of costs
	//TransportProblem newProblem(6, 6, 1500, 5);
	TransportProblem newProblem;
	std::cout << "<--------------------Sytuacja poczatkowa--------------------->" << std::endl;
	std::cout << std::endl;
	newProblem.showOperationTable();
	newProblem.showTransportCostTableTest();
	newProblem.minimalElement();
	std::cout << "<-----------------------Sytuacja koncowa--------------------->" << std::endl;
	std::cout << std::endl;
	newProblem.showOperationTableTest();
	newProblem.showWorkers();
	std::cin.get();
}
