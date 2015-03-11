#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include "..\..\Task\Task\Task.cpp"

using namespace std;

class Storage{

private:
	vector<Task*> taskList;

public:
	void addTask(Task*);

	//vector<Task*> getTaskList();

	void setTaskName(string);

	void setTaskStartDate(string);
	void setTaskStartTime(string);

	void setTaskEndDate(string);
	void setTaskEndTime(string);

	void setTaskDeadlineDate(string);
	void setTaskDeadlineTime(string);

	void setTaskPriority(string);

	void changeTaskStatus();

};

#endif