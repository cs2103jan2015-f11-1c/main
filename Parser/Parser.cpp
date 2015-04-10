#include "Parser.h"
#include "paraList.h"
#include "parserProcess.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

const regex X_PATTERN("(!)\\w+\\b", std::tr1::regex_constants::icase);
const regex DATE_PATTERN("(t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))", std::tr1::regex_constants::icase);
const regex TIME_PATTERN("((1[0-2]|[1-9])((:|\.)[0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))", std::tr1::regex_constants::icase);
const regex EXP_PATTERN("(:)(f|F)\\b|(:)(t|T)\\b|(:)(b|B)\\b|\\b(from)\\b|\\b(to)\\b|\\b(by)\\b|\\b(on)\\b|\\b(at)\\b|\\b(before)\\b|\\b(after)\\b", std::tr1::regex_constants::icase);
const regex F_PATTERN("(:)(f|F)\\b", std::tr1::regex_constants::icase);
const regex T_PATTERN("(:)(t|T)\\b", std::tr1::regex_constants::icase);
const regex FROM_PATTERN("\\b(from)\\b", std::tr1::regex_constants::icase);
const regex TO_PATTERN("\\b(to)\\b", std::tr1::regex_constants::icase);
const regex BY_PATTERN("(:)(b|B)\\b", std::tr1::regex_constants::icase);
const regex ADD_PATTERN("\\b(add)\\b", std::tr1::regex_constants::icase);
const regex DELETE_PATTERN("\\b(delete)\\b", std::tr1::regex_constants::icase);
const regex MARK_PATTERN("\\b(mark)\\b", std::tr1::regex_constants::icase);
const regex DISPLAY_PATTERN("\\b(display)\\b", std::tr1::regex_constants::icase);
const regex UNMARK_PATTERN("\\b(unmark)\\b", std::tr1::regex_constants::icase);
const regex SAVE_PATTERN("\\b(save)\\b", std::tr1::regex_constants::icase);
const regex SEARCH_PATTERN("\\b(search)\\b", std::tr1::regex_constants::icase);
const regex UPDATE_PATTERN("\\b(update)\\b", std::tr1::regex_constants::icase);
const regex NTRL_FROM_PATTERN("((from)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((from)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");

const regex NTRL_BY_PATTERN("((by)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((by)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");
const regex NTRL_TO_PATTERN("((to)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((to)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");

const regex NTRL_ON_PATTERN("((on)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((on)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");

const regex NTRL_AT_PATTERN("((at)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((at)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");

const regex NTRL_AFTER_PATTERN("((after)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((after)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");

const regex NTRL_BEFORE_PATTERN("((before)([\\s]+)(((1[0-2]|[1-9])[:|\.]([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((before)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))");


Parser::Parser()
{}

void Parser::sortCommand(string &userInput)
{

	int index;
	index = userInput.find_first_of(" ");
	string temp = userInput.substr(0, index);
	para.processCommand(temp);
	userInput.erase(0, index + 1);
	return;
}




