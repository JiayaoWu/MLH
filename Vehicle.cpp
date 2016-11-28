#include <iostream>
using std::cout;
using std::cin;

#include "Vehicle.h"

/*constructor*/
Vehicle::Vehicle(int idNum, int year, const string &color, double miles)
{
	id = idNum;
	modelYear = year;
	Color = color;
	mileage = miles;
	listOfTask = new List();
}

/*destructor*/
Vehicle::~Vehicle()
{
	delete listOfTask;
	listOfTask = NULL;
}


/*print a list of tasks*/
void Vehicle::taskList()
{
	cout << "Here is a list to add the tasks:\n"
	<< "1. Scheduled maintenance\n2. Brake change\n3. Tune-up\n";
}

/*returns a string*/
string Vehicle::insertTask(int choice)
{
	return "";

}

/*add a task*/
void Vehicle::addTask(string &nameOfTask)
{
	cout << "What is the cost of parts -> ";
        cin >> costPart;
        cout << "What is the cost of labor -> ";
        cin >> costLabor;
        Task *task = new Task(nameOfTask, costLabor, costPart);
        listOfTask->insert(*task);

}

/*print the bill of vehicle*/
void Vehicle::printBill() const
{
	listOfTask->print();
}

/*print the status of the vehicle*/
void Vehicle::print() const
{
	cout << "ID: " << id << "\nModel year: " << modelYear
	<< "\nColor: " << Color << "\nMileage: " << mileage << " km\n";
}


/*overload the << operator*/
ostream &operator<<(ostream &output, const Vehicle &vehicle)
{
	vehicle.print();
}
