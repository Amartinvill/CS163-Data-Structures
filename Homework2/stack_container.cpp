#include "stack_container.h"
using namespace std;

//the purpose of this constructor is to be abel to initialize
//the pointer and the array
stack::stack()
{
	head = NULL;
	top_index = 0;
}

stack::stack(int size_array)
{
	head = NULL;
	SIZE = size_array;
	top_index = 0;

}

//this function is use as a constructor to be able to deallocate
//all the memory that has been allocated.
stack::~stack()
{
	if(!head) return;
	if(!head->next)
	{	
		delete [] head->Container;
		delete head;
		head = NULL;
		top_index = 0;
	}
	s_node * current = head;
	while(current)
	{
		current = head->next; 
		delete [] head->Container;
		delete head;
		head = current;
	}
	head = NULL;
	top_index = 0;

}

//adds to the stack
int stack::push(const container_info & to_add)
{
	if(!head)
	{
		head = new s_node;
		head->Container = new container_info[MAX];
		head->Container[top_index].copy_item(to_add);
		head->next== NULL;
		++top_index;
	}
	else if(top_index==MAX)
	{
		top_index = 0;
		s_node * temp = new s_node;
		temp->Container = new container_info[MAX];
		temp->Container[top_index].copy_item(to_add);
		temp->next = head;
		head = temp;
		++top_index;
		
	}
	else 
	{
		head->Container[top_index].copy_item(to_add);
                ++top_index;
	}
   return 0;
}
//deletes for the top of the stack
int stack::pop()
{
	if(!head) return 0;
	if(top_index>0) --top_index;
    	else if(top_index == 1)
    	{
        	if(!head->next)
        	{
            		--top_index;
            		delete [] head->Container;
            		delete head;
            		head = NULL;
            		top_index = 0;
        	}
		s_node * temp;
		temp->next = head->next;
		--top_index;
		delete [] head->Container;
		delete head;
		head = temp;
		top_index = MAX-1;
    	}

    	else

   return 0;
}

//displays all items
int stack::display_all()const
{
	if(!head)return 0;
	s_node * current = head;
	int holder = top_index;
	while(current)
	{
		for(int i=0; i<top_index; ++i)
		{
			current->Container[i].display_item();
		}
		current= current->next;
	}
   return 0;
}
//displays only the items without the descriptions
int stack::display_only_name_item()
{
	if(!head)return 0;
	s_node * current = head;
	int holder = top_index;
	while(current)
	{
		for(int i=0; i<top_index; ++i)
		{
			current->Container[i].display_only_item();
		}
		current= current->next;
	}
   return 0;
}	
