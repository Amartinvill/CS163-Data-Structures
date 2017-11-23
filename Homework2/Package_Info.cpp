#include "Package_Info.h"
using namespace std;

//this fiction is to constructor that will be initializeing all 
//data memeber form the package information.
Package_Info::Package_Info()
{
	name = NULL;
	contact_info = NULL;
	package_size = NULL;
}
//This function is a distructor that will be dealication and deleteing 
//all memore being creatied by the data memebers of class Package_info
Package_Info::~Package_Info()
{
	if(name)
		delete [] name;
	if(contact_info)
		delete [] contact_info;
	if(package_size)
		delete [] package_size;
}
//The purpuse of this function is to be able to take in arguments and 
//add the information dinamically to the each of the data members
int Package_Info::create_package_info(char * name_toadd, char * contact_info_toadd, char * package_info_toadd)
{
	
	name  = new char[strlen(name_toadd)+1];
	strcpy(name, name_toadd);

	contact_info  = new char[strlen(contact_info_toadd)+1];
	strcpy(contact_info, contact_info_toadd);

	package_size = new char[strlen(package_info_toadd) +1];
	strcpy(package_size, package_info_toadd);
   return 1;	
}
//The purpuse of this function is to be able to pass in an argument
//and be able to copy the data to the respectivaly to each data
//member of the class.
int Package_Info::copy_package_info(const Package_Info & to_copy)
{
	if(name) delete name;

	name  = new char[strlen(to_copy.name)+1];
	strcpy(name, to_copy.name);
	
	if(contact_info) delete contact_info;

	contact_info  = new char[strlen(to_copy.contact_info)+1];
        strcpy(contact_info, to_copy.contact_info);
	
	if(package_size) delete package_size;

	package_size = new char[strlen(to_copy.package_size) +1];
	strcpy(package_size, to_copy.package_size);

   return 1;
}
//the purpuse of this function is solely to dislay the information
//that each data member holds.
int Package_Info::display_all(void)
{
	cout << "\nSender name: " << name <<endl;
	cout << "Contact information: " << contact_info << endl;
	cout << "Package size: "<< package_size << endl;

   return 0;
}

int Package_Info::display_sender()
{
	cout<<"Sender : "<< name <<endl;
	return 0;
}
