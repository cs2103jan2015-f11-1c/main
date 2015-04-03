#include "Logic.h"
#include "Shlwapi.h"
#include <windows.h>
#include <direct.h>
#include <stack>


using namespace std;

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

string Logic::getCommand(paraList parameterList) {
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

void Logic::executeCommand(paraList Input) {

	string command = Input.getCommand();

	Task oneTask = Input.getTask();

	if (command == "invalid") {

		UserInterface.displayInvalidCommandMessage();

	} else if (command == "add") {
		if (notExistingTask(&oneTask)==true) {
			DataBase.addTask(&oneTask);
			DataBase.updateTextFile(_filename);
			UserInterface.displaySuccessfulAddMessage();
		} else {

			cout << "Existing Task! Please enter a new task! :(" << endl;
		}
	} else if (command == "display") {
		DataBase.displayAllTasks();
		DataBase.updateTextFile(_filename);
	} else if (command == "update") {
		int updateInteger = Input.getUpdateInteger();
		string keyword1 = Input.getKeyword();
		string detail = Input.getInput();
		DataBase.updateTask(updateInteger, keyword1, detail);
		DataBase.updateTextFile(_filename);
		UserInterface.displaySuccessfulUpdateMessage();
	} else if (command == "delete") {
		int deleteInteger = Input.getDeleteInteger();
		DataBase.deleteTask(deleteInteger);
		DataBase.updateTextFile(_filename);
		UserInterface.displaySuccessfulDeleteMessage();
	} else if (command == "save") {

		string userDirectory = Input.getuserdir();
		processChangeDirectoryRequest(userDirectory);
		cout << "Saving derectory changed! :D" << endl;
	} else if (command == "mark") {
		int markIndex = Input.getmarkindex();
		DataBase.markTask(markIndex, "mark");
		DataBase.updateTextFile(_filename);
	} else if (command == "unmark") {

		int markIndex = Input.getmarkindex();

		DataBase.markTask(markIndex, "unmark");
		DataBase.updateTextFile(_filename);
	} else if (command == "clear") {
		DataBase.clearAllTasks();
	} else if (command == "undo") {
		DataBase.undoAction();
		DataBase.updateTextFile(_filename);
	}

	return;
}

