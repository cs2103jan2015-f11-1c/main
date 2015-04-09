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

	UI _UserInterface;
	Parser _ParserComponent;
	Storage _DataBase;

	vector<string> _storageTextFileCopy;
	vector<string> _fileLocation;
	vector<string> _resultVector;


	string _userInput;
	string _filename;
	string _feedbackMessage;

	static string SAVING_LOCATON_HISTORY;

	static string ERROR_INVALID_USERINPUT;
	static string ERROR_EXISTING_TASK;
	static string ERROR_TASK_UPDATED_UNSUCCESSFULLY;
	static string ERROR_TASK_DELETED_UNSUCCESSFULLY;
	static string ERROR_TASK_MARKED_UNSUCCESSFULLY;
	static string ERROR_TASK_UNMARKED_UNSUCCESSFULLY;

	static string FEEDBACK_TASK_ADDED_SUCCESSFULLY;
	static string FEEDBACK_DISPLAY_ALL_TASKS;
	static string FEEDBACK_TASK_UPDATED_SUCCESSFULLY;
	static string FEEDBACK_TASK_DELETED_SUCCESSFULLY;
	static string FEEDBACK_SAVING_FILE_DIRECTORY_CHANGED;
	static string FEEDBACK_TASK_MARKED_SUCCESSFULLY;
	static string FEEDBACK_TASK_UNMARKED_SUCCESSFULLY;
	static string FEEDBACK_CLEAR_ALL_TASKS;
	static string FEEDBACK_UNDO_PREVIOUS_TASK;
	static string FEEDBACK_SEARCH_TASK_BY_KEYWORD;
	static string FEEDBACK_SORT_TASK_BY_KEYWORD;


public:

	void initialiseSetUp();

	void initialiseFileLocationFile();

	void writeFileLocation(vector<string>);

	bool checkIfFileIsAtExeLocation();

	string getLastFileLocation();

	void updatefileLocation(string);

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
	
	void setReturnGUI(vector<string>);

	vector<string> getReturnGUI();

	string executeCommand(paraList);

	

};
#endif
