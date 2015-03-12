#include "..\..\Logic\Logic\Logic.h"

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv){

	string filename;
	if (argc < 2) {
		cout << "need filename!" << endl;
	}
	
	for (int i = 0; i < strlen(argv[1]); i++) {
		filename += argv[1][i];
	}

	Logic TSlogic;
	TSlogic.Welcome();
	
	string userInput = TSlogic.getUserInput();

	//everything above can work...//
    paraList* storageInput = TSlogic.getParaList(userInput);
	
	string command=storageInput->getCommand();
	Task task = storageInput->getTask();

	cout <<endl<< "before execureCommand" << endl;

	//this line got problem
	TSlogic.executeCommand(*storageInput, filename);

	system("pause");
	return 0;

}