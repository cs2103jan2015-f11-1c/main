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

string UI::acceptUserInput() {

	string userInput;
	cin >> userInput;
	return userInput;
}