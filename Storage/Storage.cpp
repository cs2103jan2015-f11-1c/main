#include "Storage.h"

string Storage::MESSAGE_EMPTY_STACK = "-1";

void Storage::updateTextFile(string outputFile){

	ofstream writeFile(outputFile);

	for (unsigned int i = 0; i < textFileCopy.size(); i++){
		writeFile << textFileCopy[i] << endl;
	}

	return;
}

void Storage::initialiseTextFile(string outputFile){
	ifstream readFile(outputFile);
	string tempStorage;
	while (getline(readFile, tempStorage)){
		textFileCopy.push_back(tempStorage);
	}
	readFile.close();
};

vector<string> Storage::returnTextFileCopy(){
	return textFileCopy;
}

void Storage::addTask(Task *individual_task){
	taskList.push_back(individual_task); 
	textFileCopy.push_back(individual_task->getTaskDetails());

	return;
}

void Storage::deleteTask(unsigned int taskIndex){
	if (taskIndex < 1 || taskIndex > taskList.size()){
		cout << "Invalid Number" << endl;
	}
	else {
		deleteTaskObjectStack.push(taskList.back());
		deleteTaskIndexStack.push(taskIndex);

		textFileCopy.erase(textFileCopy.begin() + taskIndex - 1);	
		taskList.erase(taskList.begin() + taskIndex - 1);
	}

	return;
}

void Storage::displayAllTasks(){
	if (textFileCopy.empty()){
		cout << "Task list is empty" << endl;

		return;
	} else {
		for (int i = 0; i < textFileCopy.size(); i++){
			cout << i + 1 << ". " << textFileCopy[i] << endl;
		}
	}
	return;
}

void Storage::displaySpecificTask(unsigned int taskIndex){
	if (taskList.empty()){
		cout << "Task list is empty" << endl;

		return;
	} else {
		if (taskIndex < 1 || taskIndex > taskList.size()){
			cout << "Invalid number" << endl;

			return;
		} else {
			cout << taskIndex << ". " << textFileCopy[taskIndex - 1] << endl; 
		}
	}
	return;
}

//For future versions, to update multiple variables in one line, maybe can try vector<string> keyword and vector<string> newInput
void Storage::updateTask(unsigned int taskIndex, string keyword, string newInput){
	vector<Task*>::iterator iter = taskList.begin();
	vector<Task*>::iterator iterEnd = taskList.end();

	if (taskIndex > iterEnd - iter){
		cout << "Invalid index" << endl;

		return;
	} else {
		iter = iter + taskIndex - 1;

		if (keyword == "name"){
			(**iter).changeTaskName(newInput);
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
										cout << "Invalid keyword" << endl;	
									}
									textFileCopy.insert(textFileCopy.begin() + taskIndex - 1, taskList[taskIndex - 1]->getTaskDetails());
									textFileCopy.erase(textFileCopy.begin() + taskIndex);
	}

	return;
}

void Storage::markTask(unsigned int taskIndex, string keyword){
	if (taskList.empty()){
		cout << "Task list is empty" << endl;

		return;
	} else {
		if (taskIndex < 1 || taskIndex > taskList.size()){
			cout << "Invalid number" << endl;

			return;
		} else {
			taskList[taskIndex - 1]->changeTaskStatus(keyword);
			textFileCopy.insert(textFileCopy.begin() + taskIndex - 1, taskList[taskIndex - 1]->getTaskDetails());
			textFileCopy.erase(textFileCopy.begin() + taskIndex);	
		}

		return;
	}
}

//Add support for keywords "mark", "unmark", "clearAllTasks", "update"
void Storage::undoAction(){
	string previousCommand = getPreviousCommand();
	commandStack.pop();

	if (previousCommand == "add"){
		unsigned int previousSize = taskList.size();
		deleteTask(taskList.size());
	}
	else {
		if (previousCommand == "delete"){
			Task *newTask = deleteTaskObjectStack.top();
			deleteTaskObjectStack.pop();
			unsigned int formerIndex = deleteTaskIndexStack.top();
			deleteTaskIndexStack.pop();
			taskList.insert(taskList.begin() + (formerIndex - 1), newTask);
			textFileCopy.insert(textFileCopy.begin() + (formerIndex - 1), newTask->getTaskDetails());
		}
	}
	return;
}

string Storage::getPreviousCommand(){
	if (commandStack.empty()){
		return MESSAGE_EMPTY_STACK;
	}
	else {
		return commandStack.top();
	}
}

void Storage::clearAllTasks(){
	taskList.clear();
	textFileCopy.clear();

	return;
}

//For future versions, can include functionality to search for words regardless of capitilization
void Storage::searchTask(const string& searchEntry){
	vector<string>::iterator iter = textFileCopy.begin();
	int count = 0;

	while (iter != textFileCopy.end()){
		if (iter->find(searchEntry) != string::npos){
			cout << (iter - textFileCopy.begin() + 1) << ". " << *iter << endl;
			count++;
		}
		iter++;
	}

	if (count == 0){
		cout << "No matching results" << endl;
	}

	return;
}