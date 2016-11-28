#include <iostream>
using std::cout;
using std::cin;

#include "Hybrid.h"
/*constructpr*/
Hybrid::Hybrid(int idNum, int year, const string &color, double miles,
	double enginesize, const string &gasType, const string &polLevel,
	double power, double usage, double capacity)
	: Car(idNum, year, color, miles, enginesize, gasType, polLevel)
{
	motorPower = power;
	totalUsage = usage;
	batteryCapacity = capacity;
}

/*print task list*/
void Hybrid::taskList()
{
	Car::taskList();
	cout << "7. Update battery\n8. Motor Control Fix\n";
}

/*return name a task*/
string Hybrid::insertTask(int choice)
{
	switch(choice)
        {
                case 1: return "Scheduled maintenance";
                case 2: return "Brake change";
                case 3: return "Tune-up";
                case 4: return "Engine Diagnostics and Operation";
                case 5: return "Oil change";
                case 6: return "Cooling System Repair";
		case 7: return "Update battery";
		case 8: return "Motor Control Fix";
        }
}

/*print status*/
void Hybrid::print() const
{
	Car::print();
	cout << "Motor Power: " << motorPower << " Watts\nMotor overall usage: "
	<< totalUsage << " hours\nBatter Capacity: " << batteryCapacity
	<< " Ah\n";

}

/*overload << operator*/
ostream &operator<<( ostream &output, const Hybrid &hybrid)
{
	hybrid.print();
}

