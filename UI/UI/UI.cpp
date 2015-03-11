#include "UI.h"

void UI::displayWelcomeMessage() {

	cout << _welcomeMessage;
	return;
}

void UI::displayExitMessage() {

	cout << _exitMessage;
	return;
}

void UI::displayPromptInputMessage() {

	cout << _promptInputMessage;
	return;
}

void UI::displayInvalidCommandMessage() {

	cout << _invalidCommandMessage;
	return;
}

void UI::displayDeleteErrorMessage() {

	cout << _deleteErrorMessage;
	return;
}



void UI::displayTask(vector<string> taskString) {

	vector<string>::iterator iter;
	for(iter = taskString.begin(); iter != taskString.end(); ++iter) {
		cout << *iter << " ";
	}

	return;
}

string UI::acceptUserInput() {

	string userInput;
	getline(cin, userInput);
	return userInput;
}