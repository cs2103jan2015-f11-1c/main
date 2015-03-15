#ifndef PARSER_H
#define PARSER_H

#include "paraList.h"

#include<iostream>
#include <string>


using namespace std;

class Parser{

public:
	
Parser();
paraList para;
void sortCommand(string &userInput);
void sortDetails(string &userInput);
paraList *parseCommand(string userInput);
void processCommand(string &userInput);
void splitstring (string &first,string &second,string &input);

void processBeforeKeywordFrom(string &userinput);
void processBeforeKeywordTo(string &userinput);
string checkingKeywordX(string &userinput);

};

#endif
