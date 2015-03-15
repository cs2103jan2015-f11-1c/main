#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

struct Timeframe{
	string date;
	string time;
};

class Task{

private:
	static string MESSAGE_COMPLETE_TASK;
	static string MESSAGE_INCOMPLETE_TASK;

	string _taskName;
	Timeframe _taskStart;
	Timeframe _taskEnd;
	Timeframe _taskDeadline;
	string _taskPriority;
	string _taskStatus;

public:
	Task();
	Task(string,string,string,string,string,string,string,string);

	string getTaskDetails(){
	
		ostringstream oss;
		oss << _taskName << " "
			<< _taskStart.date << " "
			<< _taskStart.time << " "
			<< _taskEnd.date << " "
			<< _taskEnd.time << " "
			<< _taskDeadline.date << " "
			<< _taskDeadline.time << " "
			<< _taskPriority << " " << endl;
			//<< _taskStatus << endl;

		return oss.str();		
	}

	string getTaskName(); 

	string getTaskStartDate();
	string getTaskStartTime();

	string getTaskEndDate();
	string getTaskEndTime();

	string getTaskDeadlineDate();
	string getTaskDeadlineTime();

	string getTaskPriority();

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