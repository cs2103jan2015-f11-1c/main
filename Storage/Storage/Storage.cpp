#include "Storage.h"

/*
vector<Task*> getTaskList(){
	return taskList;
}
*/

void Storage::updateTextFile(string outputFile){
	ofstream updatedTaskList;
	updatedTaskList.open(outputFile);
	for (unsigned int i = 0; i < taskList.size(); i++){
		updatedTaskList << i+1 <<". "<< taskList[i]->getTaskDetails() << endl;
	}
	updatedTaskList.close();

	return;
}

void Storage::addTask(Task *individual_task, string outputFile){

	/*string taskName = individual_task->getTaskName(); 
	string taskStartDate = individual_task->getTaskStartDate();
	string taskStartTime = individual_task->getTaskStartTime();
	string taskEndDate = individual_task->getTaskEndDate();
	string taskEndTime = individual_task->getTaskEndTime();
	string taskDeadlineDate = individual_task->getTaskDeadlineDate();
	string taskDeadlineTime = individual_task->getTaskDeadlineTime();
	string taskPriority = individual_task->getTaskPriority();
	*/
	taskList.push_back(individual_task); 

	//vector<Task*>::iterator iter = taskList.end();
	//(**iter).changeTaskName(taskName);
	//string b=(**iter).getTaskName();
	//cout<<b;
	/*
	taskList.back()->changeTaskName(taskName);
	taskList.back()->changeTaskStartDate(taskStartDate);
	taskList.back()->changeTaskStartTime(taskStartTime);
	taskList.back()->changeTaskEndDate(taskEndDate);
	taskList.back()->changeTaskEndTime(taskEndTime);
	taskList.back()->changeTaskDeadlineDate(taskDeadlineDate);
	taskList.back()->changeTaskDeadlineTime(taskDeadlineTime);
	taskList.back()->changeTaskPriority(taskPriority);
	*/
	/*
	taskList[0]->changeTaskName(taskName);
	taskList[0]->changeTaskStartDate(taskStartDate);
	taskList[0]->changeTaskStartTime(taskStartTime);
	taskList[0]->changeTaskEndDate(taskEndDate);
	taskList[0]->changeTaskEndTime(taskEndTime);
	taskList[0]->changeTaskDeadlineDate(taskDeadlineDate);
	taskList[0]->changeTaskDeadlineTime(taskDeadlineTime);
	taskList[0]->changeTaskPriority(taskPriority);
	*/

	updateTextFile(outputFile);
	return;
}

void Storage::deleteTask(unsigned int taskIndex){
	if(taskIndex < 1 || taskIndex > taskList.size()){
		cout << "Invalid Number" << endl;
	} else {
		taskList.erase(taskList.begin() + taskIndex - 1);
	}

	return;
}

void Storage::displayAllTasks(){
	if (taskList.empty()){
		cout <<"Task list is empty"<< endl;

		return;
	} else {
		vector<Task*>::iterator iter;
		for (iter = taskList.begin(); iter != taskList.end(); iter++){
			cout << (**iter).getTaskDetails() << endl;
		}
	}
	return;
}

void Storage::displaySpecificTask(unsigned int taskIndex){
	vector<Task*>::iterator iter = taskList.begin();
	vector<Task*>::iterator iterEnd = taskList.end();

	if (taskIndex > iterEnd - iter){
		cout <<"Invalid index"<< endl;

		return;
	} else {
		iter = iter + taskIndex - 1;
		cout << (**iter).getTaskDetails() << endl;
	}

	return;
}