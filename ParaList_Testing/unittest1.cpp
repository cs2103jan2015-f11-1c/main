//@author A0113555L
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParaList_Testing {
	TEST_CLASS(ParaList_Testing) {
public:

	TEST_METHOD(getTask_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		Task actual = test.getTask();
		Task* testTask = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		Task expected = *testTask;

		string actual1 = actual.getTaskDetails();
		string expected1 = expected.getTaskDetails();

		Assert::AreEqual(actual1, expected1);
	}

	TEST_METHOD(getCommand_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		string actual = test.getCommand();
		string expected = "add";

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(getDeleteInteger_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		int actual = test.getDeleteInteger();
		int expected = 1;

		Assert::AreEqual(actual, expected);

		//This is a boundary testing for getDeleteInteger. 
		//when the user key in delete 0, it is an invalid index, just outside the boundary
		paraList test1;
		Task* taskTest1 = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test1.setparaList("add", 0, 2, 3, "KEYWORD", "INPUT", *taskTest);

		int actual1 = test.getDeleteInteger();
		int expected1 = 0;

		Assert::AreEqual(actual, expected);

	}

	TEST_METHOD(getDisplayInteger_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		int actual = test.getDisplayInteger();
		int expected = 2;

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(getUpdateInteger_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		int actual = test.getUpdateInteger();
		int expected = 3;

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(processCommand_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processCommand("delete");
		string actual = test.getCommand();
		string expected = "delete";

		Assert::AreEqual(actual, expected);
	}

	//void processTask(string inputTask);

	TEST_METHOD(processDeleteNumber_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processDeleteNumber(2);
		int actual = test.getDeleteInteger();
		int expected = 2;

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(processDisplayNumber_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processDisplayNumber(3);
		int actual = test.getDisplayInteger();
		int expected = 3;

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(processUpdateNumber_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processUpdateNumber(1);
		int actual = test.getUpdateInteger();
		int expected = 1;

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(clearAllNumber_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.clearAllNumber();

		int actual = test.getDeleteInteger();
		int expected = NULL;

		int actual1 = test.getDisplayInteger();
		int expected1 = NULL;

		int actual2 = test.getUpdateInteger();
		int expected2 = NULL;

		Assert::AreEqual(actual, expected);
		Assert::AreEqual(actual1, expected1);
		Assert::AreEqual(actual2, expected2);
	}

	TEST_METHOD(getKeyword_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		string actual = test.getKeyword();
		string expected = "KEYWORD";

		Assert::AreEqual(actual, expected);
	}


	TEST_METHOD(getInput_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);


		string actual = test.getInput();
		string expected = "INPUT";

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(processKeyWord_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processKeyWord("KEYWORD!");
		string actual = test.getKeyword();
		string expected = "KEYWORD!";

		Assert::AreEqual(actual, expected);
	}

	TEST_METHOD(processInput_test) {
		paraList test;
		Task* taskTest = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "Incompleted");
		test.setparaList("add", 1, 2, 3, "KEYWORD", "INPUT", *taskTest);

		test.processInput("INPUT!");
		string actual = test.getInput();
		string expected = "INPUT!";

		Assert::AreEqual(actual, expected);
	}


	};
}

/*
paraList();
//for unit testing purpose.

void clearTask();

*/