#include "Storage.h"

string Storage::ERROR_EMPTY_LIST = "Task list is empty!";
string Storage::ERROR_INVALID_NUMBER = "Invalid number!";
string Storage::ERROR_NO_COMPLETED_TASKS = "You have not completed any tasks!";
string Storage::ERROR_NO_INCOMPLETE_TASKS = "You have completed all outstanding tasks!";
string Storage::ERROR_TASK_PREVIOUSLY_COMPLETED = "Task already marked as completed!";
string Storage::ERROR_TASK_PREVIOUSLY_INCOMPLETE = "Task already marked as incomplete!";
string Storage::ERROR_CANNOT_UNDO = "Nothing to undo!";
string Storage::ERROR_INVALID_SEARCH_TERM = "No matching results";
string Storage::ERROR_ONLY_ONE_TASK = "There is no need to sort a single task!";
string Storage::ERROR_INVALID_NAME_SORT = "Task list is already sorted by name!";
string Storage::ERROR_INVALID_STATUS_SORT = "Task list is already sorted by status!";
string Storage::ERROR_INVALID_PRIORITY_SORT = "Task list is already sorted by priority!";
string Storage::ERROR_INVALID_UPDATE_KEYWORD = "Component to be updated is invalid!";
string Storage::ERROR_INVALID_UPDATE_PRIORITY_KEYWORD = "Priority must be High, Medium or Low!";
string Storage::FEEDBACK_MESSAGE_UPDATED_SUCCESSFULLY = "Update Successful!";
string Storage::FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY = "Undo Completed! :D";
string Storage::FEEDBACK_MESSAGE_VIEW_COMPLETED_SUCCESSFULLY = "Your Completed Tasks! :D";
string Storage::FEEDBACK_MESSAGE_VIEW_INCOMPLETE_SUCCESSFULLY = "Your Incomplete Tasks! :/";

bool Storage::isEmptyTaskList(){
	if (taskList.empty()){
		return true;
	}
	return false;
}

//checks if index is out of range
bool Storage::isInvalidIndex(unsigned int taskIndex){
	assert(taskIndex != NULL);
	if (taskIndex < 1 || taskIndex > textFileCopy.size()){
		cout << ERROR_INVALID_NUMBER << endl;

		return true;
	}

	return false;
}

vector<Task> Storage::performSearchForViewingTasks(string keyword){

	assert(keyword != "");

	vector<Task> tempTaskList;
	vector<Task>::iterator iter = taskList.begin();

	while (iter != taskList.end()){
		if ((iter->getTaskStatus()) == keyword){
			tempTaskList.push_back(*iter);
		}
		iter++;
	}

	return tempTaskList;
}

bool Storage::isOnlyOneTask(){

	return (taskList.size() == 1);
}
/*
bool Storage::isSortedByName(vector<Task> taskListDuplicate){
	//for (auto &words : taskListDuplicate)
		//transform(words.getTaskName, words.getTaskName, words.getTaskName, toupper);

	return (is_sorted(taskListDuplicate.begin()->getTaskName, taskListDuplicate.end()->getTaskName));
}
*/
bool Storage::isSortedByStatus(){

	return (textFileCopy == sortByStatusAfterStack.top());
}

bool Storage::isSortedByPriority(){

	return (textFileCopy == sortByPriorityAfterStack.top());
}

//sorts the tasklist based on the keyword given by Logic
void Storage::performSort(queue<string>& sortedTextFileCopy, string keyword){

	assert(keyword != "");
	vector<string>::iterator iter = textFileCopy.begin();
	while (iter != textFileCopy.end()){
		string::const_iterator pos = search(iter->begin(), iter->end(), keyword.begin(), keyword.end(), caseInsensitiveEqual);
		if (pos != iter->end()){
			sortedTextFileCopy.push(*iter);
		}
		iter++;
	}

	return;
}

//Returns the original task list
vector<Task> Storage::returnTaskList() {

	return taskList;

}

//Returns the task list containing only completed tasks
vector<Task> Storage::returnCompletedTaskList() {

	return completedTaskList;

}

//Returns the task list containing only incompleted tasks
vector<Task> Storage::returnIncompleteTaskList() {

	return incompleteTaskList;

}

