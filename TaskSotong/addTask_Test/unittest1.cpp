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
			string userInput = "add Andy's birthday";
			paraList* parameterList = addTaskObject.getParaList(userInput);
			string outputFile = "addTaskTest.txt";
			addTaskObject.executeCommand(*parameterList, outputFile);
			vector<string> actualOutput = addTaskObject.getTextFileCopy();
			vector<string> expectedOutput;
			expectedOutput.push_back("Andy's birthday");

			Assert::AreEqual(expectedOutput[0], actualOutput[0]);


		}

	};
}