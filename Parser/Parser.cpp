// @author A0111642W
#include "Parser.h"
#include "paraList.h"
#include "parserProcess.h"
//#define NDEBUG
#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

const regex X_PATTERN("(!)\\w+\\b", std::tr1::regex_constants::icase);
const regex DATE_PATTERN("(t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))", std::tr1::regex_constants::icase);
const regex TIME_PATTERN("(^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))|((1[0-2]|[1-9])(\\s)?(o|O)(')?(clock))", std::tr1::regex_constants::icase);
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
const regex VIEW_C_PATTERN("\\b(view-c)\\b",std::tr1::regex_constants::icase);
const regex VIEW_I_PATTERN("\\b(view-i)\\b", std::tr1::regex_constants::icase);
const regex VIEW_PATTERN("\\b(view)\\b", std::tr1::regex_constants::icase);
const regex NTRL_FROM_PATTERN("((from)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((from)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(from)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_BY_PATTERN("((by)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((by)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(by)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_TO_PATTERN("((to)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((to)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(to)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_ON_PATTERN("((on)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((on)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(on)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_AT_PATTERN("((at)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((at)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(at)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_AFTER_PATTERN("((after)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((after)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(after)([\\s]+)((!high)|(!low))", std::tr1::regex_constants::icase);
const regex NTRL_BEFORE_PATTERN("((before)([\\s]+)((^((2[0-4]|1[0-9]|0?[1-9])([:|.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?)|[^/.:\\w]((2[0-4]|1[0-9]|0?[1-9])([:|\.])?([0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM)?))|((2[0-4]|1[0-9]|[1-9])(\\s)?(o|O)(')?(clock))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))))|((before)([\\s]+)((t(o+|)d(a+|)(y))|(t(\\w+|)m(\\w+|)(w|r))|(mondays?)\\b|(tuesdays?)\\b|(wednesdays?)\\b|(thursdays?)\\b|(fridays?)\\b|(saturdays?)\\b|(sundays?)\\b|(mons?\\b)|(tues?)\\b|(weds?)\\b|(thurs?)\\b|(fri)\\b|(sats?)\\b|(sun)\\b|(y(\\w+|)(e|s)(\\w+|)(t|r|y))|(([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2}))))|(before)([\\s]+)((!high)|(!low))");
const int PROCESS_INITIAL = 1000;

Parser::Parser()
{}

//extracts the command from userInput
void Parser::sortCommand(string &userInput){

	int index;
	index = userInput.find_first_of(" ");
	string temp = userInput.substr(0, index);
	para.processCommand(temp);
	userInput.erase(0, index + 1);

	return;
}

//extracts the command parameters from userInput
void Parser::sortDetails(string &userInput)
{
	int index;
	string eventStartDetails;
	string eventEndDetails;
	keywordType Keyword;
	Keyword = determineKeywords(userInput);

	switch (Keyword){

	case ABST_NIL:
	{
		para._task.changeTaskName(userInput);

		return;
	}
	case NONE:
	{	
		
		int firstToken = PROCESS_INITIAL;
		int secondToken = PROCESS_INITIAL; 
		int thirdToken = PROCESS_INITIAL; 
		int process = 0;

		getNoneToken(userInput, firstToken, secondToken, thirdToken);
		processNum(firstToken, secondToken, thirdToken, process);
	
		processupdateNone(userInput,process);

		if (para._task.getTaskDeadlineDate() == "" && para._task.getTaskDeadlineTime() != ""){
			parserProcess now;
			para._task.changeTaskDeadlineDate(now.parserReturnNowTime());
		}

		return;
	}
	case STARTONLY:
	{
		string startTime; 
		string startDate;


		processX(userInput);
		processBeforeKeywordf(userInput);
		checkStart(startDate, startTime, userInput);
		para._task.changeTaskStartDate(startDate);
		para._task.changeTaskStartTime(startTime);

		if (para._task.getTaskStartDate() == "" && para._task.getTaskStartTime() != "")
		{
			parserProcess now;
			para._task.changeTaskStartDate(now.parserReturnNowTime());
		}

		return;
	}
	case ENDONLY:
	{   string endTime;
	    string endDate;
	
		processX(userInput);
		processBeforeKeywordt(userInput);
		checkEnd(endDate, endTime, userInput);
		para._task.changeTaskEndDate(endDate);
		para._task.changeTaskEndTime(endTime);

		if (para._task.getTaskEndDate() == "" && para._task.getTaskEndTime() != ""){
			parserProcess now;
			para._task.changeTaskEndDate(now.parserReturnNowTime());

		}

		return;
	}
	case DEADLINE:
	{
		string deadTime; 
		string deadDate;


		processX(userInput);
		processBeforeKeywordb(userInput);
		checkEnd(deadDate, deadTime, userInput);
		para._task.changeTaskDeadlineDate(deadDate);
		para._task.changeTaskDeadlineTime(deadTime);
	

		if (para._task.getTaskDeadlineDate() == "" && para._task.getTaskDeadlineTime() != ""){
			parserProcess now;
			para._task.changeTaskDeadlineDate(now.parserReturnNowTime());
		}

		return;
	}
	case START_END:
	{   
		index = userInput.find(":f") - 1;
		string tempName = userInput.substr(0, index);

		para._task.changeTaskName(userInput.substr(0, index));

		processBeforeKeywordf(userInput);
		index = userInput.find(":t") - 1;
		eventStartDetails = userInput.substr(0, index);
		userInput.erase(0, index + 4);

		eventEndDetails = userInput;

		processStartKey(eventStartDetails);
		processEndKey(eventEndDetails);

		return;
	}
	case FROM:
	{    
		string fromtime;
		string fromdate;

		processX(userInput);
		processKeywordFrom(userInput);
		checkStart(fromdate, fromtime, userInput);
		para._task.changeTaskStartDate(fromdate);
		para._task.changeTaskStartTime(fromtime);

	if (para._task.getTaskStartDate() == "" && para._task.getTaskStartTime() != ""){
		
		parserProcess now;
		para._task.changeTaskStartDate(now.parserReturnNowTime());

	}

	return;
	}
	case TO:
	{
		string endtime;
		string enddate;

		processX(userInput);
		processKeywordTo(userInput);
		checkStart(enddate, endtime, userInput);
		para._task.changeTaskEndDate(enddate);
		para._task.changeTaskEndTime(endtime);

		if (para._task.getTaskEndDate() == "" && para._task.getTaskEndTime() != ""){
			parserProcess now;
			para._task.changeTaskEndDate(now.parserReturnNowTime());
		}

		return;
	}
	case ON:
	{
		string ontime;
		string ondate;

		processX(userInput);
		processKeywordOn(userInput);
		checkStart(ondate, ontime, userInput);
		para._task.changeTaskStartDate(ondate);
		para._task.changeTaskStartTime(ontime);

		if (para._task.getTaskStartDate() == "" && para._task.getTaskStartTime() != ""){
			parserProcess now;
			para._task.changeTaskStartDate(now.parserReturnNowTime());
		}

		return;

	}
	case AT:
	{
		string attime;
		string atdate;

		processX(userInput);
		processKeywordAt(userInput);
		checkStart(atdate, attime, userInput);
		para._task.changeTaskStartDate(atdate);
		para._task.changeTaskStartTime(attime);

		if (para._task.getTaskStartDate() == "" && para._task.getTaskStartTime() != ""){
			parserProcess now;
			para._task.changeTaskStartDate(now.parserReturnNowTime());
		}

		return;

	}
	case BY:
	{
		string bytime;
		string bydate;

		processX(userInput);
		processKeywordBy(userInput);
		checkStart(bydate, bytime, userInput);
		para._task.changeTaskDeadlineDate(bydate);
		para._task.changeTaskDeadlineTime(bytime);

		if (para._task.getTaskDeadlineDate() == "" && para._task.getTaskDeadlineTime() != ""){
			parserProcess now;
			para._task.changeTaskDeadlineDate(now.parserReturnNowTime());
		}

		return;

	}
	case AFTER:
	{
		
		string afttime;
		string aftdate;

		processX(userInput);
		processKeywordAfter(userInput);

		checkStart(aftdate, afttime, userInput);
		para._task.changeTaskStartDate(aftdate);
		para._task.changeTaskStartTime(afttime);

		if (para._task.getTaskStartDate() == "" && para._task.getTaskStartTime() != ""){
			parserProcess now;
			para._task.changeTaskStartDate(now.parserReturnNowTime());
		}

		return;

	}
	case BEFORE:
	{
		string beftime;
		string befdate;

		processX(userInput);
		processKeywordBefore(userInput);
		checkStart(befdate, beftime, userInput);
		para._task.changeTaskDeadlineDate(befdate);
		para._task.changeTaskDeadlineTime(beftime);

		if (para._task.getTaskDeadlineDate() == "" && para._task.getTaskDeadlineTime() != ""){
			parserProcess now;
			para._task.changeTaskDeadlineDate(now.parserReturnNowTime());
		}

		return;
	}
	case FROM_TO:
	{
		string tempName;
		
		index = userInput.find("from") - 1;
		tempName = userInput.substr(0, index);

		para._task.changeTaskName(userInput.substr(0, index));

		processBeforeKeywordFrom(userInput);
		index = findToIndex(userInput)-1;
		eventStartDetails = userInput.substr(0, index);
		userInput.erase(0, index + 4);

		eventEndDetails = userInput;
		
		processStartKey(eventStartDetails);
		processEndKey(eventEndDetails);
		
		return;
	}
	}
	return;
}

paraList* Parser::parseCommand(string userInput){

	assert(userInput != "");

	para.clearTask();
	assertCommand(userInput);
	sortCommand(userInput);
	processCommand(userInput);

	return &para;
}

void Parser::processCommand(string &userInput){
	string command = para.getCommand();
	parserProcess a;
	int index;

	assertCommand(command);


	if (regex_search(command, ADD_PATTERN)){
		sortDetails(userInput);
		processDate();
		processTime();
	} else if (regex_search(command, DELETE_PATTERN)){
		istringstream iss(userInput);
		iss >> index;
		para.processDeleteNumber(index);
	} else if (regex_search(command, DISPLAY_PATTERN)){
		istringstream iss(userInput);
		iss >> index;
		para.processDisplayNumber(index);

	} else if (regex_search(command, UPDATE_PATTERN)){
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

		processUpdateKeywords();
		convertKeywordTime(para.getInput(),para.getKeyword());

	} else if (regex_search(command, MARK_PATTERN)){
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);
		para.processMarkStatus("mark");

	} else if (regex_search(command, UNMARK_PATTERN)){
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);
		para.processMarkStatus("unmark");

	} else if (regex_search(command, UNMARK_PATTERN)){
		para.processUserDir(userInput);

	} else if (regex_search(command, SEARCH_PATTERN)){
		para.processSearchWord(userInput);

	} else if (regex_search(command, SAVE_PATTERN)){
		para.processUserDir(userInput);

	} else if (regex_search(command, VIEW_C_PATTERN)){

	} else if (regex_search(command, VIEW_I_PATTERN)){

	} else if (regex_search(command, VIEW_PATTERN))	{

	} else {
		command == "invalid";

	}

	return;
}

void Parser::processBeforeKeywordf(string &userInput){
	int index;

	index = userInput.find(":f") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);

	return;
}

void Parser::processBeforeKeywordt(string &userInput){
	int index;
	index = userInput.find(":t") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);

	return;
}

void Parser::processBeforeKeywordb(string &userInput){
	int index;
	index = userInput.find(":b") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);

	return;
}

string Parser::checkingKeywordX(string &userInput){
	string details;

	if (userInput.find("!") != string::npos){
		int index = userInput.find("!") - 1;
		details = userInput.substr(0, index);
		userInput.erase(0, index + 2);
		para._task.changeTaskPriority(userInput);
	} else {
		details = userInput;
	}

	return details;
}

Parser::keywordType Parser::determineKeywords(string userInput){

	string command = para.getCommand();

	if (command.find("#") != string::npos){
		para.processCommand(command.substr(0, 3));
		
		return ABST_NIL;
	} else if (!regex_search(userInput, EXP_PATTERN)){

		return NONE;

	} else if (regex_search(userInput, FROM_PATTERN) && regex_search(userInput, TO_PATTERN)){
		
		return FROM_TO;

	} else if (regex_search(userInput, F_PATTERN) && !regex_search(userInput, T_PATTERN)){
		
		return STARTONLY;

	} else if (!regex_search(userInput, F_PATTERN) && regex_search(userInput, T_PATTERN)){
		
		return ENDONLY;

	} else if (regex_search(userInput, BY_PATTERN)){

		return DEADLINE;
	
	} else if (regex_search(userInput, NTRL_FROM_PATTERN)){
		
		return FROM;

	} else if (regex_search(userInput, NTRL_BEFORE_PATTERN)){
		
		return BEFORE;

	} else if (regex_search(userInput, NTRL_AFTER_PATTERN)){
		
		return AFTER;

	} else if (regex_search(userInput, NTRL_TO_PATTERN)){
		
		return TO;

	} else if (regex_search(userInput, NTRL_BY_PATTERN)){
		
		return BY;

	} else if (regex_search(userInput, NTRL_ON_PATTERN)){
		
		return ON;

	} else if (regex_search(userInput, NTRL_AT_PATTERN)){
		
		return AT;

	} else {
		
		return  START_END;
	}
}

void Parser::checkStart(string&startdate, string &starttime, string userinput){
	
	startdate = checkSD(userinput);
	starttime = checkST(userinput);

	return;
}

string Parser::checkST(string userinput){
	string  date[50], time[50];
	int count1 = 0, count2 = 0;

	time[0] = "";

	const sregex_token_iterator d;
	for (sregex_token_iterator e(userinput.begin(), userinput.end(), TIME_PATTERN); e != d; ++e){

		time[count2] = *e;
		count2++;
	}

	return time[0];
}

string Parser::checkSD(string userinput){

	string  date[50], time[50];
	int count1 = 0, count2 = 0;

	date[0] = "";

	const sregex_token_iterator end;
	for (sregex_token_iterator i(userinput.begin(), userinput.end(), DATE_PATTERN); i != end; ++i){

		date[count1] = *i;
		count1++;
	}

	return date[0];
}

void Parser::checkEnd(string&enddate, string &endtime, string userinput){

	enddate = checkSD(userinput);
	endtime = checkST(userinput);

	return;
}

void Parser::processX(string userinput){

	string  keyword[50];
	int  count = 0;

	smatch X;
	const sregex_token_iterator d;
	for (sregex_token_iterator e(userinput.begin(), userinput.end(), X_PATTERN); e != d; ++e){

		keyword[count] = *e;
		count++;
	}
	
	if (regex_search(userinput, X, X_PATTERN))
		para._task.changeTaskPriority(keyword[0].substr(1));

	return;
}

void Parser::getNoneToken(string userinput, int& xtoken, int& timetoken, int& datetoken){

	smatch matchX;
	smatch matchdate;
	smatch matchtime;

	if (regex_search(userinput, matchX, X_PATTERN))
		xtoken = matchX.position(0);
	if (regex_search(userinput, matchdate, DATE_PATTERN))
		datetoken = matchdate.position(0);
	if (regex_search(userinput, matchtime, TIME_PATTERN))
		timetoken = matchtime.position(0);

	return;
}

void Parser::processNum(int& a, int& b, int& c, int& answer){

	if (a < b){
		if (c < a){
			answer = c;
		} else {
			answer = a;
		}
	} else {
		if (c < b){
			answer = c;
		} else {
			answer = b;
		}
	}

	return;
}

void Parser::processDate(){
	parserProcess end;
	parserProcess start;
	parserProcess deadline;

	string startStr = para._task.getTaskStartDate();
	string endStr = para._task.getTaskEndDate();
	string deadlineStr = para._task.getTaskDeadlineDate();
	
	if (startStr != ""){
		
		start.setNowDT();
		start.processDate(startStr);
		para._task.changeTaskStartDate(start.parserReturnDate());

	}

	if (endStr != ""){
		
		end.setNowDT();
		end.processDate(endStr);
		para._task.changeTaskEndDate(end.parserReturnDate());
	}

	if (deadlineStr != ""){
		
		deadline.setNowDT();
		deadline.processDate(deadlineStr);
		para._task.changeTaskDeadlineDate(deadline.parserReturnDate());
	}

	return;
}

void Parser::processKeywordFrom(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_FROM_PATTERN);

	token = matchx.position(0);

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 5);

	return;
}

void Parser::processKeywordTo(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_TO_PATTERN);

	token = matchx.position(0);

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;
}

void Parser::processKeywordBy(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_BY_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;
}

void Parser::processKeywordAt(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_AT_PATTERN);

	token = matchx.position(0);

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;
}

