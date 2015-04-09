#include "Logic.h"
#include "Shlwapi.h"
#include <windows.h>
#include <direct.h>
#include <stack>
#include <stdio.h>



using namespace std;

string Logic::SAVING_LOCATON_HISTORY = "taskSotong_saving_Location_history.txt";


string Logic::ERROR_INVALID_USERINPUT = "Invalid User Input. Please Enter Again! :<";
string Logic::ERROR_EXISTING_TASK = "That Task Has Already Existed~! Please Enter A New Task~";
string Logic::ERROR_TASK_UPDATED_UNSUCCESSFULLY = "Failed To Update The Task!";
string Logic::ERROR_TASK_DELETED_UNSUCCESSFULLY = "Failed To Delete The Task!";
string Logic::ERROR_TASK_MARKED_UNSUCCESSFULLY = "Nah.. Index Out Of Range! Cannot Mark!";
string Logic::ERROR_TASK_UNMARKED_UNSUCCESSFULLY = "Nah.. Index Out Of Range! Cannot Unmark!";

string Logic::FEEDBACK_TASK_ADDED_SUCCESSFULLY = "Task Added Successfully! :>";
string Logic::FEEDBACK_DISPLAY_ALL_TASKS = "All Tasks Are Displayed!";
string Logic::FEEDBACK_TASK_UPDATED_SUCCESSFULLY = "Task Updated Successfully!";
string Logic::FEEDBACK_TASK_DELETED_SUCCESSFULLY = "Task Deleted Successfully!";
string Logic::FEEDBACK_SAVING_FILE_DIRECTORY_CHANGED = "Saving directory changed! :D";
string Logic::FEEDBACK_TASK_MARKED_SUCCESSFULLY = "Task Marked Completed! ";
string Logic::FEEDBACK_TASK_UNMARKED_SUCCESSFULLY = "Unmarked The Task!";
string Logic::FEEDBACK_CLEAR_ALL_TASKS = "All Tasks Cleared!";
string Logic::FEEDBACK_UNDO_PREVIOUS_TASK = "Undo Completed! :D";
string Logic::FEEDBACK_SEARCH_TASK_BY_KEYWORD = "Search Result Displayed! :D";
string Logic::FEEDBACK_SORT_TASK_BY_KEYWORD = "Tasks Sorted Accordingly!";


void Logic::initialiseSetUp() {

	initialiseFileLocationFile();
	bool areInTheSameLocation = checkIfFileIsAtExeLocation();
	string filename;
	if (areInTheSameLocation == false) {

		string lastFileLocation = getLastFileLocation();
		setFileName(lastFileLocation);
	} else {

		string exePath = getExePath() + "\\taskSotong.txt";
		setFileName(exePath);

	}
	filename = getFileName();
	callInitialise(filename);

}




void Logic::initialiseFileLocationFile() {


	ifstream readFile(SAVING_LOCATON_HISTORY);
	string tempStorage;

	while (getline(readFile, tempStorage)) {
		_fileLocation.push_back(tempStorage);

	}
	readFile.close();

	return;

}

void Logic::writeFileLocation(vector<string> fileLocation) {

	ofstream writeFile(SAVING_LOCATON_HISTORY);

	for (unsigned int i = 0; i < fileLocation.size(); i++) {
		writeFile << fileLocation[i] << endl;
	}

	return;

}

bool Logic::checkIfFileIsAtExeLocation() {

	int lastIndex = _fileLocation.size();
	if (lastIndex == 0) {
		return true;
	} else {

		string lastLocation = _fileLocation[lastIndex - 1];
		string exeLocation = getExePath();

		if (lastLocation == exeLocation) {
			return true;
		} else {
			return false;
		}
	}
}

string Logic::getLastFileLocation() {

	int lastIndex = _fileLocation.size();
	return _fileLocation[lastIndex - 1];
}

void Logic::updatefileLocation(string userDirectory) {

	_fileLocation.push_back(userDirectory);
	return;
}

//this function only gets the directory of the .exe file, not where the .txt file is. 
string Logic::getExePath() {

	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);

}

