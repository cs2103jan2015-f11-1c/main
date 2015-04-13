//@author A0111642W
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
	string keyword;
	string input;
	string markStatus;
	string userDir;
	string searchKeyword;
	bool viewIncompleted;
	bool viewCompleted;
    int deleteNumber;
	int displayNumber;
	int updateNumber;
	int markIndex;


public:
	paraList();
	//for unit testing purpose.

	Task _task;
	Task getTask();
	string getKeyword();
	string getInput();
	string getCommand();
	string getSearchKey();
	string getuserdir();
	string getmarkstatus();
	int getDeleteInteger();
	int getDisplayInteger();
	int getUpdateInteger();
	int getmarkindex();
	void setparaList(string, int, int, int, string, string, Task);
	void displayTaskName(string taskName);
	void processCommand(string inputCommand);
	void processTask(string inputTask);
	void processDeleteNumber(int index);
	void processDisplayNumber(int index);
	void processUpdateNumber(int index);
	void processKeyWord(string a);
	void processInput(string b);
	void processMarkIndex(int);
	void processMarkStatus(string);
	void processUserDir(string);
	void processSearchWord(string);
	void processViewInc();
	void processViewComp();
	void clearAllNumber();
	void clearTask();
	bool getprocessViewInc();
	bool getprocessViewComp();

};

#endif
