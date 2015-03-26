#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Logic_Test
{
	TEST_CLASS(Logic_Test)
	{
	public:

		TEST_METHOD(addTask_Successful)
		{
			Logic addTaskObject;

			string userInput = "add Name StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority";
			paraList* parameterList = addTaskObject.getParaList(userInput);
			addTaskObject.executeCommand(*parameterList);
			vector<string> actualOutputVector = addTaskObject.getTextFileCopy();

			string expectedOutputString = "Name StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Incomplete";
			string actualOutputString = actualOutputVector[0];

			Assert::AreEqual(expectedOutputString, actualOutputString);


		}

		/*
		TEST_METHOD(addTask_Successful)
		{
			Logic addTaskObject;

			string userInput = "add Name StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority";
			paraList* parameterList = addTaskObject.getParaList(userInput);
			string outputFile = "addTaskTest.txt";
			addTaskObject.executeCommand(*parameterList, outputFile);
			vector<string> actualOutputVector = addTaskObject.getTextFileCopy();

			string expectedOutputString = "Name StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Incompleted";
			string actualOutputString = actualOutputVector[0];

			Assert::AreEqual(expectedOutputString, actualOutputString);


		}
		*/

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