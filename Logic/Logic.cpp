#include "Logic.h"
#include "Shlwapi.h"
#include <windows.h>
#include <direct.h>
#include <stack>


using namespace std;

string Logic::Error_invalidUserInput = "Invalid User Input. Please Enter Again! :<";
string Logic::FeedBack_taskAdded = "Task Added Successfully! :>";
string Logic::FeedBack_existingTask = "That Task Has Already Existed~! Please Enter A New Task~";
string Logic::FeedBack_displayAllTasks = "All Tasks Are Displayed!";
string Logic::FeedBack_updateTaskSuccessfully = "Task Updated Successfully!";
string Logic::FeedBack_updateTaskUnsuccessfully = "Failed To Update Task!";
string Logic::FeedBack_deleteTaskSuccessfully = "Task Deleted Successfully!";
string Logic::FeedBack_deleteTaskUnsuccessfully = "Failed To Delete The Task!";
string Logic::FeedBack_changeFileDirectory = "Saving directory changed! :D";
string Logic::FeedBack_MarkTaskSuccessfully = "Task Marked Completed! ";
string Logic::FeedBack_UnmarkTask = "Unmarked The Task!";
string Logic::FeedBack_ClearTask = "All Tasks Cleared!";
string Logic::FeedBack_UndoTask = "Undo Done! :D";
string Logic::FeedBack_SearchTask = "Search Result Displayed! :D";
string Logic::FeedBack_SortTasks = "Tasks Sorted Accordingly!";


string Logic::getUserInput() {
	return UserInterface.acceptUserInput();
}

void Logic::Welcome() {
	UserInterface.displayWelcomeMessage();
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
		//for debugging purpose
		//cout << directoryParts.top() << endl;
		directory = directory + directoryParts.top();
		_mkdir(directory.c_str());
		directoryParts.pop();
	}

	return;
}

void Logic::changeFileDirectory(string userFileDirectory) {

	createNewDirectory(userFileDirectory);
	setFileName(userFileDirectory);
	//"C:\ts\ts1\gt.txt";
	return;
}

void Logic::processChangeDirectoryRequest(string userFileDirectory) {
	changeFileDirectory(userFileDirectory);
	return;
}

void Logic::setFileName(string updatedFileName) {
	_filename = updatedFileName;
	return;
}


string Logic::getFileName() {
	return _filename;
}

void Logic::CommandPrompt() {
	UserInterface.displayPromptInputMessage();
	return;
}

paraList* Logic::getParaList(string userInput) {

	return ParserComponent.parseCommand(userInput);
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
	textFileCopy_fromStorage = getTextFileCopy();
	return;
}

vector<string> Logic::getTextFileCopy() {
	return DataBase.returnTextFileCopy();
}

void Logic::callInitialise(string outputFile) {
	DataBase.initialiseTextFile(outputFile);
}

bool Logic::notExistingTask(Task* task) {
	string taskDetail;
	taskDetail = task->getTaskDetails();
	copyTestFilefromStorage();
	for (unsigned int i = 0; i < textFileCopy_fromStorage.size(); i++) { 
		if (taskDetail == textFileCopy_fromStorage[i]) {
			return false;
		}
	}
	return true;
}


string Logic::getFeedbackMsg() {
	return feedbackMessage;

}

void Logic::executeCommand(paraList Input) {

	string command = getLowerCaseCommand(Input);

	cout << "commmand= " << command << endl;
	//for (unsigned int i = 0; i < command.length(); ++i){
	//	command[i] == tolower(command[i]);
	//}
	
	if (command == "invalid") {

		feedbackMessage = Error_invalidUserInput;

	} else if (command == "add") {
		Task oneTask = Input.getTask();
		string taskdetails = oneTask.getTaskDetails();
		cout << "taskdetails: " << taskdetails << endl;
		if (notExistingTask(&oneTask)==true) {
			DataBase.addTask(&oneTask);
			DataBase.updateTextFile(_filename);
			feedbackMessage = FeedBack_taskAdded;

		} else {
			feedbackMessage = FeedBack_existingTask;

		}
	} else if (command == "display") {
		DataBase.displayAllTasks();
		DataBase.updateTextFile(_filename);
		feedbackMessage = FeedBack_displayAllTasks;

	} else if (command == "update") {
		int updateInteger = Input.getUpdateInteger();
		string keyword1 = Input.getKeyword();
		string detail = Input.getInput();

		copyTestFilefromStorage();
		if (updateInteger >= textFileCopy_fromStorage.size()||updateInteger<=0) {
			feedbackMessage = FeedBack_updateTaskUnsuccessfully;

		} else {
			DataBase.updateTask(_filename, updateInteger, keyword1, detail);
			DataBase.updateTextFile(_filename);
			feedbackMessage = FeedBack_updateTaskSuccessfully;
		
		}

	} else if (command == "delete") {
		int deleteInteger = Input.getDeleteInteger();
		copyTestFilefromStorage();
		if (deleteInteger >= textFileCopy_fromStorage.size() || deleteInteger <= 0) {
			feedbackMessage = FeedBack_deleteTaskUnsuccessfully;
		
		} else {
			DataBase.deleteTask(_filename, deleteInteger);
			DataBase.updateTextFile(_filename);
			feedbackMessage = FeedBack_deleteTaskSuccessfully;
		
		}

	} else if (command == "save") {
		string userDirectory = Input.getuserdir();
		processChangeDirectoryRequest(userDirectory);
		feedbackMessage = FeedBack_changeFileDirectory;

	} else if (command == "mark") {
		int markIndex = Input.getmarkindex();
		DataBase.markTask(_filename, markIndex);
		DataBase.updateTextFile(_filename);
		feedbackMessage = FeedBack_MarkTaskSuccessfully;

	} else if (command == "unmark") {
		int markIndex = Input.getmarkindex();
		DataBase.unmarkTask(_filename, markIndex);
		DataBase.updateTextFile(_filename);
		feedbackMessage = FeedBack_UnmarkTask;

	} else if (command == "clear") {
		DataBase.clearAllTasks();
		feedbackMessage = FeedBack_ClearTask;

	} else if (command == "undo") {
		DataBase.undoAction();
		DataBase.updateTextFile(_filename);
		feedbackMessage = FeedBack_UndoTask;

	} else if (command == "search") {
		//string searchKeyWord= Input
		feedbackMessage = FeedBack_SearchTask;

	} else if (command == "sort") {
		DataBase.sortTaskByName(_filename);
		DataBase.updateTextFile(_filename);
		feedbackMessage = FeedBack_SortTasks;

	}

	return;
}

