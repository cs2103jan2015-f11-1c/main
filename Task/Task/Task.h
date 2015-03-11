#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;



class Task{

private:

	struct Timeframe{
		string date;
		string time;
	};

	static string MESSAGE_COMPLETE_TASK;
	static string MESSAGE_INCOMPLETE_TASK;

	//static string _taskName;
	Timeframe _taskStart;
	Timeframe _taskEnd;
	Timeframe _taskDeadline;
	string _taskPriority;
	string _taskStatus;


public:
	Task();
	Task(string,string,string,string,string,string,string,string);

	string _taskName;

	void changeTaskName(string);

	void changeTaskStartDate(string);
	void changeTaskStartTime(string);

	void changeTaskEndDate(string);
	void changeTaskEndTime(string);

	void changeTaskDeadlineDate(string);
	void changeTaskDeadlineTime(string);

	void changeTaskPriority(string);

	void changeTaskStatus();
};

#endif