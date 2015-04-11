#include "Task.h"

string Task::MESSAGE_COMPLETE_TASK = "Completed";
string Task::MESSAGE_INCOMPLETE_TASK = "Incomplete";

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

Task::Task (string taskName, string taskStartDate, string taskStartTime, string taskEndDate, string taskEndTime, string taskDeadlineDate, string taskDeadlineTime, string taskPriority, string taskStatus) {
	
	_taskName = taskName;

	_taskStart.date = taskStartDate;
	_taskStart.time = taskStartTime;

	_taskEnd.date = taskEndDate;
	_taskEnd.time = taskEndTime;

	_taskDeadline.date = taskDeadlineDate;
	_taskDeadline.time = taskDeadlineTime;

	_taskPriority = taskPriority;

	if (taskStatus.empty()){
		_taskStatus = MESSAGE_INCOMPLETE_TASK;
	} else {
		_taskStatus = taskStatus;
	}
}

string Task::checkNull(string input){

	if (input.empty()){
		input = "N/A";
		return input;
	} else {
		string space = " ";
		input = input.append(space);
		return input;
	}
}

string Task::getTaskName(){
	if (_taskName == "") {
		_taskName = "NO TASK NAME";
	}
	return _taskName;
}

string Task::getTaskStartDate(){
	if (_taskStart.date == "") {
		_taskStart.date = "NO START DATE";
	}
	return _taskStart.date;
}

string Task::getTaskStartTime(){
	if (_taskStart.time == "") {
		_taskStart.time = "NO START TIME";
	}

	return _taskStart.time;
}

string Task::getTaskEndDate(){
	if (_taskEnd.date == "") {
		_taskEnd.date = "NO END DATE";
	}
	return _taskEnd.date;
}

string Task::getTaskEndTime(){
	if (_taskEnd.time == "") {
		_taskEnd.time = "NO END TIME";
	}
	return _taskEnd.time;
}

string Task::getTaskDeadlineDate(){
	if (_taskDeadline.date == "") {
		_taskDeadline.date == "NO DEADLINE DATE";
	} else if (_taskDeadline.date == "\n") {
		_taskDeadline.date = "newline";
	} else(
		_taskDeadline.date = "something weird");
	return _taskDeadline.date;
}

string Task::getTaskDeadlineTime(){
	if (_taskDeadline.time == "") {
		_taskDeadline.time == "NO DEADLINE TIME";
	}
	return _taskDeadline.time;
}

string Task::getTaskPriority(){
	if (_taskPriority == "") {
		_taskPriority = "N/A";
	}
	return _taskPriority;
}

string Task::getTaskStatus(){
	return _taskStatus;
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

void Task::changeTaskStatus(string newTaskStatus){
	if (newTaskStatus == "mark"){
		_taskStatus = MESSAGE_COMPLETE_TASK;

		return;
	} else {
		_taskStatus = MESSAGE_INCOMPLETE_TASK;
	}

	return;
}