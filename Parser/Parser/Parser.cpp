#include "Parser.h"
#include "paraList.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


Parser::Parser()
{}

//sortcommand checked!
void Parser::sortCommand(string &userInput)
{   
	
	int index;
	index=userInput.find_first_of(" ");
	string temp = userInput.substr(0, index);
	para.processCommand(temp);
	userInput.erase(0,index+1);
//	cout<<"Command:"<<para.getCommand()<<endl;
	return;
}

//testing
void Parser::sortDetails(string &userInput)
{
    int index;
	string _eventstartdetails;
	string _eventenddetails;
	
	if(userInput.find("from")==string::npos&&userInput.find("to")==string::npos)
	{  
		para._task.changeTaskName(userInput);
	    return;

	}
	else if (userInput.find("from")!=string::npos&&userInput.find("to")==string::npos)
	{
		processBeforeKeywordFrom(userInput);
		string sd,st;
	
		
		splitstring(sd,st,checkingKeywordX(userInput));
	    para._task.changeTaskStartDate(sd);
	    para._task.changeTaskStartTime(st);
		
		return;
	}
	else if (userInput.find("from")==string::npos&&userInput.find("to")!=string::npos)
	{
		processBeforeKeywordTo(userInput);
		return;
	}
	else
	{

	processBeforeKeywordFrom(userInput);
	index=userInput.find("to")-1;
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

	//Event Start details sort SLAP 
	string a,b;
	splitstring(a,b,_eventstartdetails);
	para._task.changeTaskStartDate(a);
	para._task.changeTaskStartTime(b);



	//Event End details sort SLAP 
	string c,d;
	splitstring(c,d,_eventenddetails);
	para._task.changeTaskEndDate(c);
	para._task.changeTaskEndTime(d);
	
	return;  }
}
paraList* Parser::parseCommand(string userInput)
{  
	
	cout<<"Starting parseCommand test...."<<endl;
	sortCommand(userInput);
	processCommand(userInput);
	
//	
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
		cout<<"Task added..."<<endl;

	}
	else if(command=="delete")
	{   istringstream iss (userInput);
		iss>>index;
	    cout<<"Delete command..."<<endl;
		
	    para.processDeleteNumber(index);
		cout<<"Number that is input in the file:"<<para.getDeleteInteger()<<endl; 

	}
	else if(command=="display")
	{   istringstream iss (userInput);
		
		cout<<"Displaying..."<<endl;
	    iss>>index;
	    para.processDisplayNumber(index);
		cout<<"Number that is input in the file:"<<para.getDisplayInteger()<<endl; 
	    
		cout<<"eventname:"<<para._task.getTaskName()<<endl;
		cout<<"start date:"<<para._task.getTaskStartDate()<<endl;
		cout<<"start time:"<<para._task.getTaskStartTime()<<endl;
		
		cout<<"end date:"<<para._task.getTaskEndDate()<<endl;
		cout<<"end time:"<<para._task.getTaskEndTime()<<endl;
		cout<<"p:"<<para._task.getTaskPriority()<<endl;
	}
	else if(command=="update")
	{   int b,index;
	    string a;
		
		
		cout<<"Update command..."<<endl;
	    b=userInput.find_first_of(" ");
	    a=userInput.substr(0,b);
        istringstream iss (a);
		iss>>index;
		userInput.erase(0,b+1);
		b=userInput.find_first_of(" ");
		para.processKeyWord(userInput.substr(0,b));
		userInput.erase(0,b+1);
		para.processInput(userInput);
		para.processUpdateNumber(index);
		cout<<"Number that is input in the file:"<<para.getUpdateInteger()<<endl;
		para.displayKeyword();
		para.displayInput();
	}
	else
	{
	 cout<<"Unknown command please try again..."<<endl;

	}



	return;
}

void Parser::processBeforeKeywordFrom(string &userInput)
{
	int index;
   
	
	index=userInput.find("from")-1;
    para._task.changeTaskName(userInput.substr(0,index));
	userInput.erase(0,index+6);

	return;
}


void Parser::processBeforeKeywordTo(string &userInput)
{   int index;
	index=userInput.find("to")-1;
	para._task.changeTaskName(userInput.substr(0,index));
	userInput.erase(0,index+4);
	string a,b;
	splitstring(a,b,checkingKeywordX(userInput));
	    para._task.changeTaskEndDate(a);
	    para._task.changeTaskEndTime(b);
		
	return;
}

string Parser::checkingKeywordX(string &userInput)
{   
	string details;
	
	
	
	if(userInput.find("!")!=string::npos){  
	 int index=userInput.find("!")-1;
        details=userInput.substr(0,index);
		userInput.erase(0,index+2);
	    para._task.changeTaskPriority(userInput);}
	else{   
		para._task.changeTaskPriority("No priority");
        details=userInput;
	     
        }

	return details;
}
