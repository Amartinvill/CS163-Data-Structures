#include <cstring>
#include <cctype>
#include <iostream>

/*
Angel Martinez Villalta
Spring 2016 CS163
Program # 2 

This file contains information provided by the application client.
*/

class Package_Info
{
	public: 
		Package_Info();
		~Package_Info();
		//this function will pass in couple argument from the aplication client and 
		//add the information to the data members.
		int create_package_info(char * name, char * contact_info, char * package_size);
		//this function takes Package_Info class  to be able to copy in the its own
		//respectably data memebers.
		int copy_package_info(const Package_Info & to_copy);
		//This Fuction display all the data form the package.
		int display_all(void);
		int display_sender();
	private:
		char * name;
		char * contact_info;
		char *  package_size;
};
