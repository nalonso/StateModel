using namespace System;
using namespace System::Windows::Forms;

#include "MicrowaveForm.h"

[STAThread]//leave this as is
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MicrowaveForm::MicrowaveForm form;
	Application::Run(%form);
}