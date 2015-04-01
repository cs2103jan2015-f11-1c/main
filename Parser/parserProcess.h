#ifndef PARSERPROCESS_H
#define PARSERPROCESS_H

#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <atltime.h>
#include "..\Common\Task.h"

using namespace std;




struct dateStore{

	int day;
	int month;
	int year;
	string dayName;
	int dayNameRef;
	
};

struct timeStore
{

    int min;
	int hours;
	string timeStatus;



};


struct nowDTstore{


	int day;
	int month;
	int year;
	string dayName;
	int dayNameRef;
	int min;
	int hour;
	bool isLongMonth;
};




class parserProcess{

private:
	string rawDateStore;
	string rawTimeStore;
	dateStore processedDateStore;
	timeStore processedtimeStore;
	nowDTstore nowDT;

public:
	enum dayName {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY ,SUNDAY };
	enum Time {JAN,FEB,MAR,APR,JUN,JUL,AUG,SEPT,OCT,NOV,DEC};
	enum datekeyWord { DAY_NAME , DAY_NUM , DAY_NATURALISED};
	enum natExp{ TODAY,YEST,TMR};
	void processDate(string);
	void processTime(string);
	bool addition(string);
	bool subtraction(string);
	void processCommandType();
	void processDate(string&);
	void processDateNatExp(string&);
	void processDateName(string&);
	void processDateNum(string&);
	void processTime();
	void setNowDT();
	void setRawDT(string&,string&);
	bool monthDayIndicator(int&); //true for 31 days, false for 30 days 
	void processMonthMoreDays(int&, int&, dateStore&);
	void processMonthLessDays(int&, int&, dateStore&);
	void addDayCalc(int, int);
	void addMonthCalc(int&, int&);
    datekeyWord sortDateType(string&);
	dayName sortDayName(string&);
    dateStore dateNumCalculator(int&, int&);
	natExp sortNatExp(string&);
		
};

#endif
