#include "airport_info.h"
using namespace std;

//this constructor is being use to allocate the memory
airport_info::airport_info()
{
	head = NULL;
	index = 0;
	admin = new node* [MAX];
	for(int i = 0; i <MAX ; ++i)
	{
		admin[i]= NULL;
	}
}
// destructor to deallocate the memory that was created
airport_info::~airport_info()
{
	/*	node * temp;
		node * current;

		if(!flight_info)return 0;
		if(flight_info->next==NULL)
		{
		delete flight_info;
		flight_info == NULL;
		}
		current = flight_info;
		while(current->next!=NULL)
		{
		temp->next = current->next;
		delete current;
		current = temp->next;
		current = current->next;

		}
		delete flight_info;
		flight_info = NULL:
	 */
}

//this function will read from an external file and add directly too a LLL
//by passing in a node with the data that is being read.
int airport_info::read_from_file()
{
	char temp[SIZE];
	node * temp_flight;
	ifstream load_in;
	load_in.open("airport.txt");
	if(load_in)
	{
		load_in.get(temp, SIZE, ':');
		load_in.ignore(100,':');

		while(load_in && !load_in.eof())
		{

			temp_flight = new node;
			temp_flight->Flight.airport_name = new char[strlen(temp) +1];
			strcpy(temp_flight->Flight.airport_name, temp);

			load_in >> temp_flight->Flight.num_customs;
			load_in.ignore(100,':');

			load_in >> temp_flight->Flight.num_immigration;
			load_in.ignore(100,':');

			load_in >> temp_flight->Flight.num_of_check_points;
			load_in.ignore(100,':');

			load_in >> temp_flight->Flight.lines_WaitTime;
			load_in.ignore(100,':');

			load_in >> temp_flight->Flight.gate2gate_time;
			load_in.ignore(100,'\n');

			insert_to_LLL(head,temp_flight);

			load_in.get(temp, SIZE, ':');
			load_in.ignore(100,':');
		}
	}
	load_in.close();
	load_in.clear();

	return 0;

}
//This function is to make the program a little bit more clearnig so that I do
//not have to keep typing the same information over and over again. This function makes
//a copy of the data that is being passed in.
int flight_info::copy_info(flight_info & to_copy)
{

	airport_name = new char[strlen(to_copy.airport_name)+1];
	strcpy(airport_name, to_copy.airport_name);

	num_customs = to_copy.num_customs;

	num_immigration = to_copy.num_immigration;

	num_of_check_points = to_copy.num_of_check_points;

	lines_WaitTime = to_copy.lines_WaitTime;

	gate2gate_time = to_copy.gate2gate_time;

	return 0;

}
// this function creates a liner linked list of information form the external file.
//this function passed a node with information to then be add to the list. 
int airport_info::insert_to_LLL(node *& head, node *& to_add)
{
	if(!head)
	{
		head = to_add;
		head->next = NULL;
		return 0;
	}

	to_add->next = head;
	head = to_add;

	return 0;
}

//This function created a array of linked list and depending on the match, if that match  exist
//in the original list then i make a copy to the array of liniear linked list.
int airport_info::itinerary(char * location, int trips)
{
	if(!head) return 0;

	if(!head->next)// if there is only one airport on the list just copy only just the location
	{
		if(strcmp(head->Flight.airport_name,location)==0)
		{
			index = trips;

			if(admin[index]==NULL)
			{
				node * tempCurrent = admin[index];
				tempCurrent = new node;
				tempCurrent->Flight.copy_info(head->Flight);
				tempCurrent->next = NULL;
			}   
		}	
	}
	else
	{
		node * current = head;
		node * holder = admin[trips];
		bool match = false;
		while(current && !match)
		{
			if(strcmp(current->Flight.airport_name, location)==0)
			{
				if(!admin[trips])
				{
					admin[trips] = new node;
					admin[trips]->Flight.copy_info(current->Flight);
					admin[trips]->next=NULL;
					match = true;
				}

				else
				{
					while(holder->next!=NULL)
					{
						holder = holder->next;
					}
					node * temp = new node;
					temp->Flight.copy_info(current->Flight);
					temp->next = NULL;
					holder->next = temp;	
					match = true;
				}
			}


			current = current->next;
		}
		
	}	

	return 0; 

}

//this function displays the information that each pointer in the array have as
//an Itinerary for the user. 
int airport_info::display_itinerary()
{
	for(int i=0; i<MAX; ++i)
	{
		if(!admin[i]) return 0;

		node * current = admin[i];
		while(current!=NULL)
		{
			cout <<"Name of the Airport: "<<current->Flight.airport_name << endl;
			//cout <<"Number of Customs: "<<current->Flight.num_customs << endl;
			//cout <<"Number of Immigration: "<<current->Flight.num_immigration <<endl;
			//cout <<"Number of Check Points: "<<current->Flight.num_of_check_points << endl;
			cout <<"Estimated Waiting time throughout you trip:"<<current->Flight.lines_WaitTime << endl;
			cout <<"Estimate time from gate to gate: "<<current->Flight.gate2gate_time << endl;
			current = current->next;
		}

	}
	return 1;
}
//made this so i could display the names of the airport list so the user coould know what to 
//choose form and not break the code
int airport_info::display_airport()
{
	if(!head) return 0;
	if(!head->next)
	{
		cout << "Airport Name: " << head->Flight.airport_name << endl;
	}

	node * temp = head;
	while(temp!=NULL){
		cout << "Airport Name: " << temp->Flight.airport_name << endl;
		temp = temp->next;
	}

	return 0;

}

/*
   int airport_info::remove_from_LLL(char * to_remove)
   {
   remove_from_LLL(head,to_remove);
   return 0;
   }

   int airport_info::remove_from_LLL(node *& head, char * to_remove)
   {
   if(!head)return 0;
   if(!head->next)
   {
   if(strcpy(head->Flight.airport_name,to_remove)==0)
   {
   delete head;
   head = NULL;
   }

   return 0;
   }
   if(strcpy(head->Flight.airport_name,to_remove)==0)
   {
   node * temp = head->next;
   delete head;
   head = temp;
   }

   remove_from_LLL(head->next,to_remove);

   return 0;
   }
 */	



