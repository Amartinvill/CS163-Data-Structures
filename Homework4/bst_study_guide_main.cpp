/*
Angel Martinez Villalta
Assignment #4
Date: 5/23/16
Proctor: Karla Fant

The purpose of this file is to be able to building an application 
that can test all the function implemented

*/
#include "bst_study_guide.h"
using namespace std;

int main()
{
	study_guide guide;
	guide.load_from_file();

	for(int i= 0; i<100; ++i)
		cout<<"\n" <<endl;
	int option = 0;
	char  * keyword;
	char char_temp[SIZE];
	char * new_notes;
	bool again = false;  
	do
	{	
		//menue in which the user can select an option
		cout<<"Choose an option from this menu:"<<endl;
		cout<<"(1) To display study guide"<<endl;
		cout<<"(2) To edit notes "<<endl;
		cout<<"(3) To remove undesire notes"<<endl;
		cout<<"(4) done"<<endl;
		
		cout<<"Enter option: ";
		cin>>option; cin.ignore(100,'\n');
		//if the user chooses 1 than it will display the data
		if(option == 1)
		{
			guide.display_all();
		}
		//if the user choose this option, it will promtp them to entry
		//a keyword which the want to modefy
		else if(option == 2)
		{
			cout<<"Enter notes title you wish to modify: ";
			cin.get(char_temp,SIZE,'\n'); cin.ignore(100, '\n');
			for(int i=0; i<strlen(char_temp); ++i)
				char_temp[i] = toupper(char_temp[i]); 
			keyword = new char[strlen(char_temp)+1];
			strcpy(keyword, char_temp); 
			

			cout<<"Add new notes: ";
			cin.get(char_temp,SIZE,'\n'); cin.ignore(100,'\n');
			new_notes = new char[strlen(char_temp)+1];
			strcpy(new_notes, char_temp);
		
			//if the data exist in the list then i will display that expecific data
			if(guide.edit_notes(keyword,new_notes)== 1)	
			{	
				cout<<"The notes have been changes" <<endl;
				guide.display_specific_notes(keyword);
			}
			else
			cout<<"Notes not in the list" <<endl<<endl;
			//dealocaling memory that i was created in thes file
			delete [] keyword;
			delete [] new_notes;
				 
		}
		//option 3 will allowed the user to remove a desire item.
		else if(option == 3)
		{
			cout<<"Enter notes title to remove: ";
			cin.get(char_temp,SIZE,'\n'); cin.ignore(SIZE,'\n');
			for(int i=0; i<strlen(char_temp); ++i)
				char_temp[i] = toupper(char_temp[i]);
			keyword = new char[strlen(char_temp)+1];
			strcpy(keyword, char_temp);
			guide.remove_keyword(keyword);
			cout<<"Notes have been deleted" <<endl<<endl;
			guide.display_all();
		
			//cout<<"notes not in the list"<<endl<<endl;
			delete [] keyword;	
		}

	}while(option !=4);

   return 0;
}