void Parser::processKeywordBefore(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_BEFORE_PATTERN);

	token = matchx.position(0);
	cout << "token: " << token << endl;

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 6);

	return;
}

void Parser::processKeywordOn(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_ON_PATTERN);

	token = matchx.position(0);

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 3);

	return;
}

void Parser::processKeywordAfter(string &userInput){
	int token;
	smatch matchx;

	regex_search(userInput, matchx, NTRL_AFTER_PATTERN);

	token = matchx.position(0);

	para._task.changeTaskName(userInput.substr(0, token));
	userInput.erase(0, token + 6);

	return;
}

void Parser::processTime(){
	parserProcess end, start, deadline;
	string startStr = para._task.getTaskStartTime();
	string endStr = para._task.getTaskEndTime();
	string deadlineStr = para._task.getTaskDeadlineTime();
	cout << "DLdate: " << deadlineStr << endl;

	if (startStr != ""){
		start.setNowDT();
		start.processTime(startStr);
		para._task.changeTaskStartTime(start.parserReturnTime());
	}

	if (endStr != ""){
		end.setNowDT();
		end.processTime(endStr);
		para._task.changeTaskEndTime(end.parserReturnTime());
	}

	if (deadlineStr != ""){
		deadline.setNowDT();
		cout << deadlineStr << endl;
		deadline.processTime(deadlineStr);
		para._task.changeTaskDeadlineTime(deadline.parserReturnTime());
	}

	return;
}

