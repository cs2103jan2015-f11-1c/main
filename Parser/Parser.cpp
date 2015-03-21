#include "Parser.h"
#include "paraList.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>

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
	keywordType Keyword;
	Keyword = determineKeywords(userInput);


	switch (Keyword)
	{
	case NONE:
	{	para._task.changeTaskName(checkingKeywordX(userInput));
	return; }
	case STARTONLY:
	{
		processBeforeKeywordFrom(userInput);
		string sd, st;


		splitstring(sd, st, checkingKeywordX(userInput));
		para._task.changeTaskStartDate(sd);
		para._task.changeTaskStartTime(st);

		return;
	}
	case ENDONLY:
	{
		processBeforeKeywordTo(userInput);
		return;
	}
	case DEADLINE:
	{

		processBeforeKeywordBy(userInput);
		return;
	}
	case START_END:
	{
		index = userInput.find("from") - 1;
		string tempName = userInput.substr(0, index);

		para._task.changeTaskName(userInput.substr(0, index));

		processBeforeKeywordFrom(userInput);
		index = userInput.find("to") - 1;
		_eventstartdetails = userInput.substr(0, index);
		userInput.erase(0, index + 4);
		//getting the priorities
		if (userInput.find("!") != string::npos){
			index = userInput.find("!") - 1;
			_eventenddetails = userInput.substr(0, index);
			userInput.erase(0, index + 2);
			para._task.changeTaskPriority(userInput);
		}
		else{
			//para._task.changeTaskPriority("No priority");
			_eventenddetails = userInput.substr(0, index);

		}

		string a, b;
		splitstring(a, b, _eventstartdetails);
		para._task.changeTaskStartDate(a);
		para._task.changeTaskStartTime(b);

		//Event End details sort SLAP 
		string c, d;
		splitstring(c, d, _eventenddetails);


		para._task.changeTaskEndDate(c);
		para._task.changeTaskEndTime(d);
	}
	}
	return;  
}



paraList* Parser::parseCommand(string userInput)
{  
	para.clearTask();
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
	{   int b,index;
	    string a;
		
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
	}
	else
	{
		command == "invalid";

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


void Parser::processBeforeKeywordBy(string &userInput)
{
	int index;
	index = userInput.find("by") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);
	string a, b;
	splitstring(a, b, checkingKeywordX(userInput));
	para._task.changeTaskDeadlineDate(a);
	para._task.changeTaskDeadlineTime(b);

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
		//para._task.changeTaskPriority("No priority");
        details=userInput;
	     
        }

	return details;
}

Parser::keywordType Parser::determineKeywords(string userInput)
{
	if (userInput.find("from") == string::npos&&userInput.find("to") == string::npos&&userInput.find("by") == string::npos)
	{
		return NONE;
	}
	else if (userInput.find("from") != string::npos&&userInput.find("to") == string::npos)
	{
		

		return STARTONLY;
	}
	else if (userInput.find("from") == string::npos&&userInput.find("to") != string::npos)
	{
		
		return ENDONLY;
	}
	else if (userInput.find("by") != string::npos)
	{

		
		return DEADLINE;
	}
	else
	{
		return  START_END;
	}
}