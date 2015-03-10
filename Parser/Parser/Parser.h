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
void sortCommand();
void sortDetails();
void parseCommand(string userInput);



};

#endif
