#ifndef PARSER_H
#define PARSER_H

#include<iostream>
#include <string>
#include "paraList.h"


using namespace std;

class Parser{



public:
Parser();
paraList para;
void sortCommand(string &userInput);
void sortDetails(string &userInput);
paraList parseCommand(string userInput);



};

#endif
