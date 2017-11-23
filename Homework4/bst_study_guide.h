/*
Angel Martinez Villalta
date: 5/26/06
Professor: Karla Fant
Homework 4

the purpose of this file is to create an ADT that will performe that necessary
data structure require to complete this assigment. the concept of this program
is to work with binary tress, there for we are going to implement functions that
will be using to create this data structure
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

int const SIZE = 150;
//The purpose of this struct is to hold the data members information
//from an external file.
struct study_info
{
	char * notes_title;
	int chapter_num;
	int page_num;
	char * notes;

	study_info();
	~study_info();
	int copy_data(study_info & to_copy);
	bool retreive_info(study_info & to_retreive, char * keyword);
	int display_guide();
	
};

//this is a struct node that the left and right child
struct node
{
	study_info data;
	node * left;
	node * right;

};

class study_guide
{
	public:
		study_guide();
		~study_guide();
		int load_from_file();	
		int display_all();
		int display_specific_notes(char * root);
		int remove_all();
		int remove_keyword(char * keyword);
		int edit_notes(char * to_find, char * to_edit);
		bool retrieve_notes(study_info & to_find, char * keyword);
	private:
		int insert_to_bst(node *& root, node *& to_add);
		int display_all(node * root);
		int display_specific_notes(node * root, char * to_find);
		int remove_all(node *& root);
		int remove_keyword(node *& root, char * keyword);
		int edit_notes(node *& root, char * to_find, char * to_edit);
		bool retreive_notes(node * root,study_info & to_find,  char * keyword);
		node * root;
};

