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
	static string MESSAGE_COMPLETE_TASK;
	static string MESSAGE_INCOMPLETE_TASK;

	//static string _taskName;
	static Timeframe _taskStart;
	static Timeframe _taskEnd;
	static Timeframe _taskDeadline;
	static string _taskPriority;
	static string _taskStatus;


public:
	Task();
	Task(string,string,string,string,string,string,string,string);

	struct Timeframe{
		string date;
		string time;
	};

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