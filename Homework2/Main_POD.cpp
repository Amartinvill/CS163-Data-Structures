#include "queue_info.h"
using namespace std;

/*
Angel Martinez
Homework 1
*/


int main()
{
	Package_Info to_add;
	container_info insert;
	stack test;
	queue test2;	

	char * sender_name;
	char * contact_info;
	char * package;

	char * item;
	char * description;
	
	/*
	for(int i=0; i<100; ++i)
	{
		cout<<"\n"<<endl;
		++i;
	}	*/

	cout<<""
	    <<"\n"
	    <<"\n" 
	    <<"\n"<<endl<<endl;
	
	int option = 4;
	do
	{
		cout<<" Options to choose form:" <<endl;
		cout<<" (1) Add POD Information"
		    <<" (2) Display content in PODs"
		    <<" (3) Deliver Package"
		    <<" (4) Done" <<endl<<endl;
		cout<<"Enter your option: ";
		
		cin>> option;
		cin.ignore(100,'\n');
		
		if(option == 1)
		{
						
			bool  again = false;
			char temp[100];
			int size = 0;
			int num_array = 0;
			do
			{
				cout<<"\n\n\nEnter Sender Name: ";
				cin.get(temp,100,'\n');
				cin.ignore(100,'\n');
				sender_name = new char[strlen(temp)+1];
				strcpy(sender_name,temp);
				
				cout<<"\n\nEnter Contact Information: ";
				cin.get(temp,100,'\n');
				cin.ignore(100,'\n');
				contact_info = new char[strlen(temp)+1];
				strcpy(contact_info, temp);
				
				cout<<"\n\nSelect a size of package:"<<endl;
				cout<<"(1) SMALL = 18X24" <<endl;
				cout <<"(2) MEDIUM = 24x28" <<endl;
				cout <<"(3) LARGE = 26x36" <<endl;
				cout<<"\nEnter a Size: ";	
				cin>>size;
				cin.ignore(100,'\n');
				if(size==1)
				{
					package = new char[strlen("SMALL")+1];
					strcpy(package, "SMALL");
				}
				else if(size==2)
				{
					package = new char[strlen("MEDIUM")+1];
					strcpy(package, "MEDIUM");
				}
				else if(size==3)
				{
					package = new char[strlen("LARGE")+1];
					strcpy(package, "LARGE");
				}
				else
				{
					cout<<"Invalid option" << endl;
				}
				
				//cout<<"\nHow many Items are part of this person?: ";
				//cin>>num_array;
				
				cout<<"Enter iterm for least important to most important"<< endl;
				
				bool again2 = false;	
				do
				{
					cout<<"\n\nEnter Item: ";
					cin.get(temp,100,'\n');
					cin.ignore(100,'\n');
					item = new char[strlen(temp)+1];
					strcpy(item, temp);
					
					cout<<"\nEnter Description of Item: ";
					cin.get(temp,100,'\n');
					cin.ignore(100,'\n');
					description = new char[strlen(temp) +1];
					strcpy(description, temp);

					insert.add_item(item,description);
					test.push(insert);
						
					cout<<"\nWould you like to add one more Item?(Y/N)";
					char response;
					cin >> response;
					cin.ignore(100, '\n');
					if(toupper(response) == 'N') again2 = true;
				
				}while(!again2);		
				
				to_add.create_package_info(sender_name, contact_info, package);	
				//test.push(to_add);
				test2.enqueue(to_add);
				
				cout<<"\nWould you like to add one more Package?(Y/N) ";
				char response;
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'N')
				again = true;
			
			}while(!again);
		}
		else if(option == 2)
		{
			cout<<"\n\nSenders Infomation:"<<endl;
			test2.display_package_info();
			test.display_all();
			
		}
		else if(option == 3)
		{
			char response = 'N';
			bool again = false;

			cout<<"List of people to deliver package:"<< endl;
			test2.display_name_only();
			
			cout<<"Items of the that need to be delivers:"<< endl;
			test.display_only_name_item();
	
			cout<<"would you like to do a first delivery?(Y/N) ";
			cin>> response;
			cin.ignore(100,'\n');
			if(toupper(response) == 'Y')
			{
				test2.dequeue();
				test.pop();
				return 1;
			}
				
			return 0;
		}
		
	}while(option!=4);



   return 0;
}
