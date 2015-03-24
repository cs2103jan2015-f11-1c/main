#ifndef LOGIC_H
#define LOGIC_H

#include "..\UI\UI.h"
#include "..\Parser\Parser.h"
#include "..\Storage\Storage.h"
#include "..\Common\Task.h"


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
	
	UI UserInterface;

	Parser ParserComponent;

	Storage DataBase;

	vector<string> textFileCopy_fromStorage;
	
	string userInput;

public:

	void Welcome();

	void CommandPrompt();

	string getExePath();
	
	paraList* getParaList(string);
	
	//void writeFile(vector<string>, string);
	
	string getUserInput();
	
	string getCommand(paraList);
	
	Task getTask(paraList);
	
	void copyTestFilefromStorage();

	vector<string> getTextFileCopy();

	void callInitialise(string);

	bool notExistingTask(Task*);
	
	void executeCommand(paraList, string);
	
	void displayFeedback(string);

};
#endif
