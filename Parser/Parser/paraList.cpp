#include "paraList.h"
#include <iostream>
using namespace std;


Task paraList::getTask()
{ return _task;
}

string paraList::getCommand()
{ return _command;
}


void paraList::displayTaskName(string taskName)
{
	cout<<taskName<<endl;
	return;
}

void paraList::processCommand(string inputCommand)
{
	_command=inputCommand;
}

void paraList::processTask(string inputTask)
{
	return;
}