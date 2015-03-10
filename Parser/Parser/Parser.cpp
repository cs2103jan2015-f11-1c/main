#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Parser::Parser()
{}*/

/*
void Parser::sortCommand(string &userInput)
{   
    int index;
	index=userInput.find_first_of(" ");
	para.processCommand(userInput.substr(0,index));
	userInput.erase(0,index+1);
	
	return;
}

void Parser::sortDetails(string &userInput)
{
    int index;
	index=userInput.find("from")-1;
	para.processCommand(userInput.substr(0,index));
	userInput.erase(0,index+1);
	
	
	return;
}
*/
string Parser::parseCommand(string userInput)
{  
	
	
	//sortCommand(userInput);
	//sortDetails(userInput);

	
  // para._command=userInput;
	

	//return para;

	return userInput;
}
