#include "Storage.h"


void Storage::updateTextFile(string outputFile){
	ofstream updatedTaskList;
	updatedTaskList.open(outputFile);
	for (unsigned int i = 0; i < textFileCopy.size(); i++){
		updatedTaskList << i+1 <<". "<< textFileCopy[i] << endl;
	}
	updatedTaskList.close();

	return;
}

void Storage::initializeVector2(string outputFile){
	ifstream readFile(outputFile);
	string tempStorage;
	while (getline(readFile, tempStorage)){
		textFileCopy.push_back(tempStorage);
	}
	readFile.close();
};

void Storage::addTask(Task *individual_task, string outputFile){
	taskList.push_back(individual_task); 
	textFileCopy.push_back(individual_task->getTaskDetails());

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
		unsigned int i;
		vector<Task*>::iterator iter;
		for (iter = taskList.begin(), i=1; iter != taskList.end(); iter++, i++){
			cout << i <<". "<< (**iter).getTaskDetails() << endl;
		}
	}
	return;
}

void Storage::displaySpecificTask(unsigned int taskIndex){
	if (taskList.empty()){
		cout <<"Task list is empty"<< endl;

		return;
	} else {
		if (taskIndex < 1 || taskIndex > taskList.size()){
			cout <<"Invalid number"<< endl;

			return;
		} else {
			cout << taskIndex <<". "<< textFileCopy[taskIndex - 1] << endl; 
		}
	}
	return;
}

//For future versions, to update multiple variables in one line, maybe can try vector<string> keyword and vector<string> newInput
void Storage::updateTask(unsigned int taskIndex, string keyword, string newInput){
	vector<Task*>::iterator iter = taskList.begin();
	vector<Task*>::iterator iterEnd = taskList.end();

	if (taskIndex > iterEnd - iter){
		cout <<"Invalid index"<< endl;

		return;
	} else {
		iter = iter + taskIndex - 1;

		if (keyword == "name"){
			(**iter).changeTaskName(newInput);
			cout<<"change task name"<<endl;
		} else 
			if (keyword == "start-date"){
				(**iter).changeTaskStartDate(newInput);
			} else 
				if (keyword == "start-time"){
					(**iter).changeTaskStartTime(newInput);
				} else 
					if (keyword == "end-date"){
						(**iter).changeTaskEndDate(newInput);
					} else 
						if (keyword == "end-time"){
							(**iter).changeTaskEndTime(newInput);
						} else 
							if (keyword == "deadline-date"){
								(**iter).changeTaskDeadlineDate(newInput);
							} else
								if (keyword == "deadline-time"){
									(**iter).changeTaskDeadlineTime(newInput);
								} else
									if (keyword == "priority"){
										(**iter).changeTaskPriority(newInput);
									} else {
										cout <<"Invalid keyword"<< endl;	
									}
	}

	return;
}