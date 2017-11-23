#include "queue_info.h"
using namespace std;

queue::queue()
{
	rear = NULL;
}
queue::~queue()
{
	remove_all(rear);

}
int queue::enqueue(const Package_Info & to_add)
{
	//Write the function here
    if(!rear)
    {
        rear = new q_node;
        rear->lable.copy_package_info(to_add);
        rear->next= rear;
    }
    else
    {
        q_node * temp = new q_node;
        temp->lable.copy_package_info(to_add);
        temp->next= rear->next;
	rear->next = temp;
        rear = temp;
    }
  return 0;
        
} 

int queue::dequeue()
{

    if(!rear) return 0;
    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    else
    {
        q_node * temp = rear->next;
        rear->next = temp->next;
        delete temp;
        return 1;
    }
    return 0;
}

int queue::display_package_info()
{
	if(!rear) return 0;
	if(rear->next==rear)
	{
		rear->lable.display_all();
		return 1;
	}
	q_node * head = rear->next;
	rear->next = NULL;
	q_node * current = head;
	while(current!=NULL)
	{
		current->lable.display_all();
		current = current->next;
	}
	rear->next = head;
   return 0;
}

int queue:: display_name_only()
{
	if(!rear) return 0;
	if(rear->next==rear)
	{
		rear->lable.display_sender();
		return 1;
	}
	q_node * head = rear->next;
	rear->next = NULL;
	q_node * current = head;
	while(current!=NULL)
	{
		current->lable.display_sender();
		current = current->next;
	}
	rear->next = head;
   return 0;
}
int queue::remove_all(q_node *& rear)
{
	if(!rear) return 0;
	if(rear->next = rear)
	{
		delete [] rear;
		delete rear;
		rear = NULL;
	}
	else
	{
	q_node * temp = rear->next;
	rear->next = temp->next;
	delete temp;
	}
   return remove_all(rear->next);
}

