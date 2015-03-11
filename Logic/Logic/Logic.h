#ifndef LOGIC_H
#define LOGIC_H

#include "..\..\UI\UI\UI.h"
#include "..\..\Parser\Parser\Parser.h"
#include "..\..\Storage\Storage\Storage.h"
#include "..\..\Task\Task\Task.h"


#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

class Logic{

private:
	
	string _feedbackMessagetoUI = "Logic functions well.";

	UI UserInterface;
	Parser ParserComponent;

	//Storage DataBase;
	//vector<Task*> CopyTaskList;
	string userInput;

public:

	void Welcome();
	string getUserInput();
	string ParseUserInput(string);
	string getCommand(paraList);
	Task getTask(paraList);

	void executeCommand(string);
	void displayFeedback(string);


};
#endif
