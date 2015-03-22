#ifndef PARSER_H
#define PARSER_H

#include "paraList.h"

#include<iostream>
#include <string>


using namespace std;

class Parser{

private:
	

public:
enum keywordType { START_END, STARTONLY, ENDONLY , DEADLINE ,NONE  };
	
Parser();
paraList para;
void sortCommand(string &);
void sortDetails(string &);
paraList *parseCommand(string );
void processCommand(string &);
void splitstring (string &,string &,string &);

void processBeforeKeywordFrom(string &);
void processBeforeKeywordTo(string &);
void processBeforeKeywordBy(string &);
string checkingKeywordX(string &);
keywordType determineKeywords(string );
void checkStart(string&, string &, string );
void checkEnd(string&, string &, string );
void empty(string&, string &, string&, string &, string);
string checkST(string );
string checkSD(string );
void processX(string );
void getNoneToken(string,int&,int&,int&);
void processNum(int& , int&, int& ,int&);


};

#endif
