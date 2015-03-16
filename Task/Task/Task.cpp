#include "Task.h"

string Task::MESSAGE_COMPLETE_TASK = "Incomplete";
string Task::MESSAGE_INCOMPLETE_TASK = "Complete";

Task::Task () {
	
	_taskName = "";

	_taskStart.date = "";
	_taskStart.time = "";

	_taskEnd.date = "";
	_taskEnd.time = "";

	_taskDeadline.date = "";
	_taskDeadline.time = "";

	_taskPriority = "";

	_taskStatus = MESSAGE_INCOMPLETE_TASK;
}

Task::Task (string taskName, string taskStartDate, string taskStartTime, string taskEndDate, string taskEndTime, string taskDeadlineDate, string taskDeadlineTime, string taskPriority) {
	
	_taskName = taskName;

	_taskStart.date = taskStartDate;
	_taskStart.time = taskStartTime;

	_taskEnd.date = taskEndDate;
	_taskEnd.time = taskEndTime;

	_taskDeadline.date = taskDeadlineDate;
	_taskDeadline.time = taskDeadlineTime;

	_taskPriority = taskPriority;

	_taskStatus = MESSAGE_INCOMPLETE_TASK;
}

string Task::getTaskName(){
	return _taskName;
}

string Task::getTaskStartDate(){
	return _taskStart.date;
}

string Task::getTaskStartTime(){
	return _taskStart.time;
}

string Task::getTaskEndDate(){
	return _taskEnd.date;
}

string Task::getTaskEndTime(){
	return _taskEnd.time;
}

string Task::getTaskDeadlineDate(){
	return _taskDeadline.date;
}

string Task::getTaskDeadlineTime(){
	return _taskDeadline.time;
}

string Task::getTaskPriority(){
	return _taskPriority;
}

void Task::changeTaskName(string newTaskName){
	_taskName = newTaskName;
	return;
}

void Task::changeTaskStartDate(string newStartDate){
	_taskStart.date = newStartDate;
	return;
}

void Task::changeTaskStartTime(string newStartTime){
	_taskStart.time = newStartTime;
	return;
}

void Task::changeTaskEndDate(string newEndDate){
	_taskEnd.date = newEndDate;
	return;
}

void Task::changeTaskEndTime(string newEndTime){
	_taskEnd.time = newEndTime;
	return;
}

void Task::changeTaskDeadlineDate(string newDeadlineDate){
	_taskDeadline.date = newDeadlineDate;
	return;
}

void Task::changeTaskDeadlineTime(string newDeadlineTime){
	_taskDeadline.time = newDeadlineTime;
	return;
}

void Task::changeTaskPriority(string newTaskPriority){
	_taskPriority = newTaskPriority;
	return;
}

/*
void Task::changeTaskStatus(){
	if (mark == true){
		_taskStatus = MESSAGE_COMPLETE_TASK;
	} else {
		_taskStatus = MESSAGE_INCOMPLETE_TASK;
	}
}
*/