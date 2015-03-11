#ifndef PARALIST_H
#define PARALIST_H

#include "..\..\Task\Task\Task.h"

#include <vector>
#include <iostream>
#include <string>


using namespace std;

class paraList{

private:
    
   
public: 
    paraList();
    string _command; 
	Task* _task;  
	Task* getTask();
	string getCommand();
	void displayTaskName(string taskName);
	void processCommand(string inputCommand);
	void processTask(string inputTask);

	
};

#endif
