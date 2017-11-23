#include "airport_info.h"
using namespace std;
/*
Angel Martinez
Homework 1
*/


int main()
{
	airport_info test;
	test.read_from_file();
	
	char * From_Location;
	char * To_destination;
	char * Answer;
	
	
	for(int i=0; i<100; ++i)
	{
		cout<<"\n"<<endl;
		++i;
	}	

	cout<<"welcome! and congratulations! You have been selecteve to receive couple"<<endl;
	cout<<"trips FREE OF CHARCHE. YES! free of charge for being one of the first"<<endl;
	cout<<"member since we launch this app. Down bellow you wil have the menue that"<<endl; 
	cout<<"will allow you to shoose from panny of our awesome deal just for you."<<endl;
	
	int option = 4;
	do
	{
		cout<<"\n\n\t Options to choose form:" <<endl;
		cout<<"\n\n\t (1) Add a trip"
		    <<"\n\n\t (2) Display Itineraty"
		    <<"\n\n\t (3) Make a change to Itinerary"
		    <<"\n\n\t (4) Done" <<endl<<endl;
		cout<<"Enter your option: ";
		
		cin>> option;
		cin.ignore(100,'\n');
		
		if(option == 1)
		{
			int trips = 0;
			cout<<"Number of Trips booking: ";
			cin>> trips;
			cin.ignore(100,'\n');
			for(int i = 0; i<trips; ++i)
			{
				
				bool  again = false;
				
				char temp[SIZE];
				cout<<"\n\nHere are the locations to choose form:"<<endl;
				test.display_airport();
				cout<<"\n\n\nAirport traveling from: ";
				cin.get(temp,SIZE,'\n');
				cin.ignore(100,'\n');
				From_Location = new char[strlen(temp)+1];
				strcpy(From_Location,temp);
				test.itinerary(From_Location,trips);	
				
				do{
				cout<<"\n\nEnter Destination: ";
				cin.get(temp,SIZE,'\n');
				cin.ignore(100,'\n');
				To_destination = new char[strlen(temp)+1];
				strcpy(To_destination, temp);
				/*
				cout<<"Are you a memeber of the Pre TSA club?"<<endl;
				cout<<"Yes or No: ";
				cin.get(temp,SIZE,'\n');
				cin.ignore(100,'\n');
				Answer = new char[strlen(temp)+1];
				strcpy(Answer,temp);*/
				test.itinerary(To_destination, i);
				
				cout<<"Would you like to go anywhere else from here?(Y/N) ";
				char response;
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'N')
					again = true;
				
				}while(!again);
			}
			
		}
		else if(option == 2)
		{
			cout<<"\n\nHere is your Itinerary:"<<endl;
			test.display_itinerary();
		}
		else if(option == 3)
		{
			//meant to construct couple functions to be able to do this option
			return 0;
		}
		
	}while(option!=4);



   return 0;
}
