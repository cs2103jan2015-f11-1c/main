#include <iostream>
#include <string>
#include "Parser.h"
#include "paraList.h"



using namespace std;

int main()
{
	Parser test;
	paraList a;
	string teststring;
	getline(cin,teststring);

	test.parseCommand(teststring);
	
	
	
	
	return 0; 
}


