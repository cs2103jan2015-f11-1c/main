#ifndef LOGIC_H
#define LOGIC_H

#include "..\..\Storage\Storage\Storage.h"
#include "..\..\Storage\Storage\Storage.cpp"
#include "..\..\UI\UI\UI.h"
#include "..\..\UI\UI\UI.cpp"
#include "..\..\Parser\Parser\Parser.h"
#include "..\..\Parser\Parser\Parser.cpp" 
/*#include "..\..\Task\Task\Task.h"
#include "..\..\Task\Task\Task.cpp"
*/

#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <fstream>

using namespace std;

class Logic{

private:
	UI UserInterface;
	Parser ParserComponent;
	Storage DataBase;
	vector<Task*> CopyTaskList;
	string userInput;

public:

	string getUserInput();
	paraList ParseUserInput(string);
	void executeCommand(Storage, paraList);
	void displayFeedback(UI, string);
	void Welcome();


};
#endif
