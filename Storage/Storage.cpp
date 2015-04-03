#include "Storage.h"

string Storage::ERROR_EMPTY_LIST = "Task list is empty!";
string Storage::ERROR_INVALID_NUMBER = "Invalid number!";
string Storage::ERROR_TASK_PREVIOUSLY_COMPLETED = "Task already marked as completed!";
string Storage::ERROR_TASK_PREVIOUSLY_INCOMPLETE = "Task already marked as incomplete!";
string Storage::ERROR_CANNOT_UNDO = "Nothing to undo!";

bool Storage::isEmptyTextFile(){
	if (textFileCopy.empty()){
		cout << ERROR_EMPTY_LIST << endl;

		return true;
	}

	return false;
}

bool Storage::isInvalidIndex(unsigned int taskIndex){
	if (taskIndex < 1 || taskIndex > textFileCopy.size()){
		cout << ERROR_INVALID_NUMBER << endl;

		return true;
	}

	return false;
}

void Storage::updateTextFile(string fileName){

	ofstream writeFile(fileName);

	for (unsigned int i = 0; i < textFileCopy.size(); i++){
		writeFile << textFileCopy[i] << endl;
	}

	return;
}

void Storage::initialiseTextFile(string fileName){
	ifstream readFile(fileName);
	string tempStorage;
	while (getline(readFile, tempStorage)){
		textFileCopy.push_back(tempStorage);
	}
	readFile.close();

	return;
};

vector<string> Storage::returnTextFileCopy(){
	return textFileCopy;
}

void Storage::addTask(Task *individual_task){
	textFileCopy.push_back(individual_task->getTaskDetails());
	commandStack.push("add");

	return;
}

void Storage::deleteTask(string fileName, unsigned int taskIndex){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTextFile() || isInvalidIndex(taskIndex)){
		return;
	}

	deleteTaskDetailsStack.push(textFileCopy[taskIndex - 1]);
	deleteTaskIndexStack.push(taskIndex);
	commandStack.push("delete");

	textFileCopy.erase(textFileCopy.begin() + taskIndex - 1);

	return;
}

void Storage::displayAllTasks(){
	if (isEmptyTextFile()){
		return;
	} 
		
	for (unsigned int i = 0; i < textFileCopy.size(); i++){
		cout << i + 1 << ". " << textFileCopy[i] << endl;
	}

	return;
}

//For future versions, to update multiple variables in one line, maybe can try vector<string> keyword and vector<string> newInput
void Storage::updateTask(string fileName, unsigned int taskIndex, string keyword, string newInput){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTextFile() || isInvalidIndex(taskIndex)){
		return;
	}
	
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

void Storage::markTask(string fileName, unsigned int taskIndex){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTextFile() || isInvalidIndex(taskIndex)){
		return;
	}

	size_t index = 0;
	unsigned int lengthOfIncomplete = 10;

	index = textFileCopy[taskIndex - 1].find("Incomplete", index);
	if (index == string::npos){
		cout << ERROR_TASK_PREVIOUSLY_COMPLETED << endl;
	} else {
		textFileCopy[taskIndex - 1].replace(index, lengthOfIncomplete, "Completed");
		markTaskIndexStack.push(taskIndex);
		commandStack.push("mark");
	}

	return;
}

void Storage::unmarkTask(string fileName, unsigned int taskIndex){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTextFile() || isInvalidIndex(taskIndex)){
		return;
	}

	size_t index = 0;
	unsigned int lengthOfCompleted = 9;

	index = textFileCopy[taskIndex - 1].find("Completed", index);
	if (index == string::npos){
		cout << ERROR_TASK_PREVIOUSLY_INCOMPLETE << endl;
	} else {
		textFileCopy[taskIndex - 1].replace(index, lengthOfCompleted, "Incomplete");
		unmarkTaskIndexStack.push(taskIndex);
		commandStack.push("unmark");
	}

	return;
}

<<<<<<< HEAD
//Add support for keywords "clearAllTasks", "update", "sort"
=======
//Add support  for keywords "mark", "unmark", "clearAllTasks", "update"
//Add support for keywords "mark", "unmark", "clearAllTasks", "update", "sort"
>>>>>>> 2d6fc7637e724e7f8236a08f802a49cd87dd2093
void Storage::undoAction(){

	if (commandStack.empty()){
		cout << ERROR_CANNOT_UNDO << endl;

		return;
	}

	string previousCommand = commandStack.top();
	commandStack.pop();

	if (previousCommand == "add"){
		textFileCopy.erase(textFileCopy.end() - 1);

		return;
	}

	if (previousCommand == "delete"){
		string newTask = deleteTaskDetailsStack.top();
		deleteTaskDetailsStack.pop();

		unsigned int formerIndex = deleteTaskIndexStack.top();
		deleteTaskIndexStack.pop();

		textFileCopy.insert(textFileCopy.begin() + (formerIndex - 1), newTask);
	
		return;
	}
	
	if (previousCommand == "mark"){
		unsigned int formerIndex = markTaskIndexStack.top();
		markTaskIndexStack.pop();

		size_t index = 0;
		unsigned int lengthOfCompleted = 9;

		index = textFileCopy[formerIndex - 1].find("Completed", index);
		textFileCopy[formerIndex - 1].replace(index, lengthOfCompleted, "Incomplete");

		return;
	}

	if (previousCommand == "unmark"){
		unsigned int formerIndex = unmarkTaskIndexStack.top();
		unmarkTaskIndexStack.pop();

		size_t index = 0;
		unsigned int lengthOfIncomplete = 10;

		index = textFileCopy[formerIndex - 1].find("Incomplete", index);
		textFileCopy[formerIndex - 1].replace(index, lengthOfIncomplete, "Completed");
	
		return;
	}

	if (previousCommand == "clear"){
		string newTextFileCopy = clearAllTasksStack.top();
		clearAllTasksStack.pop();

	}

	return;
}

void Storage::clearAllTasks(){
	if (isEmptyTextFile()){
		return;
	}

	string backupText;
	for (unsigned int i = 0; i < textFileCopy.size(); i++){
		backupText.append(textFileCopy[i] + '\n');
	}

	textFileCopy.clear();
	clearAllTasksStack.push(backupText);
	//commandStack.push("clear");

	return;
}

bool caseInsensitiveEqual(char ch1, char ch2){
	return toupper((unsigned char)ch1) == toupper((unsigned char)ch2);
}

void Storage::searchTask(string fileName, const string& searchEntry){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTextFile()){
		return;
	}

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

	if (isEmptyTextFile()){
		return;
	}

	sort(textFileCopy.begin(), textFileCopy.end(), noCaseLess);

	return;
}