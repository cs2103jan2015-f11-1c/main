#include "Logic.h"
#include "Shlwapi.h"
#include <windows.h>
#include <direct.h>
#include <stack>


using namespace std;

string Logic::getUserInput(){
	return UserInterface.acceptUserInput();
}

void Logic::Welcome(){
	UserInterface.displayWelcomeMessage();
	return;
}

string Logic::getExePath(){

	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);

}

/*bool Logic::validDirectory(string userFileDirectory){

int index = userFileDirectory.find_last_of('\\');
string input = userFileDirectory.substr(0, index);
char buffer_1[100];

strcpy_s(buffer_1, input.c_str());

char *lpStr1;
lpStr1 = buffer_1;
int retval;

retval = PathFileExists(lpStr1);
if (retval == 1)
{
cout << "Search for the file path of : " << lpStr1 << endl;
cout << "The file requested \"" << lpStr1 << "\" is a valid file" << endl;
cout << "The return from function is : " << retval << endl;
return true;
}

else
{
cout << "\nThe file requested " << lpStr1 << " is not a valid file" << endl;
cout << "The return from function is : " << retval << endl;
return false;
}


}
*/

void Logic::createNewDirectory(string userFileDirectory){

	int index = userFileDirectory.find_last_of('\\');
	int index2 = userFileDirectory.find_first_of('\\');
	string inputDirectory = userFileDirectory.substr(0, index);

	stack<string> directoryParts;
	int firstIndex = inputDirectory.find_last_of('\\');
	while (firstIndex != -1){

		firstIndex = inputDirectory.find_last_of('\\');
		string temp = inputDirectory.substr(firstIndex, inputDirectory.size() - 1);

		if (temp == "\\"){

		}
		else{
			directoryParts.push(temp);
		}

		inputDirectory = inputDirectory.substr(0, firstIndex);

		firstIndex = inputDirectory.find_last_of('\\');
	}

	directoryParts.push(inputDirectory);

	string directory = directoryParts.top();
	directoryParts.pop();

	while (!directoryParts.empty()){
		cout << directory << endl;
		cout << directoryParts.top() << endl;
		directory = directory + directoryParts.top();
		_mkdir(directory.c_str());
		directoryParts.pop();


	}

	return;
}

void Logic::changeFileDirectory(string userFileDirectory){

	createNewDirectory(userFileDirectory);
	_filename = userFileDirectory;
	//"C:\ts\ts1\gt.txt";

	return;

}

void Logic::processChangeDirectoryRequest(string userFileDirectory){

		cout << "you want to save it here? " << userFileDirectory << endl;
		changeFileDirectory(userFileDirectory);
	return;

}

void Logic::setFileName(string updatedFileName){
	_filename = updatedFileName;
	return;
}


string Logic::getFileName(){
	return _filename;
}

void Logic::CommandPrompt(){
	UserInterface.displayPromptInputMessage();
	return;
}

paraList* Logic::getParaList(string userInput){

	return ParserComponent.parseCommand(userInput);
}


string Logic::getCommand(paraList parameterList){
	string command = parameterList.getCommand();
	transform(command.begin(), command.end(), command.begin(), tolower);
	return command;

}

Task Logic::getTask(paraList parameterList){
	return parameterList.getTask();
}

void Logic::copyTestFilefromStorage(){
	textFileCopy_fromStorage = getTextFileCopy();
	return;
}

vector<string> Logic::getTextFileCopy(){
	return DataBase.returnTextFileCopy();
}

void Logic::callInitialise(string outputFile){
	DataBase.initialiseTextFile(outputFile);
}

bool Logic::notExistingTask(Task* task){
	string taskDetail;
	taskDetail = task->getTaskDetails();
	for (unsigned int i = 0; i < textFileCopy_fromStorage.size(); i++){
		if (taskDetail == textFileCopy_fromStorage[i]){
			return false;
		}
	}
	return true;
}

void Logic::executeCommand(paraList Input, string outputFile){

	string command = Input.getCommand();

	Task oneTask = Input.getTask();

	if (command == "invalid"){
		UserInterface.displayInvalidCommandMessage();
	}
	else if (command == "add"){
		if (notExistingTask(&oneTask)){
			DataBase.addTask(&oneTask);
			DataBase.updateTextFile(outputFile);
			UserInterface.displaySuccessfulAddMessage();
		}
		else{
			cout << "Existing Task! Please enter a new task! :(" << endl;
		}
	}
	else if (command == "display"){
		DataBase.displayAllTasks();
		DataBase.updateTextFile(outputFile);
	}
	else if (command == "update"){
		int updateInteger = Input.getUpdateInteger();
		string keyword1 = Input.getKeyword();
		string detail = Input.getInput();
		DataBase.updateTask(updateInteger, keyword1, detail);
		DataBase.updateTextFile(outputFile);
		UserInterface.displaySuccessfulUpdateMessage();

	}
	else if (command == "delete"){
		int deleteInteger = Input.getDeleteInteger();
		DataBase.deleteTask(deleteInteger);
		DataBase.updateTextFile(outputFile);
		UserInterface.displaySuccessfulDeleteMessage();
	}
	else if (command == "save"){

		string userDirectory = Input.getuserdir();
		cout << "parser's directory: " << endl;
		processChangeDirectoryRequest(userDirectory);
	}
	else if (command == "mark"){
		int markIndex = Input.getmarkindex();
		DataBase.markTask(markIndex, "mark");
		DataBase.updateTextFile(outputFile);
	}
	else if (command == "unmark"){

		int markIndex = Input.getmarkindex();
		DataBase.markTask(markIndex, "unmark");
		DataBase.updateTextFile(outputFile);
	
	}
	else if (command == "clear"){
		DataBase.clearAllTasks();
	}
	else if (command == "undo"){
		DataBase.undoAction();
		DataBase.updateTextFile(outputFile);
	}

	return;
}