void Parser::sortDetails(string &userInput)
{
	int index;
	string _eventstartdetails;
	string _eventenddetails;
	keywordType Keyword;
	Keyword = determineKeywords(userInput);


	switch (Keyword)
	{
	case ABST_NIL:
	{


		para._task.changeTaskName(userInput);



		return;
	}
	case NONE:
	{	int a = 1000, b = 1000, c = 1000, process = 0;

	string dltime, dldate;
	getNoneToken(userInput, a, b, c);
	cout << a << endl << b << endl << c << endl;
	processNum(a, b, c, process);
	cout << "min" << process << endl;



	if (process != 1000)
	{
		para._task.changeTaskName(userInput.substr(0, process - 1));
		cout << "this is taskname:" << userInput.substr(0, process - 1) << endl;
		userInput.erase(0, process - 1);
		cout << "after erase:" << userInput << endl;
		checkStart(dldate, dltime, userInput);
		para._task.changeTaskDeadlineDate(dldate);
		para._task.changeTaskDeadlineTime(dltime);
		processX(userInput);
	}
	else
	{
		para._task.changeTaskName(checkingKeywordX(userInput));

	}
	return;


	}
	case STARTONLY:
	{
		string st, sd;
		processX(userInput);
		processBeforeKeywordf(userInput);
		checkStart(sd, st, userInput);
		para._task.changeTaskStartDate(sd);
		para._task.changeTaskStartTime(st);

		return;
	}
	case ENDONLY:
	{   string et, ed;
	processX(userInput);
	processBeforeKeywordt(userInput);
	checkEnd(ed, et, userInput);
	para._task.changeTaskEndDate(ed);
	para._task.changeTaskEndTime(et);
	return;
	}
	case DEADLINE:
	{
		string dt, dd;
		processX(userInput);
		processBeforeKeywordb(userInput);
		checkEnd(dd, dt, userInput);
		cout << "dldate:" << dd << endl;
		cout << "dddate:" << dt << endl;
		para._task.changeTaskDeadlineDate(dd);
		para._task.changeTaskDeadlineTime(dt);
		cout << "GET NAME:" << para._task.getTaskDeadlineDate() << endl;
		return;
	}
	case START_END:
	{   cout << "STARTEND";
	index = userInput.find(":f") - 1;
	string tempName = userInput.substr(0, index);

	para._task.changeTaskName(userInput.substr(0, index));

	processBeforeKeywordf(userInput);
	index = userInput.find(":t") - 1;
	_eventstartdetails = userInput.substr(0, index);
	userInput.erase(0, index + 4);



	_eventenddetails = userInput;
	cout << "eventstart" << _eventstartdetails << endl;
	cout << "eventend" << _eventenddetails << endl;


	string a, b;
	checkStart(a, b, _eventstartdetails);
	para._task.changeTaskStartDate(a);
	para._task.changeTaskStartTime(b);
	processX(_eventstartdetails);


	string c, d;
	checkEnd(c, d, _eventenddetails);
	para._task.changeTaskEndDate(c);
	para._task.changeTaskEndTime(d);
	processX(_eventenddetails);


	return;
	}
	case FROM:
	{    cout << "from " << endl;
	string fromtime, fromdate;
	processX(userInput);
	processKeywordFrom(userInput);
	checkStart(fromdate, fromtime, userInput);
	para._task.changeTaskStartDate(fromdate);
	para._task.changeTaskStartTime(fromtime);

	return;
	}
	case TO:
	{
		string endtime, enddate;
		processX(userInput);
		processKeywordTo(userInput);
		checkStart(enddate, endtime, userInput);
		para._task.changeTaskStartDate(enddate);
		para._task.changeTaskStartTime(endtime);

		return;
	}
	case ON:
	{
		string ontime, ondate;
		processX(userInput);
		processKeywordOn(userInput);
		checkStart(ondate, ontime, userInput);
		para._task.changeTaskStartDate(ondate);
		para._task.changeTaskStartTime(ontime);


		return;


	}
	case AT:
	{
		string attime, atdate;
		processX(userInput);
		processKeywordAt(userInput);
		checkStart(atdate, attime, userInput);
		para._task.changeTaskStartDate(atdate);
		para._task.changeTaskStartTime(attime);


		return;


	}
	case BY:
	{

		string bytime, bydate;
		processX(userInput);
		processKeywordBy(userInput);
		checkStart(bydate, bytime, userInput);
		para._task.changeTaskDeadlineDate(bydate);
		para._task.changeTaskDeadlineTime(bytime);


		return;


	}
	case AFTER:
	{
		cout << "j";

		string afttime, aftdate;
		processX(userInput);
		processKeywordAfter(userInput);


		checkStart(aftdate, afttime, userInput);
		para._task.changeTaskStartDate(aftdate);
		para._task.changeTaskStartTime(afttime);


		return;

	}
	case BEFORE:
	{
		string beftime, befdate;
		processX(userInput);
		processKeywordBefore(userInput);
		checkStart(befdate, beftime, userInput);
		para._task.changeTaskDeadlineDate(befdate);
		para._task.changeTaskDeadlineTime(beftime);

		return;
	}
	case FROM_TO:
	{
		index = userInput.find("from") - 1;
		string tempName = userInput.substr(0, index);

		para._task.changeTaskName(userInput.substr(0, index));

		processBeforeKeywordFrom(userInput);
		index = userInput.find("to") - 1;
		_eventstartdetails = userInput.substr(0, index);
		userInput.erase(0, index + 4);



		_eventenddetails = userInput;
		cout << "eventstart" << _eventstartdetails << endl;
		cout << "eventend" << _eventenddetails << endl;


		string a, b;
		checkStart(a, b, _eventstartdetails);
		para._task.changeTaskStartDate(a);
		para._task.changeTaskStartTime(b);
		processX(_eventstartdetails);


		string c, d;
		checkEnd(c, d, _eventenddetails);
		para._task.changeTaskEndDate(c);
		para._task.changeTaskEndTime(d);
		processX(_eventenddetails);
		return;





	}
	}
	return;
}



paraList* Parser::parseCommand(string userInput)
{
	para.clearTask();
	sortCommand(userInput);
	processCommand(userInput);

	return &para;
}

void Parser::splitstring(string &first, string &second, string &input)
{
	int index;



	/*index=input.find_first_of(" ");
	first=input.substr(0,index);
	input.erase(0,index+1);
	second=input;
	*/
	return;
}

