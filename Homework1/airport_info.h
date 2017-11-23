#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
/*
Angel Martinez Villalta
Program # 1
The purpose of this Program is to facilitate travelers to travel form one airport
to another withought missing their flight. In this Porgram i will be using two
different data structure to complete this assigmnet succesfully. the first
part of this program will be dealing with a liner linked list that reading from 
an external file that should have all the information need it for travelers.
 10 */                                                                              
const int SIZE = 50;                                                            
const int MAX = 10;                                                                                 
struct flight_info                                                              
{                                                                               
        char * airport_name;                                                    
        int num_customs;                                                        
        int num_immigration;                                                     
        int num_of_check_points;                                                
        int lines_WaitTime;
	int gate2gate_time;                                                                      
	int copy_info(flight_info & to_copy);
	   
};                                                                              
                                                                                 
struct node                                                                     
{   
	char * int_or_dom;
	int sum_waittime;
	int  num_of_immigration;
	                                                                            
	flight_info Flight;                                                       
        node * next;
};
                                                            
class airport_info                                                              
{                                                                               
         
	public:                                                                 
		airport_info(void);                                             
                ~airport_info(void);                                            
                int read_from_file(); // read function to read data from a file and added to a LLL.
		int display_airport(); // displays the name of the airport in the list of LLL                              
                int display_itinerary(); //display the itinerary of the trips taken
  //              int remove_from_LLL(char * to_remove);
		int itinerary(char * match, int trips);// adds a information to the array of LLL.
	private:                                                                
         	int insert_to_LLL(node *& head, node *& to_add); //created a LLL
//		int remove_from_LLL(node *& head, char * to_remove);                         
         	
		node * head;                                                            
                node ** admin;
		int index;                                                                
};

                                                                              

