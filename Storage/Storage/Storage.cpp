#include "Storage.h"

//string taskName, taskStartDate, taskStartTime, taskEndDate, taskEndTime, taskDeadlineDate, taskDeadlineTime, taskPriority;

//vector<Task*> getTaskList(){
//	return taskList;
//}

void Storage::addTask(Task *individual_task){
//Task *individualTask = new Task(taskName,taskStartDate,taskStartTime,taskEndDate,taskEndTime,taskDeadlineDate,taskDeadlineTime,taskPriority);
	//individual_task->changeTaskName(individual_task->_taskName);
	taskList.push_back(individual_task); 
	vector<Task*>::iterator iter = taskList.end();
	//taskList[0]->changeTaskName(individual_task->_taskName);
	(**iter).changeTaskName(individual_task->_taskName);
}
