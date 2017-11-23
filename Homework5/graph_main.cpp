/*
Angel Martinez Villalta
date: 6/2/16
Assigment #5
Proctor: Karla Fant
*/

#include "graph_file.h"
using namespace std;

int main()
{
	graph_table file;
	file_entry * to_add = NULL;
	
	char temp_directory[SIZE]; char * directory;
	char temp_name[SIZE]; char * name;
	char temp_type[SIZE]; char * type;
	char temp_context[SIZE]; char * context;
	ifstream load_in;
	load_in.open("file_entry.txt");
	if(load_in)
	{
		load_in.peek();
		while(!load_in.eof())
		{
			load_in.get(temp_directory,SIZE,':'); load_in.ignore(100,':');
			directory = new char[strlen(temp_directory)+1];
			strcpy(directory,temp_directory);	
			
			load_in.get(temp_name,SIZE,':'); load_in.ignore(100,':');
			name = new char[strlen(temp_name)+1];
			strcpy(name, temp_name);

			load_in.get(temp_type,SIZE,':'); load_in.ignore(100,':');
			type = new char[strlen(temp_type)+1];
			strcpy(type, temp_type);
			
			load_in.get(temp_context,SIZE,'\n'); load_in.ignore(100,'\n');
			context = new char[strlen(temp_context)+1];
			strcpy(context, temp_context);

			to_add = new file_entry(directory,name,type,context);
			file.insert_to_vertex(*to_add);
		
		load_in.peek();
		}
		delete [] directory;
		delete [] name;
		delete [] type;
		delete [] context;
	}
	load_in.close();
	load_in.clear();
	///////////////////////////////////////////////////////////////////////////////////////////
		
	int option = 0;
	char * first; char first_temp[SIZE];
	char * second; char second_temp[SIZE];
	
	do
	{
		cout<<"'1' To display all items"<<endl;
		cout<<"'2' To add conections"<<endl;
		cout<<"'3' To display all connections: "<<endl;
		cout<<"'4' Done"<<endl;
		
		cout<<"\n\nEnter Option: ";
		cin>>option; cin.ignore(100, '\n');

		if(option == 1)
		{
			file.display_vertecies();
			cout<<endl<<endl;
		}
		else if(option == 2)
		{
			file.display_vertecies_name();
			cout<<endl<<endl;

			cout<<"Enter two file names wich are connected:"<<endl;
			cout<<"First file name: ";
			cin.get(first_temp, SIZE, '\n'); cin.ignore(100, '\n');
			first = new char[strlen(first_temp)+1];
			strcpy(first,first_temp);

			cout<<"File related: ";
			cin.get(second_temp, SIZE, '\n'); cin.ignore(100, '\n');
			second = new char[strlen(second_temp)+1];
			strcpy(second, second_temp);
			
			file.insert_to_edge(first, second);
			file.display_adjacent(first);
			
			delete [] first;
			delete [] second;
		}
		else if(option == 3)
		{
			cout<<"Enter the file name to see all conection: ";
			cin.get(first_temp, SIZE, '\n'); 
			cin.ignore(100,'\n');
			first = new char[strlen(first_temp)+1];
			strcpy(first, first_temp);
			file.display_breath_first(first);
		
			delete [] first;
		}else return 1;
		
		}while(option!=4);

   return 0;
}

