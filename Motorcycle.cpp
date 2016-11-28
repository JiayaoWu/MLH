#include <iostream>
using std::cout;
using std::cin;

#include "Motorcycle.h"

/*Constructor*/
Motorcycle::Motorcycle(int idNum, int year, const string &color, double miles, 
	double engine, double front, double back)
	: Vehicle(idNum, year, color, miles)
{
	enginesize = engine;
	frontSize = front;
	backSize = back;
}

/*print task list*/
void Motorcycle::taskList()
{
	Vehicle::taskList();
	cout << "4. Change Front Wheel\n5. Change Back Wheel\n6. Engine Diagnostics and Operation\n";

}

/*return string*/
string Motorcycle::insertTask(int choice)
{
	switch(choice)
        {
                case 1: return "Scheduled maintenance";
                case 2: return "Brake change";
                case 3: return "Tune-up";
                case 4: return "Change Front Wheel";
                case 5: return "Change Back Wheel";
                case 6: return "Engine Diagnostics and Operation";
        }
}

/*print status*/
void Motorcycle::print() const
{
	Vehicle::print();
	cout << "Engine size: " << enginesize << " cubic centimeters\nFront Wheel Size: "
	<< frontSize << " cubic centimeters\nBack Wheel Size: " << backSize << " cubic centimeters\n";
}


/*overload << */
ostream &operator<<( ostream &output, const Motorcycle &motorcycle)
{
	motorcycle.print();
}