void Parser::processBeforeKeywordFrom(string &userInput){
	int index;

	index = userInput.find("from") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 6);

	return;
}

void Parser::processUpdateKeywords(){  

	string updateint;
	string input = para.getInput();
	string keyword=para.getKeyword();
	
	ostringstream oss;
	oss << para.getUpdateInteger();
	updateint = oss.str();

	if (updateint == input){
		para.processInput("");
		para.processKeyWord("");

	} else if (input == keyword){
		para.processInput("");
	}

	return;
}

void  Parser::processupdateNone (string& userInput, int& process){
	string dldate, dltime;
	
	if (process != 1000){
		para._task.changeTaskName(userInput.substr(0, process - 1));
		userInput.erase(0, process - 1);
		checkStart(dldate, dltime, userInput);
		para._task.changeTaskDeadlineDate(dldate);
		para._task.changeTaskDeadlineTime(dltime);
		processX(userInput);
	} else {
		para._task.changeTaskName(checkingKeywordX(userInput));
	}

	return;
}

void Parser::convertKeywordTime(string& input,string& type){
	if (input != ""&& (para.getKeyword() == "start-date" | para.getKeyword() == "end-date" | para.getKeyword() == "endline-date")){
		parserProcess end;

		end.setNowDT();
		end.processDate(input);
		para.processInput(end.parserReturnDate());

	} else if (input != "" && (para.getKeyword() == "start-time" | para.getKeyword() == "end-time" | para.getKeyword() == "endline-time")){
		parserProcess end;

		end.setNowDT();
		end.processTime(input);
		para.processInput(end.parserReturnTime());
	}

	return;	
}

void Parser::processStartKey(string& eventStartDetails){

	string startDate;
	string startime;
	checkStart(startDate, startime, eventStartDetails);
	para._task.changeTaskStartDate(startDate);
	para._task.changeTaskStartTime(startime);
	processX(eventStartDetails);

	return;
}

void Parser::processEndKey(string&  eventEndDetails){
	string endDate;
	string endTime;
	checkEnd(endDate, endTime, eventEndDetails);
	para._task.changeTaskEndDate(endDate);
	para._task.changeTaskEndTime(endTime);
	processX(eventEndDetails);

	return;
}

int  Parser::findToIndex(string& input){

	smatch matchX;
	int match=0;

	if (regex_search(input, matchX, TO_PATTERN)){
		match = matchX.position(0);
	}

	return match;
}

void Parser::assertCommand(string command){

	assert(command != " ");
	assert(command != "");

	return;
}