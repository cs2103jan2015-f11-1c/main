#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <iomanip>

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
	Task(string,string,string,string,string,string,string,string,string);


	string getTaskDetails(){

		string taskName = checkNull(_taskName);
		string date1 = checkNull(_taskStart.date);
		string time1 = checkNull(_taskStart.time);
		string date2 = checkNull(_taskEnd.date);
		string time2 = checkNull(_taskEnd.time);
		string date3 = checkNull(_taskDeadline.date);
		string time3 = checkNull(_taskDeadline.time);
		string priority = checkNull(_taskPriority);
		string status = _taskStatus;
//to be updated 


		ostringstream oss;
		oss << setw(15) << right << taskName
		<<setw(7)<< left << date1
			<< setw(5)<< left << time1
			<< setw(7)<< left << date2
			<< setw(5)<< left << time2
			<< setw(7)<< left << date3
			<< setw(5)<< left << time3
			<< setw(4)<< left << priority
			<< setw(5)<<left<<status;

		return oss.str();		
	}

	string checkNull(string);

	string getTaskName(); 

	string getTaskStartDate();
	string getTaskStartTime();

	string getTaskEndDate();
	string getTaskEndTime();

	string getTaskDeadlineDate();
	string getTaskDeadlineTime();

	string getTaskPriority();
	string getTaskStatus();

	void changeTaskName(string);

	void changeTaskStartDate(string);
	void changeTaskStartTime(string);

	void changeTaskEndDate(string);
	void changeTaskEndTime(string);

	void changeTaskDeadlineDate(string);
	void changeTaskDeadlineTime(string);

	void changeTaskPriority(string);

	void changeTaskStatus(string);
};

#endif