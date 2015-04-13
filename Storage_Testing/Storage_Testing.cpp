//@author A0114484H
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Storage_Testing
{
	TEST_CLASS(StorageTest)
	{
	public:

		
		TEST_METHOD(addTaskTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask("Homework", "03/05/15", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask);
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskName();
			string expectedOutput1 = "Homework";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[0].getTaskStartDate();
			string expectedOutput2 = "03/05/15";
			Assert::AreEqual(output, expectedOutput2);

			output = testVector[0].getTaskStartTime();
			string expectedOutput3 = "09:00";
			Assert::AreEqual(output, expectedOutput3);
		}
		//@author A0110469J
		TEST_METHOD(deleteTaskTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Homework", "03/05/15", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Task myTask2("Hello", "03/06/15", "19:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.deleteTask("tasksotong.txt", 1);
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskName();
			string expectedOutput1 = "Hello";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[0].getTaskStartDate();
			string expectedOutput2 = "03/06/15";
			Assert::AreEqual(output, expectedOutput2);

			output = testVector[0].getTaskStartTime();
			string expectedOutput3 = "19:00";
			Assert::AreEqual(output, expectedOutput3);
		}
		// @author A0114484H
		TEST_METHOD(updateTaskTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Homework", "03/05/2015", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Task myTask2("Hello", "03/06/2015", "19:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.updateTask("tasksotong.txt", 1, "name", "Hullabaloo");
			myStorage.updateTask("tasksotong.txt", 1, "end-date", "21/12/2016");
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskName();
			string expectedOutput1 = "Hullabaloo";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[0].getTaskEndDate();
			string expectedOutput2 = "21/12/2016";
			Assert::AreEqual(output, expectedOutput2);
		}


		TEST_METHOD(markTaskTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Homework", "03/05/15", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Task myTask2("Hello", "03/06/15", "19:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.markTask("tasksotong.txt", 1);
			myStorage.markTask("tasksotong.txt", 2);
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskStatus();
			string expectedOutput1 = "Completed";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[1].getTaskStatus();
			string expectedOutput2 = "Completed";
			Assert::AreEqual(output, expectedOutput2);
		}


		TEST_METHOD(unmarkTastTest){
			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Homework", "03/05/15", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Task myTask2("Hello", "03/06/15", "19:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.markTask("tasksotong.txt", 1);
			myStorage.markTask("tasksotong.txt", 2);
			myStorage.unmarkTask("tasksotong.txt", 1);
			myStorage.unmarkTask("tasksotong.txt", 2);
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskStatus();
			string expectedOutput1 = "Incomplete";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[1].getTaskStatus();
			string expectedOutput2 = "Incomplete";
			Assert::AreEqual(output, expectedOutput2);
		}

		TEST_METHOD(clearAllTasksTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Andy Soh's drinking party", "10 May", "8pm", "11 May", "2am", "today", "night", "low", "");
			Task myTask2("Jie Yang cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.addTask(myTask3);
			myStorage.clearAllTasks();
			testVector = myStorage.returnTaskList();

			Assert::IsTrue(testVector.empty());
		}
		//@author A0110469J
		TEST_METHOD(sortTaskByNameTest){

			Storage myStorage;
			vector<Task> testVector;
			Task myTask1("Andy Soh's drinking party", "10 May", "8pm", "11 May", "2am", "today", "night", "low", "");
			Task myTask2("Jie Yang cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Task myTask4("Homework", "03/05/15", "09:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Task myTask5("Hello", "03/06/15", "19:00", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			string output;

			myStorage.addTask(myTask1);
			myStorage.addTask(myTask2);
			myStorage.addTask(myTask3);
			myStorage.addTask(myTask4);
			myStorage.addTask(myTask5);
			myStorage.sortTaskByName("tasksotong.txt");
			testVector = myStorage.returnTaskList();

			output = testVector[0].getTaskName();
			string expectedOutput1 = "Andy Soh's drinking party";
			Assert::AreEqual(output, expectedOutput1);

			output = testVector[1].getTaskName();
			string expectedOutput2 = "Gan Tian's dinner date";
			Assert::AreEqual(output, expectedOutput2);

			output = testVector[2].getTaskName();
			string expectedOutput3 = "Hello";
			Assert::AreEqual(output, expectedOutput3);

			output = testVector[3].getTaskName();
			string expectedOutput4 = "Homework";
			Assert::AreEqual(output, expectedOutput4);

			output = testVector[4].getTaskName();
			string expectedOutput5 = "Hello";
			Assert::AreNotEqual(output, expectedOutput5);
		}
	};
}