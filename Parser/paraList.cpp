//@author A0111642W
#include "paraList.h"
#include <assert.h>
#include <iostream>
using namespace std;

paraList::paraList()
{}

void paraList::setparaList(string command1, int deleteNumber1, int displayNumber1, int updateNumber1, string keyword1, string input1, Task task1){
	_command = command1;
	deleteNumber = deleteNumber1;
	displayNumber = displayNumber1;
	updateNumber = updateNumber1;
	keyword = keyword1;
	input = input1;
	_task = task1;


	return;
}

Task paraList::getTask()
{
	return _task;
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
{
	return _command;
}


void paraList::processCommand(string inputCommand)
{
	_command = inputCommand;
	return;
}

void paraList::processTask(string inputTask)
{
	return;
}
void paraList::processDeleteNumber(int index)
{
	try
	{
		deleteNumber = index;
		if (deleteNumber < 0)
		{
			throw;
		}

	}
	catch (...)
	{

		cout << "Exceptation Case:Delete Number <0";


	}





	
}

void paraList::processDisplayNumber(int index)
{
	


	try
	{
		displayNumber = index;
		if (displayNumber < 0)
		{
			throw;
		}

	}
	catch (...)
	{

		cout << "Exceptation Case:Display Number <0";


	}


}

void paraList::processUpdateNumber(int index)
{

	try
	{
		updateNumber = index;
		if (updateNumber < 0)
		{
			throw;
		}

	}
	catch (...)
	{

		cout << "Exceptation Case:update Number <0";


	}







	
}

void paraList::clearAllNumber()
{
	deleteNumber = NULL;
	displayNumber = NULL;
	updateNumber = NULL;
}

void paraList::processKeyWord(string a)
{
	keyword = a;
	return;
}

void paraList::processInput(string b)
{
	input = b;
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

//changes all task parameters to empty string
void paraList::clearTask()
{
	_task.changeTaskDeadlineDate("");
	_task.changeTaskDeadlineTime("");
	_task.changeTaskEndDate("");
	_task.changeTaskEndTime("");
	_task.changeTaskStartDate("");
	_task.changeTaskStartTime("");
	_task.changeTaskName("");
	_task.changeTaskPriority("");
	_task.changeTaskStatus("");
	return;
}

void paraList::processMarkIndex(int index)
{

	try
	{
	
	markIndex = index;
	if (markIndex < 0)
	{
		throw;
	}
	
	}
	catch (...)
	{

		cout << "Exceptation Case:Mark index<0";


	}
	
	


	return;
}


void paraList::processMarkStatus(string keyword)
{

	markStatus = keyword;


	return;
}

void paraList::processUserDir(string directory)
{

	userDir = directory;

	return;
}

void paraList::processSearchWord(string keyWord)
{
	//assert(keyWord != "");
	searchKeyword = keyWord;

	return;
}


string paraList::getuserdir()
{
	return userDir;

}

string  paraList::getmarkstatus()
{
	
	return markStatus;

}

int paraList::getmarkindex()
{

	return markIndex;
}

string paraList::getSearchKey()
{
	return searchKeyword;
}


void paraList::processViewInc()
{

	viewIncompleted = true;

}
void paraList::processViewComp()
{
	viewCompleted = true;

}
bool paraList::getprocessViewInc()
{
	return viewIncompleted;

}
bool paraList::getprocessViewComp()
{
	return viewCompleted;


}