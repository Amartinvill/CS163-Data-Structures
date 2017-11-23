/*
Angel Martinez Villalta
Assignment #5
date: 06/02/16
Proctor: karla Fant

The purpose of this file is to be able to implent the functions
neccessary to be able to buld a graph data structure we learn in
class. This will allow us to have data differently than what we 
have worked in the past. 
*/

#include "file_entry.h"

struct vertex
{
	file_entry * entry;
	struct edge * head;
	bool visited_flag;
};
//this is a struct to edges of the data structure
struct edge
{
	vertex * adjacent;
	edge * next;
	int weight; //to indicate the the edges are weithed
};

struct holder
{
	vertex * data;
	holder * next;

};
//this class contains all the funtions need to build a graph
//data structure/
class graph_table
{
	public:
		graph_table(int size = 5);
		~graph_table();
		int insert_to_vertex(file_entry & entry);
		int find_index(char * key_value);
		int insert_to_edge(char * current_vertext, char * to_connect);
		int display_adjacent(char *key_value);
		int display_vertecies();
		int remove_all();
		int flag_reset();
		bool  is_visited(char * keyword);
		int display_vertecies_name();
		
		int display_breath_first(char * keyword);

		int enqueue(vertex * pointer);
		vertex * dequeue();
		
	private:
		int display_first(vertex * );
		vertex * adjacency_list;
		holder * rear;
		int list_size;
};


