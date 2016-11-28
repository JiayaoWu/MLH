#include <iostream>
#include "Task.h"
#include "List.h"

using std::cout;

//LNode class
/*constructor*/
LNode::LNode(const Task &task)
	:content(task), next(0)
{
	//empty
}

/*Returns the task*/
Task LNode::get_Task() const
{
	return content;	
}


//List class
/*Constructor*/
List::List()
{
	first_ptr = NULL;
	sumOfLaborCost = 0;
	sumOfPartCost = 0;
}

/*Destructor*/
List::~List()
{
	LNode *pnode;
	while (first_ptr != NULL) {
		pnode = first_ptr;
		first_ptr = pnode->next;
		delete pnode;
	}
}

/*Insert a task*/
void List::insert(const Task &task)
{
	LNode *pnode;
	pnode = new LNode(task);
	sumOfLaborCost += task.getLabor();
	sumOfPartCost += task.getPart();
	pnode->next = first_ptr;
	first_ptr = pnode;
}


/*Print the tasks in the list*/
void List::print() const
{
	LNode *pnode;
	pnode = first_ptr;
	while (pnode != NULL) {
		pnode->get_Task().print();
		cout << "\n";
		pnode = pnode->next;
	}	
	cout << "Total costs of labor: $" << sumOfLaborCost
	<< "\nTotal costs of parts: $" << sumOfPartCost << "\n"
	<< "Total costs: $" << sumOfLaborCost + sumOfPartCost << "\n";
}

