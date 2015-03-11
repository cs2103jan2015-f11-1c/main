#include "Logic.h"

using namespace std;

string Logic::getUserInput(){
	return UserInterface.acceptUserInput();
}

void Logic::Welcome(){
	UserInterface.displayWelcomeMessage();
	return;
}

string Logic::ParseUserInput(string userInput){

	 return ParserComponent.parseCommand(userInput);
	
}

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






}


int main(){

	Logic TSlogic;
	TSlogic.Welcome();

	string userInput = TSlogic.getUserInput();
	cout << userInput << endl;

	//everything abover can work...//
	string storageInput = TSlogic.ParseUserInput(userInput);

	//string command = storageInput.getCommand();
	//Task temptask = storageInput.getTask();

	cout << "Parser: "<<storageInput << endl;

	system("pause");
	return 0;

}