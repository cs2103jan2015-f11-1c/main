#include "parserProcess.h"
#include <iostream>
#include <ctime>
#include <atltime.h>
#include <sstream> 



const regex MONTH_INPUT();
const regex DAY_INPUT("(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b", std::tr1::regex_constants::icase);
const regex TIME_INPUT("");
const regex KEYWORD_INPUT("");
const regex DATE_NATURALIZED("(t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(y(\\w+|)(e|s)(\\w+|)(t|r|y))", std::tr1::regex_constants::icase);
const regex DATE_NAME("(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b", std::tr1::regex_constants::icase);
const regex DATE_NUM("(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))", std::tr1::regex_constants::icase);
const regex JAN_INPUT("(januarys?\\b)|(jans?\\b)", std::tr1::regex_constants::icase);
const regex FEB_INPUT("(februarys?\\b)|(febs?\\b)", std::tr1::regex_constants::icase);
const regex MAR_INPUT("(marchs?\\b)|(mar?\\b)", std::tr1::regex_constants::icase);
const regex APR_INPUT("(aprils?\\b)|(aprl?s?\\b)", std::tr1::regex_constants::icase);
const regex MAY_INPUT("(mays?\\b)", std::tr1::regex_constants::icase);
const regex JUN_INPUT("(junes?\\b)|(jun?\\b)", std::tr1::regex_constants::icase);
const regex JUL_INPUT("(julys?\\b)|(juls?\\b)", std::tr1::regex_constants::icase);
const regex AUG_INPUT("(augusts?\\b)|(aug?\\b)", std::tr1::regex_constants::icase);
const regex SEPT_INPUT("(septembers?\\b)|(sept?s?\\b)", std::tr1::regex_constants::icase);
const regex OCT_INPUT("(octobers?\\b)|(octs?\\b)", std::tr1::regex_constants::icase);
const regex NOV_INPUT("(novembers?\\b)|(novs?\\b)", std::tr1::regex_constants::icase);
const regex DEC_INPUT("(decembers?\\b)|(decs?\\b)", std::tr1::regex_constants::icase);
const regex MONDAY_INPUT("(mondays?\\b)|(mons?\\b)", std::tr1::regex_constants::icase);
const regex TUESDAY_INPUT("(tues?days?\\b)|(tues?\\b)", std::tr1::regex_constants::icase);
const regex WEDNESDAY_INPUT("(wednesdays?\\b)|(weds?\\b)", std::tr1::regex_constants::icase);
const regex THURSDAY_INPUT("(thursdays?\\b)|(thurs?\\b)", std::tr1::regex_constants::icase);
const regex FRIDAY_INPUT("(fridays?\\b)|(fris?\\b)", std::tr1::regex_constants::icase);
const regex SATURDAY_INPUT("(saturdays?\\b)|(sats?\\b)", std::tr1::regex_constants::icase);
const regex SUN_INPUT("(sundays?\\b)|(suns?\\b)", std::tr1::regex_constants::icase);
const regex TODAY_INPUT("(t(o+|)d(a+|)(y))", std::tr1::regex_constants::icase);
const regex TMR_INPUT("(t(\\w+|)m(\\w+|)(w|r))", std::tr1::regex_constants::icase);
const regex YEST_INPUT("(y(\\w+|)(e|s)(\\w+|)(t|r|y))", std::tr1::regex_constants::icase);
const regex AMPM_INPUT("(1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)", std::tr1::regex_constants::icase);
const regex AMPM_SHORT_INPUT("(((1[0-2]|[1-9])(\\s)?(am|pm|noon)))", std::tr1::regex_constants::icase);
const regex NIL_INPUT("((2[0-3]|1[0-9]|0[1-9]|[1-9])([:|\.])?([0-5][0-9]))", std::tr1::regex_constants::icase);
const regex OCLOCK_INPUT("((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))", std::tr1::regex_constants::icase);
const regex SYM_INPUT("([:|\.])", std::tr1::regex_constants::icase);

