#include <iostream>

#include "Task.h"

//node class
class LNode
{
public:
	LNode (const Task &task);
	
	Task get_Task() const;

private:
	Task content;
	LNode *next;
	friend class List;

};


//list class
class List
{
public:
	List();
	~List();

	void insert(const Task &task);
	void print() const;
private:

	LNode *first_ptr;
	double sumOfLaborCost;
	double sumOfPartCost;
};
