#include "..\..\Logic\Logic\Logic.h"

#include <iostream>

using namespace std;

int main(){

	Logic TSlogic;
	TSlogic.Welcome();

	string userInput = TSlogic.getUserInput();
	cout <<"from UI"<< userInput << endl;

	//everything above can work...//
    paraList* storageInput = TSlogic.getParaList(userInput);
	string command=storageInput->getCommand();
	
	Task task = storageInput->getTask();

	string abc = task.getTaskName();
	string adf = task.getTaskStartDate();
	string b = task.getTaskStartTime();
	string c = task.getTaskEndDate();
	string d = task.getTaskEndTime();

	cout << "test " <<abc <<endl<<c<<endl<<d<< endl;

	system("pause");
	return 0;

}