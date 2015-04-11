#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Logic_Test
{
	TEST_CLASS(Logic_Test)
	{
	public:

		TEST_METHOD(executeCommand_add)
		{
			Logic testLogic;

			Task* test = new Task("Andy's bday", "10/04/2015", "1300", "10/04/2015", "1400", "11/04/2015", "0000", "high", "Incompleted");
			Task* test1 = new Task("Andy's bday1", "10/04/2015", "1300", "10/04/2015", "1400", "11/04/2015", "0000", "high", "Incompleted");
			Task* test2 = new Task("Andy's bday1", "10/04/2015", "1300", "10/04/2015", "1400", "11/04/2015", "0000", "high", "Incompleted");


			paraList testParaList;
			paraList testParaList1;
			paraList testParaList2;


			testParaList.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test);
			testParaList1.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test1);
			testParaList2.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test2);


			string feedBack=testLogic.executeCommand(testParaList);
			string feedBack1 = testLogic.executeCommand(testParaList1);
			string feedBack2 = testLogic.executeCommand(testParaList2);

			
			string actualOutputString = feedBack;
			string actualOutputString1 = feedBack1;
			string expectedOutputString = "Task Added Successfully! :>";

			Assert::AreEqual(expectedOutputString, actualOutputString);
			Assert::AreEqual(expectedOutputString, actualOutputString1);

			string actualOutputString3 = feedBack2;
			string expectedOutputString1 = "That Task Has Already Existed~! Please Enter A New Task~";
			Assert::AreEqual(expectedOutputString1, actualOutputString3);


			vector<string> actualOutputVector = testLogic.getReturnGUI();
			vector<string> expectedOutputVector;
			expectedOutputVector.push_back("Andy's bday    10/04/2015 1300 10/04/2015 1400 11/04/2015 0000 high Incompleted");
			expectedOutputVector.push_back("Andy's bday1   10/04/2015 1300 10/04/2015 1400 11/04/2015 0000 high Incompleted");

			Assert::AreEqual(expectedOutputVector[0], actualOutputVector[0]);
			Assert::AreEqual(expectedOutputVector[1], actualOutputVector[1]);

		}
		TEST_METHOD(executeCommand_display) {
			
			Logic testLogic;

			Task* test = new Task("Andy's bday", "10/04/2015", "1300", "10/04/2015", "1400", "11/04/2015", "0000", "high", "Incompleted");
			Task* test1 = new Task("Andy's bday1", "10/04/2015", "1300", "10/04/2015", "1400", "11/04/2015", "0000", "high", "Incompleted");

			paraList testParaList;
			paraList testParaList1;
			paraList testParaList2;

			testParaList.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test);
			testParaList1.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test1);
			testParaList2.setparaList("display", 1, 2, 3, "KEYWORD", "INPUT", *test1);

			string feedBack1 = testLogic.executeCommand(testParaList);
			string feedBack2 = testLogic.executeCommand(testParaList1);
			string feedBack = testLogic.executeCommand(testParaList2);
		

			string expectedOutputString = feedBack;
			string actualOutputString = "All Tasks Are Displayed!";

			Assert::AreEqual(expectedOutputString, actualOutputString);


			vector<string> actualOutputVector = testLogic.getReturnGUI();
			vector<string> expectedOutputVector;
			expectedOutputVector.push_back("Andy's bday    10/04/2015 1300 10/04/2015 1400 11/04/2015 0000 high Incompleted");
			expectedOutputVector.push_back("Andy's bday1   10/04/2015 1300 10/04/2015 1400 11/04/2015 0000 high Incompleted");

			Assert::AreEqual(expectedOutputVector[0], actualOutputVector[0]);
			Assert::AreEqual(expectedOutputVector[1], actualOutputVector[1]);
		}
		




	};
}

/*
void Welcome();

void CommandPrompt();

string getExePath();

//bool validDirectory(string);

void createNewDirectory(string);

void changeFileDirectory(string);

void processChangeDirectoryRequest(string);

string getFileName();

paraList* getParaList(string);

//void writeFile(vector<string>, string);

string getUserInput();

string getCommand(paraList);

Task getTask(paraList);

void copyTestFilefromStorage();

vector<string> getTextFileCopy();

void callInitialise(string);

bool notExistingTask(Task*);

void executeCommand(paraList, string);

void displayFeedback(string);
*/