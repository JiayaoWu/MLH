#ifndef MLH_H
#define MLH_H

#include <iostream>
using std::cout;
using std::ostream;

#include "Node.h"
#include "ML_hash.h"
#include <stdlib.h>

template <typename NODETYPE>
ostream & operator << (ostream &, const MLH<NODETYPE> &);

template < typename NODETYPE >
class MLH
{

public:
	MLH();
	~MLH();
	void deleteNode(Node<NODETYPE> *);
	bool MLH_insert(int key, NODETYPE *data);
	void print(Node<NODETYPE> *) const; //helper method for printing
	void print() const;
	NODETYPE* MLH_get(int key);	
	NODETYPE* MLH_delete(int key);	
	int findMaxLevel() const;
	void MLH_set_print(int num);
	int set_print;
	friend ostream & operator << <>(ostream &, const MLH<NODETYPE> &);
private:
	Node<NODETYPE> *firstNode;
	int numHashNode;
	int numOfKV;
	int level[9]; //keep track of how many nodes on each level
	unsigned long int steps;
};

/*default constructor that creates an empty node
 *and initializes the constants*/
template< typename NODETYPE >
MLH< NODETYPE>::MLH()
{
	firstNode = new Node<NODETYPE>();
	numHashNode = 1;
	numOfKV = 0;
	for (int i = 0; i < 9; i++) {
		level[i] = 0;
	}
	level[0] = 1;
	steps = 0;
}

/*Destructor that destroyes every single node
*/ 
template< typename NODETYPE>
MLH< NODETYPE>::~MLH()
{
	deleteNode(firstNode);
}

/*helper method for destructor to do recursion
 */
template< typename NODETYPE>
void MLH<NODETYPE>::deleteNode(Node< NODETYPE> *ptr) 
{
	Node<NODETYPE> *currptr = ptr;

	
	for (int i = 0; i < MAX_SIZE; i++) {
		if (currptr->pointers[i] != NULL) {
			deleteNode(currptr->pointers[i]);
		}	
	}
	
	Node<NODETYPE> *parentNN = currptr->parent;
	if (parentNN != NULL) {
		int index = currptr->parentIndex;
		//delete from the parent
		delete parentNN->pointers[index];
		parentNN->pointers[index] = NULL;
	}

}

/*set up to determine if there is need to print out
 * all the key and data. If num == 1, yes. if num ==2, no
 */
template< typename NODETYPE>
void MLH<NODETYPE>::MLH_set_print(int num) {
	set_print = num;
}


/*Insert function that inserts the {key, value} pair 
 * if the value is not in the MLH yet/
 * Return true if inserted succesfully, false otherwise
 */
template< typename NODETYPE>
bool MLH<NODETYPE>::MLH_insert(int key,  NODETYPE *data)
{
	Node<NODETYPE> *currptr = firstNode;
	
	while (currptr->size > MAX_SIZE) {
		int hashNew = ML_hash(currptr->level + 1, key) - 1;
		if (currptr->pointers[hashNew] == NULL) {
			//create a new node
			currptr->pointers[hashNew] = new Node<NODETYPE>();
			currptr->pointers[hashNew]->parent = currptr;
			currptr->pointers[hashNew]->level = currptr->level + 1;
			numHashNode++;
			currptr->pointers[hashNew]->parentIndex = hashNew;
			level[currptr->level + 1]++;
		} 
		currptr = currptr->pointers[hashNew];
		steps++;
	}

	//the size can be either 5 or < 5 now. 
	//so consider == 5 first
	
	while (currptr->size == MAX_SIZE) {
		//do the explode things
		//first check if the key already exists
		for (int i = 0; i < MAX_SIZE; i++) {
			
			if (currptr->key[i] == key) {
				return false;
			}
                }
		
		//now do explode!
		for (int i = 0; i < MAX_SIZE; i++) {
			int hash = ML_hash(currptr->level+1, currptr->key[i]) - 1;
                        if (currptr->pointers[hash] == NULL) {
				//create a new node
				currptr->pointers[hash] = new Node<NODETYPE>();
				currptr->pointers[hash]->level = currptr->level+1;
                                currptr->pointers[hash]->parent = currptr;
                                currptr->pointers[hash]->parentIndex = hash;
				numHashNode++;
        			level[currptr->level + 1]++; 
                        }
			
			for (int j = 0; j < MAX_SIZE; j++) {
				//to find an empty space
				if (currptr->pointers[hash]->key[j] == 0) {	
					currptr->pointers[hash]->key[j] = currptr->key[i];
                                        currptr->pointers[hash]->data[j] = currptr->data[i];
                                        currptr->pointers[hash]->size++;
                                        break;
                                }
			}

		}
	
		int hashNew = ML_hash(currptr->level + 1, key) - 1;
                if (currptr->pointers[hashNew] == NULL) {  //then creat a new Node
			currptr->pointers[hashNew] = new Node<NODETYPE>();
                        currptr->pointers[hashNew]->level = currptr->level + 1;
                        currptr->pointers[hashNew]->parent = currptr;
                        currptr->pointers[hashNew]->parentIndex = hashNew;
			currptr = currptr->pointers[hashNew];
                       	steps++;
			numHashNode++;
        		level[currptr->level]++; 
                 } else {
                        currptr = currptr->pointers[hashNew];
        		steps++; 
	        }
	}

	//now we have reached a node of size < 5. Just insert key and data in empty slots
	if (currptr->size < MAX_SIZE) {
		int emptyIndex;
		for (int i = 0; i < MAX_SIZE; i++) {
			if (currptr->key[i] == key) return false;
		}

		for (int i = 0; i < MAX_SIZE; i++) {
                        if (currptr->key[i] == 0)  {
				emptyIndex = i;
				break;
			}
                }

		currptr->key[emptyIndex] = key;
                currptr->data[emptyIndex] = data;
                currptr->size++;
                numOfKV++;

		//now update the size of the parents
		Node<NODETYPE> *parentN = currptr->parent;
		steps++;
		while (parentN != NULL) {
			parentN->size++;
			parentN = parentN->parent;
			steps++;
		}
		return true;
	}
	return false;
}

