#ifndef PARSER_H
#define PARSER_H
#include "paraList.h"
#include "..\..\Task\Task\Task.h"
#include <string>

class Parser{
 

private:
paraList para;



public:
Parser();
void sortCommand(string userInput);
void sortDetails(string userInput);
void parseCommand(string userInput);



};

#endif
