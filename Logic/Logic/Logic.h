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

	Storage DataBase;
	//vector<Task*> CopyTaskList;
	string userInput;

public:
	void Welcome();
	void CommandPrompt();
	paraList* getParaList(string);
	void writeFile(vector<string>, string);
	string getUserInput();
	string getCommand(paraList);
	Task getTask(paraList);
	vector<string> getTextFileCopy();

	void callInitialise(string);
	void executeCommand(paraList, string);
	void displayFeedback(string);

};
#endif
