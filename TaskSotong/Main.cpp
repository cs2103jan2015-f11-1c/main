#include <iostream>
#include <sstream>
#include "..\Logic\Logic.h"
#include <direct.h>

using namespace std;

int main(){

	Logic TSlogic;
	TSlogic.Welcome();
	
	TSlogic.initialiseFileLocationFile();
	cout << "finish initialising?" << endl;
	bool areInTheSameLocation=TSlogic.checkIfFileIsAtExeLocation();
	cout << "bool check: " << areInTheSameLocation << endl;
	string filename;
	if (areInTheSameLocation == false) {
	
		string lastFileLocation = TSlogic.getLastFileLocation();
		TSlogic.setFileName(lastFileLocation);
	} else {

		cout << "exePath: " << TSlogic.getExePath() << endl;
		string exePath = TSlogic.getExePath()+"\\taskSotong.txt";
		cout << "new path: " << exePath << endl;
		TSlogic.setFileName(exePath);

	}
	filename = TSlogic.getFileName();
	
	cout << "Your TaskSotong is currently at: " << filename << endl;
	
	TSlogic.callInitialise(filename);
	TSlogic.CommandPrompt();
	string userInput = TSlogic.getUserInput();

	while (userInput != "exit"){

		paraList* storageInput = TSlogic.getParaList(userInput);
		string command = storageInput->getCommand();
		Task task = storageInput->getTask();
		//string taskname = task.getTaskName();

		TSlogic.executeCommand(*storageInput);

		cout << endl;
		TSlogic.CommandPrompt();

		userInput = TSlogic.getUserInput();

	}

	system("pause");
	return 0;
}

