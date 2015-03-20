#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace addTask_Test
{
	TEST_CLASS(addTask_Test)
	{
	public:

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

	};
}