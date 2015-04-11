#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parser_Testing
{		
	TEST_CLASS(ParserTest)
	{
	public:
		
		TEST_METHOD(processCommandTesting1)
		{
			string userInput = "add andy";
			string output;
			string expectedOutput="andy";
		
			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskName();
			Assert::AreEqual(output,expectedOutput);

		}
		TEST_METHOD(processCommandTesting2)
		{
			string userInput = "add CS Homework before 6pm";
			string output;
			string expectedOutput = "18:00";

			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskDeadlineTime();
			Assert::AreEqual(output, expectedOutput);

		}
		TEST_METHOD(processCommandTesting3)
		{
			string userInput = "add# day after tmr";
			string output;
			string expectedOutput = "day after tmr";

			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskName();
			Assert::AreEqual(output, expectedOutput);

		}
		TEST_METHOD(processCommandTesting4)
		{
			string userInput = "add happytreefriends from tues 4:00pm to weds 8pm";
			string output;
			string expectedOutput1 = "16:00";
			string expectedOutput2 = "20:00";

			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskStartTime();
			Assert::AreEqual(output, expectedOutput1);

			output = a.para._task.getTaskEndTime();
			Assert::AreEqual(output, expectedOutput2);

		}
	

	};
}