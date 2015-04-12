#ifndef LOG_H
#define LOG_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Log {
private:

public:
	void writeToLogFile(string);
	void clearLogFile();
};
#endif