#include <iostream>
#include <string>

using namespace std;

#ifndef UI_H
#define UI_H

class UI {
private:

	string _welcomeMessage = "Welcome to TaskSotong!"; 
	string _exitMessage = "Goodbye!";
	string _promptInputMesssage = "What would you like to do?";

public:

	void displayWelcomeMessage();
	void displayExitMessage();
	void displayPromptInputMessage();

	string acceptUserInput();
};

#endif