void Parser::processCommand(string &userInput)
{
	string command = para.getCommand();
	int index;
	parserProcess a;

	if (regex_search(command, ADD_PATTERN))
	{
		sortDetails(userInput);
		processDate();
		processTime();
	}
	else if (regex_search(command, DELETE_PATTERN))
	{
		istringstream iss(userInput);
		iss >> index;
		para.processDeleteNumber(index);
	}
	else if (regex_search(command, DISPLAY_PATTERN))
	{
		istringstream iss(userInput);
		iss >> index;
		para.processDisplayNumber(index);

	}
	else if (regex_search(command, UPDATE_PATTERN))
	{
		int b, index;
		string a;

		b = userInput.find_first_of(" ");
		a = userInput.substr(0, b);
		istringstream iss(a);
		iss >> index;
		userInput.erase(0, b + 1);
		b = userInput.find_first_of(" ");
		para.processKeyWord(userInput.substr(0, b));
		userInput.erase(0, b + 1);
		para.processInput(userInput);
		para.processUpdateNumber(index);
	}
	else if (regex_search(command, MARK_PATTERN))
	{
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);

		para.processMarkStatus("mark");


	}
	else if (regex_search(command, UNMARK_PATTERN))
	{
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);
		para.processMarkStatus("unmark");


	}
	else if (regex_search(command, UNMARK_PATTERN))
	{
		para.processUserDir(userInput);

	}
	else if (regex_search(command, SEARCH_PATTERN))
	{

		para.processSearchWord(userInput);


	}
	else
	{
		command == "invalid";

	}


	return;
}

void Parser::processBeforeKeywordf(string &userInput)
{
	int index;


	index = userInput.find(":f") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);

	return;
}


void Parser::processBeforeKeywordt(string &userInput)
{
	int index;
	index = userInput.find(":t") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);


	return;
}


void Parser::processBeforeKeywordb(string &userInput)
{
	int index;
	index = userInput.find(":b") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);


	return;
}






string Parser::checkingKeywordX(string &userInput)
{
	string details;



	if (userInput.find("!") != string::npos){
		int index = userInput.find("!") - 1;
		details = userInput.substr(0, index);
		userInput.erase(0, index + 2);
		para._task.changeTaskPriority(userInput);
	}
	else{

		details = userInput;

	}

	return details;
}

Parser::keywordType Parser::determineKeywords(string userInput)
{

	string command = para.getCommand();

	cout << "command:" << command << endl;

	if (command.find("#") != string::npos)
	{

		para.processCommand(command.substr(0, 3));
		cout << "b" << endl;
		return ABST_NIL;
	}
	else if (!regex_search(userInput, EXP_PATTERN))
	{
		cout << "a" << endl;
		return NONE;
	}
	else if (regex_search(userInput, FROM_PATTERN) && regex_search(userInput, TO_PATTERN))
	{
		cout << "from to";
		return FROM_TO;

	}
	else if (regex_search(userInput, F_PATTERN) && !regex_search(userInput, T_PATTERN))
	{

		cout << "b";
		return STARTONLY;
	}
	else if (!regex_search(userInput, F_PATTERN) && regex_search(userInput, T_PATTERN))
	{
		cout << "c";
		return ENDONLY;
	}
	else if (regex_search(userInput, BY_PATTERN))
	{

		cout << "deadline";
		return DEADLINE;
	}
	else if (regex_search(userInput, NTRL_FROM_PATTERN))
	{
		cout << "from" << endl;
		return FROM;
	}
	else if (regex_search(userInput, NTRL_BEFORE_PATTERN))
	{
		cout << "before" << endl;
		return BEFORE;
	}
	else if (regex_search(userInput, NTRL_AFTER_PATTERN))
	{
		cout << "after" << endl;
		return AFTER;

	}
	else if (regex_search(userInput, NTRL_TO_PATTERN))
	{
		cout << "to" << endl;
		return TO;
	}
	else if (regex_search(userInput, NTRL_BY_PATTERN))
	{
		cout << "by" << endl;
		return BY;
	}
	else if (regex_search(userInput, NTRL_ON_PATTERN))
	{
		cout << "on" << endl;
		return ON;
	}
	else if (regex_search(userInput, NTRL_AT_PATTERN))
	{
		cout << "at" << endl;
		return AT;
	}
	else
	{
		cout << "startend" << endl;
		return  START_END;
	}
}

void Parser::checkStart(string&startdate, string &starttime, string userinput)
{
	cout << "userinput:" << userinput << endl;
	startdate = checkSD(userinput);
	starttime = checkST(userinput);
	return;

}


