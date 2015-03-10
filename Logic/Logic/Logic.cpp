#include "Logic.h"



using namespace std;

string Logic::getUserInput(){
	return UserInterface.acceptUserInput();
}

void Logic::Welcome(){
	UserInterface.displayWelcomeMessage();
	return;
}

paraList Logic::ParseUserInput(string userInput){

	 return ParserComponent.parseCommand(userInput);
	
}

int main(){

	Logic TSlogic;
	TSlogic.Welcome();

	string userInput = TSlogic.getUserInput();
	cout << userInput << endl;

	//everything abover can work...//
	paraList ParameterList = TSlogic.ParseUserInput(userInput);




	system("pause");
	return 0;

}