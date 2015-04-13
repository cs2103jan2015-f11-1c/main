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

	vector<Task> subTaskList = performSearchForViewingTasks("Completed");

	if (subTaskList.empty()){
		setFeedbackMessage(ERROR_NO_COMPLETED_TASKS);
		return taskList;
	}

	return subTaskList;
}

vector<Task> Storage::viewIncompleteTasks(){

	vector<Task> subTaskList = performSearchForViewingTasks("Incomplete");

	if (subTaskList.empty()){
		setFeedbackMessage(ERROR_NO_INCOMPLETE_TASKS);
		return taskList;
	}

	return subTaskList;
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

bool noCaseLess(Task task1,Task task2){
	//return lexicographical_compare(task1.begin(), task1.end(), task2.begin(), task2.end(), caseInsensitiveLess());
	return lexicographical_compare((task1.getTaskName()).begin(), (task1.getTaskName()).end(), (task2.getTaskName()).begin(), (task2.getTaskName()).end(), caseInsensitiveLess());
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

/*vector<string> Storage::searchTask(string fileName, const string& searchEntry){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTaskList()){
		return;
	}

	vector<string>::iterator iter = textFileCopy.begin();
	vector<string> returnTextFileCopy;
	int count = 0;

	while (iter != textFileCopy.end()){
		string::const_iterator pos = search(iter->begin(), iter->end(), searchEntry.begin(), searchEntry.end(), caseInsensitiveEqual);
		if (pos != iter->end()){
			returnTextFileCopy.push_back(*iter);
			count++;
		}
		iter++;
	}
	if (count == 0){
		cout << ERROR_INVALID_SEARCH_TERM << endl;
	}

	return returnTextFileCopy;
}

struct less_than_key
{
	inline bool operator() (Task struct1, Task struct2)
	{
		string task1name = struct1.getTaskName();
		string task2name = struct2.getTaskName();
		int task1 = stoi(task1name);
		int task2 = stoi(task2name);
		return (task1 < task2);
		//return (transform(task1name.begin(), task1name.end(), task1name.begin(), tolower) < transform(task2name.begin(), task2name.end(), task2name.begin(), tolower));

	}
};

struct less_than_key
{
	bool operator () (char x, char y) const {
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};
*/
struct less_than_key
{
	inline bool operator() (Task& struct1, Task& struct2)
	{
		return (struct1.getTaskName() < struct2.getTaskName());
	}
};

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
	sort(taskList.begin(), taskList.end(), less_than_key());
	//sort((taskList.begin())->getTaskName(), (taskList.end())->getTaskName(), noCaseLess);
	//sort(taskList.begin(), taskList.end(), noCaseLess);

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