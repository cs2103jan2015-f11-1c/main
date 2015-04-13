// @author A0113555L
#ifndef LOGIC_H
#define LOGIC_H

//#define NDEBUG

#include "..\UI\UI.h"
#include "..\Parser\Parser.h"
#include "..\Storage\Storage.h"
#include "..\Common\Task.h"
#include "..\TaskSotong_Log\Log.h"

#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <fstream>
#include <cctype>
#include <algorithm>
#include <assert.h>

using namespace std;

class Logic {

private:

	UI _UserInterface;
	Parser _ParserComponent;
	Storage _DataBase;

	vector<string> _fileLocation;
	vector<Task> _resultVector;
	vector<Task> _storageTaskListCopy;

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
	static string ERROR_EMPTY_LIST;
	static string ERROR_TASK_INSUFFICIENT_PARAMETERS;
	static string ERROR_NO_INDEX;
	static string ERROR_INDEX_OUT_OF_RANGE;
	static string ERROR_NO_COMPONENT;
	static string ERROR_COMPONENT_INVALID;
	static string ERROR_NO_CONTENT;
	static string ERROR_INVALID_CONTENT;
	static string ERROR_INVALID_YEAR;
	static string ERROR_INVALID_MONTH;
	static string ERROR_INVALID_DAY;
	static string ERROR_INVALID_HOUR;
	static string ERROR_INVALID_MINUTE;
	static string ERROR_START_TIME_AFTER_END_TIME;
	static string ERROR_START_DATE_AFTER_END_DATE; 

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
	static string FEEDBACK_VIEW_ALL_SUCCESSFULLY;

	Log _Logic_LogFile;

public:

	string checkTimeValidity(string);

	string checkDateValidity(string);

	string checkTaskDatenTimeValidity(Task);

	string convertYearToCorrectForm(string);

	string convertTimeToCorrectForm(string);

	string compareTaskDateandTime(Task);

	void setTaskList();

	vector<Task> getTaskList();

	void setCompletedTaskList();

	vector<Task> getCompletedTaskList();

	void setIncompleteTaskList();

	vector<Task> getIncompleteTaskList();

	void initialiseSetUp();

	void initialiseFileLocationFile();

	void writeFileLocation(vector<string>);

	bool checkIfFileIsAtExeLocation();

	string getLastFileLocation();

	void updatefileLocation(string);

	string getExePath();

	void createNewDirectory(string);

	void changeFileDirectory(string);

	void setFileName(string);

	string getFileName();

	paraList* getParaList(string);

	string getLowerCaseCommand(paraList);

	Task getTask(paraList);

	vector<string> getTextFileCopy();

	void callInitialise(string);

	bool ExistingTask(Task);

	string getFeedbackMsg();

	string executeCommand(paraList);

};
#endif
