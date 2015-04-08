#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <msclr/marshal_cppstd.h>
#include "..\Logic\Logic.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TSGUI
	/// </summary>
	public ref class TSGUI : public System::Windows::Forms::Form
	{
	private:
		Logic* TSlogic;

	public:
		TSGUI(void)
		{
			InitializeComponent();
			TSlogic = new Logic();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TSGUI()
		{
			if (components)
			{
				delete components;
				delete TSlogic;
			}
		}
	private: System::Windows::Forms::TextBox^  commandline;

	protected:

	protected:

	private: System::Windows::Forms::TextBox^  displaybox;

	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::TextBox^  feedbackbox;
	private: System::Windows::Forms::Label^  tasksotonglabel;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->commandline = (gcnew System::Windows::Forms::TextBox());
			this->displaybox = (gcnew System::Windows::Forms::TextBox());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->feedbackbox = (gcnew System::Windows::Forms::TextBox());
			this->tasksotonglabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// commandline
			// 
			this->commandline->Location = System::Drawing::Point(12, 279);
			this->commandline->Name = L"commandline";
			this->commandline->Size = System::Drawing::Size(602, 20);
			this->commandline->TabIndex = 0;
			this->commandline->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TSGUI::commandline_KeyPress);
			// 
			// displaybox
			// 
			this->displaybox->Font = (gcnew System::Drawing::Font(L"Celeste Hand", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displaybox->Location = System::Drawing::Point(12, 12);
			this->displaybox->Multiline = true;
			this->displaybox->Name = L"displaybox";
			this->displaybox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->displaybox->Size = System::Drawing::Size(363, 261);
			this->displaybox->TabIndex = 2;
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(387, 78);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 3;
			// 
			// feedbackbox
			// 
			this->feedbackbox->Location = System::Drawing::Point(387, 250);
			this->feedbackbox->Name = L"feedbackbox";
			this->feedbackbox->Size = System::Drawing::Size(227, 20);
			this->feedbackbox->TabIndex = 4;
			// 
			// tasksotonglabel
			// 
			this->tasksotonglabel->AutoSize = true;
			this->tasksotonglabel->Font = (gcnew System::Drawing::Font(L"Celeste Hand", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tasksotonglabel->Location = System::Drawing::Point(387, -3);
			this->tasksotonglabel->Name = L"tasksotonglabel";
			this->tasksotonglabel->Size = System::Drawing::Size(247, 72);
			this->tasksotonglabel->TabIndex = 5;
			this->tasksotonglabel->Text = L"TaskSotong";
			// 
			// TSGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(630, 314);
			this->Controls->Add(this->tasksotonglabel);
			this->Controls->Add(this->feedbackbox);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->displaybox);
			this->Controls->Add(this->commandline);
			this->Name = L"TSGUI";
			this->Text = L"TSGUI";
			this->Load += gcnew System::EventHandler(this, &TSGUI::TSGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		

	private: System::Void commandline_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		
		Logic TSlogic;
		TSlogic.setFileName("taskSotong.txt");
		ifstream readFile("taskSotong.txt");
		std::string filename = TSlogic.getFileName();
		TSlogic.callInitialise(filename);

		if (e->KeyChar == (char)13){
			
			String^ input = commandline->Text;
			std::string userInput = msclr::interop::marshal_as< std::string >(input);


			if (userInput != "exit") {

				paraList* storageInput = TSlogic.getParaList(userInput);
				std::string command = storageInput->getCommand();
				Task task = storageInput->getTask();
				TSlogic.executeCommand(*storageInput);
			
				std::string x;
				queue<string> taskVector;
				std::string entireList;

				while (getline(readFile, x)) {
					taskVector.push(x);
				}

				while (!taskVector.empty()) {
					
					std::string taskLine = taskVector.front();
					entireList = entireList + taskLine + "\r\n";
					taskVector.pop();
				}

				String^ displayList = gcnew String(entireList.c_str());
				displaybox->Text = displayList;


				std::string feedbackmsg = TSlogic.getFeedbackMsg();
				String^ feedback = gcnew String(feedbackmsg.c_str());
				feedbackbox->Text = feedback;
			}
			
			std::string restoreCommandLine = "";
			String^ restoreCmdLine = gcnew String(restoreCommandLine.c_str());
			commandline->Text = restoreCmdLine;
			
		}
	}  
	private: System::Void TSGUI_Load(System::Object^  sender, System::EventArgs^  e) {
	}



};
}
/*
#include "UI.h"

void UI::displayWelcomeMessage() {

	cout << _welcomeMessage << endl;
	return;
}


void UI::displayExitMessage() {

	cout << _exitMessage << endl;
	return;
}

void UI::displayPromptInputMessage() {

	cout << _promptInputMessage << endl;
	return;
}

void UI::displaySuccessfulAddMessage() {

	cout << _successfulAddMessage << endl;
	return;
}

void UI::displaySuccessfulUpdateMessage() {

	cout << _successfulUpdateMessage << endl;
	return;
}

void UI::displaySuccessfulDeleteMessage() {

	cout << _successfulDeleteMessage << endl;
	return;
}

void UI::displaySuccessfulSortMessage() {

	cout << _successfulSortMessage << endl;
	return;
}

void UI::displayInvalidCommandMessage() {

	cout << _invalidCommandMessage << endl;
	return;
}

void UI::displayDeleteErrorMessage() {

	cout << _deleteErrorMessage << endl;
	return;
}

void UI::displayUpdateCompletedStatusErrorMessage() {

	cout << _updateCompletedStatusErrorMessage << endl;
	return;
}

void UI::displayUpdateNotCompletedStatusErrorMessage() {

	cout << _updateNotCompletedStatusErrorMessage << endl;
	return;
}

void UI::displayTaskList(vector<string> taskList) {

	vector<string>::iterator iter;

	for (iter = taskList.begin(); iter != taskList.end(); ++iter) {
		cout << *iter << endl;
	}

	return;
}


string UI::acceptUserInput() {

	string userInput;
	getline(cin, userInput);
	return userInput;
}
*/