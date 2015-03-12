#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include "..\..\Task\Task\Task.h"

using namespace std;

class Storage{

private:
	vector<Task*> taskList;

public:
	//vector<Task*> getTaskList();
	
	void updateTextFile(string);

	void addTask(Task*, string);

	void deleteTask(unsigned int);

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