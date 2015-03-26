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
	cout << "Do you want to change saving file directory? [Y/N]" << endl;

	TSlogic.processChangeDirectoryRequest();
	string filename = TSlogic.getFileName();

	TSlogic.callInitialise(filename);

	string userInput = TSlogic.getUserInput();


	while (userInput != "exit"){

		paraList* storageInput = TSlogic.getParaList(userInput);
		string command = storageInput->getCommand();
		Task task = storageInput->getTask();
		string taskname = task.getTaskName();

		TSlogic.executeCommand(*storageInput, filename);

		cout << endl;
		TSlogic.CommandPrompt();

		userInput = TSlogic.getUserInput();

	}


	system("pause");
	return 0;



}

/*
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

TSlogic.callInitialise(filename);

while (userInput != "exit"){

paraList* storageInput = TSlogic.getParaList(userInput);
string command = storageInput->getCommand();
Task task = storageInput->getTask();
string taskname = task.getTaskName();

TSlogic.executeCommand(*storageInput, filename);

userInput = TSlogic.getUserInput();
}

system("pause");
return 0;

}*/