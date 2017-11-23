#include "container_info.h"
/*
Angel Martinez

The purpose of this data stucture if to be able to work with stacks
using linear linked list of arrays. For this assiment we are using this
data structure to be able to contain senders information
*/

const int MAX = 5;

//this struct contains a pointer to a Package_Info that we have created 
//to be able to facilitace our work when adding data from the application
//client dinamically.
struct s_node
{
	char * sender;
	container_info * Container;
	s_node * next;
};

class stack
{
	public:
		stack();
		stack( int size_array);
		~stack();
		int push(const container_info & to_add);
		int pop();
		int display_all()const;
		int peek(container_info & find) const;
		int display_only_name_item();
	
	private:
		int SIZE;
		s_node * head;
		int top_index;//This will by use to indicate where in our 
			      //stack the data will be added. assuming that
			     //we are only adding at the top.		 	

};