void parserProcess::setRawDT(string& rawDate, string& rawTime)
{

	rawDateStore = rawDate;
	rawTimeStore = rawTime;
}


void parserProcess::setNowDT()
{


	UINT DayOfWeek[] = {
		LOCALE_SDAYNAME7,   // Sunday
		LOCALE_SDAYNAME1,
		LOCALE_SDAYNAME2,
		LOCALE_SDAYNAME3,
		LOCALE_SDAYNAME4,
		LOCALE_SDAYNAME5,
		LOCALE_SDAYNAME6   // Saturday
	};
	TCHAR strWeekday[256];
	CTime time(CTime::GetCurrentTime());   // Initialize CTime with current time
	::GetLocaleInfo(LOCALE_USER_DEFAULT,   // Get string for day of the week from system
		DayOfWeek[time.GetDayOfWeek() - 1],   // Get day of week from CTime
		strWeekday, sizeof(strWeekday) / sizeof(strWeekday[0]));


	time_t t = time.GetTime();   // get time now
	struct tm * now = localtime(&t);

	nowDT.year = (now->tm_year + 1900);
	nowDT.month = (now->tm_mon + 1);
	nowDT.day = now->tm_mday;
	nowDT.hour = now->tm_hour;
	nowDT.min = now->tm_min;
	nowDT.dayName = strWeekday;
	nowDT.dayNameRef = time.GetDayOfWeek() - 2;



}


void parserProcess::processDate(string rawDate)
{

	datekeyWord dateProcess;
	dateProcess = sortDateType(rawDate);

	switch (dateProcess)
	{
	case DAY_NATURALISED:
	{
		natExp exp;
		exp = sortNatExp(rawDate);
		nowDT.isLongMonth = monthDayIndicator(nowDT.month);

		switch (exp)
		{
		case TODAY:
		{
			if (nowDT.isLongMonth)
			{
				addDayCalc(31, 0);
			}
			else
			{
				addDayCalc(30, 0);
			}

			return;
		}
		case YEST:
		{

			if (nowDT.isLongMonth)
			{
				addDayCalc(31, -1);
			}
			else
			{
				addDayCalc(30, -1);
			}


			return;

		}
		case TMR:
		{
			if (nowDT.isLongMonth)
			{
				addDayCalc(31, 1);
			}
			else
			{
				addDayCalc(30, 1);
			}

			return;
		}
		}
	}
	case DAY_NAME:
	{   cout << "daynane";
	processDateName(rawDate);

	cout << endl;
	cout << "pds dnf:" << processedDateStore.dayNameRef << endl;
	cout << "nowdt dnf:" << nowDT.dayNameRef << endl;

	dateNumCalculator(processedDateStore.dayNameRef, nowDT.dayNameRef);

	return;
	}
	case DAY_NUM:
	{

		char c;
		istringstream iss(rawDate);


		iss >> processedDateStore.day;
		iss >> c;
		iss >> processedDateStore.month;
		iss >> c;
		iss >> processedDateStore.year;


		return;
	}



	}




}




parserProcess::datekeyWord parserProcess::sortDateType(string& rawInput)
{

	if (regex_search(rawInput, DATE_NATURALIZED))
	{
		return DAY_NATURALISED;

	}
	else if (regex_search(rawInput, DATE_NAME))
	{

		return DAY_NAME;

	}
	else if (regex_search(rawInput, DATE_NUM))
	{


		return DAY_NUM;
	}



}


void parserProcess::processDateNatExp(string&)
{





}




void parserProcess::processDateName(string& input)
{
	dayName day;
	day = sortDayName(input);

	switch (day)
	{
	case(MONDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 0;
		return;
	}
	case(TUESDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 1;
		return;
	}
	case(WEDNESDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 2;
		return;

	}
	case(THURSDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 3;
		return;
	}
	case(FRIDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 4;
		return;
	}
	case(SATURDAY) :
	{   cout << "ok!";
		processedDateStore.dayNameRef = 5;
		return;
	}
	case(SUNDAY) :
	{
		cout << "ok!";
		processedDateStore.dayNameRef = 6;
		return;
	}






	}
}

