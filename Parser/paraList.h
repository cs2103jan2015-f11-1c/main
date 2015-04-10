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
   int markIndex;
   string keyword;
   string input;
   string markStatus;
   string userDir;
   string searchKeyword;
  


public: 
    paraList();
	//for unit testing purpose.
	void setparaList(string, int, int, int, string, string, Task);
    Task _task;  
	Task getTask();
	string getCommand();
	int getDeleteInteger();
	int getDisplayInteger();
	int getUpdateInteger();
	string getuserdir();
	string getmarkstatus();
	int getmarkindex();
	string getSearchKey();



	//what's the use of this ah? -GT
	void displayTaskName(string taskName);
	void processCommand(string inputCommand);

	//what's the use of this ah? -GT
	void processTask(string inputTask);
	void processDeleteNumber(int index);
	void processDisplayNumber(int index);
    void processUpdateNumber(int index);
	void clearAllNumber();
	void processKeyWord(string a);
	void processInput(string b);
	string getKeyword();
	string getInput();
	void clearTask();
	void processMarkIndex(int);
	void processMarkStatus(string);
	void processUserDir(string);
	void processSearchWord(string);

	
};

#endif
