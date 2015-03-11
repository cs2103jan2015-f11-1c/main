#include "Parser.h"
#include "paraList.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


Parser::Parser()
{}


void Parser::sortCommand(string &userInput)
{   
    int index;
	index=userInput.find_first_of(" ");
	para.processCommand(userInput.substr(0,index));
	cout<<"Command:"<<para._command<<endl;
	userInput.erase(0,index+1);
	
	return;
}

void Parser::sortDetails(string &userInput)
{
    int index;
	string _eventstartdetails;
	string _eventenddetails;
	
	index=userInput.find("from")-1;
	//changing task name 
	para->_task->changeTaskName(userInput.substr(0,index));
	userInput.erase(0,index+6);
	index=userInput.find("to")-1;
	//getting start details 
	_eventstartdetails=userInput.substr(0,index);
    userInput.erase(0,index+4);
	//getting the priorities
	if(userInput.find("!")!=string::npos){  
		index=userInput.find("!")-1;
        _eventenddetails=userInput.substr(0,index);
		userInput.erase(0,index+2);
	    para->_task->changeTaskPriority(userInput);}
	else{   
		para->_task->changeTaskPriority("No priority");
        _eventenddetails=userInput.substr(0,index);
	     
        }
	
	


	//Event Start details sort SLAP 
	string stString=_eventstartdetails;
	index=stString.find_first_of(" ");
	para->_task->changeTaskStartDate(stString.substr(0,index));
	stString.erase(0,index+1);
	para->_task->changeTaskStartTime(stString);

	//Event End details sort SLAP 
    string endString=_eventenddetails;
	index=endString.find_first_of(" ");
	para->_task->changeTaskEndDate(endString.substr(0,index));
	endString.erase(0,index+1);
	para->_task->changeTaskEndTime(endString);
	
	
	return;
}

paraList* Parser::parseCommand(string userInput)
{  
	
	cout<<"Starting parseCommand test...."<<endl;
	sortCommand(userInput);
	sortDetails(userInput);

	
    
	

	return para;

	
}
