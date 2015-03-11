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

paraList Logic::getParaList(string userInput){

	return ParserComponent.parseCommand(userInput);
}



/*void Logic::writeFile(vector<Task*> TaskList, string outputFile){
	ofstream writeFile(outputFile);
	for (int i = 0; i < TaskList.size(); i++){
		writeFile << TextBuddyContent[i] << endl;
	}
	writeFile.close();
}
*/

string Logic::getCommand(paraList parameterList){
	string command=parameterList.getCommand();
	transform(command.begin(), command.end(), command.begin(), tolower);
	return command;

}

Task* Logic::getTask(paraList parameterList){
	return parameterList.getTask();
}

/*
void Logic::executeCommand(paraList Input){
	string command = getCommand(Input);
	Task oneTask = getTask(Input);

	if (command == "add"){
		Task tempTask = getTask();
		DataBase.addTask(oneTask);
	}
	else if (command == "display"){
		DataBase.displayTask();
	}
	else if (command == "update"){
		DataBase.updateTask();
	}
	else if (command == " delete"){
		DataBase.deleteTask();
	}
	
	return;
	}

	*/