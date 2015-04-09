#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Storage_Testing
{		
	TEST_CLASS(StorageTest)
	{
	public:
		
		TEST_METHOD(addTaskTest){
			Task myTask("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Storage myStorage;
			myStorage.addTask(&myTask);
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString = actualOutputVector[0];
			string expectedOutputString = "Name           StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Incomplete";
			Assert::AreEqual(expectedOutputString, actualOutputString);
		}

		TEST_METHOD(deleteTaskTest){
			Task myTask("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Storage myStorage;
			myStorage.addTask(&myTask);
			myStorage.updateTextFile("test_file.txt");
			myStorage.deleteTask("test_file.txt", 1);
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			Assert::IsTrue(actualOutputVector.empty());
		}

		TEST_METHOD(updateTaskTest){
			Task myTask("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Storage myStorage;
			myStorage.addTask(&myTask);
			myStorage.updateTextFile("test_file.txt");
			myStorage.updateTask("test_file.txt", 1, &myTask, "name", "newName");
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString = actualOutputVector[0];
			string expectedOutputString = "newName        StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Incomplete";
			Assert::AreEqual(expectedOutputString, actualOutputString);
		}

		TEST_METHOD(markTaskTest){
			Task myTask("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Storage myStorage;
			myStorage.addTask(&myTask);
			myStorage.updateTextFile("test_file.txt");
			myStorage.markTask("test_file.txt", 1);
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString = actualOutputVector[0];
			string expectedOutputString = "Name           StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Completed";
			Assert::AreEqual(expectedOutputString, actualOutputString);
		}

		TEST_METHOD(unmarkTastTest){
			Task myTask("Name", "StartDate", "StartTime", "EndDate", "EndTime", "DeadlineDate", "DeadlineTime", "Priority", "");
			Storage myStorage;
			myStorage.addTask(&myTask);
			myStorage.updateTextFile("test_file.txt");
			myStorage.markTask("test_file.txt", 1);
			myStorage.updateTextFile("test_file.txt");
			myStorage.unmarkTask("test_file.txt", 1);
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString = actualOutputVector[0];
			string expectedOutputString = "Name           StartDate StartTime EndDate EndTime DeadlineDate DeadlineTime Priority Incomplete";
			Assert::AreEqual(expectedOutputString, actualOutputString);
		}

		TEST_METHOD(undoTaskTest){
			// TODO: Your test code here
		}

		TEST_METHOD(clearAllTasksTest){
			Task myTask1("Andy Soh's drinking party", "10 May", "8pm", "11 May", "2am", "today", "night", "low", "");
			Task myTask2("Jie Yang cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Storage myStorage;
			myStorage.addTask(&myTask1);
			myStorage.addTask(&myTask2);
			myStorage.addTask(&myTask3);
			myStorage.clearAllTasks();
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			Assert::IsTrue(actualOutputVector.empty());
		}

		TEST_METHOD(searchTaskTest){
			Task myTask1("Andy Koh's birthday chalet", "18 Nov", "5pm", "19 Nov", "10am", "tomorrow", "afternoon", "high", "");
			Task myTask2("Andy Soh's graduation party", "10 May", "8pm", "11 May", "2am", "today", "night", "low", "");
			Task myTask3("Jie Yang cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask4("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Storage myStorage;
			myStorage.addTask(&myTask1);
			myStorage.addTask(&myTask2);
			myStorage.addTask(&myTask3);
			myStorage.addTask(&myTask4);
			myStorage.updateTextFile("test_file.txt");
			myStorage.searchTask("test_file.txt", "Andy");
		}

		TEST_METHOD(sortTaskByNameTest){
			Task myTask1("JIE YANG cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask2("Andy Soh's graduation party", "10 May", "8pm", "11 May", "2am", "today", "afternoon", "low", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Task myTask4("buy groceries", "8 Sep", "8am", "9 Sep", "10am", "monday", "morning", "medium", "");
			Task myTask5("Andy Koh's birthday chalet", "18 Nov", "5pm", "19 Nov", "10am", "tomorrow", "afternoon", "high", "");
			Task myTask6("andy Goh's concert recital", "17 Jul", "9pm", "18 Jul", "11pm", "today", "night", "low", "");
			Storage myStorage;
			myStorage.addTask(&myTask1);
			myStorage.addTask(&myTask2);
			myStorage.addTask(&myTask3);
			myStorage.addTask(&myTask4);
			myStorage.addTask(&myTask5);
			myStorage.addTask(&myTask6);
			myStorage.updateTextFile("test_file.txt");
			myStorage.sortTaskByName("test_file.txt");
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString1 = actualOutputVector[0];
			string actualOutputString2 = actualOutputVector[1];
			string actualOutputString3 = actualOutputVector[2];
			string actualOutputString4 = actualOutputVector[3];
			string actualOutputString5 = actualOutputVector[4];
			string actualOutputString6 = actualOutputVector[5];
			string expectedOutputString1 = "andy Goh's concert recital 17 Jul 9pm 18 Jul 11pm today night low Incomplete";
			string expectedOutputString2 = "Andy Koh's birthday chalet 18 Nov 5pm 19 Nov 10am tomorrow afternoon high Incomplete";
			string expectedOutputString3 = "Andy Soh's graduation party 10 May 8pm 11 May 2am today afternoon low Incomplete";
			string expectedOutputString4 = "buy groceries  8 Sep 8am 9 Sep 10am monday morning medium Incomplete";
			string expectedOutputString5 = "Gan Tian's dinner date 21 Mar 7pm 21 Mar 8pm saturday night high Incomplete";
			string expectedOutputString6 = "JIE YANG cut hair 13 Mar 1pm 15 Apr 2pm tomorrow evening medium Incomplete";
			Assert::AreEqual(expectedOutputString1, actualOutputString1);
			Assert::AreEqual(expectedOutputString2, actualOutputString2);
			Assert::AreEqual(expectedOutputString3, actualOutputString3);
			Assert::AreEqual(expectedOutputString4, actualOutputString4);
			Assert::AreEqual(expectedOutputString5, actualOutputString5);
			Assert::AreEqual(expectedOutputString6, actualOutputString6);
		}

		TEST_METHOD(sortTaskByStatusTest){
			Task myTask1("JIE YANG cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask2("Andy Soh's graduation party", "10 May", "8pm", "11 May", "2am", "today", "afternoon", "low", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Task myTask4("buy groceries", "8 Sep", "8am", "9 Sep", "10am", "monday", "morning", "medium", "");
			Task myTask5("Andy Koh's birthday chalet", "18 Nov", "5pm", "19 Nov", "10am", "tomorrow", "afternoon", "high", "");
			Task myTask6("andy Goh's concert recital", "17 Jul", "9pm", "18 Jul", "11pm", "today", "night", "low", "");
			Storage myStorage;
			myStorage.addTask(&myTask1);
			myStorage.addTask(&myTask2);
			myStorage.addTask(&myTask3);
			myStorage.addTask(&myTask4);
			myStorage.addTask(&myTask5);
			myStorage.addTask(&myTask6);
			myStorage.updateTextFile("test_file.txt");
			myStorage.markTask("test_file.txt", 2);
			myStorage.updateTextFile("test_file.txt");
			myStorage.markTask("test_file.txt", 6);
			myStorage.updateTextFile("test_file.txt");
			myStorage.sortTaskByStatus("test_file.txt");
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString1 = actualOutputVector[0];
			string actualOutputString2 = actualOutputVector[1];
			string actualOutputString3 = actualOutputVector[2];
			string actualOutputString4 = actualOutputVector[3];
			string actualOutputString5 = actualOutputVector[4];
			string actualOutputString6 = actualOutputVector[5];
			string expectedOutputString1 = "andy Goh's concert recital 17 Jul 9pm 18 Jul 11pm today night low Completed";
			string expectedOutputString2 = "Andy Soh's graduation party 10 May 8pm 11 May 2am today afternoon low Completed";
			string expectedOutputString3 = "Andy Koh's birthday chalet 18 Nov 5pm 19 Nov 10am tomorrow afternoon high Incomplete";
			string expectedOutputString4 = "buy groceries  8 Sep 8am 9 Sep 10am monday morning medium Incomplete";
			string expectedOutputString5 = "Gan Tian's dinner date 21 Mar 7pm 21 Mar 8pm saturday night high Incomplete";
			string expectedOutputString6 = "JIE YANG cut hair 13 Mar 1pm 15 Apr 2pm tomorrow evening medium Incomplete";
			Assert::AreEqual(expectedOutputString1, actualOutputString1);
			Assert::AreEqual(expectedOutputString2, actualOutputString2);
			Assert::AreEqual(expectedOutputString3, actualOutputString3);
			Assert::AreEqual(expectedOutputString4, actualOutputString4);
			Assert::AreEqual(expectedOutputString5, actualOutputString5);
			Assert::AreEqual(expectedOutputString6, actualOutputString6);
		}

		TEST_METHOD(sortTaskByPriorityTest){
			Task myTask1("JIE YANG cut hair", "13 Mar", "1pm", "15 Apr", "2pm", "tomorrow", "evening", "medium", "");
			Task myTask2("Andy Soh's graduation party", "10 May", "8pm", "11 May", "2am", "today", "afternoon", "low", "");
			Task myTask3("Gan Tian's dinner date", "21 Mar", "7pm", "21 Mar", "8pm", "saturday", "night", "high", "");
			Task myTask4("buy groceries", "8 Sep", "8am", "9 Sep", "10am", "monday", "morning", "medium", "");
			Task myTask5("Andy Koh's birthday chalet", "18 Nov", "5pm", "19 Nov", "10am", "tomorrow", "afternoon", "high", "");
			Task myTask6("andy Goh's concert recital", "17 Jul", "9pm", "18 Jul", "11pm", "today", "night", "low", "");
			Storage myStorage;
			myStorage.addTask(&myTask1);
			myStorage.addTask(&myTask2);
			myStorage.addTask(&myTask3);
			myStorage.addTask(&myTask4);
			myStorage.addTask(&myTask5);
			myStorage.addTask(&myTask6);
			myStorage.updateTextFile("test_file.txt");
			myStorage.sortTaskByPriority("test_file.txt");
			myStorage.updateTextFile("test_file.txt");
			vector<string> actualOutputVector = myStorage.returnTextFileCopy();
			string actualOutputString1 = actualOutputVector[0];
			string actualOutputString2 = actualOutputVector[1];
			string actualOutputString3 = actualOutputVector[2];
			string actualOutputString4 = actualOutputVector[3];
			string actualOutputString5 = actualOutputVector[4];
			string actualOutputString6 = actualOutputVector[5];
			string expectedOutputString1 = "Andy Koh's birthday chalet 18 Nov 5pm 19 Nov 10am tomorrow afternoon high Incomplete";
			string expectedOutputString2 = "Gan Tian's dinner date 21 Mar 7pm 21 Mar 8pm saturday night high Incomplete";
			string expectedOutputString3 = "buy groceries  8 Sep 8am 9 Sep 10am monday morning medium Incomplete";
			string expectedOutputString4 = "JIE YANG cut hair 13 Mar 1pm 15 Apr 2pm tomorrow evening medium Incomplete";
			string expectedOutputString5 = "andy Goh's concert recital 17 Jul 9pm 18 Jul 11pm today night low Incomplete";
			string expectedOutputString6 = "Andy Soh's graduation party 10 May 8pm 11 May 2am today afternoon low Incomplete";
			Assert::AreEqual(expectedOutputString1, actualOutputString1);
			Assert::AreEqual(expectedOutputString2, actualOutputString2);
			Assert::AreEqual(expectedOutputString3, actualOutputString3);
			Assert::AreEqual(expectedOutputString4, actualOutputString4);
			Assert::AreEqual(expectedOutputString5, actualOutputString5);
			Assert::AreEqual(expectedOutputString6, actualOutputString6);
		}
	};
}