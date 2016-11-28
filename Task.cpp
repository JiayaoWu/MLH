#include <iostream>
using std::cout;
#include "Task.h"

/*constructor*/
Task::Task(const std::string & nameOfTask, const double laborCost, const double partCost)
{
	name = nameOfTask;
	costofLabor = laborCost;
	costofPart = partCost;
}

/*Returns cost of labor*/
double Task::getLabor() const
{
	return costofLabor;
}

/*Returns cost of part*/
double Task::getPart() const
{
	return costofPart;
}

/*Prints name of task, cost of labor and part*/
void Task::print() const
{
	cout << "Task name: " << name << "\nCost of Labor: " << costofLabor
	<< "\nCost of Part: " << costofPart << "\n";

}

