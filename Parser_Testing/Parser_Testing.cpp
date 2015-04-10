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
	

	};
}