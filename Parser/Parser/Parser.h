#ifndef PARSER_H
#define PARSER_H
#include "paraList.h"
#include <string>

class Parser{
 

private:



public:
Parser();
static paraList para;
void sortCommand(string &userInput);
void sortDetails(string &userInput);
string parseCommand(string userInput);



};

#endif