//Converts vector<Task> taskList to vector<string> taskListStringVector 
void Storage::toString(){
	for (unsigned int i = 0; i < taskList.size(); i++){
		ostringstream oss;

		oss << taskList[i].getTaskName() << endl;
		oss << taskList[i].getTaskStartDate() << endl;
		oss << taskList[i].getTaskStartTime() << endl;
		oss << taskList[i].getTaskEndDate() << endl;
		oss << taskList[i].getTaskEndTime() << endl;
		oss << taskList[i].getTaskDeadlineDate() << endl;
		oss << taskList[i].getTaskDeadlineTime() << endl;
		oss << taskList[i].getTaskPriority() << endl;
		oss << taskList[i].getTaskStatus() << endl;

		taskListStringVector.push_back(oss.str());
	}

	return;
}

//Converts vector<string> taskListStringVector back to vector<Task> taskList 
void Storage::toTaskList(){
	ostringstream oss;
	for (int i = 0; i < taskListStringVector.size(); i++){
		oss << taskListStringVector[i];
	}

	string line;
	assert(line == "");
	vector<string> taskParameters;
	istringstream iss(oss.str());
	while (getline(iss, line)) {

		if (isalnum(line[0])) {
			taskParameters.push_back(line);
			for (int i = 0; i < 8; i++) {
				getline(iss, line);
				taskParameters.push_back(line);
			}
			string temp1 = taskParameters[0];
			string temp2 = taskParameters[1];
			string temp3 = taskParameters[2];
			string temp4 = taskParameters[3];
			string temp5 = taskParameters[4];
			string temp6 = taskParameters[5];
			string temp7 = taskParameters[6];
			string temp8 = taskParameters[7];
			string temp9 = taskParameters[8];

			Task tempTask(temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9);
			taskList.push_back(tempTask);
			taskParameters.clear();
		}
	}

	return;
};

void Storage::updateTaskList(Task taskTobeEntered) {

	taskList.push_back(taskTobeEntered);

	return;
}

//Updates the text file with the current tasklist vector
void Storage::updateTextFile(string fileName){

	assert(fileName != "");

	ofstream writeFile(fileName);

	for (unsigned int i = 0; i < taskList.size(); i++){
		
		writeFile << "***************************************************************"<<endl;
		writeFile << taskList[i].getTaskName() << endl;
		writeFile << taskList[i].getTaskStartDate() << endl;
		writeFile << taskList[i].getTaskStartTime() << endl;
		writeFile << taskList[i].getTaskEndDate() << endl;
		writeFile << taskList[i].getTaskEndTime() << endl;
		writeFile << taskList[i].getTaskDeadlineDate() << endl;
		writeFile << taskList[i].getTaskDeadlineTime() << endl;
		writeFile << taskList[i].getTaskPriority() << endl;
		writeFile << taskList[i].getTaskStatus()<<endl;

	}

	return;
}

//Updates the task list vector with the contents in text file
void Storage::initialiseTextFile(string fileName){

	_Storage_LogFile.writeToLogFile("***********LOGGING _STORAGE_START***********");

	assert(fileName != "");

	ifstream readFile(fileName);
	string tempStorage;
	vector<string> taskParameters;
	while (getline(readFile, tempStorage)) {

		if (tempStorage == "***************************************************************") {
			
			for (int i = 0; i < 9; i++) {
				getline(readFile, tempStorage);
				taskParameters.push_back(tempStorage);
			}
			string temp1 = taskParameters[0];
			string temp2 = taskParameters[1];
			string temp3 = taskParameters[2];
			string temp4 = taskParameters[3];
			string temp5 = taskParameters[4];
			string temp6 = taskParameters[5];
			string temp7 = taskParameters[6];
			string temp8 = taskParameters[7];
			string temp9 = taskParameters[8];

			_Storage_LogFile.writeToLogFile(temp1);
			_Storage_LogFile.writeToLogFile(temp2);
			_Storage_LogFile.writeToLogFile(temp3);
			_Storage_LogFile.writeToLogFile(temp4);
			_Storage_LogFile.writeToLogFile(temp5);
			_Storage_LogFile.writeToLogFile(temp6);
			_Storage_LogFile.writeToLogFile(temp7);
			_Storage_LogFile.writeToLogFile(temp8);
			_Storage_LogFile.writeToLogFile(temp9);

			Task tempTask(temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9);
			taskList.push_back(tempTask);
			taskParameters.clear();
		}
	}
	
	readFile.close();

	return;
};

