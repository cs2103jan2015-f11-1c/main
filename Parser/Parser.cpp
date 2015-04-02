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
const regex TIME_PATTERN("((1[0-2]|0[1-9])((:|\.)[0-5][0-9])(Am|am|PM|pm|Pm|AM|aM|pM))|((1[0-2]|[1-9])(\\s)?(Am|am|PM|pm|Pm|AM|aM|pM|noon))|((1[0-2]|0[1-9])(\\s)?(o|O)(')?(clock))", std::tr1::regex_constants::icase);

Parser::Parser()
{}

void Parser::sortCommand(string &userInput)
{   
	
	int index;
	index=userInput.find_first_of(" ");
	string temp = userInput.substr(0, index);
	para.processCommand(temp);
	userInput.erase(0,index+1);
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
	case NONE:
	{	int a = 1000, b = 1000, c = 1000, process = 0;

	string dltime, dldate;
	getNoneToken(userInput, a, b, c);
	//cout << a << endl << b << endl << c << endl;
	processNum(a, b, c, process);
	//cout << "min" << process << endl;



	if (process != 1000)
	{	para._task.changeTaskName(userInput.substr(0,process-1));
	cout << "this is taskname:" << userInput.substr(0,process-1) << endl;
	userInput.erase(0,process-1);
	cout << "after erase:" << userInput<<endl;
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
		processBeforeKeywordFrom(userInput);
		checkStart(sd, st, userInput);
		para._task.changeTaskStartDate(sd);
		para._task.changeTaskStartTime(st);

		return;
	}
	case ENDONLY:
	{   string et, ed;
	    processX(userInput);
		processBeforeKeywordTo(userInput);
		checkEnd(ed, et, userInput);
		para._task.changeTaskEndDate(ed);
		para._task.changeTaskEndTime(et);
		return;
	}
	case DEADLINE:
	{
		string dt, dd;
		processX(userInput);
		processBeforeKeywordBy(userInput);
		checkEnd(dt, dd, userInput);
		para._task.changeTaskDeadlineDate(dd);
		para._task.changeTaskDeadlineTime(dt);
		return;
	}
	case START_END:
	{
		index = userInput.find("from") - 1;
		string tempName = userInput.substr(0, index);

		para._task.changeTaskName(userInput.substr(0, index));

		processBeforeKeywordFrom(userInput);
		index = userInput.find("to") - 1;
		_eventstartdetails = userInput.substr(0, index);
		userInput.erase(0, index + 4);
		
		
	
      _eventenddetails = userInput;
	  cout <<"eventstart" << _eventstartdetails << endl;
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

void Parser::splitstring (string &first,string &second,string &input)
{   int index;
    


   /*index=input.find_first_of(" ");
	first=input.substr(0,index);
	input.erase(0,index+1);
	second=input;
	*/
	return;
}

void Parser::processCommand(string &userInput)
{
	string command=para.getCommand();
	int index;
	parserProcess a;
	
	if(command=="add")
	{
		sortDetails(userInput);
		processDate();
	}
	else if(command=="delete")
	{   istringstream iss (userInput);
		iss>>index;	
	    para.processDeleteNumber(index);
	}
	else if(command=="display")
	{   istringstream iss (userInput);
	    iss>>index;
	    para.processDisplayNumber(index);
	   
	}
	else if(command=="update")
	{   int b,index;
	    string a;
		
	    b=userInput.find_first_of(" ");
	    a=userInput.substr(0,b);
        istringstream iss (a);
		iss>>index;
		userInput.erase(0,b+1);
		b=userInput.find_first_of(" ");
		para.processKeyWord(userInput.substr(0,b));
		userInput.erase(0,b+1);
		para.processInput(userInput);
		para.processUpdateNumber(index);
	}
	else if (command == "mark")
	{
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);

		para.processMarkStatus("mark");


	}
	else if (command == "unmark")
	{
		istringstream iss(userInput);
		iss >> index;
		para.processMarkIndex(index);

		para.processMarkStatus("unmark");



	}
	else if (command == "save")
	{
		para.processUserDir(userInput);

	}
	else
	{
		command == "invalid";

	}
	

	return;
}

void Parser::processBeforeKeywordFrom(string &userInput)
{
	int index;
   
	
	index=userInput.find("from")-1;
    para._task.changeTaskName(userInput.substr(0,index));
	userInput.erase(0,index+6);

	return;
}


void Parser::processBeforeKeywordTo(string &userInput)
{   int index;
	index=userInput.find("to")-1;
	para._task.changeTaskName(userInput.substr(0,index));
	userInput.erase(0,index+4);
	
		
	return;
}


void Parser::processBeforeKeywordBy(string &userInput)
{
	int index;
	index = userInput.find("by") - 1;
	para._task.changeTaskName(userInput.substr(0, index));
	userInput.erase(0, index + 4);
	

	return;
}






string Parser::checkingKeywordX(string &userInput)
{   
	string details;
	
	
	
	if(userInput.find("!")!=string::npos){  
	 int index=userInput.find("!")-1;
        details=userInput.substr(0,index);
		userInput.erase(0,index+2);
	    para._task.changeTaskPriority(userInput);}
	else{   
		
        details=userInput;
	     
        }

	return details;
}

Parser::keywordType Parser::determineKeywords(string userInput)
{
	if (userInput.find("from") == string::npos&&userInput.find("to") == string::npos&&userInput.find("by") == string::npos)
	{
		return NONE;
	}
	else if (userInput.find("from") != string::npos&&userInput.find("to") == string::npos)
	{
		

		return STARTONLY;
	}
	else if (userInput.find("from") == string::npos&&userInput.find("to") != string::npos)
	{
		
		return ENDONLY;
	}
	else if (userInput.find("by") != string::npos)
	{

		
		return DEADLINE;
	}
	else
	{
		return  START_END;
	}
}

void Parser::checkStart(string&startdate, string &starttime, string userinput)
{
	startdate = checkSD(userinput);
	starttime = checkST(userinput);
	return;

}


string Parser::checkST(string userinput)
{
	string  date[50], time[50];
	int count1 = 0, count2 = 0;

	const sregex_token_iterator d;
	for (sregex_token_iterator e(userinput.begin(), userinput.end(),TIME_PATTERN); e != d; ++e)
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
	for (sregex_token_iterator i(userinput.begin(), userinput.end(),DATE_PATTERN); i != end; ++i)
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
	if (regex_search(userinput,X,X_PATTERN))
    para._task.changeTaskPriority(keyword[0].substr(1));



	return;

}


void Parser::getNoneToken(string userinput, int& xtoken, int& timetoken, int& datetoken)
{
	
	

	smatch matchX,matchdate,matchtime;
	
	
	if(regex_search(userinput, matchX, X_PATTERN))
    xtoken = matchX.position(0);
	if(regex_search(userinput, matchdate, DATE_PATTERN))
    datetoken = matchdate.position(0);
	if(regex_search(userinput, matchtime,TIME_PATTERN))
    timetoken = matchtime.position(0);
	
	
	
	

   
   return ;
} 


void Parser::processNum(int& a,int& b,int& c,int& answer)
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
	parserProcess end,start,deadline;
	string startStr = para._task.getTaskStartDate();
	string endStr = para._task.getTaskEndDate();
	string deadlineStr = para._task.getTaskDeadlineDate();


	if (startStr!="")
	{
		start.setNowDT();
		start.processDate(startStr);
		para._task.changeTaskStartDate(start.parserReturnDate());

	}
	if (endStr != "")
	{
		end.setNowDT();
		end.processDate(endStr);
		para._task.changeTaskEndDate(end.parserReturnDate());
	}
	if (deadlineStr != "")
	{   
		
		deadline.setNowDT();
		deadline.processDate(deadlineStr);
		para._task.changeTaskDeadlineDate(deadline.parserReturnDate());
	}





}