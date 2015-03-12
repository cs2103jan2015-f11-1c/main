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
	while (userInput != "exit"){
		paraList* storageInput = TSlogic.getParaList(userInput);
		string command = storageInput->getCommand();
		Task task = storageInput->getTask();
		string taskname = task.getTaskName();
		cout << "second name: " << taskname << endl;

		//this line got problem
		TSlogic.executeCommand(*storageInput, filename);
		userInput = TSlogic.getUserInput();
	}

	system("pause");
	return 0;

}