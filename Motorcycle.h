#ifndef MOTORCYCLE_H
#define MOTORCYLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle(int idNum, int year, const string &color, double miles,
		double engine, double front, double back);
	virtual void print() const;
	virtual string insertTask(int choice);
	
	friend ostream &operator<<( ostream &, const Motorcycle &);
	virtual void taskList();
private:
	double enginesize;
	double frontSize;
	double backSize;

};
#endif
