#include "Storage.h"

string Storage::MESSAGE_EMPTY_STACK = "Nothing to undo!";

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
	commandStack.push("add");

	return;
}

void Storage::deleteTask(unsigned int taskIndex){
	if (taskIndex < 1 || taskIndex > taskList.size()){
		cout << "Invalid Number" << endl;
	} else {
		deleteTaskObjectStack.push(taskList.back());
		deleteTaskIndexStack.push(taskIndex);
		commandStack.push("delete");

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
		for (unsigned int i = 0; i < textFileCopy.size(); i++){
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
			cout << taskList[taskIndex - 1]->getTaskName() << endl;
			cout << taskList[taskIndex - 1]->getTaskStatus() << endl;
			cout << taskList[taskIndex - 1]->getTaskDetails() << endl;
			taskList[taskIndex - 1]->changeTaskStatus(keyword);
			cout << taskList[taskIndex - 1]->getTaskName() << endl;
			cout << taskList[taskIndex - 1]->getTaskStatus() << endl;
			cout << taskList[taskIndex - 1]->getTaskDetails() << endl;
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

	if (previousCommand == "invalid"){
		cout << MESSAGE_EMPTY_STACK << endl;
		
		return;
	}

	if (previousCommand == "add"){
		textFileCopy.erase(textFileCopy.begin() + taskList.size() - 1);
		taskList.erase(taskList.begin() + taskList.size() - 1);

		return;
	}

	if (previousCommand == "delete"){
		Task *newTask = deleteTaskObjectStack.top();
		deleteTaskObjectStack.pop();
		unsigned int formerIndex = deleteTaskIndexStack.top();
		deleteTaskIndexStack.pop();
		taskList.insert(taskList.begin() + (formerIndex - 1), newTask);
		textFileCopy.insert(textFileCopy.begin() + (formerIndex - 1), newTask->getTaskDetails());
	
		return;
	}
	
	return;
}

string Storage::getPreviousCommand(){
	if (commandStack.empty()){
		return "invalid";
	} else {
		return commandStack.top();
	}
}

void Storage::clearAllTasks(){
	taskList.clear();
	textFileCopy.clear();

	return;
}

bool caseInsensitiveEqual(char ch1, char ch2){
	return toupper((unsigned char)ch1) == toupper((unsigned char)ch2);
}

void Storage::searchTask(string fileName, const string& searchEntry){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	vector<string>::iterator iter = textFileCopy.begin();
	int count = 0;

	while (iter != textFileCopy.end()){
		string::const_iterator pos = search(iter->begin(), iter->end(), searchEntry.begin(), searchEntry.end(), caseInsensitiveEqual);
		if (pos != iter->end()){
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

struct caseInsensitiveLess : public binary_function < char, char, bool > {
	bool operator () (char x, char y) const {
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

bool noCaseLess(const string &a, const string &b){
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), caseInsensitiveLess());
}

void Storage::sortTaskByName(string fileName){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	sort(textFileCopy.begin(), textFileCopy.end(), noCaseLess);

	return;
}