vector<string> Storage::returnTextFileCopy(){
	return textFileCopy;
}

//Pushes the task added into task list vector
void Storage::addTask(Task individual_task){
	
	taskList.push_back(individual_task);

	assert(!taskList.empty());
	
	commandStack.push("add");

	_Storage_LogFile.writeToLogFile("add");

	return;
}

//Removes the task from the task list vector
void Storage::deleteTask(string fileName, unsigned int taskIndex){

	try{

		if (taskIndex < 0)
		{

			throw;

		}




	}
	catch (...){

		cout << "exception case:task index is a negative number";



	}




	assert(taskIndex != NULL);

	deleteTaskStack.emplace(taskList[taskIndex - 1], taskIndex);
	commandStack.push("delete");

	_Storage_LogFile.writeToLogFile("delete");

	taskList.erase(taskList.begin() + taskIndex - 1);
	
	return;
}

//Returns a task list containing only completed tasks
vector<Task> Storage::viewCompletedTasks(){

	completedTaskList = performSearchForViewingTasks("Completed");
	_Storage_LogFile.writeToLogFile("Completed");

	if (completedTaskList.empty()){
		setFeedbackMessage(ERROR_NO_COMPLETED_TASKS);
		return taskList;
	}

	setFeedbackMessage(FEEDBACK_MESSAGE_VIEW_COMPLETED_SUCCESSFULLY);
	return completedTaskList;
}

//Returns a task list containing only incomplete tasks
vector<Task> Storage::viewIncompleteTasks(){

	incompleteTaskList = performSearchForViewingTasks("Incomplete");
	_Storage_LogFile.writeToLogFile("Incomplete");

	if (incompleteTaskList.empty()){
		setFeedbackMessage(ERROR_NO_INCOMPLETE_TASKS);
		return taskList;
	}

	setFeedbackMessage(FEEDBACK_MESSAGE_VIEW_INCOMPLETE_SUCCESSFULLY);
	return incompleteTaskList;
}

void Storage::setFeedbackMessage(string messageToBeSet){
	
	assert(messageToBeSet != "");

	feedbackMessage = messageToBeSet;

	return;
}

string Storage::returnLogicFeedbackMessage(){

	return feedbackMessage;
}

//Checking whether a character is smaller than another character in the ASCII code
struct caseInsensitiveLess : public binary_function < char, char, bool > {
	bool operator () (char x, char y) const {
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

//To compare each character in both strings using a predicate
bool noCaseLess(const string &a, const string &b){
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), caseInsensitiveLess());
}

//To update a task in the task list by identifying the keyword and then replacing the old input
void Storage::updateTask(string fileName, unsigned int taskIndex, string keyword, string newInput) {



	try{

		if (taskIndex < 0)
		{

			throw;
		}

	}
	catch(...){


		cout << "Taskindex less than 0";


	}

	_Storage_LogFile.writeToLogFile(keyword);

	updateTaskStack.emplace(taskList[taskIndex - 1], taskIndex);
	commandStack.push("update");

	if (keyword == "name") {
		taskList[taskIndex - 1].changeTaskName(newInput);
	} else if (keyword == "start-date") {
		taskList[taskIndex - 1].changeTaskStartDate(newInput);
	} else if (keyword == "start-time") {
		taskList[taskIndex - 1].changeTaskStartTime(newInput);
	} else if (keyword == "end-date") {
		taskList[taskIndex - 1].changeTaskEndDate(newInput);
	} else if (keyword == "end-time") {
		taskList[taskIndex - 1].changeTaskEndTime(newInput);
	} else if (keyword == "deadline-date") {
		taskList[taskIndex - 1].changeTaskDeadlineDate(newInput);
	} else if (keyword == "deadline-time") {
		taskList[taskIndex - 1].changeTaskDeadlineTime(newInput);
	} else if(keyword == "priority") {
		transform(newInput.begin(), newInput.end(), newInput.begin(), toupper);
		if ((newInput == "HIGH") || (newInput == "MEDIUM") || (newInput == "LOW") || (newInput == "!H") || (newInput == "!M") || (newInput == "!L")){
			taskList[taskIndex - 1].changeTaskPriority(newInput);
		} else {
			setFeedbackMessage(ERROR_INVALID_UPDATE_PRIORITY_KEYWORD);
		}
	} else {
		setFeedbackMessage(ERROR_INVALID_UPDATE_KEYWORD);
	}	

	return;
}

