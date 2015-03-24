
#include "tasksotongGUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	tasksotongUI::tasksotongGUI mainWindow;
	Application::Run(%mainWindow);
}

