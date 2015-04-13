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
string Logic::ERROR_EMPTY_LIST = "Task List Is Empty!";
string Logic::ERROR_TASK_INSUFFICIENT_PARAMETERS="Insufficient Parameters Entered!";
string Logic::ERROR_NO_INDEX = "No Index! :<";
string Logic::ERROR_INDEX_OUT_OF_RANGE="Index Out Of Range!";
string Logic::ERROR_NO_COMPONENT="No Component!";
string Logic::ERROR_COMPONENT_INVALID="Component Invalid!";
string Logic::ERROR_NO_CONTENT="No Content!";
string Logic::ERROR_INVALID_CONTENT="Content Invalid!";
string Logic::ERROR_INVALID_YEAR="Year Entered Is Invalid!";
string Logic::ERROR_INVALID_MONTH="Month Entered Is Invalid!";
string Logic::ERROR_INVALID_DAY="Day Entered Is Invalid";
string Logic::ERROR_INVALID_HOUR="Hour Entered Is Invalid";
string Logic::ERROR_INVALID_MINUTE="Minute Entered Is Invalid";


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
string Logic::FEEDBACK_VIEW_ALL_SUCCESSFULLY = "Viewing All Tasks!";

string Logic::checkTimeValidity(string timeInput) {

	string tempFeedback = "Pass Time Test";

		string tempMinute = timeInput.substr(timeInput.find_first_of(":") + 1, timeInput.length());
		string tempHour = timeInput.substr(0, timeInput.find_first_of(":"));

		int minute = atoi(tempMinute.c_str());
		int hour = atoi(tempHour.c_str());

		if ((hour < 0) || (hour>23)) {
			tempFeedback = ERROR_INVALID_HOUR;
		} else if (minute > 59) {
			tempFeedback = ERROR_INVALID_MINUTE;
		}

		return tempFeedback;
}

string Logic::checkDateValidity(string dateInput) {

	string tempFeedback = "Pass Date Test";

		string tempYear = dateInput.substr(dateInput.length() - 4, dateInput.length());
		string temp = dateInput.substr(0, dateInput.length() - 5);
		string tempMonth = temp.substr(temp.find_last_of("/") + 1, temp.length());
		string tempDay = temp.substr(0, temp.find_first_of("/"));
		
		int year = atoi(tempYear.c_str());
		int month = atoi(tempMonth.c_str());
		int day = atoi(tempDay.c_str());
		
		if (year < 2015) {
			tempFeedback = ERROR_INVALID_YEAR;
		} else if ((month < 1) || (month>12)) {
			tempFeedback = ERROR_INVALID_MONTH;
		} else if (day < 1) {
			tempFeedback = ERROR_INVALID_DAY;
		} else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
			if (day>31) {
				tempFeedback = ERROR_INVALID_DAY;
			}
		} else if (month == 2) {
			if (day > 28) {
				tempFeedback = ERROR_INVALID_DAY;;
			}
		} else if (day > 30) {
			tempFeedback = ERROR_INVALID_DAY;
			
		}

	return tempFeedback;

}

string Logic::checkTaskDatenTimeValidity(Task taskInput) {

	string tempFeedback;
	tempFeedback = "Pass Test";

	string taskStartDate = taskInput.getTaskStartDate();
	string taskStartTime = taskInput.getTaskStartTime();
	string taskEndDate = taskInput.getTaskEndDate();
	string taskEndTime = taskInput.getTaskEndTime();
	string taskDeadlineDate = taskInput.getTaskDeadlineDate();
	string taskDeadlineTime = taskInput.getTaskDeadlineTime();

	vector<string> dateVector;
	dateVector.push_back(taskStartDate);
	dateVector.push_back(taskEndDate);
	dateVector.push_back(taskDeadlineDate);

	vector<string> timeVector;
	timeVector.push_back(taskStartTime);
	timeVector.push_back(taskEndTime);
	timeVector.push_back(taskDeadlineTime);

	vector<string> componentVector;
	componentVector.push_back("Start Date: "); 
	componentVector.push_back("End Date: ");
	componentVector.push_back("Deadline Date: ");
	componentVector.push_back("Start Time: ");
	componentVector.push_back("End Time: ");
	componentVector.push_back("Deadline Time: ");

	string feedbackMsg_Date = "";
	for (int i = 0; i < dateVector.size(); i++) {

		if (dateVector[i] == "") {

		} else {
			feedbackMsg_Date = checkDateValidity(dateVector[i]);
			if (feedbackMsg_Date != "Pass Date Test") {
				tempFeedback = componentVector[i] + feedbackMsg_Date;	
				break;
			}
		}
	}

	if (tempFeedback == "Pass Test") {

		string feedbackMsg_Time="";
		for (int j = 0; j < timeVector.size(); j++) {

			if (timeVector[j] == "") {

			} else {
				feedbackMsg_Time = checkTimeValidity(timeVector[j]);
				if (feedbackMsg_Time != "Pass Time Test") {
					tempFeedback = componentVector[j % 3] + feedbackMsg_Time;
					break;
				} else {}
			}
		}

	}

	return tempFeedback;

}

