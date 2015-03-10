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

/*void Logic::executeCommand(paraList){
	DataBase.addTask();
}
*/

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