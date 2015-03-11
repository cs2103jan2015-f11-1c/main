#include "Storage.h"

//vector<Task*> getTaskList(){
//	return taskList;
//}

void Storage::updateTextFile(){
	ofstream updatedTaskList;
	updatedTaskList.open("Jim's Task List.txt");
	for (int i = 0; i < taskList.size(); i++){
		updatedTaskList << taskList[i]->getTaskDetails() << endl;
	}
	updatedTaskList.close();

	return;
}

void Storage::addTask(Task *individual_task){

	string taskName = individual_task->getTaskName(); 
	string taskStartDate = individual_task->getTaskStartDate();
	string taskStartTime = individual_task->getTaskStartTime();
	string taskEndDate = individual_task->getTaskEndDate();
	string taskEndTime = individual_task->getTaskEndTime();
	string taskDeadlineDate = individual_task->getTaskDeadlineDate();
	string taskDeadlineTime = individual_task->getTaskDeadlineTime();
	string taskPriority = individual_task->getTaskPriority();

	taskList.push_back(individual_task); 

	//vector<Task*>::iterator iter = taskList.end();
	//(**iter).changeTaskName(taskName);
	//string b=(**iter).getTaskName();
	//cout<<b;
	
	taskList[0]->changeTaskName(taskName);
	taskList[0]->changeTaskStartDate(taskStartDate);
	taskList[0]->changeTaskStartTime(taskStartTime);
	taskList[0]->changeTaskEndDate(taskEndDate);
	taskList[0]->changeTaskEndTime(taskEndTime);
	taskList[0]->changeTaskDeadlineDate(taskDeadlineDate);
	taskList[0]->changeTaskDeadlineTime(taskDeadlineTime);
	taskList[0]->changeTaskPriority(taskPriority);

	string taskNameOutput=taskList[0]->getTaskName();
	cout<<taskNameOutput<<endl;
	string taskPriorityOutput=taskList[0]->getTaskPriority();
	cout<<taskPriorityOutput<<endl;

}
