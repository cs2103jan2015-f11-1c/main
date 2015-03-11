#ifndef PARALIST_H
#define PARALIST_H
#include <vector>
#include <string>
#include "..\..\Task\Task\Task.h"
#include "..\..\Task\Task\Task.cpp"

using namespace std;

class paraList{

private:
 
public: 
	string _command; 
    Task _task; 

	Task getTask();
	string getCommand();
	string displayCommand();
	void displayTaskName(string taskName);
	void processCommand(string inputCommand);
	void processTask(string inputTask);


};

#endif
