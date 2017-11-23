/*
Angel martinez villalta
assigment # 5
proctor: karla fant
*/
#include "graph_file.h"
using namespace std;

//the porpuse of this function is to be able to initialize data for 
//this data strcutue. since were are working with an array of vertex
//pointer and a LLL edge, we need to initialize dat for both of them
graph_table::graph_table(int size)
{
	adjacency_list = new vertex[size];
	for(int i = 0; i<size; ++i)
	{
		adjacency_list[i].head = NULL; //creating a head pointer
					       //for our edge list	
		adjacency_list[i].entry = NULL; //creating a table with
					        //entry pointers
		adjacency_list[i].visited_flag = false;
	}
	list_size = size;
	rear = NULL;
}
graph_table::~graph_table()
{
	for(int i=0; i<list_size; ++i)
	{
		
		edge * current = adjacency_list[i].head;
		while(current)
		{
			edge * holder = current->next;
			delete adjacency_list[i].head;
			adjacency_list[i].head = holder;
			current=current->next;
		}
		if(adjacency_list[i].entry)
			delete adjacency_list[i].entry;
		adjacency_list[i].head = NULL;
	}		
	delete [] adjacency_list;
	adjacency_list = NULL;

}
//the purpose of this functuon is to be able to add data into our
//array of vertex. We will be reading form an external file that
//will allow us to add each data read in to each of the adjacency
//list that do not hae data.
int graph_table::insert_to_vertex(file_entry & entry)
{
	for(int i = 0; i<list_size; ++i)
	{
		if(!adjacency_list[i].entry)
		{
			adjacency_list[i].entry  = new file_entry;
			adjacency_list[i].entry->copy_file_entry(entry);
			return 1;
		}
	}
   
   return 0;
}
//This function will display the content of what each index in the array 
//of Vertecx
int graph_table::display_vertecies()
{
	//go into the array and start from the fist elemet untill the end 
	//of the table
	for(int i = 0; i<list_size; ++i)
	{
		//for every element that this loop encounters in th earray
		//and is a NULL pointed, allocate data to this pointer.
		adjacency_list[i].entry->display_file();
	}

   return 1;
}
int graph_table::display_vertecies_name()
{
	for(int i = 0; i<list_size; ++i)
		adjacency_list[i].entry->display_file_name();
   return 1;
}
//the purpose of this function is to be able to locate the index of the
//desire keyvalue, where is going to be supplied back.
int graph_table::find_index(char * key_value)
{
	for(int i = 0; i<list_size; ++i)
	{
		if(adjacency_list[i].entry && adjacency_list[i].entry->compare_directory(key_value))
			return i;
		
	}
   return 0;
}
//the purpose of this function is to be abel to create an edge list of 
//Linear Link List base of the data that the connecting to the current 
//data. 
int graph_table::insert_to_edge(char * current_vertext, char * to_connect)
{
	int current_index = find_index(current_vertext);
	int connect_index = find_index(to_connect);
	
	//if none of the indexex are in the list then return 0;
	if(current_index == -1 || connect_index ==-1) return 0;
	//else we asume that the two keyword enter have been found in array
	//step 1, make a temporary pointer that holds the LLL of head, if any
	edge * holder = adjacency_list[current_index].head;
	//step 2, is to insert a node the head of the current vertex we wish
	//to add. while not loosing the lll.
	adjacency_list[current_index].head = new edge; 
	//step 3, is to reconect the holder back to the newly added edge
	adjacency_list[current_index].head->next = holder;
	//final step is to connect to the a pointer to the data in the list of vertex
	adjacency_list[current_index].head->adjacent = &adjacency_list[connect_index];
	
   return 1;
}
//this function display the items adjacent to the item asked by the user
int graph_table::display_adjacent(char * key_value)
{
	int index = find_index(key_value);
	if(index == -1) return 0;
	
	adjacency_list[index].entry->display_file();
	cout<<"Is Connected to:"<<endl;

	edge * current = adjacency_list[index].head;
	if(!current) return 0;
	while(current)
	{
		current->adjacent->entry->display_file();
		current = current->next;
	}
	
   return 0;
}
//this function reset all the vertex flags to false so the 
//can be used again for other match datas
int graph_table::flag_reset()
{
	for(int i=0; i<list_size; ++i)
		adjacency_list[i].visited_flag =false;

   return false;
}
bool graph_table::is_visited(char * keyword)
{
	int index = find_index(keyword);
	if(adjacency_list[index].visited_flag == false)
	{
		adjacency_list[index].visited_flag = true;
	   return true;
	}
   return false;
}
//this function expect a vetet pointer where it add to the queue
//where it hold just the pointer to the data we have not flagged yet
int graph_table::enqueue(vertex * to_add)
{

	if(!rear)
	{
		rear = new holder;
		rear->data = to_add;//.copy_file_entry(to_add);
		rear->next = rear;
		return 1;
	}
	holder * temp = new holder;
	temp->data = to_add;//copy_file_entry(to_add);
	temp->next = rear->next;
	rear->next = temp;
	rear = temp;

   return 0;
}

vertex *  graph_table::dequeue()
{
	if(!rear) return NULL;
	if(rear->next = rear)
	{
		vertex * temp = rear->data;
		delete rear;
		rear = NULL;
	   return temp;
	}
	holder * temp = rear->next;
	vertex * temp2 = temp->data;
	rear->next = temp->next;
	delete temp;

   return temp2; 
}
//this is a wrapper function to display a breath first function whre
//im am initializing the vertext pointer to the one the user woudl
//like to see.
int graph_table::display_breath_first(char * keyword)
{
	int index = find_index(keyword);	
	if(index == -1) return 0;
	adjacency_list[index].visited_flag = true;
	
	enqueue(&adjacency_list[index]);

	display_first(dequeue());

	flag_reset();
   return 0;
}

int graph_table::display_first(vertex * pointer)
{
	if(!pointer) return 0;

	edge  * current = pointer->head;
		
	while(current)
	{
		if(!current->adjacent->visited_flag)
		{
			current->adjacent->visited_flag = true;
			enqueue(current->adjacent);
		}
		current = current->next;
	}
	pointer->entry->display_file();
	display_first(dequeue());
return 0;	
}
