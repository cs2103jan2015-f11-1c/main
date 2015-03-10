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

	struct Timeframe{
		string date;
		string time;
	};

	static string _taskName;
	static Timeframe _taskStart;
	static Timeframe _taskEnd;
	static Timeframe _taskDeadline;
	static string _taskPriority;
	static string _taskStatus;


public:
	Task();
	Task(string,string,string,string,string,string,string,string);
	void changeDate();
	void changeTime();
	void changeTaskName();
	void changeTaskStatus();
};

#endif