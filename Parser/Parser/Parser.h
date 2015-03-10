#ifndef PARSER_H
#define PARSER_H
#include "paraList.h"
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