//Changes status from "Incomplete" to "Completed"
void Storage::markTask(string fileName, unsigned int taskIndex){

	assert(taskIndex != NULL);

	try{

		if (taskIndex < 0)
		{

			throw;
		}

	}
	catch (...){


		cout << "Taskindex less than 0";


	}



	taskList[taskIndex - 1].changeTaskStatus("mark");
	markTaskIndexStack.push(taskIndex);
	commandStack.push("mark");

	return;
}

//Changes status from "Completed" to "Incomplete"
void Storage::unmarkTask(string fileName, unsigned int taskIndex){

	assert(taskIndex != NULL);
	try{

		if (taskIndex < 0)
		{

			throw;
		}

	}
	catch (...){


		cout << "Taskindex less than 0";


	}




	taskList[taskIndex - 1].changeTaskStatus("unmark");
	unmarkTaskIndexStack.push(taskIndex);
	commandStack.push("unmark");

	return;
}

//Undo previous action based on the last command entered
void Storage::undoAction(){

	if (commandStack.empty()){
		setFeedbackMessage(ERROR_CANNOT_UNDO);

		return;
	}

	string previousCommand = commandStack.top();
	commandStack.pop();

	assert(previousCommand != "");

	if (previousCommand == "add"){
		taskList.erase(taskList.end() - 1);

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	if (previousCommand == "delete"){
		Task deletedTask = get<0>(deleteTaskStack.top());
		unsigned int formerIndex = get<1>(deleteTaskStack.top());
		deleteTaskStack.pop();

		taskList.insert(taskList.begin() + (formerIndex - 1), deletedTask);

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);
	
		return;
	}
	
	if (previousCommand == "update"){
		Task originalTask = get<0>(updateTaskStack.top());
		unsigned int formerIndex = get<1>(updateTaskStack.top());
		updateTaskStack.pop();

		taskList.insert(taskList.begin() + (formerIndex - 1), originalTask);
		taskList.erase(taskList.begin() + formerIndex);

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}
	
	if (previousCommand == "mark"){
		unsigned int formerIndex = markTaskIndexStack.top();
		markTaskIndexStack.pop();

		taskList[formerIndex - 1].changeTaskStatus("unmark");

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	if (previousCommand == "unmark"){
		unsigned int formerIndex = unmarkTaskIndexStack.top();
		unmarkTaskIndexStack.pop();

		taskList[formerIndex - 1].changeTaskStatus("mark");

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	if (previousCommand == "clear"){
		taskList = clearAllTasksStack.top();
		clearAllTasksStack.pop();

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}
	
	if (previousCommand == "sort by name"){

		taskList = sortByNameStack.top();
		sortByNameStack.pop();

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	return;
}

//Clear all tasks currently in task list vector
void Storage::clearAllTasks(){
	clearAllTasksStack.push(taskList);
	commandStack.push("clear");

	taskList.clear();

	assert(taskList.empty());

	return;
}

bool caseInsensitiveEqual(char ch1, char ch2){
	return toupper((unsigned char)ch1) == toupper((unsigned char)ch2);
}

vector<Task> Storage::sortTaskByName(string fileName){

	if (isOnlyOneTask()){
		setFeedbackMessage(ERROR_ONLY_ONE_TASK);
		return taskList;
	}

	commandStack.push("sort by name");
	sortByNameStack.push(taskList);

	taskListStringVector.clear();
	toString();
	sort(taskListStringVector.begin(), taskListStringVector.end(), noCaseLess);
	taskList.clear();
	toTaskList();

	return taskList;
}

