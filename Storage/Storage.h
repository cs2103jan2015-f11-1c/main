#ifndef STORAGE_H
#define STORAGE_H

//#define NDEBUG

#include <iostream>
#include <utility>
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
#include <assert.h>
#include "..\Common\Task.h"
#include "..\TaskSotong_Log\Log.h"

using namespace std;

bool caseInsensitiveEqual(char, char);
bool noCaseLess(const string &a, const string &b);

class Storage{

private:

	vector<Task> taskList;
	vector<string> taskListStringVector;
	vector<Task> completedTaskList;
	vector<Task> incompleteTaskList;
	stack<string> commandStack;
	stack<pair<Task, unsigned int>> deleteTaskStack;
	stack<pair<Task, unsigned int>> updateTaskStack;
	stack<int> markTaskIndexStack;
	stack<int> unmarkTaskIndexStack;
	stack<vector<Task>> clearAllTasksStack;
	stack<vector<Task>> sortByNameStack;

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
	static string ERROR_INVALID_UPDATE_KEYWORD;
	static string ERROR_INVALID_UPDATE_PRIORITY_KEYWORD;
	static string FEEDBACK_MESSAGE_UPDATED_SUCCESSFULLY;
	static string FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY;
	static string FEEDBACK_MESSAGE_VIEW_COMPLETED_SUCCESSFULLY;
	static string FEEDBACK_MESSAGE_VIEW_INCOMPLETE_SUCCESSFULLY;

	string feedbackMessage;

	vector<Task> performSearchForViewingTasks(string);
	bool isOnlyOneTask();
	bool isSortedByName(vector<Task>);

	Log _Storage_LogFile;

public:

	vector<Task> returnTaskList();

	vector<Task> returnCompletedTaskList();

	vector<Task> returnIncompleteTaskList();

	void toString();

	void toTaskList();

	void updateTaskList(Task);

	void updateTextFile(string);

	void initialiseTextFile(string);

	void addTask(Task);

	void deleteTask(string, unsigned int);

	vector<Task> viewCompletedTasks();

	vector<Task> viewIncompleteTasks();

	void setFeedbackMessage(string);

	string returnLogicFeedbackMessage();

	void updateTask(string, unsigned int, string, string);

	void markTask(string, unsigned int);

	void unmarkTask(string, unsigned int);

	void undoAction();

	void clearAllTasks();

	vector<string> searchTask(string, const string&);

	vector<Task> sortTaskByName(string);

};

#endif