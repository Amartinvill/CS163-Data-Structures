/*
Angel Martinez Villalta
Assignment #4
Date: 5/23/16
Professor: Karla Fant

The purpuse of this file is to be able to implement each function
require for this assignment, as well as the neccessary code to
build a bst.
*/
#include "bst_study_guide.h"
using namespace std;
//this is a constructor that helps initialize data for each of the
//data member located in the struct.
study_info::study_info()
{
	notes_title = NULL;
	chapter_num = 0;
	notes = NULL;
	page_num = 0;
}
//this is a destructor for a study info struct that will help
//dealocate all free memory.
study_info::~study_info()
{
	if(notes_title)
	delete [] notes_title;
	if(notes)
	delete [] notes;
}

//this is a constructor of class study guide which initializes 
//the pointer root
study_guide::study_guide()
{
	root = NULL;
}
//this is a distructor that takes care of dealication the data
//that is being created to build the tree
study_guide::~study_guide()
{
	remove_all(root);
}
//the purpose of this function is to be able to load information
//in a external file to our data members. in addition this function
//will allowed to build the data structure desired.
int study_guide::load_from_file()
{
	
	char temp_char[SIZE];

	ifstream load_in; 
	load_in.open("bst_study_guide.txt"); 
	if(load_in)
	{
		load_in.peek();	
		while(!load_in.eof())
		{
			node * holder = new node;
				
			load_in.get(temp_char, SIZE, ':');
			load_in.ignore(100, ':');
			holder->data.notes_title  = new char[strlen(temp_char)+1];
			strcpy(holder->data.notes_title,temp_char);

			load_in >> holder->data.chapter_num;
			load_in.ignore(100, ':');

			load_in >> holder->data.page_num;
			load_in.ignore(100, ':');

			load_in.get(temp_char, SIZE, '\n');
			load_in.ignore(100, '\n');
			holder->data.notes = new char[strlen(temp_char) + 1];
			strcpy(holder->data.notes, temp_char);
			
			//for each line that is being read, it is added to a node
			//in which we pass to the insert function to be compared 
			//and then added.
			insert_to_bst(root, holder);
						
		load_in.peek();	
		}
			
	}
	load_in.close();
	load_in.clear();	

   return 0;
}

//the purpose of this function is to be able to create an insert function
//that will allow the building of the data structure
int study_guide::insert_to_bst(node *& root, node *& to_add)
{
	if(!root)
	{
		root = to_add;
		root->left = root->right = NULL;
	}
	//now we can assume that there is at list a node at the root of the
	//tree and we can start adding data depending whether is less or
	//grater than root.
	else if(strcmp(root->data.notes_title,to_add->data.notes_title) > 0)
		insert_to_bst(root->left, to_add);
	//else we can sure asume that the data is otherwise where is grater
	//than the data in the root so we add to the right of the bst.
	else insert_to_bst(root->right, to_add);

   return 0;
}

//this is a wrapper for a display all function that does not has root pass
//as an argument which can me call in the by the client programmer
int study_guide::display_all()
{
	display_all(root);

   return 0;
}

//the purpose of this function is to be able to display all the data in
//sorted order from smalles to grates
int study_guide::display_all(node * root)
{
	if(!root) return 0;
	//now we can assumne that there is data in the tree and we can
	//traverse all the a left and display the data in sorted order
	display_all(root->left);
	root->data.display_guide();
	display_all(root->right);

   return 1;
}

//***************
int study_guide::display_specific_notes(char * to_find)
{
	display_specific_notes(root, to_find);

   return 1;
}

int study_guide::display_specific_notes(node * root, char * to_find)
{
	if(!root) return 0;
	if(strcmp(root->data.notes_title,to_find)==0)
	{
		root->data.display_guide();
		return 1;
	}
   return display_specific_notes(root->left, to_find) + display_specific_notes(root->right, to_find);
}

