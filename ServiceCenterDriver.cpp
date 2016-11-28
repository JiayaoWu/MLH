#include "MLH.h"
#include "Vehicle.h"
#include "Car.h"
#include "Hybrid.h"
#include "Motorcycle.h"
#include "Bus.h"

#include <iomanip>
using std::setprecision;
using std::fixed;

#include <iostream>
using std::cout;
using std::cin;

main()
{
	cout << fixed <<setprecision(2);
	
	MLH<Vehicle> *center = new MLH<Vehicle>();
	center->MLH_set_print(1);
	int choice;
	int taskChoice;	

	int id;
	int typeOfCar;
	int year;
	string color;
	double mileage;

	double enginesize;
	string gas;
	string polLevel;

	double motorPower;
	double motorusage;
	double batteryCap;

	double frontsize;
	double backsize;

	int passengerCap;

	Vehicle *vehicle;
	Vehicle *removedVehicle;

	bool result;

	string name;
	cout << "Welcome to the Vehicle Service Center!\n";
	do {
		cout << "Here is the menu: \n"
		<< "1. Add a vehicle to the center \n"
		<< "2. Add task(s) to a vehicle in the center \n"
		<< "3. Check out a vehicle and print its bill \n"
		<< "4. View a report of all vehicles \n"
		<< "5. View the status of a specific vehicle \n"
		<< "6. Exit \n"
		<< "Your choice-> ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Which type of vehicle would you like to add? \n"
				<< "1. Car \n2. Hybrid \n3. Motorcycle \n4. Bus\n"
				<< "Your choice-> ";
				cin >> typeOfCar; 
				cout << "Please specify a unique id for this vehicle (1 - 100000) -> ";
				cin >> id;
				cout << "Please specify the model year for this vehicle (2001 - 2015) -> ";
				cin >> year;
				cout << "Please specify the color for this vehicle-> ";
				cin >> color;
				cout << "Please specify the mileage for this vehicle-> ";
				cin >> mileage;
				switch(typeOfCar)
				{
					case 1:
						cout << "Please specify the Engine Size (in cubic centimeters) -> ";
						cin >> enginesize;
						cout << "Please specify the Gas type (premium, plus or regular) -> ";
						cin >> gas;
						cout << "Please specify the engine pollution level (low, medium or high) -> ";
						cin >> polLevel;
						vehicle = new Car(id, year, color, mileage, enginesize, gas, polLevel);
						break;
					case 2:
						cout << "Please specify the Engine Size (in cubic centimeters) -> ";
                                                cin >> enginesize;
                                                cout << "Please specify the Gas type (premium, plus or regular) -> ";
                                                cin >> gas;
                                                cout << "Please specify the engine pollution level (low, medium or high) -> ";
                                                cin >> polLevel;
						cout << "Please specify the motor power (in watts) -> ";
						cin >> motorPower;
						cout << "Please specify the motor overall usage (in hours) -> ";
						cin >> motorusage;
						cout << "Please specify the battery capacity (in Ah) -> ";
						cin >> batteryCap;
						vehicle = new Hybrid(id, year, color, mileage, enginesize, gas, polLevel, 
								motorPower, motorusage, batteryCap);
						break;
					case 3:
						cout << "Please specify the Engine Size (in cubic centimeters) -> ";
                                                cin >> enginesize;
						cout << "Please specify the front wheel size (in cubic centimeters) -> ";
						cin >> frontsize;
						cout << "Please specify the back wheel size (in cubic centimeters) -> ";
						cin >> backsize;
						vehicle = new Motorcycle(id, year, color, mileage, enginesize, frontsize, backsize);  
						break;
					case 4:
						cout << "Please specify the Passenger Capacity -> ";
						cin >> passengerCap;
						vehicle = new Bus(id, year, color, mileage, passengerCap);
						break;
					default:
						cout << "Invalid choice \n";
				}
				result = center->MLH_insert(id, vehicle);
				if (!result) { //if this id already exists
					cout << "Sorry, you didn't add the vehicle successfully.\n\n";
				} else {
					cout << "\nYou just added the vehicle successfully!\n";
					vehicle->taskList(); //for adding the tasks
					cout << "Your choice -> ";
					cin >> taskChoice;
					name = vehicle->insertTask(taskChoice);
					vehicle->addTask(name);
					cout << "\n";	
				}
				break;
			case 2:
				cout << "Which vehicle to add task? Please specify its id: ";
				cin >> id;
				vehicle = center->MLH_get(id);
				if (vehicle == NULL) {
					cout << "\nSorry, this vehicle does not exist.\n\n";
				} else {
					vehicle->taskList();
					cout << "Your choice -> ";
					cin >> taskChoice;
					name = vehicle->insertTask(taskChoice);
					vehicle->addTask(name);
					cout << "\n";
				}
				break;
			case 3:
				cout << "Which vehicle do you want to check out? Please specify the id -> ";
				cin >> id;
				removedVehicle = center->MLH_delete(id);
				if (removedVehicle != NULL) {
					cout << "Here is the bill details \n";
					removedVehicle->printBill();	
					delete removedVehicle;
					cout << "\n";
				} else {
					cout << "Sorry we can't find this vehicle \n\n";
				}
				break;			
			case 4:
				cout << "Here is a report of all the vehicles in the center: \n";
				cout << *center;
				cout << "\n";
				break;
			case 5:
				cout << "Which vehicle do you want to view the status? Please specify the id -> ";
				cin >> id;
				vehicle = center->MLH_get(id);
				if (vehicle != NULL) {
					cout << "Here is the report for this vehicle: \n";
					cout << *vehicle;
					cout << "\nHere are the current tasks: \n";
					vehicle->printBill();
				} else {
					cout << "Sorry, we can't find this vehicle. \n\n";
				}
				break;
		}
	} while (choice != 6);
	
	cout << "\nThanks for choosing this service center!\n";
	delete center;
}
