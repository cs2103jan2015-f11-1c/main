//@author A0113555L

#include "Log.h"

void Log::writeToLogFile(string stringToBeLogged) {

	ofstream writeFile("log.txt", ios::app);
	writeFile << stringToBeLogged<< endl;

	writeFile.close();
}

void Log::clearLogFile() {


	ofstream writeFile("log.txt");
	writeFile.close();
}