#ifndef TASK_H
#define TASK_H

#include<string>
using std::string;

class Task
{
public:
	Task(const string &, const double, const double);
	void print() const;
	double getLabor() const;
	double getPart() const;
private:
	string name;
	double costofLabor;
	double costofPart;
};

#endif
