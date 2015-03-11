#include "..\..\Logic\Logic\Logic.h"

#include <iostream>

using namespace std;

int main(){

	Logic TSlogic;
	TSlogic.Welcome();

	string userInput = TSlogic.getUserInput();
	cout << userInput << endl;

	//everything above can work...//
	//string storageInput = TSlogic.ParseUserInput(userInput);

	//string command = storageInput.getCommand();
	//Task temptask = storageInput.getTask();

	//cout << "Parser: " << storageInput << endl;

	system("pause");
	return 0;

}