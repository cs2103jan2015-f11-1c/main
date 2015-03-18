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

vector<string> Logic::getTextFileCopy(){
	return DataBase.returnTextFileCopy();

}

void Logic::callInitialise(string outputFile){
	DataBase.initializeVector2(outputFile);
}

void Logic::executeCommand(paraList Input, string outputFile){
	
	string command = Input.getCommand();
	
	Task oneTask = Input.getTask();

	if (command == "invalid"){
		UserInterface.displayInvalidCommandMessage();
	}else if (command == "add"){
		DataBase.addTask(&oneTask);
		DataBase.updateTextFile(outputFile);
		UserInterface.displaySuccessfulAddMessage();
	}else if (command == "display"){
		DataBase.displayAllTasks();
	}else if (command == "update"){
		int updateInteger = Input.getUpdateInteger();
		string keyword1 = Input.getKeyword();
		string detail = Input.getInput();
		DataBase.updateTask(updateInteger, keyword1, detail);
		UserInterface.displaySuccessfulUpdateMessage();

	}
	else if (command == "delete"){
		int deleteInteger = Input.getDeleteInteger();
		DataBase.deleteTask(deleteInteger);
		UserInterface.displaySuccessfulDeleteMessage();
	}
	
	return;
	}

