#include <iostream>
#include <sstream>
#include "..\Logic\Logic.h"
#include <direct.h>

using namespace std;

//static string filename = "gantian.txt";

int main(){

	Logic TSlogic;
	TSlogic.Welcome();
	cout << "Hello testing" << endl;
	cout << "Your TaskSotong is currently at: " << TSlogic.getExePath() << endl;

	TSlogic.setFileName("taskSotong.txt");
	string filename = TSlogic.getFileName();

	TSlogic.callInitialise(filename);
	TSlogic.CommandPrompt();
	string userInput = TSlogic.getUserInput();


	while (userInput != "exit"){

		paraList* storageInput = TSlogic.getParaList(userInput);
		string command = storageInput->getCommand();
		Task task = storageInput->getTask();
		string taskname = task.getTaskName();

		TSlogic.executeCommand(*storageInput);

		cout << endl;
		TSlogic.CommandPrompt();

		userInput = TSlogic.getUserInput();

	}


	system("pause");
	return 0;



}
