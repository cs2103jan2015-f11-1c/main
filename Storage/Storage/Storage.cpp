#include "Storage.h"

string taskName, taskStartDate, taskStartTime, taskEndDate, taskEndTime, taskDeadlineDate, taskDeadlineTime, taskPriority;

//vector<Task*> getTaskList(){
//	return taskList;
//}

void Storage::addTask(Task *individual_task){
//Task *individualTask = new Task(taskName,taskStartDate,taskStartTime,taskEndDate,taskEndTime,taskDeadlineDate,taskDeadlineTime,taskPriority);          
	individual_task->changeTaskName("me");
	taskList.push_back(individual_task); 
	taskList[0]->changeTaskName("meee");
}