string Logic::convertYearToCorrectForm(string input) {
	string output;
	if (input == "") {
		output = "";
	}
	else {
		string tempYear = input.substr(input.length() - 4, input.length());
		string temp = input.substr(0, input.length() - 5);
		string tempMonth = temp.substr(temp.find_last_of("/") + 1, temp.length());
		string tempDay = temp.substr(0, temp.find_first_of("/"));

		output = tempYear + tempMonth + tempDay;
	}

	return output;

}

string Logic::convertTimeToCorrectForm(string input) {

	string tempMinute = input.substr(input.find_first_of(":") + 1, input.length());
	string tempHour = input.substr(0, input.find_first_of(":"));
	string output = tempHour + tempMinute;

	return output;

}

string Logic::compareTaskDateandTime(Task taskInput) {
	string tempStartDate = taskInput.getTaskStartDate();
	string tempStartTime = taskInput.getTaskStartTime();
	string tempEndDate = taskInput.getTaskEndDate();
	string tempEndTime = taskInput.getTaskEndTime();

	string startDate = convertYearToCorrectForm(tempStartDate);


	string startTime = convertTimeToCorrectForm(tempStartTime);
	string endDate = convertYearToCorrectForm(tempEndDate);
	string endTime = convertTimeToCorrectForm(tempEndTime);

	
	string tempFeedback="";
	if (startDate == endDate) {
		if (startTime > endTime) {
			tempFeedback = "Start Time After End Time :<";
		} else {
		}
	} else if (startDate > endDate) {
		tempFeedback = "Start Date After End Date :<";
	} else {
	}
	return tempFeedback;
}

void Logic::setTaskList() {

	_storageTaskListCopy = _DataBase.returnTaskList();
}

vector<Task> Logic::getTaskList() {

	return _storageTaskListCopy;
}

void Logic::setCompletedTaskList() {

	_storageTaskListCopy = _DataBase.returnCompletedTaskList();
}

vector<Task> Logic::getCompletedTaskList() {

	return _storageTaskListCopy;
}

void Logic::setIncompleteTaskList() {

	_storageTaskListCopy = _DataBase.returnIncompleteTaskList();
}

vector<Task> Logic::getIncompleteTaskList() {

	return _storageTaskListCopy;
}

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

vector<string> Logic::getTextFileCopy() {
	return _DataBase.returnTextFileCopy();
}

void Logic::callInitialise(string outputFile) {
	_DataBase.initialiseTextFile(outputFile);
}

bool Logic::notExistingTask(Task* task) {

	return true;
}

string Logic::getFeedbackMsg() {
	return _feedbackMessage;

}

