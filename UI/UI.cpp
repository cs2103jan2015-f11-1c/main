#include "UI.h"

void UI::displayWelcomeMessage() {

	cout << _welcomeMessage << endl;
	return;
}

void UI::displayExitMessage() {

	cout << _exitMessage << endl;
	return;
}

void UI::displayPromptInputMessage() {

	cout << _promptInputMessage << endl;
	return;
}

void UI::displaySuccessfulAddMessage() {

	cout << _successfulAddMessage << endl;
	return;
}

void UI::displaySuccessfulUpdateMessage() {

	cout << _successfulUpdateMessage << endl;
	return;
}

void UI::displaySuccessfulDeleteMessage() {

	cout << _successfulDeleteMessage << endl;
	return;
}

void UI::displaySuccessfulSortMessage() {

	cout << _successfulSortMessage << endl;
	return;
}

void UI::displayInvalidCommandMessage() {

	cout << _invalidCommandMessage << endl;
	return;
}

void UI::displayDeleteErrorMessage() {

	cout << _deleteErrorMessage << endl;
	return;
}

void UI::displayUpdateCompletedStatusErrorMessage() {

	cout << _updateCompletedStatusErrorMessage << endl;
	return;
}

void UI::displayUpdateNotCompletedStatusErrorMessage() {

	cout << _updateNotCompletedStatusErrorMessage << endl;
	return;
}

void UI::displayTaskList(vector<string> taskList) {

	vector<string>::iterator iter;

	for(iter = taskList.begin(); iter != taskList.end(); ++iter) {
		cout << *iter << endl;
	}

	return;
}


string UI::acceptUserInput() {

	string userInput;
	getline(cin, userInput);
	return userInput;
}