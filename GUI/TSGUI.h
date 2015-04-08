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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TSGUI::typeid));
			this->commandline = (gcnew System::Windows::Forms::TextBox());
			this->displaybox = (gcnew System::Windows::Forms::TextBox());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->feedbackbox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// commandline
			// 
			this->commandline->Location = System::Drawing::Point(189, 214);
			this->commandline->Name = L"commandline";
			this->commandline->Size = System::Drawing::Size(634, 20);
			this->commandline->TabIndex = 0;
			this->commandline->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TSGUI::commandline_KeyPress);
			// 
			// displaybox
			// 
			this->displaybox->BackColor = System::Drawing::Color::DarkOrchid;
			this->displaybox->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displaybox->ForeColor = System::Drawing::Color::White;
			this->displaybox->Location = System::Drawing::Point(12, 12);
			this->displaybox->Multiline = true;
			this->displaybox->Name = L"displaybox";
			this->displaybox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->displaybox->Size = System::Drawing::Size(452, 194);
			this->displaybox->TabIndex = 2;
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->ForeColor = System::Drawing::Color::Purple;
			this->monthCalendar1->Location = System::Drawing::Point(475, 12);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 3;
			this->monthCalendar1->TitleBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->monthCalendar1->TitleForeColor = System::Drawing::Color::Purple;
			this->monthCalendar1->TrailingForeColor = System::Drawing::Color::Purple;
			// 
			// feedbackbox
			// 
			this->feedbackbox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->feedbackbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->feedbackbox->Location = System::Drawing::Point(475, 183);
			this->feedbackbox->Name = L"feedbackbox";
			this->feedbackbox->Size = System::Drawing::Size(348, 22);
			this->feedbackbox->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(703, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(114, 162);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &TSGUI::pictureBox1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Purple;
			this->label1->Location = System::Drawing::Point(10, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"What would you like to do\?";
			// 
			// TSGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(834, 243);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->feedbackbox);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->displaybox);
			this->Controls->Add(this->commandline);
			this->Name = L"TSGUI";
			this->Text = L"TSGUI";
			this->Load += gcnew System::EventHandler(this, &TSGUI::TSGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
				entireList = "";

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



private: System::Void tasksotonglabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
