#include "Storage.h"


void Storage::updateTextFile(string outputFile){

	ofstream writeFile(outputFile);
	cout << textFileCopy.size() << endl;
	for (int i = 0; i < textFileCopy.size(); i++){
		writeFile<< textFileCopy[i] << endl;
	}
	writeFile.close();

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
		for (int i = 0; i < textFileCopy.size(); i++){
			cout << i+1 <<"\t" <<textFileCopy[i] << endl;
		}

		/*vector<Task*>::iterator iter;
		for (iter = taskList.begin(); iter != taskList.end(); iter++){
			cout << (**iter).getTaskDetails() << endl;
			*/
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