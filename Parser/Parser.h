#ifndef PARSER_H
#define PARSER_H

#include "paraList.h"
#include "parserProcess.h"

#include<iostream>
#include <string>
#include <regex>


using namespace std;

class Parser{

private:


public:
	enum keywordType { START_END, STARTONLY, ENDONLY, DEADLINE, NONE, BY, AT, AFTER, BEFORE, FROM, TO, ON, FROM_TO, ABST_NIL };


	Parser();
	paraList para;
	void sortCommand(string &);
	void sortDetails(string &);
	paraList *parseCommand(string);
	void processCommand(string &);
	void splitstring(string &, string &, string &);
	void processKeywordFrom(string &);
	void processKeywordTo(string &);
	void processKeywordBy(string &);
	void processKeywordAt(string &);
	void processKeywordBefore(string &);
	void processKeywordOn(string &);
	void processKeywordAfter(string &);
	void processBeforeKeywordf(string &);
	void processBeforeKeywordt(string &);
	void processBeforeKeywordb(string &);
	string checkingKeywordX(string &);
	keywordType determineKeywords(string);
	void checkStart(string&, string &, string);
	void checkEnd(string&, string &, string);
	void empty(string&, string &, string&, string &, string);
	string checkST(string);
	string checkSD(string);
	void processX(string);
	void getNoneToken(string, int&, int&, int&);
	void processNum(int&, int&, int&, int&);
	void getLocalTime();
	void processDate();
	void processTime();
	void processBeforeKeywordFrom(string &);

};

#endif
