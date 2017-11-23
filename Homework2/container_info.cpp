#include "container_info.h"
using namespace std;
/*
the purpose of thes class is to be able to add item for the client
application so they can be used for the stack in the future.

*/

container_info::container_info()
{
	item = NULL;
	description = NULL;
}

container_info::~container_info()
{
	if(item) delete [] item;
	if(description) delete [] description;

}

int container_info::add_item(char * item_toadd, char * description_toadd)
{
	if(item) delete item;

	item = new char[strlen(item_toadd)+1];
	strcpy(item, item_toadd);
	
	if(description) delete description;

	description = new char[strlen(description_toadd) +1];
	strcpy(description, description_toadd);

   return 1;
}

int container_info::copy_item(const container_info & copy_from)
{
	// if they do exist the dekete what already there to add new stuff
	if(copy_from.item)
		delete copy_from.item;	
		
		item = new char[strlen(copy_from.item) + 1];
		strcpy(item, copy_from.item);
	if(copy_from.description)
		delete copy_from.description;

		description = new char[strlen(copy_from.description) +1];
		strcpy(description, copy_from.description);	

   return 1;
}
int container_info::display_item()
{
	cout <<"\nItem Name: " << item <<endl;
	cout <<"Item Description: " << description <<endl;

   return 1;
}

int container_info::display_only_item()
{
	cout <<"Name of Item: " << item <<endl;

   return 1;
}

	
	
