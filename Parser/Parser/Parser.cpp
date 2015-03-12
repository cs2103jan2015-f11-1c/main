#include "Parser.h"
#include "paraList.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


Parser::Parser()
{}

void Parser::sortCommand(string &userInput)
{   
	
	int index;
	index=userInput.find_first_of(" ");
	string temp = userInput.substr(0, index);
	para.processCommand(temp);
	userInput.erase(0,index+1);
	return;
}

void Parser::sortDetails(string &userInput)
{
    int index;
	string _eventstartdetails;
	string _eventenddetails;
	
	index=userInput.find("from")-1;
	string tempName = userInput.substr(0, index);

	para._task.changeTaskName(userInput.substr(0,index));
		

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
	    para._task.changeTaskPriority(userInput);}
	else{   
		para._task.changeTaskPriority("No priority");
        _eventenddetails=userInput.substr(0,index);
	     
        }

	string a,b;
	splitstring(a,b,_eventstartdetails);
	para._task.changeTaskStartDate(a);
	para._task.changeTaskStartTime(b);

	//Event End details sort SLAP 
	string c,d;
	splitstring(c,d,_eventenddetails);
	

	para._task.changeTaskEndDate(c);
	para._task.changeTaskEndTime(d);

	return;
}


paraList* Parser::parseCommand(string userInput)
{  

	sortCommand(userInput);
	processCommand(userInput);
	
	return &para;	
}

void Parser::splitstring (string &first,string &second,string &input)
{   int index;
	index=input.find_first_of(" ");
	first=input.substr(0,index);
	input.erase(0,index+1);
	second=input;

	return;
}

void Parser::processCommand(string &userInput)
{
	string command=para.getCommand();
	int index;
	
	if(command=="add")
	{
		sortDetails(userInput);   	
	}
	else if(command=="delete")
	{   istringstream iss (userInput);
		iss>>index;	
	    para.processDeleteNumber(index);
	}
	else if(command=="display")
	{   istringstream iss (userInput);
	    iss>>index;
	    para.processDisplayNumber(index);
	}
	else if(command=="update")
	{    istringstream iss (userInput);
		
	    iss>>index;
	    para.processUpdateNumber(index);
	}
	else
	{
		command == "invalid";

	}

	para.clearAllNumber();

	return;
}
