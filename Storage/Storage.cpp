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

bool Storage::isEmptyTaskList(){
	if (taskList.empty()){
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

void Storage::performSearchForViewingTasks(string keyword, int& count){

	vector<string>::iterator iter = textFileCopy.begin();

	while (iter != textFileCopy.end()){
		if (iter->find(keyword) != string::npos){
			cout << (iter - textFileCopy.begin() + 1) << ". " << *iter << endl;
			count++;
		}
		iter++;
	}

	return;
}

bool Storage::isOnlyOneTask(){

	return (textFileCopy.size() == 1);
}

bool Storage::isSortedByName(vector<string> textFileDuplicate){
	for (auto &words : textFileDuplicate)
		transform(words.begin(), words.end(), words.begin(), toupper);

	return (is_sorted(textFileDuplicate.begin(), textFileDuplicate.end()));
}

bool Storage::isSortedByStatus(){

	return (textFileCopy == sortByStatusAfterStack.top());
}

bool Storage::isSortedByPriority(){

	return (textFileCopy == sortByPriorityAfterStack.top());
}

void Storage::performSort(queue<string>& sortedTextFileCopy, string keyword){
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


void Storage::updateTextFile(string fileName){

	ofstream writeFile(fileName);

	for (unsigned int i = 0; i < taskList.size(); i++){
		
		writeFile << "\\s"<<endl;
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

		if (tempStorage == "\\s") {
			
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
	//textFileCopy.clear();
	//initialiseTextFile(fileName);
	
	if (isEmptyTaskList()){
		return;
	}
	

	//deleteTaskStack.emplace(textFileCopy[taskIndex - 1], taskIndex); What's this?
	commandStack.push("delete");

	taskList.erase(taskList.begin()+taskIndex-1);
	
	

	return;
}
//need to be deleted-GT
void Storage::displayAllTasks(){

	return;
}

void Storage::viewCompletedTasks(){
	if (isEmptyTaskList()){
		return;
	}

	int count = 0;
	performSearchForViewingTasks("Completed", count);

	if (count == 0){
		cout << ERROR_NO_COMPLETED_TASKS << endl;
	}

	return;
}

void Storage::viewIncompleteTasks(){
	if (isEmptyTaskList()){
		return;
	}

	int count = 0;
	performSearchForViewingTasks("Incomplete", count);

	if (count == 0){
		cout << ERROR_NO_INCOMPLETE_TASKS << endl;
	}

	return;
}

void Storage::updateTask(string fileName, unsigned int taskIndex, string keyword, string newInput) {



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
		taskList[taskIndex-1].changeTaskPriority(newInput);
	}

	
	return;
}

void Storage::markTask(string fileName, unsigned int taskIndex){

	taskList[taskIndex - 1].changeTaskStatus("mark");
	markTaskIndexStack.push(taskIndex);
	commandStack.push("mark");
	return;
}

void Storage::unmarkTask(string fileName, unsigned int taskIndex){
	taskList[taskIndex - 1].changeTaskStatus("unmark");
	markTaskIndexStack.push(taskIndex);
	commandStack.push("unmark");
	return;
}

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
		string deletedTask = get<0>(deleteTaskStack.top());
		unsigned int formerIndex = get<1>(deleteTaskStack.top());
		deleteTaskStack.pop();

		textFileCopy.insert(textFileCopy.begin() + (formerIndex - 1), deletedTask);
	
		return;
	}

	if (previousCommand == "update"){
		string originalTask = get<0>(updateTaskStack.top());
		unsigned int formerIndex = get<1>(updateTaskStack.top());
		updateTaskStack.pop();

		textFileCopy.insert(textFileCopy.begin() + (formerIndex - 1), originalTask);
		textFileCopy.erase(textFileCopy.begin() + formerIndex);

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

	/*if (previousCommand == "clear"){
		vector<Task> formerTextFileCopy = clearAllTasksStack.top();
		clearAllTasksStack.pop();

		istringstream iss(formerTextFileCopy);
		string line;
		while (getline(iss, line)){
			textFileCopy.push_back(line);
		}

		return;
	}
	*/
	if (previousCommand == "sort by name"){

		textFileCopy = sortByNameStack.top();
		sortByNameStack.pop();

		return;
	}

	if (previousCommand == "sort by status"){

		textFileCopy = sortByStatusBeforeStack.top();
		sortByStatusBeforeStack.pop();

		return;
	}

	if (previousCommand == "sort by priority"){

		textFileCopy = sortByPriorityBeforeStack.top();
		sortByPriorityBeforeStack.pop();

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


struct caseInsensitiveLess : public binary_function < char, char, bool > {
	bool operator () (char x, char y) const {
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

bool noCaseLess(const string &a, const string &b){
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), caseInsensitiveLess());
}

vector<string> Storage::sortTaskByName(string fileName){
	textFileCopy.clear();
	initialiseTextFile(fileName);

	if (isEmptyTaskList()){
		return;
	}

	if (isOnlyOneTask()){
		cout << ERROR_ONLY_ONE_TASK << endl;
		return;
	}

	if (isSortedByName(textFileCopy)){
		cout << ERROR_INVALID_NAME_SORT << endl;
		return;
	}

	commandStack.push("sort by name");
	sortByNameStack.push(textFileCopy);
	sort(textFileCopy.begin(), textFileCopy.end(), noCaseLess);

	return textFileCopy;
}

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