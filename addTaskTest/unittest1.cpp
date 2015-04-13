// @author A0113555L
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Logic_Test {
	TEST_CLASS(Logic_Test) {
public:

	TEST_METHOD(executeCommand_add) {
		Logic testLogic;

		Task* test = new Task("Andy's bday", "14/4/2015", "13:00", "14/4/2015", "14:00", "", "", "!h", "");
		Task* test1 = new Task("Andy's bday1", "14/4/2015", "13:00", "14/4/2015", "14:00", "", "", "!h", "");
		Task* test1_copy = new Task("Andy's bday1", "14/4/2015", "13:00", "14/4/2015", "14:00", "", "", "!h", "");

		paraList testParaList;
		paraList testParaList1;
		paraList testParaList1_copy;

		testParaList.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test);
		testParaList1.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test1);
		testParaList1_copy.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test1_copy);

		string feedBack = testLogic.executeCommand(testParaList);
		string feedBack1 = testLogic.executeCommand(testParaList1);
		string feedBack1_copy = testLogic.executeCommand(testParaList1_copy);

		string actualOutputString = feedBack;
		string actualOutputString1 = feedBack1;
		string expectedOutputString = "Task Added Successfully! :>";

		Assert::AreEqual(expectedOutputString, actualOutputString);
		Assert::AreEqual(expectedOutputString, actualOutputString1);

	}

	TEST_METHOD(executeCommand_delete) {

		Logic testLogic;

		Task* test = new Task("Andy's bday", "10/4/2015", "13:00", "10/4/2015", "14:00", "11/4/2015", "00:00", "high", "Incompleted");
		Task* test1 = new Task("Andy's bday1", "10/4/2015", "13:00", "10/4/2015", "14:00", "11/4/2015", "00:00", "high", "Incompleted");

		paraList testParaList;
		paraList testParaList1;
		paraList testParaList2;

		testParaList.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test);
		testParaList1.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *test1);
		testParaList2.setparaList("delete", 1, 1, 1, "KEYWORD", "INPUT", *test1);

		testLogic.setTaskList();
		string feedBack1 = testLogic.executeCommand(testParaList);
		testLogic.setTaskList();
		string feedBack2 = testLogic.executeCommand(testParaList1);
		testLogic.setTaskList();
		string feedBack = testLogic.executeCommand(testParaList2);

		string expectedOutputString = feedBack;
		string actualOutputString = "Task Deleted Successfully!";

		Assert::AreEqual(expectedOutputString, actualOutputString);
	}
	};
}
