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
	paraList *parseCommand(string);
	paraList para;
	string checkST(string);
	string checkSD(string);
	string checkingKeywordX(string &);
	keywordType determineKeywords(string);
	void sortCommand(string &);
	void sortDetails(string &);
	void processCommand(string &);
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
	void processX(string);
	void processNum(int&, int&, int&, int&);
	void processDate();
	void processTime();
	void processBeforeKeywordFrom(string &);
	void processUpdateKeywords();
	void processupdateNone(string&, int&);
	void processStartKey(string&);
	void processEndKey(string&);
	void checkStart(string&, string &, string);
	void checkEnd(string&, string &, string);
    void getNoneToken(string, int&, int&, int&);
	void getLocalTime();
	void convertKeywordTime(string&, string&);
	void assertCommand(string);
	int  findToIndex(string&);
};

#endif
