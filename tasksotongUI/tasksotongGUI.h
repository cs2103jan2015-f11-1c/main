#pragma once

#include "..\Logic\Logic.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <msclr\marshal_cppstd.h>


namespace tasksotongUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for tasksotongGUI
	/// </summary>



	//hashtable added
	// Hash map class template
	/*template <typename K, typename V, typename F = KeyHash<K>>
	class HashMap {
	public:
	HashMap() {
	// construct zero initialized hash table of size
	table = new HashNode<K, V> *[TABLE_SIZE]();
	}

	~HashMap() {
	// destroy all buckets one by one
	for (int i = 0; i < TABLE_SIZE; ++i) {
	HashNode<K, V> *entry = table[i];
	while (entry != NULL) {
	HashNode<K, V> *prev = entry;
	entry = entry->getNext();
	delete prev;
	}
	table[i] = NULL;
	}
	// destroy the hash table
	delete[] table;
	}

	bool get(const K &key, V &value) {
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V> *entry = table[hashValue];

	while (entry != NULL) {
	if (entry->getKey() == key) {
	value = entry->getValue();
	return true;
	}
	entry = entry->getNext();
	}
	return false;
	}

	void put(const K &key, const V &value) {
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V> *prev = NULL;
	HashNode<K, V> *entry = table[hashValue];

	while (entry != NULL && entry->getKey() != key) {
	prev = entry;
	entry = entry->getNext();
	}

	if (entry == NULL) {
	entry = new HashNode<K, V>(key, value);
	if (prev == NULL) {
	// insert as first bucket
	table[hashValue] = entry;
	} else {
	prev->setNext(entry);
	}
	} else {
	// just update the value
	entry->setValue(value);
	}
	}

	void remove(const K &key) {
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V> *prev = NULL;
	HashNode<K, V> *entry = table[hashValue];

	while (entry != NULL && entry->getKey() != key) {
	prev = entry;
	entry = entry->getNext();
	}

	if (entry == NULL) {
	// key not found
	return;
	} else {
	if (prev == NULL) {
	// remove first bucket of the list
	table[hashValue] = entry->getNext();
	} else {
	prev->setNext(entry->getNext());
	}
	delete entry;
	}
	}

	private:
	// hash table
	HashNode<K, V> **table;
	F hashFunc;
	};





	private enum Accelerators {
	Unspecified = 0, Home, Save, Print, Logout
	};

	HashMap _accelHash() = new HashMap();
	public class AcceleratorKey {
	private Keys key_ = Keys.None;
	public AcceleratorKey() {
	}

	public AcceleratorKey(Keys key) {
	key_ = key;
	}

	public Keys Key
	{
	get{ return key_; }
	set{ key_ = value; }
	}

	public override Int32 GetHashCode() {
	return (Int32)key_;
	}

	public override bool Equals(Object obj) {
	// It is unlikely that two hashcodes would
	// be equal... :)
	if (obj.GetHashCode() == (Int32)key_) return true;

	return false;
	}
	}

	_accelHash.Add(new AcceleratorKey(Keys.Alt | Keys.H),
	Accelerators.Home);
	_accelHash.Add(new AcceleratorKey(Keys.Alt | Keys.S),
	Accelerators.Save);
	_accelHash.Add(new AcceleratorKey(Keys.Alt | Keys.P),
	Accelerators.Print);
	_accelHash.Add(new AcceleratorKey(Keys.Alt | Keys.X),
	Accelerators.Logout);

	protected override bool ProcessCmdKey(ref Message msg,
	Keys keyData) {
	// Check this key...
	bool bHandled = false;

	// Look up value
	Accelerators accel = Accelerators.Unspecified;
	if (_accelHash.ContainsKey(AcceleratorKey(keyData))) {
	accel = (Accelerators)_accelHash[key];

	switch (accel) {
	case Accelerators.Home:
	DisplayHome();
	bHandled = true;
	break;

	case Accelerators.Save:
	Save();
	bHandled = true;
	break;

	case Accelerators.Print:
	Print();
	bHandled = true;
	break;

	case Accelerators.Logout:
	LogOut();
	bHandled = true;
	break;

	case Accelerators.Unspecified:
	default:
	break;

	} // switch
	} // if

	return bHandled;
	}
	*/

	//HashTable ended

	public ref class tasksotongGUI : public System::Windows::Forms::Form {
	public:
		tasksotongGUI(void) {
			TSLogic = new Logic;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~tasksotongGUI() {
			if (components) {
				delete components;

			}
		}
	private: System::Windows::Forms::TextBox^  UserInputBox;
	private: System::Windows::Forms::Button^  Enter;
	protected:



	private: System::Windows::Forms::TextBox^  WelcomeBox;


	private: System::Windows::Forms::Button^  IncompleteButton;
	private: System::Windows::Forms::Button^  PriorityButton;
	private: System::Windows::Forms::Button^  DeadlineButton;



	private:
		/// <summary>
		/// Required designer variable.
		Logic* TSLogic;


	private: System::Windows::Forms::Button^  CompleteButton;
	private: System::Windows::Forms::ToolStrip^  Help;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  featuresToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  flexibleCommandToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tOBEENTEREDBYJIEYANGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortByNameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortByDateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortByDeadlineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortByPriorityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tOBEENTEREDBYANDYToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  Display_richTextBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;

			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void) {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(tasksotongGUI::typeid));
				 this->UserInputBox = (gcnew System::Windows::Forms::TextBox());
				 this->WelcomeBox = (gcnew System::Windows::Forms::TextBox());
				 this->IncompleteButton = (gcnew System::Windows::Forms::Button());
				 this->PriorityButton = (gcnew System::Windows::Forms::Button());
				 this->DeadlineButton = (gcnew System::Windows::Forms::Button());
				 this->Enter = (gcnew System::Windows::Forms::Button());
				 this->CompleteButton = (gcnew System::Windows::Forms::Button());
				 this->Help = (gcnew System::Windows::Forms::ToolStrip());
				 this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
				 this->featuresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->flexibleCommandToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->tOBEENTEREDBYJIEYANGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortByNameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortByDateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortByDeadlineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sortByPriorityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->tOBEENTEREDBYANDYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->Display_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->Help->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // UserInputBox
				 // 
				 this->UserInputBox->BackColor = System::Drawing::Color::DimGray;
				 resources->ApplyResources(this->UserInputBox, L"UserInputBox");
				 this->UserInputBox->ForeColor = System::Drawing::Color::MintCream;
				 this->UserInputBox->Name = L"UserInputBox";
				 this->UserInputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &tasksotongGUI::UserInputBox_KeyPress);
				 // 
				 // WelcomeBox
				 // 
				 this->WelcomeBox->BackColor = System::Drawing::Color::MistyRose;
				 resources->ApplyResources(this->WelcomeBox, L"WelcomeBox");
				 this->WelcomeBox->ForeColor = System::Drawing::Color::Goldenrod;
				 this->WelcomeBox->Name = L"WelcomeBox";
				 this->WelcomeBox->Click += gcnew System::EventHandler(this, &tasksotongGUI::WelcomeBox_TextChanged);
				 this->WelcomeBox->TextChanged += gcnew System::EventHandler(this, &tasksotongGUI::WelcomeBox_TextChanged);
				 // 
				 // IncompleteButton
				 // 
				 this->IncompleteButton->BackColor = System::Drawing::Color::LightCoral;
				 resources->ApplyResources(this->IncompleteButton, L"IncompleteButton");
				 this->IncompleteButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->IncompleteButton->Name = L"IncompleteButton";
				 this->IncompleteButton->UseVisualStyleBackColor = false;
				 this->IncompleteButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::IncompleteButton_Click);
				 // 
				 // PriorityButton
				 // 
				 this->PriorityButton->BackColor = System::Drawing::Color::PaleVioletRed;
				 resources->ApplyResources(this->PriorityButton, L"PriorityButton");
				 this->PriorityButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->PriorityButton->Name = L"PriorityButton";
				 this->PriorityButton->UseVisualStyleBackColor = false;
				 this->PriorityButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::PriorityButton_Click);
				 // 
				 // DeadlineButton
				 // 
				 this->DeadlineButton->BackColor = System::Drawing::Color::DarkSlateBlue;
				 resources->ApplyResources(this->DeadlineButton, L"DeadlineButton");
				 this->DeadlineButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->DeadlineButton->Name = L"DeadlineButton";
				 this->DeadlineButton->UseVisualStyleBackColor = false;
				 this->DeadlineButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::DeadlineButton_Click);
				 // 
				 // Enter
				 // 
				 this->Enter->BackColor = System::Drawing::Color::MidnightBlue;
				 resources->ApplyResources(this->Enter, L"Enter");
				 this->Enter->ForeColor = System::Drawing::SystemColors::Control;
				 this->Enter->Name = L"Enter";
				 this->Enter->UseVisualStyleBackColor = false;
				 this->Enter->Click += gcnew System::EventHandler(this, &tasksotongGUI::Enter_Click);
				 // 
				 // CompleteButton
				 // 
				 this->CompleteButton->BackColor = System::Drawing::Color::LightPink;
				 resources->ApplyResources(this->CompleteButton, L"CompleteButton");
				 this->CompleteButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->CompleteButton->Name = L"CompleteButton";
				 this->CompleteButton->UseVisualStyleBackColor = false;
				 this->CompleteButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::Complete_click);
				 // 
				 // Help
				 // 
				 this->Help->BackColor = System::Drawing::Color::Transparent;
				 this->Help->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripDropDownButton1 });
				 resources->ApplyResources(this->Help, L"Help");
				 this->Help->Name = L"Help";
				 // 
				 // toolStripDropDownButton1
				 // 
				 this->toolStripDropDownButton1->BackColor = System::Drawing::Color::PaleGreen;
				 this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
				 this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					 this->featuresToolStripMenuItem,
						 this->flexibleCommandToolStripMenuItem, this->sortToolStripMenuItem, this->updateToolStripMenuItem
				 });
				 resources->ApplyResources(this->toolStripDropDownButton1, L"toolStripDropDownButton1");
				 this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
				 // 
				 // featuresToolStripMenuItem
				 // 
				 this->featuresToolStripMenuItem->Name = L"featuresToolStripMenuItem";
				 resources->ApplyResources(this->featuresToolStripMenuItem, L"featuresToolStripMenuItem");
				 this->featuresToolStripMenuItem->Click += gcnew System::EventHandler(this, &tasksotongGUI::featuresToolStripMenuItem_Click);
				 // 
				 // flexibleCommandToolStripMenuItem
				 // 
				 this->flexibleCommandToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tOBEENTEREDBYJIEYANGToolStripMenuItem });
				 this->flexibleCommandToolStripMenuItem->Name = L"flexibleCommandToolStripMenuItem";
				 resources->ApplyResources(this->flexibleCommandToolStripMenuItem, L"flexibleCommandToolStripMenuItem");
				 // 
				 // tOBEENTEREDBYJIEYANGToolStripMenuItem
				 // 
				 this->tOBEENTEREDBYJIEYANGToolStripMenuItem->Name = L"tOBEENTEREDBYJIEYANGToolStripMenuItem";
				 resources->ApplyResources(this->tOBEENTEREDBYJIEYANGToolStripMenuItem, L"tOBEENTEREDBYJIEYANGToolStripMenuItem");
				 // 
				 // sortToolStripMenuItem
				 // 
				 this->sortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					 this->sortByNameToolStripMenuItem,
						 this->sortByDateToolStripMenuItem, this->sortByDeadlineToolStripMenuItem, this->sortByPriorityToolStripMenuItem
				 });
				 this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
				 resources->ApplyResources(this->sortToolStripMenuItem, L"sortToolStripMenuItem");
				 // 
				 // sortByNameToolStripMenuItem
				 // 
				 this->sortByNameToolStripMenuItem->Name = L"sortByNameToolStripMenuItem";
				 resources->ApplyResources(this->sortByNameToolStripMenuItem, L"sortByNameToolStripMenuItem");
				 // 
				 // sortByDateToolStripMenuItem
				 // 
				 this->sortByDateToolStripMenuItem->Name = L"sortByDateToolStripMenuItem";
				 resources->ApplyResources(this->sortByDateToolStripMenuItem, L"sortByDateToolStripMenuItem");
				 // 
				 // sortByDeadlineToolStripMenuItem
				 // 
				 this->sortByDeadlineToolStripMenuItem->Name = L"sortByDeadlineToolStripMenuItem";
				 resources->ApplyResources(this->sortByDeadlineToolStripMenuItem, L"sortByDeadlineToolStripMenuItem");
				 // 
				 // sortByPriorityToolStripMenuItem
				 // 
				 this->sortByPriorityToolStripMenuItem->Name = L"sortByPriorityToolStripMenuItem";
				 resources->ApplyResources(this->sortByPriorityToolStripMenuItem, L"sortByPriorityToolStripMenuItem");
				 // 
				 // updateToolStripMenuItem
				 // 
				 this->updateToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tOBEENTEREDBYANDYToolStripMenuItem });
				 this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
				 resources->ApplyResources(this->updateToolStripMenuItem, L"updateToolStripMenuItem");
				 // 
				 // tOBEENTEREDBYANDYToolStripMenuItem
				 // 
				 this->tOBEENTEREDBYANDYToolStripMenuItem->Name = L"tOBEENTEREDBYANDYToolStripMenuItem";
				 resources->ApplyResources(this->tOBEENTEREDBYANDYToolStripMenuItem, L"tOBEENTEREDBYANDYToolStripMenuItem");
				 // 
				 // Display_richTextBox
				 // 
				 this->Display_richTextBox->BackColor = System::Drawing::Color::RosyBrown;
				 resources->ApplyResources(this->Display_richTextBox, L"Display_richTextBox");
				 this->Display_richTextBox->ForeColor = System::Drawing::Color::MintCream;
				 this->Display_richTextBox->Name = L"Display_richTextBox";
				 this->Display_richTextBox->ReadOnly = true;
				 this->Display_richTextBox->TextChanged += gcnew System::EventHandler(this, &tasksotongGUI::Display_richTextBox_TextChanged);
				 // 
				 // button1
				 // 
				 resources->ApplyResources(this->button1, L"button1");
				 this->button1->Name = L"button1";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &tasksotongGUI::button1_Click);
				 // 
				 // textBox1
				 // 
				 resources->ApplyResources(this->textBox1, L"textBox1");
				 this->textBox1->Name = L"textBox1";
				 // 
				 // tasksotongGUI
				 // 
				 resources->ApplyResources(this, L"$this");
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::BurlyWood;
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->Help);
				 this->Controls->Add(this->Enter);
				 this->Controls->Add(this->DeadlineButton);
				 this->Controls->Add(this->PriorityButton);
				 this->Controls->Add(this->IncompleteButton);
				 this->Controls->Add(this->CompleteButton);
				 this->Controls->Add(this->WelcomeBox);
				 this->Controls->Add(this->UserInputBox);
				 this->Controls->Add(this->Display_richTextBox);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->MaximizeBox = false;
				 this->Name = L"tasksotongGUI";
				 this->Load += gcnew System::EventHandler(this, &tasksotongGUI::tasksotongGUI_Load);
				 this->Help->ResumeLayout(false);
				 this->Help->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }


