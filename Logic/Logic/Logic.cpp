#include "Logic.h"

using namespace std;

string Logic::getUserInput(){
	return UserInterface.acceptUserInput();
}

void Logic::Welcome(){
	UserInterface.displayWelcomeMessage();
	return;
}

//void Logic::ParseUserInput(string userInput){

	// return ParserComponent.parseCommand(userInput);
	
//}

string getCommand(paraList parameterList){
	string command=parameterList.getCommand();
	transform(command.begin(), command.end(), command.begin(), tolower);
	return command;

}
Task getTask(paraList parameterList){
	return parameterList.getTask();
}


void executeCommand(string command){
	if (command == "add"){

	
	
	
	
	
	
	}





	return;
}
