//@author A0111642W
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//Testing StartDT, EndDT, Priority Tests
namespace Parser_Testing
{		
	TEST_CLASS(newParserTest)
	{
	public:
		
		TEST_METHOD(taskNametest)
		{
			string userInput = "add andy";
			string output;
			string expectedOutput="andy";
		
			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskName();
			Assert::AreEqual(output,expectedOutput);

		}
		TEST_METHOD(taskDeadlineTimetest)
		{
			string userInput = "add CS Homework before 6pm";
			string output;
			string expectedOutput = "18:00";

			Parser a;

			a.parseCommand(userInput);

			output = a.para._task.getTaskDeadlineTime();
			Assert::AreEqual(output, expectedOutput);

		}
		TEST_METHOD(taskNametest2)
		{
			string userInput = "add# day after tmr";
			string output;
			string expectedOutput = "day after tmr";

			Parser a;
			 
			a.parseCommand(userInput);

			output = a.para._task.getTaskName();
			Assert::AreEqual(output, expectedOutput);

		}
		TEST_METHOD(taskStartEndTimetest)
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
		
		TEST_METHOD(nullStringNametest)
		{
			string userInput = "add ";
			string output;
			string expectedOutput = "";

			Parser testParser;

			testParser.parseCommand(userInput);

			output = testParser.para._task.getTaskName();
			Assert::AreEqual(output, expectedOutput);
		}
        //@author A0110469J
		TEST_METHOD(taskNameStartEndTimetest2)
		{
			string userInput = "add Try Muthu's Curry :f today 11am :t 23:59";
			string output;
			string expectedOutput1 = "Try Muthu's Curry";
			string expectedOutput2 = "11:00";
			string expectedOutput3 = "23:59";

			Parser testParser;

			testParser.parseCommand(userInput);

			output = testParser.para._task.getTaskName();
			Assert::AreEqual(output, expectedOutput1);

			output = testParser.para._task.getTaskStartTime();
			Assert::AreEqual(output, expectedOutput2);

			output = testParser.para._task.getTaskEndTime();
			Assert::AreEqual(output, expectedOutput3);
		}

		TEST_METHOD(taskNameStartEndDateTest)
		{
			string userInput = "add Finish V0.5 :f 24/11/2015 2pm :t 31/12/2015 2pm";
			string output;
			string expectedOutput1 = "24/11/2015";
			string expectedOutput2 = "31/12/2015";

			Parser testParser;

			testParser.parseCommand(userInput);

			output = testParser.para._task.getTaskStartDate();
			Assert::AreEqual(output, expectedOutput1);

			output = testParser.para._task.getTaskEndDate();
			Assert::AreEqual(output, expectedOutput2);
		}

		TEST_METHOD(taskPriorityTest)
		{
			string userInput = "add Bobby's party !high";
			string output;
			string expectedOutput = "high";


			Parser testParser;

			testParser.parseCommand(userInput);

			output = testParser.para._task.getTaskPriority();
			Assert::AreEqual(output, expectedOutput);
		}
		 
		TEST_METHOD(testparserProcessToday) {

			parserProcess testPP;

			testPP.setNowDT(); 

		}
	
	};
}