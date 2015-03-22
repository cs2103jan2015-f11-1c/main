#include "Logic.h"

using namespace std;

string Logic::getUserInput(){
	CommandPrompt();
	return UserInterface.acceptUserInput();
}

void Logic::Welcome(){
	UserInterface.displayWelcomeMessage();
	return;
}

void Logic::CommandPrompt(){
	UserInterface.displayPromptInputMessage();
	return;
}

paraList* Logic::getParaList(string userInput){

	return ParserComponent.parseCommand(userInput);
}


string Logic::getCommand(paraList parameterList){
	string command=parameterList.getCommand();
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
	}else if (command == "add"){
		if (notExistingTask(&oneTask)){
			DataBase.addTask(&oneTask);
			DataBase.updateTextFile(outputFile);
			UserInterface.displaySuccessfulAddMessage();
		}
		else{
			cout << "Existing Task! Please enter a new task! :(" << endl;
		}
	}else if (command == "display"){
		DataBase.displayAllTasks();
		DataBase.updateTextFile(outputFile);
	}else if (command == "update"){
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
	
	return;
	}

