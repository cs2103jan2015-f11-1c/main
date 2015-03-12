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

	taskList.push_back(individual_task); 
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