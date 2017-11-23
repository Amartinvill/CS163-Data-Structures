/*
Angel Martinez Villalta
Assigment # 5
Date: 6/2/16 
Instructor: Karla Fant

The purpose of this ADT is to be able to create funtions that
will help create information for a single class of file entries
so i could use the in the ADT for graphs.
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

const int SIZE = 300;

class file_entry
{
	public:
		file_entry();
		file_entry(char *, char *, char *, char *);
		~file_entry();
		int copy_file_entry(file_entry & to_copy);
		int  insert_to_entry(char *, char *, char *, char *);
		bool compare_directory(char * to_compare);
		int display_file();
		int display_file_name();
		int retreive_data(file_entry & to_retreive, char * keyword);
		
	private:
		char * Directory;
		char * file_name;
		char * file_type;
		char * file_context;
};



