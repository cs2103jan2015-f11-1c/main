#ifndef PARALIST_H
#define PARALIST_H
#include <vector>
#include <string>
#include "..\..\Task\Task\Task.h"

using namespace std;

class paraList{

private:
   string _command; 
   Task _task; 

public:
	Task getTask();
	string getCommand();
	void displayCommand();
	void displayTaskName(string taskName);
	void processCommand(string& inputCommand);
	void processTask(string& inputTask);


};

#endif
