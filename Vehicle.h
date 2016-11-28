#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include "List.h"

class Vehicle
{
public:
	Vehicle(int idNum, int year, const string &color, double miles); 
	~Vehicle(); //destructor
	virtual void taskList();
	void printBill() const;
	virtual void print() const;
	friend ostream &operator<<( ostream &, const Vehicle &);
	virtual string insertTask(int choice);
	void addTask(string &);
private:
	int id;  //1-100000
	int modelYear; //2001-2015
	string Color;
	double mileage;
	List *listOfTask;
	double costPart;
	double costLabor;
};
#endif
