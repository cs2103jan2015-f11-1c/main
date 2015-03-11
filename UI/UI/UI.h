#include <iostream>
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

	string _invalidCommandMessage = "Error, command not recognized. Please enter a valid command! (add, update, delete, sort, exit)";
	string _deleteErrorMessage = "Error. Please enter a valid index!"

public:

	void displayWelcomeMessage();
	void displayExitMessage();
	void displayPromptInputMessage();

	void displayInvalidCommandMessage();
	void displayDeleteErrorMessage();

	void displayTask(vector<string> taskString);

	string acceptUserInput();
};

#endif