#include "stack_container.h"
/*
Angel Martinez

The purpose of this  abstract data type is to be able to work with
queue

*/


struct q_node
{
	Package_Info lable;
	q_node * next;
};


class queue
{
	public:
		queue();
		~queue();	
		int enqueue(const Package_Info & to_add);
		int dequeue();
		int display_package_info();
		int display_name_only();
	private:
		int remove_all(q_node *& rear);
		q_node * rear;
};