void Logic::createNewDirectory(string userFileDirectory) {

	int index = userFileDirectory.find_last_of('\\');
	int index2 = userFileDirectory.find_first_of('\\');
	string inputDirectory = userFileDirectory.substr(0, index);

	stack<string> directoryParts;
	int firstIndex = inputDirectory.find_last_of('\\');
	while (firstIndex != -1) {

		firstIndex = inputDirectory.find_last_of('\\');
		string temp = inputDirectory.substr(firstIndex, inputDirectory.size() - 1);

		if (temp == "\\") {

		} else {
			directoryParts.push(temp);
		}

		inputDirectory = inputDirectory.substr(0, firstIndex);

		firstIndex = inputDirectory.find_last_of('\\');
	}

	directoryParts.push(inputDirectory);

	string directory = directoryParts.top();
	directoryParts.pop();

	while (!directoryParts.empty()) {

		directory = directory + directoryParts.top();
		_mkdir(directory.c_str());
		directoryParts.pop();
	}

	return;
}

//new location should be saved in this format: "C:\ts\ts1\gt.txt";
void Logic::changeFileDirectory(string userFileDirectory) {

	createNewDirectory(userFileDirectory);
	setFileName(userFileDirectory);
	return;
}


void Logic::setFileName(string updatedFileName) {
	_filename = updatedFileName;
	return;
}

string Logic::getFileName() {
	return _filename;
}

paraList* Logic::getParaList(string userInput) {

	return _ParserComponent.parseCommand(userInput);
}


string Logic::getLowerCaseCommand(paraList parameterList) {
	string command = parameterList.getCommand();
	transform(command.begin(), command.end(), command.begin(), tolower);
	return command;

}

Task Logic::getTask(paraList parameterList) {
	return parameterList.getTask();
}

void Logic::copyTestFilefromStorage() {
	_storageTextFileCopy = getTextFileCopy();
	return;
}

vector<string> Logic::getTextFileCopy() {
	return _DataBase.returnTextFileCopy();
}

void Logic::callInitialise(string outputFile) {
	_DataBase.initialiseTextFile(outputFile);
}

bool Logic::notExistingTask(Task* task) {
	string taskDetail;
	taskDetail = task->getTaskDetails();
	copyTestFilefromStorage();
	for (unsigned int i = 0; i < _storageTextFileCopy.size(); i++) {
		if (taskDetail == _storageTextFileCopy[i]) {
			return false;
		}
	}
	return true;
}


string Logic::getFeedbackMsg() {
	return _feedbackMessage;

}

void Logic::setReturnGUI(vector<string> resultVector) {

	_resultVector = resultVector;


}

vector<string> Logic::getReturnGUI() {

	return _resultVector;

}

