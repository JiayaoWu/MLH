#ifndef HYBRID_H
#define HYBRID_H

#include <iostream>
using std::ostream;

#include "Car.h"


class Hybrid : public Car
{
public:
	Hybrid(int idNum, int year, const string &color, double miles,
		double enginesize, const string &gasType, const string &polLevel,
		double power, double usage, double capacity);
	virtual void taskList();
	virtual void print() const;
	virtual string insertTask(int choice);
	
	friend ostream &operator<<( ostream &, const Hybrid &);
private:
	double motorPower;  //unit: watt
	double totalUsage;  //unit hours
	double batteryCapacity; //unit: Ah
};
#endif
