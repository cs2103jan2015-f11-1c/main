#include "paraList.h"
#include <iostream>
using namespace std;

paraList::paraList()
{}


Task paraList::getTask()
{ return _task;
}

int paraList::getDeleteInteger()
{
	return deleteNumber;
}
int paraList::getDisplayInteger()
{
	return displayNumber;
}
int paraList::getUpdateInteger()
{
	return updateNumber;
}


string paraList::getCommand()
{ return _command;
}


void paraList::processCommand(string inputCommand)
{
	_command=inputCommand;
	return;
}

void paraList::processTask(string inputTask)
{
	return;
}
void paraList::processDeleteNumber(int index)
{
	deleteNumber=index;
}

void paraList::processDisplayNumber(int index)
{
	displayNumber=index;
}

void paraList::processUpdateNumber(int index)
{
	updateNumber=index;
}

void paraList::clearAllNumber()
{
	deleteNumber=NULL;
    displayNumber=NULL;
	updateNumber=NULL;
}

void paraList::processKeyWord(string a)
{
	keyword=a;
	return;
}

void paraList::processInput(string b)
{
	input=b;
	return;
}

string paraList::getKeyword()
{
	return keyword;
}

string paraList::getInput()
{
	return input;

}
