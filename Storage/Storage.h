#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
#include <functional>
#include "..\Common\Task.h"

using namespace std;

bool caseInsensitiveEqual(char, char);
bool noCaseLess(const string &a, const string &b);

class Storage{

private:

	vector<Task*> taskList;
	vector<string> textFileCopy;
	stack<string> commandStack;
	stack<string> deleteTaskDetailsStack;
	stack<int> deleteTaskIndexStack;
	stack<int> markTaskIndexStack;
	stack<int> unmarkTaskIndexStack;
	stack<string> clearAllTasksStack;
	stack<vector<string>> sortByNameStack;
	stack<vector<string>> sortByStatusBeforeStack;
	stack<vector<string>> sortByStatusAfterStack;
	stack<vector<string>> sortByPriorityBeforeStack;
	stack<vector<string>> sortByPriorityAfterStack;

	static string ERROR_EMPTY_LIST;
	static string ERROR_INVALID_NUMBER;
	static string ERROR_NO_COMPLETED_TASKS;
	static string ERROR_NO_INCOMPLETE_TASKS;
	static string ERROR_TASK_PREVIOUSLY_COMPLETED;
	static string ERROR_TASK_PREVIOUSLY_INCOMPLETE;
	static string ERROR_CANNOT_UNDO;
	static string ERROR_INVALID_SEARCH_TERM;
	static string ERROR_ONLY_ONE_TASK;
	static string ERROR_INVALID_NAME_SORT;
	static string ERROR_INVALID_STATUS_SORT;
	static string ERROR_INVALID_PRIORITY_SORT;

	bool isEmptyTextFile();
	bool isInvalidIndex(unsigned int);
	void performSearchForViewingTasks(string, int&);
	bool isOnlyOneTask();
	bool isSortedByName(vector<string>);
	bool isSortedByStatus();
	bool isSortedByPriority();
	void performSort(queue<string>&, string);

public:

	enum updateKeyword { INVALID_KEYWORD, NAME, START_DATE, START_TIME, END_DATE_END_TIME, DEADLINE_DATE, DEADLINE_TIME, PRIORITY };

	void updateTextFile(string);

	void initialiseTextFile(string);

	vector<string> returnTextFileCopy();

	void addTask(Task*);

	void deleteTask(string, unsigned int);

	void displayAllTasks();

	void viewCompletedTasks();

	void viewIncompleteTasks();

	updateKeyword getUpdateKeyword(string);

	void updateTask(string, unsigned int, Task*, string, string);

	void markTask(string, unsigned int);

	void unmarkTask(string, unsigned int);

	void undoAction();

	void clearAllTasks();

	void searchTask(string, const string&);

	void sortTaskByName(string);

	void sortTaskByStatus(string);

	void sortTaskByPriority(string);

};

#endif