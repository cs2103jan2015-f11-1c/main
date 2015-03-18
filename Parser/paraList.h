#ifndef PARALIST_H
#define PARALIST_H

#include <vector>
#include <iostream>
#include <string>
#include "..\Common\Task.h"

using namespace std;

class paraList{

private:
   string _command; 
   int deleteNumber;
   int displayNumber;
   int updateNumber;
   string keyword;
   string input;

public: 
    paraList();
    Task _task;  
	Task getTask();
	string getCommand();
	int getDeleteInteger();
	int getDisplayInteger();
	int getUpdateInteger();
	void displayTaskName(string taskName);
	void processCommand(string inputCommand);
	void processTask(string inputTask);
	void processDeleteNumber(int index);
	void processDisplayNumber(int index);
    void processUpdateNumber(int index);
	void clearAllNumber();
	void processKeyWord(string a);
	void processInput(string b);
	string getKeyword();
	string getInput();

	
};

#endif
