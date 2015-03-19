#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task_Testing
{		
	TEST_CLASS(Task_Testing)
	{
	public:
		
		TEST_METHOD(checkNull_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;

			actual= test->checkNull("Name");

			string expected = "Name ";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskName_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actualName;
			actualName = test->getTaskName();

			string expectedName = "Name";

			Assert::AreEqual(expectedName, actualName);
		
		}

		TEST_METHOD(getTaskStartDate_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskStartDate();

			string expected = "StartDate";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskStartTime_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskStartTime();

			string expected = "StartTime";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskEndDate_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskEndDate();

			string expected = "EndDate";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskEndTime_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskEndTime();

			string expected = "EndTime";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskDeadlineDate_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskDeadlineDate();

			string expected = "DeadlineDate";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskDeadlineTime_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskDeadlineTime();

			string expected = "DeadlineTime";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskPriority_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskPriority();

			string expected = "Priority";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(getTaskDetails_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			actual = test->getTaskDetails();

			string expected = "Name StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority";

			Assert::AreEqual(expected, actual);

		}
		
		TEST_METHOD(changeTaskName_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			test->changeTaskName("Name1");
			actual = test->getTaskName();

			string expected = "Name1";

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(changeTaskStartDate_test)
		{
			Task* test = new Task("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority");
			string actual;
			test->changeTaskStartDate("StartDate1");
			actual = test->getTaskStartDate();

			string expected = "StartDate1";

			Assert::AreEqual(expected, actual);

		}

		
	};
}


