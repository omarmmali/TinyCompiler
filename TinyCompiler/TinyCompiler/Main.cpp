#include "Main.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TinyCompiler::Main form;
	Application::Run(%form);
}

