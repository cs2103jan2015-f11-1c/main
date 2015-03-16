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
	vector<string> textFileCopy;

public:
	
	void updateTextFile(string);

	void initialiseTextFile(string);

	vector<string> returnTextFileCopy();

	void addTask(Task*, string);

	void addTask(Task*);

	void deleteTask(unsigned int);

	void displayAllTasks();

	void displaySpecificTask(unsigned int);

	void updateTask(unsigned int, string, string);

	void markTask(unsigned int, string);

};

#endif