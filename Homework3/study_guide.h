/*
Angel Matine Villalta
Assignment #3
CS163
Date: 05/09/2016
Profesor: Karla Faunt


The pourpose of this assigment is to be able to get familiar with the new concept
we jus learned in class of hash tables. We will be simulating a study guide sort of 
like program that will help us get familiarize with hash table using chaining
techniques.

*/
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

const int SIZE = 150;
//This struct contains all the data member that we will be storing data to  
//from the external file.
struct study_guide
{
	char * chapter_title;
	int chapter_num;
	int  page_num;
	char * short_description;
	
	int retreive(char * keyword, study_guide & to_retreive);
	
	int copy_guide(study_guide & to_copy);
};


struct node
{
	study_guide  data;	
	node * next;
};

//This class that implements the data structure that we wish to accomplish for this 
//assigment, and that is working with tables.
class study_table
{
	public:
		study_table(int lenght = 5);
		~study_table();
		int read_from_file();
		int hash_value(char * keyword);	
		int display_all();
		int display_chapter(char * keyword);
		bool retrieve_from_table(char * keyword, study_guide & to_find);
		int chapter_to_edit(char * keyword, char *& to_edit);
		int chapter_to_remove(char * charpter);
		
	private:
		node ** head;
		int table_size;		
};
		
	