string Logic::executeCommand(paraList Input) {

	string command = getLowerCaseCommand(Input);

	if (command == "invalid") {

		_feedbackMessage = ERROR_INVALID_USERINPUT;

	} else if (command == "add") {
		Task oneTask = Input.getTask();
		string taskdetails = oneTask.getTaskDetails();

		if (notExistingTask(&oneTask) == true) {
			_DataBase.addTask(&oneTask);
			_DataBase.updateTextFile(_filename);
			copyTestFilefromStorage();
			setReturnGUI(_storageTextFileCopy);
			_feedbackMessage = FEEDBACK_TASK_ADDED_SUCCESSFULLY;

		} else {
			_feedbackMessage = ERROR_EXISTING_TASK;

		}
	} else if (command == "display") {
		_DataBase.displayAllTasks();
		_DataBase.updateTextFile(_filename);
		copyTestFilefromStorage();
		setReturnGUI(_storageTextFileCopy);
		_feedbackMessage = FEEDBACK_DISPLAY_ALL_TASKS;

	} else if (command == "update") {
		int updateInteger = Input.getUpdateInteger();
		string parameterToBeUpdated = Input.getKeyword();
		string detailToBeUpdated = Input.getInput();
		vector<string> myTextFileCopy = getTextFileCopy();
		string input = myTextFileCopy[updateInteger - 1];
		while (input.back() != ' ') {
			input.pop_back();
		}

		paraList* pList = getParaList("add " + input);
		Task taskToBeUpdated = pList->getTask();

		copyTestFilefromStorage();
		if (updateInteger >= _storageTextFileCopy.size() || updateInteger <= 0) {
			_feedbackMessage = ERROR_TASK_UPDATED_UNSUCCESSFULLY;

		} else {
			_DataBase.updateTask(_filename, updateInteger, &taskToBeUpdated, parameterToBeUpdated, detailToBeUpdated);
			_DataBase.updateTextFile(_filename);
			copyTestFilefromStorage();
			setReturnGUI(_storageTextFileCopy);
			_feedbackMessage = FEEDBACK_TASK_UPDATED_SUCCESSFULLY;

		}

	} else if (command == "delete") {
		int deleteInteger = Input.getDeleteInteger();
		copyTestFilefromStorage();
		if (deleteInteger > _storageTextFileCopy.size() || deleteInteger <= 0) {
			_feedbackMessage = ERROR_TASK_DELETED_UNSUCCESSFULLY;

		} else {
			_DataBase.deleteTask(_filename, deleteInteger);
			_DataBase.updateTextFile(_filename);
			copyTestFilefromStorage();
			setReturnGUI(_storageTextFileCopy);
			_feedbackMessage = FEEDBACK_TASK_DELETED_SUCCESSFULLY;

		}

	} else if (command == "save") {
		string userDirectory = Input.getuserdir();
		changeFileDirectory(userDirectory);
		_feedbackMessage = FEEDBACK_SAVING_FILE_DIRECTORY_CHANGED;
		updatefileLocation(userDirectory);
		writeFileLocation(_fileLocation);
		copyTestFilefromStorage();
		setReturnGUI(_storageTextFileCopy);

		//For parser to implement!!! remind jy!

	} else if (command == "erasesavinghistory") {
		for (int i = 0; i < (_fileLocation.size() - 1); i++) {

			//int j=remove(_fileLocation[i].c_str);
		}

	} else if (command == "mark") {
		int markIndex = Input.getmarkindex();
		if (markIndex > _storageTextFileCopy.size() || markIndex <= 0) {
			_feedbackMessage = ERROR_TASK_MARKED_UNSUCCESSFULLY;

		} else {
			_DataBase.markTask(_filename, markIndex);
			_DataBase.updateTextFile(_filename);
			copyTestFilefromStorage();
			setReturnGUI(_storageTextFileCopy);
			_feedbackMessage = FEEDBACK_TASK_MARKED_SUCCESSFULLY;
		}

	} else if (command == "unmark") {
		int unmarkIndex = Input.getmarkindex();
		if (unmarkIndex > _storageTextFileCopy.size() || unmarkIndex <= 0) {
			_feedbackMessage = ERROR_TASK_UNMARKED_UNSUCCESSFULLY;

		} else {
			_DataBase.unmarkTask(_filename, unmarkIndex);
			_DataBase.updateTextFile(_filename);
			copyTestFilefromStorage();
			setReturnGUI(_storageTextFileCopy);
			_feedbackMessage = FEEDBACK_TASK_UNMARKED_SUCCESSFULLY;
		}

	} else if (command == "clear") {
		_DataBase.clearAllTasks();
		copyTestFilefromStorage();
		setReturnGUI(_storageTextFileCopy);
		_feedbackMessage = FEEDBACK_CLEAR_ALL_TASKS;

	} else if (command == "undo") {
		_DataBase.undoAction();
		_DataBase.updateTextFile(_filename);
		copyTestFilefromStorage();
		setReturnGUI(_storageTextFileCopy);
		_feedbackMessage = FEEDBACK_UNDO_PREVIOUS_TASK;

	} else if (command == "search") {
		string searchKeyWord = Input.getSearchKey();
		//_DataBase.searchTask(searchKeyWord);
		_feedbackMessage = FEEDBACK_SEARCH_TASK_BY_KEYWORD;

	} else if (command == "sort") {
		_DataBase.sortTaskByName(_filename);
		_DataBase.updateTextFile(_filename);
		copyTestFilefromStorage();
		setReturnGUI(_storageTextFileCopy);
		_feedbackMessage = FEEDBACK_SORT_TASK_BY_KEYWORD;

	} else {
		if (command[0] == '\n') {
			_feedbackMessage = "SHIT";
		} else {
			_feedbackMessage = "DUNG";
		}
		//_feedbackMessage = command[0];
	}

	return _feedbackMessage;
}

