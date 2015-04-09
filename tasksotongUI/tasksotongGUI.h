#pragma once

#include "..\Logic\Logic.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
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

	private: System::Windows::Forms::TextBox^  DisplayTaskBox;

	private: System::Windows::Forms::TextBox^  WelcomeBox;


	private: System::Windows::Forms::Button^  IncompleteButton;
	private: System::Windows::Forms::Button^  PriorityButton;
	private: System::Windows::Forms::Button^  DeadlineButton;
	private: System::Windows::Forms::VScrollBar^  vScrollBar1;


	private:
		/// <summary>
		/// Required designer variable.
		Logic* TSLogic;


	private: System::Windows::Forms::Button^  CompleteButton;

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
				 this->DisplayTaskBox = (gcnew System::Windows::Forms::TextBox());
				 this->WelcomeBox = (gcnew System::Windows::Forms::TextBox());
				 this->IncompleteButton = (gcnew System::Windows::Forms::Button());
				 this->PriorityButton = (gcnew System::Windows::Forms::Button());
				 this->DeadlineButton = (gcnew System::Windows::Forms::Button());
				 this->Enter = (gcnew System::Windows::Forms::Button());
				 this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
				 this->CompleteButton = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // UserInputBox
				 // 
				 this->UserInputBox->BackColor = System::Drawing::Color::DimGray;
				 this->UserInputBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->UserInputBox->ForeColor = System::Drawing::Color::MintCream;
				 this->UserInputBox->Location = System::Drawing::Point(12, 381);
				 this->UserInputBox->Multiline = true;
				 this->UserInputBox->Name = L"UserInputBox";
				 this->UserInputBox->Size = System::Drawing::Size(509, 33);
				 this->UserInputBox->TabIndex = 0;
				 this->UserInputBox->Text = L"...what do you want me to do\? ʕु•̫͡•ʔु ✧";
				 this->UserInputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &tasksotongGUI::UserInputBox_KeyPress);
				 // 
				 // DisplayTaskBox
				 // 
				 this->DisplayTaskBox->BackColor = System::Drawing::Color::RosyBrown;
				 this->DisplayTaskBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->DisplayTaskBox->ForeColor = System::Drawing::Color::WhiteSmoke;
				 this->DisplayTaskBox->Location = System::Drawing::Point(12, 99);
				 this->DisplayTaskBox->Multiline = true;
				 this->DisplayTaskBox->Name = L"DisplayTaskBox";
				 this->DisplayTaskBox->ReadOnly = true;
				 this->DisplayTaskBox->Size = System::Drawing::Size(509, 268);
				 this->DisplayTaskBox->TabIndex = 1;
				 this->DisplayTaskBox->Text = L"\r\nＺzz...   (¦3ꇤ[▓▓]\r\n\r\n\r\n...Your taskSotong list is empty...ᕙ(⇀‸↼‶)ᕗ\r\n";
				 this->DisplayTaskBox->Click += gcnew System::EventHandler(this, &tasksotongGUI::DisplayTaskBox_TextChanged);
				 this->DisplayTaskBox->TextChanged += gcnew System::EventHandler(this, &tasksotongGUI::DisplayTaskBox_TextChanged);
				 // 
				 // WelcomeBox
				 // 
				 this->WelcomeBox->BackColor = System::Drawing::Color::MistyRose;
				 this->WelcomeBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->WelcomeBox->ForeColor = System::Drawing::Color::Goldenrod;
				 this->WelcomeBox->Location = System::Drawing::Point(12, 31);
				 this->WelcomeBox->Multiline = true;
				 this->WelcomeBox->Name = L"WelcomeBox";
				 this->WelcomeBox->Size = System::Drawing::Size(509, 51);
				 this->WelcomeBox->TabIndex = 2;
				 this->WelcomeBox->Text = L"Welcome to TaskSotong! ฅ^._.^ฅ";
				 this->WelcomeBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->WelcomeBox->Click += gcnew System::EventHandler(this, &tasksotongGUI::WelcomeBox_TextChanged);
				 this->WelcomeBox->TextChanged += gcnew System::EventHandler(this, &tasksotongGUI::WelcomeBox_TextChanged);
				 // 
				 // IncompleteButton
				 // 
				 this->IncompleteButton->BackColor = System::Drawing::Color::LightCoral;
				 this->IncompleteButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
				 this->IncompleteButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->IncompleteButton->Location = System::Drawing::Point(543, 110);
				 this->IncompleteButton->Name = L"IncompleteButton";
				 this->IncompleteButton->Size = System::Drawing::Size(210, 64);
				 this->IncompleteButton->TabIndex = 4;
				 this->IncompleteButton->Text = L"VIEW Incompleted";
				 this->IncompleteButton->UseVisualStyleBackColor = false;
				 this->IncompleteButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::IncompleteButton_Click);
				 // 
				 // PriorityButton
				 // 
				 this->PriorityButton->BackColor = System::Drawing::Color::PaleVioletRed;
				 this->PriorityButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
				 this->PriorityButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->PriorityButton->Location = System::Drawing::Point(543, 193);
				 this->PriorityButton->Name = L"PriorityButton";
				 this->PriorityButton->Size = System::Drawing::Size(210, 64);
				 this->PriorityButton->TabIndex = 5;
				 this->PriorityButton->Text = L"SORT Priority";
				 this->PriorityButton->UseVisualStyleBackColor = false;
				 this->PriorityButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::PriorityButton_Click);
				 // 
				 // DeadlineButton
				 // 
				 this->DeadlineButton->BackColor = System::Drawing::Color::DarkSlateBlue;
				 this->DeadlineButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
				 this->DeadlineButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->DeadlineButton->Location = System::Drawing::Point(543, 276);
				 this->DeadlineButton->Name = L"DeadlineButton";
				 this->DeadlineButton->Size = System::Drawing::Size(210, 64);
				 this->DeadlineButton->TabIndex = 6;
				 this->DeadlineButton->Text = L"SORT Deadline";
				 this->DeadlineButton->UseVisualStyleBackColor = false;
				 this->DeadlineButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::DeadlineButton_Click);
				 // 
				 // Enter
				 // 
				 this->Enter->BackColor = System::Drawing::Color::MidnightBlue;
				 this->Enter->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
				 this->Enter->ForeColor = System::Drawing::SystemColors::Control;
				 this->Enter->Location = System::Drawing::Point(543, 357);
				 this->Enter->Name = L"Enter";
				 this->Enter->Size = System::Drawing::Size(210, 64);
				 this->Enter->TabIndex = 7;
				 this->Enter->Text = L"Enter";
				 this->Enter->UseVisualStyleBackColor = false;
				 this->Enter->Click += gcnew System::EventHandler(this, &tasksotongGUI::Enter_Click);
				 // 
				 // vScrollBar1
				 // 
				 this->vScrollBar1->Location = System::Drawing::Point(497, 99);
				 this->vScrollBar1->Name = L"vScrollBar1";
				 this->vScrollBar1->Size = System::Drawing::Size(24, 268);
				 this->vScrollBar1->TabIndex = 8;
				 // 
				 // CompleteButton
				 // 
				 this->CompleteButton->BackColor = System::Drawing::Color::LightPink;
				 this->CompleteButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->CompleteButton->ForeColor = System::Drawing::SystemColors::Control;
				 this->CompleteButton->Location = System::Drawing::Point(543, 24);
				 this->CompleteButton->Name = L"CompleteButton";
				 this->CompleteButton->Size = System::Drawing::Size(210, 64);
				 this->CompleteButton->TabIndex = 3;
				 this->CompleteButton->Text = L"VIEW Completed";
				 this->CompleteButton->UseVisualStyleBackColor = false;
				 this->CompleteButton->Click += gcnew System::EventHandler(this, &tasksotongGUI::Complete_click);
				 // 
				 // tasksotongGUI
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->BackColor = System::Drawing::Color::Linen;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->ClientSize = System::Drawing::Size(778, 444);
				 this->Controls->Add(this->vScrollBar1);
				 this->Controls->Add(this->Enter);
				 this->Controls->Add(this->DeadlineButton);
				 this->Controls->Add(this->PriorityButton);
				 this->Controls->Add(this->IncompleteButton);
				 this->Controls->Add(this->CompleteButton);
				 this->Controls->Add(this->WelcomeBox);
				 this->Controls->Add(this->DisplayTaskBox);
				 this->Controls->Add(this->UserInputBox);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximizeBox = false;
				 this->Name = L"tasksotongGUI";
				 this->Text = L"TaskSotong!꒰(๑´•.̫ • `๑)꒱";
				 this->Load += gcnew System::EventHandler(this, &tasksotongGUI::tasksotongGUI_Load);
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
			vector<string> textFileCopy_fromLogic = TSLogic->getReturnGUI();
			
			//String^ stringnewlala = gcnew String(userInput.c_str());
			//DisplayTaskBox->Text = stringnewlala + "\r\n" + textFileCopy_fromLogic.size().ToString();

			//DisplayTaskBox->Text = textFileCopy_fromLogic.size().ToString();

			string itemString;
			for (int i = 0; i < textFileCopy_fromLogic.size(); i++) {
				itemString = itemString + to_string(i+1) + string(".  ") + textFileCopy_fromLogic[i] + "\r\n";
			}
			String^ displayList = gcnew String(itemString.c_str());
			DisplayTaskBox->Text = displayList;

			//std::string feedbackmsg = TSLogic->getFeedbackMsg();
			String^ feedback = gcnew String(feedbackmsg.c_str());
			WelcomeBox->Text = feedback;

			UserInputBox->Clear();
			//DisplayTaskBox->Text = "can work???";
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
	}


	};
}






/*#pragma once

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
public ref class tasksotongGUI : public System::Windows::Forms::Form
{
public:
tasksotongGUI(void)
{
InitializeComponent();
//
//TODO: Add the constructor code here
//
}

protected:
/// <summary>
/// Clean up any resources being used.
/// </summary>
~tasksotongGUI()
{
if (components)
{
delete components;
}
}

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
this->components = gcnew System::ComponentModel::Container();
this->Size = System::Drawing::Size(300,300);
this->Text = L"tasksotongGUI";
this->Padding = System::Windows::Forms::Padding(0);
this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
}
#pragma endregion
};
}

*/
