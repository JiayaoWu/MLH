#include <iostream>
using std::cout;
using std::cin;

#include "Bus.h"

/*constructor*/
Bus::Bus(int idNum, int year, const string &color, double miles, int passengerCap)
	: Vehicle(idNum, year, color, miles)
{
	passengerCapacity = passengerCap;
}

/*print task list*/
void Bus::taskList()
{
	Vehicle::taskList();
	cout << "4. Adding seats\n5. Remove seats\n6. Clean the bus\n";

}

/*return the name of a task*/
string Bus::insertTask(int choice)
{
	switch(choice)
        {       
                case 1: return "Scheduled maintenance";
                case 2: return "Brake change";
                case 3: return "Tune-up";
                case 4: return "Adding seats";
                case 5: return "Remove seats";
        	case 6: return "Clean the bus";
	}
}

/*print status*/
void Bus::print() const
{
	Vehicle::print();
	cout << "Passenger capacity: " << passengerCapacity <<"\n";
}

/*overload << */
ostream &operator<<( ostream &output, const Bus &bus)
{
	bus.print();
}
