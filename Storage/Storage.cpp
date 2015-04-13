#include "Storage.h"
#include <assert.h>

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
	if (taskIndex < 1 || taskIndex > textFileCopy.size()){
		cout << ERROR_INVALID_NUMBER << endl;

		return true;
	}

	return false;
}

vector<Task> Storage::performSearchForViewingTasks(string keyword){

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

vector<Task> Storage::returnTaskList() {

	return taskList;

}

vector<Task> Storage::returnCompletedTaskList() {

	return completedTaskList;

}

vector<Task> Storage::returnIncompleteTaskList() {

	return incompleteTaskList;

}

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

void Storage::toTaskList(){
	ostringstream oss;
	for (int i = 0; i < taskListStringVector.size(); i++){
		oss << taskListStringVector[i];
	}

	string line;
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

//updates the text file with the current tasklist vector
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

void Storage::initialiseTextFile(string fileName){
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

//updated by GT
void Storage::addTask(Task individual_task){
	
	taskList.push_back(individual_task);
	
	commandStack.push("add");

	return;
}

void Storage::deleteTask(string fileName, unsigned int taskIndex){

	deleteTaskStack.emplace(taskList[taskIndex - 1], taskIndex);
	commandStack.push("delete");

	taskList.erase(taskList.begin() + taskIndex - 1);
	
	return;
}
//need to be deleted-GT
void Storage::displayAllTasks(){

	return;
}

vector<Task> Storage::viewCompletedTasks(){

	completedTaskList = performSearchForViewingTasks("Completed");

	if (completedTaskList.empty()){
		setFeedbackMessage(ERROR_NO_COMPLETED_TASKS);
		return taskList;
	}

	setFeedbackMessage(FEEDBACK_MESSAGE_VIEW_COMPLETED_SUCCESSFULLY);
	return completedTaskList;
}

vector<Task> Storage::viewIncompleteTasks(){

	incompleteTaskList = performSearchForViewingTasks("Incomplete");

	if (incompleteTaskList.empty()){
		setFeedbackMessage(ERROR_NO_INCOMPLETE_TASKS);
		return taskList;
	}

	setFeedbackMessage(FEEDBACK_MESSAGE_VIEW_INCOMPLETE_SUCCESSFULLY);
	return incompleteTaskList;
}

void Storage::setFeedbackMessage(string messageToBeSet){
	feedbackMessage = messageToBeSet;
}

string Storage::returnLogicFeedbackMessage(){
	return feedbackMessage;
}

struct caseInsensitiveLess : public binary_function < char, char, bool > {
	bool operator () (char x, char y) const {
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

bool noCaseLess(const string &a, const string &b){
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), caseInsensitiveLess());
}

void Storage::updateTask(string fileName, unsigned int taskIndex, string keyword, string newInput) {

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

//changes status from "incomplete" to "completed"
void Storage::markTask(string fileName, unsigned int taskIndex){

	taskList[taskIndex - 1].changeTaskStatus("mark");
	markTaskIndexStack.push(taskIndex);
	commandStack.push("mark");

	return;
}

//changes status from "completed" to "incomplete"
void Storage::unmarkTask(string fileName, unsigned int taskIndex){

	taskList[taskIndex - 1].changeTaskStatus("unmark");
	unmarkTaskIndexStack.push(taskIndex);
	commandStack.push("unmark");

	return;
}

//undo user's previous action, based on the last command entered
void Storage::undoAction(){

	if (commandStack.empty()){
		setFeedbackMessage(ERROR_CANNOT_UNDO);

		return;
	}

	string previousCommand = commandStack.top();
	commandStack.pop();

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

	if (previousCommand == "sort by status"){

		textFileCopy = sortByStatusBeforeStack.top();
		sortByStatusBeforeStack.pop();

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	if (previousCommand == "sort by priority"){

		textFileCopy = sortByPriorityBeforeStack.top();
		sortByPriorityBeforeStack.pop();

		setFeedbackMessage(FEEDBACK_MESSAGE_UNDO_SUCCESSFULLY);

		return;
	}

	return;
}

void Storage::clearAllTasks(){
	clearAllTasksStack.push(taskList);
	commandStack.push("clear");

	taskList.clear();

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

	//if (isSortedByName(taskList)){
	//	setFeedbackMessage(ERROR_INVALID_NAME_SORT);
	//	return;
	//}

	commandStack.push("sort by name");
	sortByNameStack.push(taskList);

	taskListStringVector.clear();
	toString();
	sort(taskListStringVector.begin(), taskListStringVector.end(), noCaseLess);
	taskList.clear();
	toTaskList();

	return taskList;
}
/*
vector<string> Storage::sortTaskByStatus(string fileName){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTaskList()){
		return;
	}

	if (isOnlyOneTask()){
		cout << ERROR_ONLY_ONE_TASK << endl;
		return;
	}

	if (sortByStatusAfterStack.size() > 0 && isSortedByStatus()){
		cout << ERROR_INVALID_STATUS_SORT << endl;
		sortByStatusAfterStack.pop();
		return;
	}

	commandStack.push("sort by status");
	sortByStatusBeforeStack.push(textFileCopy);

	sort(textFileCopy.begin(), textFileCopy.end(), noCaseLess);
	queue<string> sortedTextFileCopy;
	string keyword1 = "Completed";
	string keyword2 = "Incomplete";

	performSort(sortedTextFileCopy, keyword1);
	performSort(sortedTextFileCopy, keyword2);

	textFileCopy.clear();
	while (!sortedTextFileCopy.empty()){
		textFileCopy.push_back(sortedTextFileCopy.front());
		sortedTextFileCopy.pop();
	}
	sortByStatusAfterStack.push(textFileCopy);

	return sortByStatusAfterStack.top();
}

vector<string> Storage::sortTaskByPriority(string fileName){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTaskList()){
		return;
	}

	if (isOnlyOneTask()){
		cout << ERROR_ONLY_ONE_TASK << endl;
		return;
	}

	if (sortByPriorityAfterStack.size() > 0 && isSortedByPriority()){
		cout << ERROR_INVALID_PRIORITY_SORT << endl;
		sortByPriorityAfterStack.pop();
		return;
	}

	commandStack.push("sort by priority");
	sortByPriorityBeforeStack.push(textFileCopy);

	sort(textFileCopy.begin(), textFileCopy.end(), noCaseLess);
	queue<string> sortedTextFileCopy;
	string keyword1 = "high";
	string keyword2 = "medium";
	string keyword3 = "low";

	performSort(sortedTextFileCopy, keyword1);
	performSort(sortedTextFileCopy, keyword2);
	performSort(sortedTextFileCopy, keyword3);

	textFileCopy.clear();
	while (!sortedTextFileCopy.empty()){
		textFileCopy.push_back(sortedTextFileCopy.front());
		sortedTextFileCopy.pop();
	}
	sortByPriorityAfterStack.push(textFileCopy);

	return sortByPriorityAfterStack.top();
}
*/