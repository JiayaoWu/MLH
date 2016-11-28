#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <iostream>
using std::ostream;

class Car : public Vehicle
{
public:
	Car(int idNum, int year, const string &color, double miles, 
	double enginesize, const string &gasType, const string &polLevel);
	virtual void taskList();
	virtual void print() const;
	virtual string insertTask(int choice);

	friend ostream &operator<<( ostream &, const Car &);

private:
	double engineSize;
	string gas; //premium, plus, regular
	string pollutionlevel; //low, medium, high
};
#endif