/**
 * get function that receives a key and returns a ptr to the 
 * object if the key exists. Return null if not found
 */
template< typename NODETYPE>
NODETYPE* MLH< NODETYPE >::MLH_get(int key)  
{
	Node<NODETYPE> *currptr = firstNode;
	

	while (currptr->size > MAX_SIZE) {
                int hashNew = ML_hash(currptr->level + 1, key) - 1;
                if (currptr->pointers[hashNew] == NULL) {
                        return NULL;
                }
                currptr = currptr->pointers[hashNew];
		steps++; 
       }	

	//now we reached a node of size <= 5
	//then just search through to see if the key is there
	for (int i = 0; i < MAX_SIZE; i++) {
		if (currptr->key[i] == key) {
			return currptr->data[i];
		}
	}
	return NULL;
} 


/**
 * Delete function that receives a key and delete the object if the key exists
 * return the deleted object (pointer) if it exists, null otherwise
 */
template<typename NODETYPE>
NODETYPE* MLH<NODETYPE>::MLH_delete(int key)
{
	Node<NODETYPE> *currptr = firstNode;

	while (currptr->size > MAX_SIZE) {
                int hashNew = ML_hash(currptr->level + 1, key) - 1;
                if (currptr->pointers[hashNew] == NULL) {
			return NULL;
		}
		
                //go to next level
		currptr = currptr->pointers[hashNew];
		steps++; 
        }	


	//now this means currpptr size is <= 5
	//and now see if the key is one of them
	for (int i = 0; i < MAX_SIZE; i++) {
		if(currptr->key[i] == key) {
                        NODETYPE *dataptr = currptr->data[i];  //so that I can return it
                        currptr->data[i] = NULL;
                        currptr->key[i] = 0;
                        currptr->size--;
	                numOfKV--;
			
			Node<NODETYPE> *parentN = currptr->parent;
			steps++;
			if (currptr->size == 0 && currptr != firstNode) {
				level[currptr->level]--;
				Node<NODETYPE> *parentNN = currptr->parent; 
				//need parentNN since if currptr is already deleted,
				//then cannot access to currptr anymore
				steps++;
				int index = currptr->parentIndex;
				delete parentNN->pointers[currptr->parentIndex];
				parentNN->pointers[index] = NULL;			
				
				numHashNode--;
			}	

			//update size of parents.
			while (parentN != NULL) {
				parentN->size--;

				//see if need to collapse if size is 5	
				if (parentN->size == MAX_SIZE) {
					int num = 0; //num is the next empty slot
					for (int j = 0; j < MAX_SIZE; j++) {
						if (parentN->pointers[j] != NULL) {
                                                        for (int k = 0; k < MAX_SIZE; k++) {
								if(parentN->pointers[j]->key[k] != 0) {
									parentN->key[num] = parentN->pointers[j]->key[k];
									parentN->data[num++] = parentN->pointers[j]->data[k];
									parentN->pointers[j]->key[k] = 0;
									//parentN->pointers[j]->data[k] = NULL;
								}		
						 	} //ends for
							level[parentN->pointers[j]->level]--;
							delete parentN->pointers[j];
                                         		parentN->pointers[j] = NULL;
                                         		numHashNode--;
						} //ends if
					} //ends for loop
				} //ends if
				parentN = parentN->parent;				
				steps++;
			} //ends while
			return dataptr; 
		}
	} //ends for
	return NULL;  //cannot find the key
}

/*Return the max level so far*/
template< typename NODETYPE>
int MLH<NODETYPE>::findMaxLevel() const
{
       	for (int i = 0; i < 9; i++) {
		if(level[i] == 0) {
			return i; 
			//should be i - 1, but my level starts from 0, 
			//so adding 1 here: i - 1 + 1 = i
		}
	}
	//means each level is full
	return 9;
}


/*Helper method that prints key and data in the repository*/
template< typename NODETYPE>
void MLH< NODETYPE >::print(Node<NODETYPE> *ptr) const
{
	
	Node<NODETYPE> *currptr;
	currptr = ptr;
	if (currptr->size <= MAX_SIZE) {
		for (int i = 0; i < MAX_SIZE; i++) {
			if (currptr->key[i] != 0) {
				cout << "Key: " << currptr->key[i] << "   objetct: "
				<< *currptr->data[i]<< "\n";
			}
		}

	} else {
		for (int i = 0; i < MAX_SIZE; i++) {
			if (currptr->pointers[i] != NULL) {
				print(currptr->pointers[i]);
			}
		}


	}
}

/*print function that calls the helper print functio*/
template< typename NODETYPE>
void MLH<NODETYPE>::print() const
{
	print(firstNode); //so recursion here

}

/*overload the << operator*/
template< typename NODETYPE>
ostream &operator<<(ostream &output, const MLH<NODETYPE> &list)
{
	cout << "Number of objects: " << list.numOfKV << "\n";
        cout << "Number of hash nodes: " << list.numHashNode << "\n";
        cout << "The maximum level so far: " << list.findMaxLevel() << "\n";
	cout << "The steps performed so far: " << list.steps << "\n";
	if (list.set_print == 1) {
		list.print();  //printing out the key, data
	} 
}
#endif



