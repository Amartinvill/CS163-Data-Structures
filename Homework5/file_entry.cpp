/*
Angel Martinez Villata
Assigment #5 
Data: 6/2/16
Instructor: Karla Fant
*/

#include "file_entry.h"
using namespace std;

//the purpose of this function is to be able to initialize data
//in the class so it can be use to add data
file_entry::file_entry()
{
	Directory = NULL;
	file_name = NULL;
	file_type = NULL;
	file_context = NULL;
}

file_entry::file_entry(char *direct, char *name, char *type, char *context)
{
	insert_to_entry(direct,name,type,context);

}


//the pupose of this data is to be able to free the memory that
//is being allocated, to add data in this class, so we can get 
//rid of any momory leak if any.
file_entry::~file_entry()
{
	if(Directory)
		delete [] Directory;
	if(file_name)
		delete [] file_name;
	if(file_type)
		delete [] file_type;
	if(file_context)
		delete [] file_context;
}

int file_entry::insert_to_entry(char *direct, char *name, char *type, char *context)
{
	if(Directory)
		delete Directory;
	Directory = new char[strlen(direct)+1]; 
	strcpy(Directory, direct);

	if(file_name)
		delete file_name;
	file_name = new char[strlen(name)+1];
	strcpy(file_name,name);
	
	if(file_type)
		delete file_type;
	file_type = new char[strlen(type)+1];
	strcpy(file_type, type);
	
	if(file_context)
		delete file_context;
	file_context = new char[strlen(context)+1];
	strcpy(file_context, context);

   return 1;
}
//the porpose of this function is to be able to make a deep copy
//of the entile information of the file to an object passed in 
//as an argument
int file_entry::copy_file_entry(file_entry & to_copy)
{
	if(Directory)
		delete Directory;
	Directory = new char[strlen(to_copy.Directory) + 1];
	strcpy(Directory, to_copy.Directory);

	if(file_name)
		delete file_name; 
	file_name = new char[strlen(to_copy.file_name)+1];
	strcpy(file_name, to_copy.file_name);

	if(file_type)
		delete file_type;
	file_type = new char[strlen(to_copy.file_type)+1];
	strcpy(file_type,to_copy.file_type);
	
	if(file_context)
		delete file_context;
	file_context = new char [strlen(to_copy.file_context)+1];
	strcpy(file_context,to_copy.file_context);
	
   return 1;
}
//this fintion displays the information of the data member of the class
int file_entry::display_file()
{
	cout<<"\nDirectory: "<< Directory << endl;
	cout<<"File Name: " << file_name <<endl;
	cout<<"File Type: " << file_type <<endl;
	cout<<"context of the File: " <<file_context <<endl<<endl;
	
   return 1;
}

//this function will compared if the directory exist in the list or
//else the directory does not exist
bool file_entry::compare_directory(char * to_compare)
{
	if(strcmp(file_name, to_compare)==0)
		return true;
   return false;
}
int file_entry::display_file_name()
{
	cout<<"\nFile name: "<< file_name <<endl;
	
   return 1;
}

int file_entry::retreive_data(file_entry & to_retreive, char * keyword)
{
	if(strcmp(file_name,keyword)==0)
	{
		to_retreive.copy_file_entry(to_retreive);
	   return 1;
	}
   return 0;
}
