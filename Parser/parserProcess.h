#ifndef PARSERPROCESS_H
#define PARSERPROCESS_H

#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include "..\Common\Task.h"

using namespace std;

class parserProcess{

private:
	string dateStore;
	string timeStore;
	int numDateStore;
	int numTimeStore;

public:
	enum Date {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY ,SUNDAY };
	enum Time {JAN,FEB,MAR,APR,JUN,JUL,AUG,SEPT,OCT,NOV,DEC};
	void processLine(string);
	bool addition(string);
	bool subtraction(string);



};

#endif