#pragma endregion


	private: System::Void UserInputBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		//DisplayTaskBox->Text = "debugging1: " + UserInputBox->Text + "testing1";
		if (e->KeyChar == (char)13) {

			string tempUserInput = msclr::interop::marshal_as<std::string>(UserInputBox->Text);

			int i = tempUserInput.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSUVWXYZ");
			string userInput = tempUserInput.substr(i);

			//DisplayTaskBox->Text ="debugging2: "+ UserInputBox->Text + "testing2";

			paraList* storageInput = TSLogic->getParaList(userInput);

			std::string feedbackmsg = TSLogic->executeCommand(*storageInput);
			//DisplayTaskBox->Clear();
			vector<Task> taskListCopy_fromLogic = TSLogic->getTaskList();

			//String^ stringnewlala = gcnew String(userInput.c_str());
			//DisplayTaskBox->Text = stringnewlala + "\r\n" + textFileCopy_fromLogic.size().ToString();

			//DisplayTaskBox->Text = textFileCopy_fromLogic.size().ToString();

			Display_richTextBox->Clear();

			for (int i = 0; i < taskListCopy_fromLogic.size(); i++) {

				string tempName = "\t" + to_string(i + 1) + ".\t" + taskListCopy_fromLogic[i].getTaskName() + "\r\n";
				String^ displayName = gcnew String(tempName.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 15.75, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = displayName;

				string start = "START: \t";
				String^ startLine = gcnew String(start.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = startLine;

				string tempStartDate;
				string tempStartTime;
				if (taskListCopy_fromLogic[i].getTaskStartDate() == "") {
					tempStartDate = "\t-";
				} else {
					tempStartDate = taskListCopy_fromLogic[i].getTaskStartDate();
				}
				if (taskListCopy_fromLogic[i].getTaskStartTime() == "") {
					tempStartTime = "-";
				} else {
					tempStartTime = taskListCopy_fromLogic[i].getTaskStartTime();
				}
				string tempStartDnT = tempStartDate + "\t" + tempStartTime + "\r\n";
				String^ displayStartDnT = gcnew String(tempStartDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayStartDnT;

				string end = "END: \t\t";
				String^ endLine = gcnew String(end.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = endLine;

				string tempEndDate;
				string tempEndTime;
				if (taskListCopy_fromLogic[i].getTaskEndDate() == "") {
					tempEndDate = "\t-";
				} else {
					tempEndDate = taskListCopy_fromLogic[i].getTaskEndDate();
				}
				if (taskListCopy_fromLogic[i].getTaskEndTime() == "") {
					tempEndTime = "-";
				} else {
					tempEndTime = taskListCopy_fromLogic[i].getTaskEndTime();
				}
				string tempEndDnT = tempEndDate + "\t" + tempEndTime + "\r\n";
				String^ displayEndDnT = gcnew String(tempEndDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayEndDnT;

				string deadLine = "DEADLINE: \t";
				String^ deadLineLine = gcnew String(deadLine.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = deadLineLine;

				string tempDeadlineDate;
				string tempDeadlineTime;
				if (taskListCopy_fromLogic[i].getTaskDeadlineDate() == "") {
					tempDeadlineDate = "\t-";
				} else {
					tempDeadlineDate = taskListCopy_fromLogic[i].getTaskDeadlineDate();
				}
				if (taskListCopy_fromLogic[i].getTaskDeadlineTime() == "") {
					tempDeadlineTime = "-";
				} else {
					tempDeadlineTime = taskListCopy_fromLogic[i].getTaskDeadlineTime();
				}
				string tempDeadlineDnT = tempDeadlineDate + "\t" + tempDeadlineTime + "\r\n";
				String^ displayDeadlineDnT = gcnew String(tempDeadlineDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayDeadlineDnT;


				string tempP;
				if (taskListCopy_fromLogic[i].getTaskPriority() == "") {
					tempP = "-";
				} else {
					tempP = taskListCopy_fromLogic[i].getTaskPriority();
				}
				string tempPriority = "\t\t" + tempP + "\t";
				String^ priority = gcnew String(tempPriority.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 12, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkSlateGray;
				Display_richTextBox->SelectedText = priority;


				string tempS;
				if (taskListCopy_fromLogic[i].getTaskStatus() == "") {
					tempS = "\t-";
				} else {
					tempS = taskListCopy_fromLogic[i].getTaskStatus();
				}
				string tempStatus = tempS + "\r\n";
				String^ status = gcnew String(tempStatus.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 12, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkMagenta;
				Display_richTextBox->SelectedText = status;
			}


			String^ feedback = gcnew String(feedbackmsg.c_str());
			WelcomeBox->Text = feedback;

			UserInputBox->Clear();
		}

	}

	private: System::Void Enter_Click(System::Object^  sender, System::EventArgs^  e) {

	}


	private: System::Void Complete_click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("hello world!");
	}

	private: System::Void DisplayTaskBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	}
	private: System::Void IncompleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void PriorityButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void DeadlineButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void WelcomeBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void tasksotongGUI_Load(System::Object^  sender, System::EventArgs^  e) {

		TSLogic->initialiseSetUp();
		TSLogic->setTaskList();	
		
		vector<Task> taskListCopy_fromLogic = TSLogic->getTaskList();

		
		if (taskListCopy_fromLogic.size() == 0) {
			

		} else {
			Display_richTextBox->Clear();
			for (int i = 0; i < taskListCopy_fromLogic.size(); i++) {

				string tempName = "\t" + to_string(i + 1) + ".\t" + taskListCopy_fromLogic[i].getTaskName() + "\r\n";
				String^ displayName = gcnew String(tempName.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 15.75, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = displayName;

				string start = "START: \t";
				String^ startLine = gcnew String(start.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = startLine;
				
				string tempStartDate;
				string tempStartTime;
				if (taskListCopy_fromLogic[i].getTaskStartDate() == "") {
					tempStartDate = "\t-";
				} else {
					tempStartDate = taskListCopy_fromLogic[i].getTaskStartDate();
				}
				if (taskListCopy_fromLogic[i].getTaskStartTime() == "") {
					tempStartTime = "-";
				} else {
					tempStartTime = taskListCopy_fromLogic[i].getTaskStartTime();
				}
				string tempStartDnT =tempStartDate + "\t" + tempStartTime + "\r\n";
				String^ displayStartDnT = gcnew String(tempStartDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayStartDnT;

				string end = "END: \t\t";
				String^ endLine = gcnew String(end.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = endLine;

				string tempEndDate;
				string tempEndTime;
				if (taskListCopy_fromLogic[i].getTaskEndDate() == "") {
					tempEndDate = "\t-";
				} else {
					tempEndDate = taskListCopy_fromLogic[i].getTaskEndDate();
				}
				if (taskListCopy_fromLogic[i].getTaskEndTime() == "") {
					tempEndTime = "-";
				} else {
					tempEndTime = taskListCopy_fromLogic[i].getTaskEndTime();
				}
				string tempEndDnT = tempEndDate + "\t" + tempEndTime + "\r\n";
				String^ displayEndDnT = gcnew String(tempEndDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayEndDnT;

				string deadLine = "DEADLINE: \t";
				String^ deadLineLine = gcnew String(deadLine.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 8, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::Snow;
				Display_richTextBox->SelectedText = deadLineLine;

				string tempDeadlineDate;
				string tempDeadlineTime;
				if (taskListCopy_fromLogic[i].getTaskDeadlineDate() == "") {
					tempDeadlineDate = "\t-";
				} else {
					tempDeadlineDate = taskListCopy_fromLogic[i].getTaskDeadlineDate();
				}
				if (taskListCopy_fromLogic[i].getTaskDeadlineTime() == "") {
					tempDeadlineTime = "-";
				} else {
					tempDeadlineTime = taskListCopy_fromLogic[i].getTaskDeadlineTime();
				}
				string tempDeadlineDnT = tempDeadlineDate + "\t" + tempDeadlineTime + "\r\n";
				String^ displayDeadlineDnT = gcnew String(tempDeadlineDnT.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 10, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkBlue;
				Display_richTextBox->SelectedText = displayDeadlineDnT;


				string tempP;
				if (taskListCopy_fromLogic[i].getTaskPriority() == "") {
					tempP = "-";
				} else {
					tempP = taskListCopy_fromLogic[i].getTaskPriority();
				}
				string tempPriority = "\t\t" + tempP + "\t";
				String^ priority = gcnew String(tempPriority.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 12, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkSlateGray;
				Display_richTextBox->SelectedText = priority;


				string tempS;
				if (taskListCopy_fromLogic[i].getTaskStatus() == "") {
					tempS = "\t-";
				} else {
					tempS = taskListCopy_fromLogic[i].getTaskStatus();
				}
				string tempStatus = tempS + "\r\n";
				String^ status = gcnew String(tempStatus.c_str());
				Display_richTextBox->SelectionFont = gcnew System::Drawing::Font("Seoge UI", 12, FontStyle::Bold);
				Display_richTextBox->SelectionColor = Color::DarkMagenta;
				Display_richTextBox->SelectedText = status;
			}
		}


	}


	private: System::Void featuresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Display_richTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int index = 0;
		String^ temp = Display_richTextBox->Text;
		Display_richTextBox->Text = "";
		Display_richTextBox->Text = temp;
		
		while (index < Display_richTextBox->Text->LastIndexOf(textBox1->Text, System::StringComparison::InvariantCultureIgnoreCase)){
			//Searches the text in Display_richTextBox control for a string within a range of text within UserInputBox
			Display_richTextBox->Find(textBox1->Text, index, Display_richTextBox->TextLength, RichTextBoxFinds::None);
			//Selection Color. This is added automatically when a match is found.
			Display_richTextBox->SelectionBackColor = Color::Gold;
			//After a match is found the index is increased so the search won't stop at the same match
			index = Display_richTextBox->Text->IndexOf(textBox1->Text, index, System::StringComparison::InvariantCultureIgnoreCase) + 1;
		}
	}
};
}






