#include <iostream>
using std::cout;
using std::cin;

#include "Car.h"

/*constructor*/
Car::Car(int idNum, int year, const string &color, double miles,
	double enginesize, const string &gasType, const string &polLevel)
	:Vehicle(idNum, year, color, miles)
{
	engineSize = enginesize;
	gas = gasType;
	pollutionlevel = polLevel;
}

/*print task list*/
void Car::taskList()
{
	Vehicle::taskList();  //calls the vehicle's taksList() method
	cout << "4. Engine Diagnostics and Operation\n5. Oil change\n"
	<< "6. Cooling System Repair\n";
}

/*insert a task*/
string Car::insertTask(int choice)
{
	
	switch(choice)
        {
                case 1: return "Scheduled maintenance";
                case 2: return "Brake change";
                case 3: return "Tune-up";
                case 4: return "Engine Diagnostics and Operation";
                case 5: return "Oil change";
                case 6: return "Cooling System Repair";
        }
}

/*print the status*/
void Car::print() const
{
	Vehicle::print();
	cout << "Engine size: " << engineSize << " cubic centimeters\nGas Type: "
	<< gas << "\nEngine Pollution level: " << pollutionlevel << "\n";

}

/*overload << operator*/
ostream &operator<<( ostream &output, const Car &car)
{
	car.print();
}

