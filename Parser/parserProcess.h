//@author A0111642W
#ifndef PARSERPROCESS_H
#define PARSERPROCESS_H

#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <atltime.h>
#include <sstream> 
#include "..\Common\Task.h"
#include "..\TaskSotong_Log\Log.h"


using namespace std;




struct dateStore{

	string dayName;
	int dayNameRef;
	int additionDay;
    int day;
	int month;
	int year;
};

struct timeStore
{

	string nilstore;
	string timeStatus;
	int min;
	int hours;

};


struct nowDTstore{

	string dayName;
	bool isLongMonth;
	int day;
	int month;
	int year;
	int dayNameRef;
	int min;
	int hour;
	
};




class parserProcess{

private:
	string rawDateStore;
	string rawTimeStore;
	dateStore processedDateStore;
	timeStore processedtimeStore;
	nowDTstore nowDT;

public:

	enum dayName { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
	enum Time { JAN, FEB, MAR, APR, JUN, JUL, AUG, SEPT, OCT, NOV, DEC };
	enum datekeyWord { DAY_NAME, DAY_NUM, DAY_NATURALISED };
	enum timeKeyWord { SHORT_AM_PM, AM_PM, NIL, OCLOCK };
	enum natExp{ TODAY, YEST, TMR };
	bool addition(string);
	bool subtraction(string);
	void processDate(string);
	void processTime(string);
	void processCommandType();	
	void processDateName(string&);
	void processDateNum(string&);
	void processTimeAmPm(string&);
	void processTimeNil(string&);
	void processTimeNatExp(string&);
	void processTimeShortAmPm(string&);
	void processMonthMoreDays(int&, int&, dateStore&);
	void processMonthLessDays(int&, int&, dateStore&);
	void setNowDT();
	void setRawDT(string&, string&);
	bool monthDayIndicator(int&); //true for 31 days, false for 30 days 
	void addDayCalc(int, int);
	void printProcessed();
	void printNow();
	void covertTime(char&, int&);
	void clearTimestore();
	datekeyWord sortDateType(string&);
	dayName sortDayName(string&);
	dateStore dateNumCalculator(int&, int&);
	timeKeyWord sortTimeKeyWord(string&);
	natExp sortNatExp(string&);
	string parserReturnDate();
	string parserReturnTime();
	string parserReturnNowTime();

	Log _ParserProcess_LogFile;
	
};

#endif
