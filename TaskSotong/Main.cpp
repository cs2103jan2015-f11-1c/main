#include <iostream>
#include <sstream>
#include "..\Logic\Logic.h"
#include <direct.h>

using namespace std;

int main(){

	Logic TSlogic;
	TSlogic.initialiseSetUp();
	string userInput = TSlogic.getUserInput();

	while (userInput != "exit"){

		paraList* storageInput = TSlogic.getParaList(userInput);
	
		//string taskname = task.getTaskName();

		TSlogic.executeCommand(*storageInput);

		cout << endl;
		TSlogic.CommandPrompt();

		userInput = TSlogic.getUserInput();

	}

	system("pause");
	return 0;
}

