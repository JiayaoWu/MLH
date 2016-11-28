#ifndef NODE_H
#define NODE_H

template< typename NODETYPE> class MLH;

template< typename NODETYPE>

#define MAX_SIZE 5

class Node
{
	friend class MLH< NODETYPE >;

public:
	Node();
	~Node();
private:
	int size;
	int level;
	int parentIndex;
	int key[MAX_SIZE];  //key array
	Node<NODETYPE> *pointers[MAX_SIZE];  //pointers array
	NODETYPE *data[MAX_SIZE]; //data array
	Node<NODETYPE> *parent;  //parent pointer that points to parent node
};  //end Node class

//constructor
template< typename NODETYPE >
Node< NODETYPE >::Node()  //setting everything to null
{
	for (int i = 0; i < MAX_SIZE; i++) {
		pointers[i] = NULL;
		key[i] = 0;
		data[i] = NULL;
	}
	parent = NULL;
	size = 0;
	level = 0; 
	parentIndex = 0;
}	

//destructor
template< typename NODETYPE>
Node< NODETYPE >::~Node()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (key[i] != 0) {
			delete data[i];
			data[i] = NULL;
		}
		//delete pointers[i];
	}
}

#endif

