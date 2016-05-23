// WindowsFormApplication1.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

#include "RSA.h"



using namespace WindowsFormApplication1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	RSA rsa;

	// Create the main window and run it
	//Application::Run(gcnew Form1());
	Form1^ frm = gcnew Form1();
	
	string str = "Write your message here...";
	String^ newSystemString = gcnew String(str.c_str());
	frm->set_plainText(newSystemString);
	Application::Run(frm);

	return 0;
}