//this function remove/dealocate all the memory form this data structure
//by going all the way to the leaves and starting from there, as the tree
//shinks.
int study_guide::remove_all(node *& root)
{
	if(!root) return 0;
	
   	remove_all(root->left);
	remove_all(root->right);
	delete root;
	root = NULL;

   return 0;
}
int study_guide::remove_keyword(char * keyword)
{
	remove_keyword(root, keyword);

   return 0;
}
//this function will remove an specific data in the tree if the keyword 
//passsed in is located somewhere in the list.
int study_guide::remove_keyword(node *& root, char * keyword)
{
	//if there is nothing in the list do nothing
	if(!root) return 0;
	
	if(strcmp(root->data.notes_title, keyword) < 0)
		return remove_keyword(root->right, keyword);
	else if(strcmp(root->data.notes_title, keyword) > 0)
		return remove_keyword(root->left, keyword);
	//The item to remove is found but is locate at
	else
	{	
		//item located at a leaf
		if(!root->left && !root->right)
		{
			delete root;
			root = NULL;
		}
		//item located in an internal node with a left child
		else if(root->left && !root->right)
		{
			node * holder = root->left;
			delete root;
			root = holder;
		}
		//item located in an internal node with a right child
		else if(!root->left && root->right)
		{
			node * holder = root->right;
			delete root;
			root = holder;
		}
		else if(!root->right->left)
		{
			root->right->left = root->left;
			node * holder = root->right;
			delete root;
			root = holder;
		}
		else
		{
			//item located in an internal node with two childer  butthe right child has no left child.
			//we first have to find the in order succesor
			node * current = root->right;
			//need a previous incase the inorder succesor has more nodes connected to the right.
			node * previous = current;
			
				while(current->left)
				{
					previous = current;
					current = current->left;
				}
				previous->left = current->right;
				
				current->right = root->right;
				current->left = root->left;
				//root gets the value of the IOS
				delete root;
				root = current;
				
				
		}
	}
   return 1;
}
//this is a wrapper function for an edit notes function that will be use
//in the application so that the user will will not know im using any
//type of data structure
int study_guide::edit_notes(char * to_find, char * to_edit)
{
	edit_notes(root, to_find, to_edit);

   return 1;
}	
//this is an edit function that modefy that information of the notes whech
//the user which to change
int study_guide::edit_notes(node *& root, char * to_find, char * to_edit)
{
	if(!root) return 0;
	if(strcmp(root->data.notes_title, to_find)==0)
	{
		delete [] root->data.notes;
		root->data.notes = new char[strlen(to_edit)+1];
		strcpy(root->data.notes, to_edit);
		return 1;
	}

   return edit_notes(root->left,to_find,to_edit) + edit_notes(root->right,to_find,to_edit);
}
//this function is a function to the struct study info that make a deep
//copy of the datat that is already alicatd in a single struct.
int study_info::copy_data(study_info & to_copy)
{
	if(to_copy.chapter_num)
		to_copy.chapter_num = 0;

	to_copy.chapter_num = chapter_num;
	
	if(to_copy.notes_title)
		delete [] to_copy.notes_title;

	to_copy.notes_title = new char[strlen(notes_title) + 1];
	strcpy(to_copy.notes_title, notes_title);
	
	if(to_copy.page_num)
		to_copy.page_num = 0;
	
	to_copy.page_num = page_num;
	
	if(to_copy.notes)
		delete [] to_copy.notes;

	to_copy.notes = new char[strlen(notes) + 1];
	strcpy(to_copy.notes, notes);

   return 1;
}
//this function is a display function that display al the data
//menber in the struct so the the tress could have access to it
//also to simplify less code and not to be able to cout the same
//functions over and over again.
int study_info::display_guide()
{
	cout<<"Notes title: " <<notes_title<<endl;
	cout<<"Chapter number: "<<chapter_num<<endl;
	cout<<"Notes: "<< notes <<endl;
	cout<<"Page located: " <<page_num<<endl<<endl;

  return 1;
}
//this function is implemeneted in the study info struct which
//has access to the data member so my class could have access to it
//and be able to retreive the data if it exist in the list
bool study_info::retreive_info(study_info & to_retreive, char * keyword)
{
	if(strcmp(notes_title,keyword)==0)
	{
		to_retreive.copy_data(to_retreive);
		return true;
	}
	
   return false;
}
//this function is a retreive function that retrieves all the data in a node
//to an object that is return to the apllication programmer. it will first find
//the correct data, then if it found the it will retreve that data. 
bool study_guide::retreive_notes(node * root, study_info & to_find,char *keyword)
{
	if(!root) return false;
	if(strcmp(root->data.notes_title,keyword)==0);
	{
		if(root->data.retreive_info(to_find,keyword)) 
		return true;
	   return true;
	}
	
	retreive_notes(root->left,to_find, keyword);
	retreive_notes(root->right,to_find, keyword);
	
   return false;
}
/*
int study_guide::display_range(node * root, char * least_key, char * greater_key)
{
	if(!root) return 0;
	if(strcmp(root->data.notes_title, least_key)==0)
	{
		
}*/
