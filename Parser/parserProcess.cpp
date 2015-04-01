#include "parserProcess.h"
#include <iostream>
#include <ctime>
#include <atltime.h>



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
const regex MONDAY_INPUT("(mondays?\b)|(mons?\b)", std::tr1::regex_constants::icase);
const regex TUESDAY_INPUT("(tues?days?\b)|(tues?\b)", std::tr1::regex_constants::icase);
const regex WEDNESDAY_INPUT("(wednesdays?\b)|(weds?\b)", std::tr1::regex_constants::icase);
const regex THURSDAY_INPUT("(thursdays?\b)|(thurs?\b)", std::tr1::regex_constants::icase);
const regex FRIDAY_INPUT("(fridays?\b)|(fris?\b)", std::tr1::regex_constants::icase);
const regex SATURDAY_INPUT("(mondays?\b)|(mons?\b)", std::tr1::regex_constants::icase);
const regex SUN_INPUT("(mondays?\b)|(mons?\b)", std::tr1::regex_constants::icase);
const regex TODAY_INPUT("(t(o+|)d(a+|)(y))", std::tr1::regex_constants::icase);
const regex TMR_INPUT("(t(\\w+|)m(\\w+|)(w|r))", std::tr1::regex_constants::icase);
const regex YEST_INPUT("(y(\\w+|)(e|s)(\\w+|)(t|r|y))", std::tr1::regex_constants::icase);

void parserProcess::setRawDT(string& rawDate, string& rawTime)
{

	rawDateStore=rawDate;
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
	nowDT.dayNameRef = time.GetDayOfWeek() - 1;
	


}


void parserProcess::processDate(string& rawDate)
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


	   }
	   }
   }
   case DAY_NAME:
   {
	   processDateName(rawDate);
	   dateNumCalculator(processedDateStore.dayNameRef, nowDT.dayNameRef);


   }
   case DAY_NUM:
   {

	   processedDateStore.day = nowDT.day;
	   processedDateStore.month = nowDT.month;
	   processedDateStore.year = nowDT.year;
	   processedDateStore.dayName = nowDT.dayName;
	   processedDateStore.dayNameRef = nowDT.dayNameRef;

   }



   }




}




parserProcess::datekeyWord parserProcess::sortDateType(string& rawInput)
{

	if (regex_search(rawInput, DATE_NATURALIZED))
	{
		return DAY_NATURALISED;

	}
	else if (regex_search(rawInput,DATE_NAME))
	{
		
		return DAY_NAME;

	}
	else if (regex_search(rawInput,DATE_NUM))
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
	{
		processedDateStore.dayNameRef = 0;

	}
	case(TUESDAY) :
	{
		processedDateStore.dayNameRef = 1;

	}
	case(WEDNESDAY) :
	{
		processedDateStore.dayNameRef = 2;


	}
	case(THURSDAY) :
	{
		processedDateStore.dayNameRef = 3;

	}
	case(FRIDAY) :
	{
		processedDateStore.dayNameRef = 4;

	}
	case(SATURDAY) :
	{
		processedDateStore.dayNameRef = 5;

	}
	case(SUNDAY) :
	{

		processedDateStore.dayNameRef = 6;

	}






	}
}

void parserProcess::processDateNum(string&)
{




}



parserProcess::dayName  parserProcess::sortDayName(string& strInput)
{

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

		return THURSDAY;

	}
	else if (regex_search(strInput, FRIDAY_INPUT))
	{
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

dateStore parserProcess::dateNumCalculator(int& dateNum,int& nowDateNum)
{
	if (monthDayIndicator(nowDT.month)==true) //31st 
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
		diff=(nowDay - givenDay) + 7;
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
		diff = (nowDay - givenDay) + 7;
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