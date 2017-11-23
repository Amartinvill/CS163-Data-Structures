/*
Angel Matine Villalta
Assignment #3
CS163
Date: 05/10/2016
Profesor: Karla Fant

The purpose of this file is to be able to implement the meat 
of the assigment. 
*/	

#include "study_guide.h"
using namespace std;

//this is a function for a constructor that create how big i want 
// my table of points to be and initialized all of them to NULL
study_table::study_table(int lenght)
{
	head = new node * [lenght];

	for(int i = 0; i < lenght; ++i)
		head[i] = NULL;
	table_size = lenght;
}
//this distructor deallocates the memory that was created during 
//the proccess of add data and creating the tabel
study_table::~study_table()
{
	node * holder;
	for(int i= 0; i < table_size; ++i)
	{
		
		while(head[i])
		{
			holder = head[i];
			head[i] = holder->next;
			delete holder;
		}
	}
	delete [] head;		
		
}

/* this function reads information form an external file and
directly stores it to the table by passing in a node with 
all the data in it. */
int study_table::read_from_file()
{
	char temp_char[SIZE];
	
	int location = 0;
	ifstream load_in; 
	load_in.open("study_guide.txt"); 
	if(load_in)
	{
		load_in.peek();	
		while(!load_in.eof())
		{
			node * holder = new node;

				
			load_in.get(temp_char, SIZE, ':');
			load_in.ignore(100, ':');
			holder->data.chapter_title  = new char[strlen(temp_char)+1];
			strcpy(holder->data.chapter_title,temp_char);

			load_in >> holder->data.chapter_num;
			load_in.ignore(100, ':');

			load_in >> holder->data.page_num;
			load_in.ignore(100, ':');

			load_in.get(temp_char, SIZE, '\n');
			load_in.ignore(100, '\n');
			holder->data.short_description = new char[strlen(temp_char) + 1];
			strcpy(holder->data.short_description, temp_char);
			
			location = hash_value(holder->data.chapter_title);
			//cout << "hash" << location <<endl; //testing where collisionhappened
			holder->next = head[location];
			head[location] = holder;


						
		load_in.peek();	
		}
			

	}
	load_in.close();
	load_in.clear();	
   return 0;
}
//this is a copy function that copies that data passed in by the struct
//to each individual data
int study_guide::copy_guide(study_guide & to_copy)
{
	chapter_num = to_copy.chapter_num;
	
	chapter_title = new char[strlen(to_copy.chapter_title) + 1];
	strcpy(chapter_title, to_copy.chapter_title);
	
	page_num = to_copy.page_num;

	short_description = new char[strlen(to_copy.short_description) + 1];
	strcpy(short_description, to_copy.short_description);

   return 0;
}

//this is a hash fucntion that takes a key and turn is in a value that
//then is use as a location where data can be stored in the table.
int study_table::hash_value( char * keyword)
{
	int keyvalue = 0;
	for(int i = 0; i<strlen(keyword); ++i)
		keyvalue += keyword[i];

   return keyvalue % table_size;	

}

//this function goes through the entire table and display all the data stored
//in the table. if the index in the table containes collision, it will step 
//through each node and display its data.
int study_table::display_all()
{
	
	for(int i = 0; i<table_size; ++i)
	{
	
		node * current = head[i];	
		while(current)
		{
			cout<<"\n--------------------------------------------"<<endl;
			cout <<"Charpter " <<current->data.chapter_num <<": " <<current->data.chapter_title <<endl;
			cout <<"Page "<<  current->data.page_num <<endl;
			cout <<"Description: " << current->data.short_description <<endl <<endl <<endl;
			
			current = current->next;
		}
	 }
   return 1;
}
//this is a retrieve function that checks to see if there key word search
//for is in the list, and if it is then copies all the data
int study_guide::retreive(char * keyword, study_guide & to_retreive)
{
	if(strcmp(chapter_title,keyword)==0)
		to_retreive.copy_guide(to_retreive);
	else
   return 0;
}

//this retrieve function takes the value of the key word and check to see
//if its in that specific index. if it is then the data will return true
bool study_table::retrieve_from_table(char * keyword, study_guide & to_find)
{
	int location = hash_value(keyword);
	
	if(!head[location]) return false;
	
	node * current = head[location];
	while(current && current->data.retreive(keyword,to_find))
		current = current->next;
   return false;
}

int study_table::display_chapter(char * key_word)
{
	int index = hash_value(key_word);
	if(head[index] == NULL) return 0;
		
	node * current = head[index];
	while(current)
	{
		if(strcmp(current->data.chapter_title,key_word) ==0)
		{
			cout<<"Chapter "<<current->data.chapter_num <<": " <<current->data.chapter_title<<endl;
			cout<<"Page "<<current->data.page_num<<endl;
			cout<<"Description: "<<current->data.short_description <<endl <<endl;

			return 1;
		}
		else 
		current = current->next;
	}

   return 0;
}
	

//this function allows to edit the description of the given guide
//if its in the list. it take the value of the kew word to derectly 
//access to that index where that datat should be.
int study_table::chapter_to_edit(char * keyword, char *& to_edit)
{
	int index = hash_value(keyword);
	
	if(!head[index]) return 0;
	
	node * current = head[index];
	
	while(current)
	{
		if(strcmp(current->data.chapter_title, keyword)==0)
		{
			delete [] current->data.short_description;
			current->data.short_description = new char[strlen(to_edit) +1];
			strcpy(current->data.short_description,to_edit);

			return 1;
		}
		else 
		current = current->next;
	}

   return 0;
}

//this is a remove function that allow to remove and item that is desired
//to be remove when you passed in the key word that we are comparing with 
//the data taht already exist.
int study_table::chapter_to_remove(char * keyword)
{
	int index = hash_value(keyword);
	
	//in the case that we have no collision and there is only one node
	// we delete that node and set the pointer to NULL.
	if(!head[index]->next)
	{
		
		if(strcmp(head[index]->data.chapter_title,keyword) == 0)
		{
			delete head[index];
			head[index] = NULL;
		   return 1;
		}
		else
		
		return 0;	
	} 
	//otherwise we do have collision and we want to have a preious pointer 
	//so we dont disconect and loose the list when deleting
	
	node * current = head[index];
	node * prev = NULL;
	while(current)
	{
		if(strcmp(current->data.chapter_title, keyword)== 0)
		{
			//in he cse that there is collision and the first node happend
			//to be the data to be deleted, we should check for this special
			//case
			if(prev==NULL)
			{
				node * temp = current->next;
				delete current;
				head[index] = temp;
			}
			//otherwise go through the list untill we find what we're looking for
			else{
				prev->next = current->next;
				delete current;
				current = prev;
			}
			return 1;
		}
		prev = current;
		current = current->next;
	}
return 0;
}
