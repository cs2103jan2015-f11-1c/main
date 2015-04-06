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
	string _filename;
	string feedbackMessage;

	static string Error_invalidUserInput;
	static string FeedBack_taskAdded;
	static string FeedBack_existingTask;
	static string FeedBack_displayAllTasks;
	static string FeedBack_updateTaskSuccessfully;
	static string FeedBack_updateTaskUnsuccessfully;
	static string FeedBack_deleteTaskSuccessfully;
	static string FeedBack_deleteTaskUnsuccessfully;
	static string FeedBack_changeFileDirectory;
	static string FeedBack_MarkTaskSuccessfully;
	static string FeedBack_UnmarkTask;
	static string FeedBack_ClearTask;
	static string FeedBack_UndoTask;
	static string FeedBack_SearchTask;
	static string FeedBack_SortTasks;


public:

	void Welcome();

	void CommandPrompt();

	string getExePath();

	void createNewDirectory(string);

	void changeFileDirectory(string);

	void processChangeDirectoryRequest(string);
	
	void setFileName(string);

	string getFileName();

	paraList* getParaList(string);

	string getUserInput();

	string getLowerCaseCommand(paraList);

	Task getTask(paraList);

	void copyTestFilefromStorage();

	vector<string> getTextFileCopy();

	void callInitialise(string);

	bool notExistingTask(Task*);

	string getFeedbackMsg();

	void executeCommand(paraList);

	

};
#endif
