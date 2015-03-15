#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifndef UI_H
#define UI_H

class UI {
private:

	string _welcomeMessage = "Welcome to TaskSotong!"; 
	string _exitMessage = "Goodbye!";

	string _promptInputMessage = "What would you like to do?";

	string _successfulAddMessage = " was added successfully!";
	string _successfulUpdateMessage = " was updated successfully!";
	string _successfulDeleteMessage = " was deleted successfully!";
	string _successfulSortMessage = "Sorted!"

	string _invalidCommandMessage = "Error, command not recognized. Please enter a valid command! (add, update, delete, sort, exit)";
	string _deleteErrorMessage = "Error. Please enter a valid index!";
	string _updateCompletedStatusErrorMessage = "Error. Task already marked as \"completed\"";
	string _updateNotCompletedStatusErrorMessage = "Error. Task already marked as \"not completed\"";


public:

	void displayWelcomeMessage();
	void displayExitMessage();
	void displayPromptInputMessage();

	void displaySuccessfulAddMessage(string taskName);
	void displaySuccessfulUpdateMessage(string taskName);
	void displaySuccessfulDeleteMessage(string taskName);
	void displaySuccessfulSortMessage();

	void displayInvalidCommandMessage();
	void displayDeleteErrorMessage();
	void displayUpdateCompletedStatusErrorMessage();
	void displayUpdateNotCompletedStatusErrorMessage();

	void displayTaskList(vector<string> taskList);

	string acceptUserInput();
};

#endif