string Parser::checkST(string userinput)
{
	string  date[50], time[50];
	int count1 = 0, count2 = 0;

	const sregex_token_iterator d;
	for (sregex_token_iterator e(userinput.begin(), userinput.end(), TIME_PATTERN); e != d; ++e)
	{

		time[count2] = *e;
		count2++;
	}

	return time[0];

}



string Parser::checkSD(string userinput)
{

	string  date[50], time[50];
	int count1 = 0, count2 = 0;

	const sregex_token_iterator end;
	for (sregex_token_iterator i(userinput.begin(), userinput.end(), DATE_PATTERN); i != end; ++i)
	{

		date[count1] = *i;
		count1++;
	}

	return date[0];


}




void Parser::checkEnd(string&enddate, string &endtime, string userinput)
{

	enddate = checkSD(userinput);
	endtime = checkST(userinput);
	return;

}


void Parser::empty(string&startdate, string &starttime, string&enddate, string &endtime, string userinput)
{



	return;


}


void Parser::processX(string userinput)
{

	string  keyword[50];
	int  count = 0;

	smatch X;
	const sregex_token_iterator d;
	for (sregex_token_iterator e(userinput.begin(), userinput.end(), X_PATTERN); e != d; ++e)
	{

		keyword[count] = *e;
		count++;
	}
	if (regex_search(userinput, X, X_PATTERN))
		para._task.changeTaskPriority(keyword[0].substr(1));



	return;

}


void Parser::getNoneToken(string userinput, int& xtoken, int& timetoken, int& datetoken)
{



	smatch matchX, matchdate, matchtime;


	if (regex_search(userinput, matchX, X_PATTERN))
		xtoken = matchX.position(0);
	if (regex_search(userinput, matchdate, DATE_PATTERN))
		datetoken = matchdate.position(0);
	if (regex_search(userinput, matchtime, TIME_PATTERN))
		timetoken = matchtime.position(0);






	return;
}


void Parser::processNum(int& a, int& b, int& c, int& answer)
{

	if (a < b)
	{
		if (c < a)
		{

			answer = c;
		}
		else
		{
			answer = a;
		}
	}
	else
	{
		if (c < b)
		{

			answer = c;
		}
		else
		{
			answer = b;
		}


	}
	return;
}



void Parser::processDate()
{
	parserProcess end, start, deadline;
	string startStr = para._task.getTaskStartDate();
	string endStr = para._task.getTaskEndDate();
	string deadlineStr = para._task.getTaskDeadlineDate();
	cout << "DLdate: " << deadlineStr << endl;

	if (startStr != "")
	{
		cout << "SS" << endl;
		start.setNowDT();
		start.processDate(startStr);
		para._task.changeTaskStartDate(start.parserReturnDate());

	}
	if (endStr != "")
	{
		cout << "ES" << endl;
		end.setNowDT();
		end.processDate(endStr);
		para._task.changeTaskEndDate(end.parserReturnDate());
	}
	if (deadlineStr != "")
	{
		cout << "DL" << endl;
		deadline.setNowDT();
		deadline.processDate(deadlineStr);
		para._task.changeTaskDeadlineDate(deadline.parserReturnDate());
	}





}



void Parser::processKeywordFrom(string &userInput)
{

	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_FROM_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 5);

	return;



}



void Parser::processKeywordTo(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_TO_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;









}



void Parser::processKeywordBy(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_BY_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;





}


void Parser::processKeywordAt(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_AT_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;








}

void Parser::processKeywordBefore(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_BEFORE_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 6);

	return;




}

void Parser::processKeywordOn(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_ON_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;



}

void Parser::processKeywordAfter(string &userInput)
{
	int token;
	smatch matchx;



	regex_search(userInput, matchx, NTRL_AFTER_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;



	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 6);

	return;









}




void Parser::processTime()
{
	parserProcess end, start, deadline;
	string startStr = para._task.getTaskStartTime();
	string endStr = para._task.getTaskEndTime();
	string deadlineStr = para._task.getTaskDeadlineTime();
	cout << "DLdate: " << deadlineStr << endl;

	if (startStr != "")
	{
		cout << "SS" << endl;
		start.setNowDT();
		start.processTime(startStr);
		para._task.changeTaskStartTime(start.parserReturnTime());

	}
	if (endStr != "")
	{
		cout << "ES" << endl;
		end.setNowDT();
		end.processTime(endStr);
		para._task.changeTaskEndTime(end.parserReturnTime());
	}
	if (deadlineStr != "")
	{
		cout << "DL" << endl;
		deadline.setNowDT();
		cout << deadlineStr << endl;
		deadline.processTime(deadlineStr);
		para._task.changeTaskDeadlineTime(deadline.parserReturnTime());
	}





}


void Parser::processBeforeKeywordFrom(string &userInput)
{
	int index;


	index = userInput.find("from") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 6);

	return;
}
