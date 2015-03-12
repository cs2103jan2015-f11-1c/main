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

void Logic::callInitialise(string outputFile){
	DataBase.initializeVector2(outputFile);
}

void Logic::executeCommand(paraList Input, string outputFile){
	
	string command = getCommand(Input);
	Task oneTask = getTask(Input);
	//DataBase.initializeVector2(outputFile);
	if (command == "add"){
		DataBase.addTask(&oneTask, outputFile);
		DataBase.updateTextFile(outputFile);
		cout << "Task Added Succefully!" << endl;
	}else if (command == "display"){
		DataBase.displayAllTasks();
	}
	/*
	else if (command == "update"){
		DataBase.updateTask();
	}
	else if (command == " delete"){
		DataBase.deleteTask();
	}
	*/
	return;
	}

