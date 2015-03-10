#ifndef PARSER_H
#define PARSER_H
#include "paraList.h"
#include <string>

class Parser{
 

private:



public:
paraList para;
Parser();
void sortCommand(string &userInput);
void sortDetails(string &userInput);
paraList parseCommand(string userInput);



};

#endif