void parserProcess::processDateNum(string&)
{




}



parserProcess::dayName  parserProcess::sortDayName(string& strInput)
{
	cout << "sorting:" << strInput;


	if (regex_search(strInput, MONDAY_INPUT))
	{
		return  MONDAY;

	}
	else if (regex_search(strInput, TUESDAY_INPUT))
	{

		return  TUESDAY;

	}
	else if (regex_search(strInput, WEDNESDAY_INPUT))
	{
		return  WEDNESDAY;

	}
	else if (regex_search(strInput, THURSDAY_INPUT))
	{
		cout << "thurs!";
		return THURSDAY;

	}
	else if (regex_search(strInput, FRIDAY_INPUT))
	{
		cout << "fri";
		return FRIDAY;

	}
	else if (regex_search(strInput, SATURDAY_INPUT))
	{

		return SATURDAY;

	}
	else if (regex_search(strInput, SUN_INPUT))
	{
		return SUNDAY;


	}





}


bool parserProcess::monthDayIndicator(int& month)
{
	return month % 2;

}

dateStore parserProcess::dateNumCalculator(int& dateNum, int& nowDateNum)
{
	if (monthDayIndicator(nowDT.month) == true) //31st 
	{

		processMonthMoreDays(dateNum, nowDateNum, processedDateStore);


	}
	else //30th 
	{


		processMonthLessDays(dateNum, nowDateNum, processedDateStore);





	}


	return processedDateStore;

}


void parserProcess::processMonthMoreDays(int& givenDay, int& nowDay, dateStore& storage)
{
	int diff;

	if (nowDay > givenDay)
	{

		diff = (givenDay - nowDay) + 7;
		addDayCalc(31, diff);

	}
	else if (nowDay < givenDay)
	{
		diff = (givenDay - nowDay);
		addDayCalc(31, diff);

	}
	else if (nowDay = givenDay)
	{
		processedDateStore.day = nowDT.day;
		processedDateStore.month = nowDT.month;
		processedDateStore.year = nowDT.year;

	}




}




void parserProcess::processMonthLessDays(int& givenDay, int& nowDay, dateStore& storage)
{

	int diff;

	if (nowDay > givenDay)
	{
		diff = (givenDay - nowDay) + 7;
		addDayCalc(30, diff);

	}
	else if (nowDay < givenDay)
	{
		diff = (givenDay - nowDay);
		addDayCalc(30, diff);

	}
	else if (nowDay = givenDay)
	{
		processedDateStore.day = nowDT.day;
		processedDateStore.month = nowDT.month;
		processedDateStore.year = nowDT.year;

	}






}


void parserProcess::addDayCalc(int daysInMonth, int diff)
{
	if (nowDT.day + diff > daysInMonth)
	{
		processedDateStore.day = (nowDT.day + diff) - daysInMonth;
		if (nowDT.month + 1 < 12)
		{
			processedDateStore.month = nowDT.month + 1;
			processedDateStore.year = nowDT.year;
		}
		else
		{
			processedDateStore.month = 1;
			processedDateStore.year = nowDT.year + 1;

		}
	}
	else
	{
		processedDateStore.day = nowDT.day + diff;
		processedDateStore.month = nowDT.month;
		processedDateStore.year = nowDT.year;


	}
}

parserProcess::natExp parserProcess::sortNatExp(string& natexp)
{

	if (regex_search(natexp, TODAY_INPUT))
	{
		return TODAY;

	}
	else if (regex_search(natexp, TMR_INPUT))
	{
		return TMR;
	}
	else if (regex_search(natexp, YEST_INPUT))
	{

		return YEST;
	}







}

void parserProcess::printProcessed()
{

	cout << processedDateStore.day << ":" << processedDateStore.month << ":" << processedDateStore.year << endl;


}

