#include "..\..\Logic\Logic\Logic.h"

#include <iostream>

using namespace std;

int main(){

	Logic TSlogic;
	TSlogic.Welcome();

	string userInput = TSlogic.getUserInput();
	cout <<"from UI"<< userInput << endl;

	//everything above can work...//
    paraList storageInput = TSlogic.getParaList(userInput);

	string command = storageInput.getCommand();
	Task* temptask = storageInput.getTask();

	cout << "Parser: " << command << endl;

	system("pause");
	return 0;

}