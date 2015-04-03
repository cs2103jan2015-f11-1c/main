#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <stack>
#include <cctype>
#include <functional>
#include "..\Common\Task.h"

using namespace std;

class Storage{

private:

	vector<Task*> taskList;
	vector<string> textFileCopy;
	stack<string> commandStack;
	stack<string> deleteTaskDetailsStack;
	stack<int> deleteTaskIndexStack;
	stack<int> markTaskIndexStack;

	static string ERROR_EMPTY_LIST;
	static string ERROR_INVALID_NUMBER;
	static string ERROR_TASK_PREVIOUSLY_COMPLETED;
	static string ERROR_TASK_PREVIOUSLY_INCOMPLETE;
	static string ERROR_CANNOT_UNDO;

	bool isEmptyTextFile();
	bool isInvalidIndex(unsigned int);

public:

	void updateTextFile(string);

	void initialiseTextFile(string);

	vector<string> returnTextFileCopy();

	void addTask(Task*);

	void deleteTask(string, unsigned int);

	void displayAllTasks();

	void updateTask(unsigned int, string, string);

	void markTask(string, unsigned int);

	void unmarkTask(string, unsigned int);

	void undoAction();

	void clearAllTasks();

	void searchTask(string, const string&);

	void sortTaskByName(string);

};

#endif