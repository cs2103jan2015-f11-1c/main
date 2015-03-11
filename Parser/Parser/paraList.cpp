#include "paraList.h"
#include "Parser.h"


Task paraList::getTask()
{ return _task;
}

string paraList::getCommand()
{ return _command;
}

string paraList::displayCommand()
{
	cout<<_command;
	return;

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