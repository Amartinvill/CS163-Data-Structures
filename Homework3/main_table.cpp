/*
Angel Martinez Villalta
Assigment #3
date: 05/18/2016
profesor: Karla Fant	

The purpose of this application is to test and see that all my functions are
working correctly and doing what we wanted to do


*/
#include "study_guide.h"
using namespace std;

int main()
{
	study_table guide;
	
	//this for loop all it does is clear n number of lines each time this
	//code is being ran. 
	for(int i = 0; i<55; ++i)
		cout<<"\n";

	guide.read_from_file();
	
	int option = 5;
	char key[SIZE];
	char * keyword;
	char description[300];
	char * to_add;

	do
	{
		cout<<"'1' Display Study Guide" <<endl;
		cout<<"'2' Edit Study Guide" <<endl;
		cout<<"'3' Display Specific Chapter" <<endl;
		cout<<"'4' Remove Undesire Chapter" <<endl;
		cout<<"'5' Done" << endl << endl;

		cout<<"Enter one option from the menu: ";
		cin>>option;
		cin.ignore(100,'\n');
		//int the case the user chooses option 1
		//which would allow them to see everythin in the table.
		if(option == 1)
		{
			cout<<"*****Study Guide Notes*****";
			guide.display_all();
		}
		//if the user decides to choose option number 2, then it would prompt
		//the user to edit the desire note and display the newly data.
		else if(option == 2)
		{
			cout<<"Enter chapter title  to edit: ";
			cin.get(key, SIZE, '\n');
			cin.ignore(100, '\n');
			for(int i = 0; i<strlen(key); ++i)
				key[i] = toupper(key[i]);
			keyword = new char[strlen(key) + 1];
			strcpy(keyword, key);
		
			cout<<"Chapter to edit" <<endl; 
			guide.display_chapter(keyword);
			
			cout<<"\nEnter new description: ";
			cin.get(description, 300, '\n');
			cin.ignore(100, '\n');
			to_add = new char[strlen(description) +1];
			strcpy(to_add, description);
			
			guide.chapter_to_edit(keyword,to_add);
			cout <<"\nChapter has been editted!"<<endl;
			guide.display_chapter(keyword);
			
		}
		//in this case the user has the option to desplay a selected guide
		//to see what the information is.
		else if(option == 3)
		{
			cout<<"Enter chapter title you wish to see: ";
			cin.get(key,SIZE,'\n');
			cin.ignore(100, '\n');
			for(int i = 0; i<strlen(key); ++i)	
				key[i]= toupper(key[i]);
			keyword = new char[strlen(key) +1];
			strcpy(keyword, key);

			guide.display_chapter(keyword);
		}
		//lastly if the user chooses this option then they can remove a 
		//desire guide
		else if(option == 4)
		{
			cout<<"Enter chapter title you wish to remove: ";
			cin.get(key,SIZE, '\n');
			cin.ignore(100,'\n');
			for(int i=0; i<strlen(key); ++i)
				key[i] = toupper(key[i]);
			keyword = new char[strlen(key) +1];
			strcpy(keyword, key);
			guide.chapter_to_remove(keyword);
			// could use the retrieve function here to check if the data
			// was in the list
			guide.display_all();	
			
			
		}
		else 
		{
			if(option <=0 || option >= 6)
			return 0;
		}
	}while(option != 5);

   return 0;
};
