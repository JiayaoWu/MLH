#include "MLH.h"
#include "random_op.h"
#include <iostream>

using std::cin;
using std::cout;

main()
{
    unsigned int s;
    int    Max_range=100;
    int    num_op;
    
    int    i;
    int    *data;
    int num_get, num_delete, num_update;

    cout << "MLH project\n";
    cout << "Please enter the number of operations requested: ";
    cin >>  num_op;
    cout << "Please enter the max range of random numbers: ";
    cin >> Max_range;
    cout << "Please enter a starting seed: ";
    cin >> s;
    cout << "\nGenerating " << num_op << " operations with range " 
	<< Max_range << "  and random seed " << s << "\n";
    cout << "-------------------------------------------------------------------------\n";

    num_get    = 0;
    num_delete = 0;
    num_update = 0;
   
    Random_operation Rand_op(s, Max_range);


    MLH< int > *intMLH = new MLH<int>();


    for( i = 1; i <= num_op; i++ )
    {

	Rand_op.Randomize_next_op();
	switch( Rand_op.Get_op() )
        {
            case 'G':
                num_get++;
                data = intMLH->MLH_get(Rand_op.Get_key());
		break;
            case 'I':
		data = new int;
		*data = i;     
		num_update++;
		intMLH->MLH_insert(Rand_op.Get_key(), data);
		break;
            case 'D':
                num_delete++;
		data = intMLH->MLH_delete(Rand_op.Get_key());
		if (data != NULL) {
			delete data;  //prevent memory leakes
		}

		break;
       }
        if( (i % (num_op/10)) == 0 )
        {
            cout << "\nPrinting after " << i << "  operations\n";
            if( Max_range > 100 ) { 
		intMLH->MLH_set_print(2);
	    } else {
	        intMLH->MLH_set_print(1);
	    }
	    cout << *intMLH;	
        }
    }
   
     
    cout << "Operation summary: get " << num_get << " delete " << num_delete
	<<"  update " << num_update << "\n";
    delete intMLH; //avoid memory leaks
}

                       
