#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task_Testing
{		
	TEST_CLASS(Task_Testing)
	{
	public:
		
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
		
	};
}


/*	string _taskName;
Timeframe _taskStart;
Timeframe _taskEnd;
Timeframe _taskDeadline;
string _taskPriority;
string _taskStatus;

string getTaskDetails(){

ostringstream oss;
oss << _taskName << " "
<< _taskStart.date << " "
<< _taskStart.time << " "
<< _taskEnd.date << " "
<< _taskEnd.time << " "
<< _taskDeadline.date << " "
<< _taskDeadline.time << " "
<< _taskPriority << " " << endl;
//<< _taskStatus << endl;

return oss.str();
}

void changeTaskName(string);

void changeTaskStartDate(string);
void changeTaskStartTime(string);

void changeTaskEndDate(string);
void changeTaskEndTime(string);

void changeTaskDeadlineDate(string);
void changeTaskDeadlineTime(string);

void changeTaskPriority(string);

void changeTaskStatus();
*/