string Logic::executeCommand(paraList Input) {

	_Logic_LogFile.writeToLogFile("******************LOGIC_EXECUTECOMMAND_START*******************");

	string command = getLowerCaseCommand(Input);
	if (command == "exit"){
		exit(0);
	
	}else if (command == "add") {
		_Logic_LogFile.writeToLogFile(command);
		Task oneTask = Input.getTask();
		string tempFeedback;
		tempFeedback=checkTaskDatenTimeValidity(oneTask);

		if (tempFeedback != "Pass Test") {
			_feedbackMessage = tempFeedback;			
		} else {

			tempFeedback = compareTaskDateandTime(oneTask);

			if (tempFeedback != "") {
				_feedbackMessage = tempFeedback;
			} else {
				_DataBase.addTask(oneTask);
				_DataBase.updateTextFile(_filename);
				setTaskList();
				_feedbackMessage =FEEDBACK_TASK_ADDED_SUCCESSFULLY;
			}
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);

	} else if (command == "update") {
		_Logic_LogFile.writeToLogFile(command);
		int updateInteger = Input.getUpdateInteger();
		string parameterToBeUpdated = Input.getKeyword();
		string detailToBeUpdated = Input.getInput();

		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else if (updateInteger < 0) {
			_feedbackMessage = ERROR_NO_INDEX;
		} else if (updateInteger > _storageTaskListCopy.size()) {
			_feedbackMessage = ERROR_INDEX_OUT_OF_RANGE;
		} else if (parameterToBeUpdated == "name") {
			if (detailToBeUpdated == "") {
				_feedbackMessage = ERROR_NO_CONTENT;
			} else {
				
				_DataBase.updateTask(_filename, updateInteger, parameterToBeUpdated, detailToBeUpdated);
				_DataBase.updateTextFile(_filename);
				setTaskList();
				_feedbackMessage = FEEDBACK_TASK_UPDATED_SUCCESSFULLY;
				
			}

		} else if ((parameterToBeUpdated == "start-date") || (parameterToBeUpdated == "end-date") || (parameterToBeUpdated == "deadline-date")) {
			if (detailToBeUpdated == "") {
				_feedbackMessage = ERROR_NO_CONTENT;
			} else {

				_feedbackMessage = checkDateValidity(detailToBeUpdated);

				if (_feedbackMessage == "Pass Date Test") {

					string copyofParameterToBeUpdated = parameterToBeUpdated;
					string copyofOriginalDetail;

					if (copyofParameterToBeUpdated == "start-date") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskStartDate();
					} else if (copyofParameterToBeUpdated == "start-time") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskStartTime();
					} else if (copyofParameterToBeUpdated == "end-date") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskEndDate();
					} else if (copyofParameterToBeUpdated == "end-time") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskEndTime();
					}

					_DataBase.updateTask(_filename, updateInteger, parameterToBeUpdated, detailToBeUpdated);
					_DataBase.updateTextFile(_filename);
					setTaskList();

					_feedbackMessage = compareTaskDateandTime(_storageTaskListCopy[updateInteger - 1]);
					if (_feedbackMessage != "") {
						_DataBase.updateTask(_filename, updateInteger, copyofParameterToBeUpdated, copyofOriginalDetail);
						_DataBase.updateTextFile(_filename);
						setTaskList();
					
					} else {
						_feedbackMessage = FEEDBACK_TASK_UPDATED_SUCCESSFULLY;
					}
				}
			}
			_Logic_LogFile.writeToLogFile(_feedbackMessage);
		} else if ((parameterToBeUpdated == "start-time") || (parameterToBeUpdated == "end-time") || (parameterToBeUpdated == "deadline-time")) {

			if (detailToBeUpdated == "") {
				_feedbackMessage = ERROR_NO_CONTENT;
			} else {

				_feedbackMessage = checkTimeValidity(detailToBeUpdated);

				if (_feedbackMessage == "Pass Time Test") {

					string copyofParameterToBeUpdated = parameterToBeUpdated;
					string copyofOriginalDetail;

					if (copyofParameterToBeUpdated == "start-date") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskStartDate();
					} else if (copyofParameterToBeUpdated == "start-time") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskStartTime();
					} else if (copyofParameterToBeUpdated == "end-date") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskEndDate();
					} else if (copyofParameterToBeUpdated == "end-time") {
						copyofOriginalDetail = _storageTaskListCopy[updateInteger - 1].getTaskEndTime();
					}

					_DataBase.updateTask(_filename, updateInteger, parameterToBeUpdated, detailToBeUpdated);
					_DataBase.updateTextFile(_filename);
					setTaskList();

					_feedbackMessage = compareTaskDateandTime(_storageTaskListCopy[updateInteger - 1]);
					if (_feedbackMessage != "") {
						_DataBase.updateTask(_filename, updateInteger, copyofParameterToBeUpdated, copyofOriginalDetail);
						_DataBase.updateTextFile(_filename);
						setTaskList();

					} else {
						_feedbackMessage = FEEDBACK_TASK_UPDATED_SUCCESSFULLY;
					}
				} 
			}
		} else if (parameterToBeUpdated == "priority"){
			if (detailToBeUpdated == "") {
				_feedbackMessage = ERROR_NO_CONTENT;
			} else {
				_DataBase.updateTask(_filename, updateInteger, parameterToBeUpdated, detailToBeUpdated);
				_DataBase.updateTextFile(_filename);
				setTaskList();
				_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
			}
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "delete") {
		int deleteInteger = Input.getDeleteInteger();

		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else if (deleteInteger > _storageTaskListCopy.size() || deleteInteger <= 0) {
			_feedbackMessage = ERROR_TASK_DELETED_UNSUCCESSFULLY;

		} else {
			_DataBase.deleteTask(_filename, deleteInteger);
			_DataBase.updateTextFile(_filename);
			setTaskList();
			_feedbackMessage = FEEDBACK_TASK_DELETED_SUCCESSFULLY;
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "save") {
		string userDirectory = Input.getuserdir();
		
		changeFileDirectory(userDirectory);

		updatefileLocation(userDirectory);

		writeFileLocation(_fileLocation);
		_feedbackMessage = userDirectory;
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	}  else if (command == "mark") {
		int markIndex = Input.getmarkindex();
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else if (markIndex > _storageTaskListCopy.size() || markIndex <= 0) {
			_feedbackMessage = ERROR_TASK_MARKED_UNSUCCESSFULLY;

		} else {
			_DataBase.markTask(_filename, markIndex);
			_DataBase.updateTextFile(_filename);
			setTaskList();
			_feedbackMessage = FEEDBACK_TASK_MARKED_SUCCESSFULLY;
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "unmark") {
		int unmarkIndex = Input.getmarkindex();
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else if (unmarkIndex > _storageTaskListCopy.size() || unmarkIndex <= 0) {
			_feedbackMessage = ERROR_TASK_UNMARKED_UNSUCCESSFULLY;

		} else {
			_DataBase.unmarkTask(_filename, unmarkIndex);
			_DataBase.updateTextFile(_filename);
			setTaskList();
			_feedbackMessage = FEEDBACK_TASK_UNMARKED_SUCCESSFULLY;
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "clear") {
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else {
			_DataBase.clearAllTasks();
			setTaskList();
			_DataBase.updateTextFile(_filename);
			_feedbackMessage = FEEDBACK_CLEAR_ALL_TASKS;
			_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
		}
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "undo") {
		_DataBase.undoAction();
		_DataBase.updateTextFile(_filename);
		setTaskList();
		_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	} else if (command == "sort") {
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else {
			_DataBase.sortTaskByName(_filename);
			_DataBase.updateTextFile(_filename);
			setTaskList();
			_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
			_Logic_LogFile.writeToLogFile(_feedbackMessage);
		}

	} else if (command == "view-c") {
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else {
			_DataBase.viewCompletedTasks();
			vector<Task> tempTaskList = getCompletedTaskList();
			if (tempTaskList.empty()){
				setTaskList();
			} else {
				setCompletedTaskList();
			}

			_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
			_Logic_LogFile.writeToLogFile(_feedbackMessage);
		}

	} else if (command == "view-i") {
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else {

			_feedbackMessage = _DataBase.returnLogicFeedbackMessage();
			_Logic_LogFile.writeToLogFile(_feedbackMessage);
		}

	} else if (command == "view") {
		if (_storageTaskListCopy.empty()) {
			_feedbackMessage = ERROR_EMPTY_LIST;
		} else {
			_DataBase.updateTextFile(_filename);
			setTaskList();
			_feedbackMessage = FEEDBACK_VIEW_ALL_SUCCESSFULLY;
			_Logic_LogFile.writeToLogFile(_feedbackMessage);
		}

	} else {
		_feedbackMessage = ERROR_INVALID_USERINPUT;
		_Logic_LogFile.writeToLogFile(_feedbackMessage);
	}

	return _feedbackMessage;
}