void parserProcess::printNow()
{


	cout << nowDT.day << ":" << nowDT.month << ":" << nowDT.year << endl;
	cout << nowDT.dayName << "DNF:" << nowDT.dayNameRef;

}


string parserProcess::parserReturnDate()
{
	ostringstream oss;

	oss << processedDateStore.day << "/" << processedDateStore.month << "/" << processedDateStore.year;

	return oss.str();

}


string parserProcess::parserReturnNowTime()
{
	ostringstream oss;
	setNowDT();
	oss << nowDT.day << "/" <<nowDT.month << "/" << nowDT.year;

	return oss.str();

}





void parserProcess::processTime(string timeInput)
{

	timeKeyWord time;
	time = sortTimeKeyWord(timeInput);
	
	clearTimestore();

	switch (time)
	{
	case(AM_PM) :
	{
		cout << "ampm" << endl;
		processTimeAmPm(timeInput);

		return;

	}
	case(OCLOCK) :
	{

		processTimeNatExp(timeInput);

		return;
	}
	case(SHORT_AM_PM) :
	{


		processTimeShortAmPm(timeInput);
		return;

	}
	case(NIL) :
	{
		processTimeNil(timeInput);
		return;

	}




	}

}


parserProcess::timeKeyWord  parserProcess::sortTimeKeyWord(string& timeInput)
{





	if (regex_search(timeInput, AMPM_INPUT))
	{
		return AM_PM;

	}
	else if (regex_search(timeInput, OCLOCK_INPUT))
	{

		return OCLOCK;
	}
	else if (regex_search(timeInput, AMPM_SHORT_INPUT))
	{

		return SHORT_AM_PM;
	}
	else if (regex_search(timeInput, NIL_INPUT))
	{

		return NIL;

	}


}

void parserProcess::processTimeAmPm(string& timeInput)
{
	istringstream iss(timeInput);
	int hours, mins;
	char sym, status;
	iss >> hours;
	iss >> sym;
	iss >> mins;
	iss >> status;
	covertTime(status, hours);

	processedtimeStore.min = mins;
	processedtimeStore.hours = hours;

	return;


}
void parserProcess::processTimeNil(string& timeInput)
{   


	if (!regex_search(timeInput,SYM_INPUT))
	{
		processedtimeStore.nilstore = timeInput;
		
	}
	else
	{ 


	istringstream iss(timeInput);
	int hours, mins;
	char sym, status;
	iss >> hours;
	iss >> sym;
	iss >> mins;
	iss >> status;

	processedtimeStore.min = mins;
	processedtimeStore.hours = hours;
    }

	return;



}

void parserProcess::processTimeNatExp(string& timeInput)
{
	istringstream iss(timeInput);
	int hours;
	char c;
	iss >> hours;

	processedtimeStore.hours = hours;
	processedtimeStore.min = 0;
}




void parserProcess::processTimeShortAmPm(string& timeInput)
{

	istringstream iss(timeInput);
	int hours;
	char c;
	iss >> hours;
	iss >> c;

	covertTime(c, hours);
	processedtimeStore.min = 0;
	processedtimeStore.hours = hours;

	return;

}


void parserProcess::covertTime(char& status, int& hour)
{
	if (status == 'p' | status == 'P')
	{
		hour = hour + 12;

	}
	return;

}


string parserProcess::parserReturnTime()
{
	if (processedtimeStore.nilstore!="")
	{

		return processedtimeStore.nilstore;

	}
	else
	{




		ostringstream oss;

		if (processedtimeStore.min < 10)
		{
			oss << processedtimeStore.hours << ":0" << processedtimeStore.min;
		}
		else
		{
			oss << processedtimeStore.hours << ":" << processedtimeStore.min;

		}



		return oss.str();
	}




}

void parserProcess::clearTimestore()
{

	processedtimeStore.hours = 0;
	processedtimeStore.min = 0;
	processedtimeStore.nilstore = "";
	processedtimeStore.timeStatus = "";


	return;


}