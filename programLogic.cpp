#include "LoginForm.h"
#include "RegisterForm.h"
#include "DashBoard.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;
	while (true) {
		v1PocketCheckercpp::LoginForm login;
		login.ShowDialog();

		if (login.switchToRegister) {
			//show the register form
			v1PocketCheckercpp::RegisterForm registerForm;
			registerForm.ShowDialog();
<<<<<<< Updated upstream
=======
			
>>>>>>> Stashed changes

			if (registerForm.switchtoLogin) {
				continue;
			}
			else {
				user = registerForm.user;
				break;
			}
		}
		else {
			user = login.main_user;
			break;
		}
	}

	if (user != nullptr) {
		v1PocketCheckercpp::DashBoard mainForm(user);
		Application::Run(% mainForm);
	}
	else {
		MessageBox::Show("Authentication cancelled ",
			"demoPocketChecker", MessageBoxButtons::OK);
	}
}