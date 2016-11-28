#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle
{
public:
	Bus(int idNum, int year, const string &color, double miles, int passengerCap);
	virtual void print() const;
	virtual string insertTask(int choice);
	
	friend ostream &operator<<( ostream &, const Bus &);
	virtual void taskList();
private:
	int passengerCapacity;
};
#endif
