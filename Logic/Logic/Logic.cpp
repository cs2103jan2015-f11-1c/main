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
	cout << "calling get command" << endl;
	string command=parameterList.getCommand();
	cout << "get command" << endl;
	transform(command.begin(), command.end(), command.begin(), tolower);
	cout << "after transform" << endl;
	return command;

}

Task Logic::getTask(paraList parameterList){
	return parameterList.getTask();
}


void Logic::executeCommand(paraList Input, string outputFile){
	cout << "before get command" << endl;
	string command = getCommand(Input);
	cout << "inbtw command" << endl;
	Task oneTask = getTask(Input);

	if (command == "add"){
		cout << "testing" << endl;
		DataBase.addTask(&oneTask, outputFile);
	}
	/*else if (command == "display"){
		DataBase.displayTask();
	}
	else if (command == "update"){
		DataBase.updateTask();
	}
	else if (command == " delete"){
		DataBase.deleteTask();
	}
	*/
	return;
	}

