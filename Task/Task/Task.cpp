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