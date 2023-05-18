#pragma once
#include "User.h"

namespace v1PocketCheckercpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
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
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ RegisterContainer;
	protected:
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ Registerlbl;
	private: System::Windows::Forms::TextBox^ LastNametb;
	private: System::Windows::Forms::TextBox^ Emailtb;
	private: System::Windows::Forms::LinkLabel^ Loginlbl;
	private: System::Windows::Forms::Button^ enterbtn;
	private: System::Windows::Forms::TextBox^ confirmpwtb;
	private: System::Windows::Forms::Label^ confirmpwlbl;
	private: System::Windows::Forms::TextBox^ passwordtb;
	private: System::Windows::Forms::TextBox^ usernametb;
	private: System::Windows::Forms::TextBox^ FirstNametb;
	private: System::Windows::Forms::Label^ passwordlbl;
	private: System::Windows::Forms::Label^ Usernamelbl;
	private: System::Windows::Forms::Label^ Namelbl;

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
			this->RegisterContainer = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Registerlbl = (gcnew System::Windows::Forms::Label());
			this->LastNametb = (gcnew System::Windows::Forms::TextBox());
			this->Emailtb = (gcnew System::Windows::Forms::TextBox());
			this->Loginlbl = (gcnew System::Windows::Forms::LinkLabel());
			this->enterbtn = (gcnew System::Windows::Forms::Button());
			this->confirmpwtb = (gcnew System::Windows::Forms::TextBox());
			this->confirmpwlbl = (gcnew System::Windows::Forms::Label());
			this->passwordtb = (gcnew System::Windows::Forms::TextBox());
			this->usernametb = (gcnew System::Windows::Forms::TextBox());
			this->FirstNametb = (gcnew System::Windows::Forms::TextBox());
			this->passwordlbl = (gcnew System::Windows::Forms::Label());
			this->Usernamelbl = (gcnew System::Windows::Forms::Label());
			this->Namelbl = (gcnew System::Windows::Forms::Label());
			this->RegisterContainer->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// RegisterContainer
			// 
			this->RegisterContainer->BackColor = System::Drawing::Color::White;
			this->RegisterContainer->Controls->Add(this->panel3);
			this->RegisterContainer->Controls->Add(this->LastNametb);
			this->RegisterContainer->Controls->Add(this->Emailtb);
			this->RegisterContainer->Controls->Add(this->Loginlbl);
			this->RegisterContainer->Controls->Add(this->enterbtn);
			this->RegisterContainer->Controls->Add(this->confirmpwtb);
			this->RegisterContainer->Controls->Add(this->confirmpwlbl);
			this->RegisterContainer->Controls->Add(this->passwordtb);
			this->RegisterContainer->Controls->Add(this->usernametb);
			this->RegisterContainer->Controls->Add(this->FirstNametb);
			this->RegisterContainer->Controls->Add(this->passwordlbl);
			this->RegisterContainer->Controls->Add(this->Usernamelbl);
			this->RegisterContainer->Controls->Add(this->Namelbl);
			this->RegisterContainer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->RegisterContainer->Location = System::Drawing::Point(48, 97);
			this->RegisterContainer->Name = L"RegisterContainer";
			this->RegisterContainer->Size = System::Drawing::Size(444, 208);
			this->RegisterContainer->TabIndex = 1;
			this->RegisterContainer->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->Registerlbl);
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(444, 29);
			this->panel3->TabIndex = 15;
			// 
			// Registerlbl
			// 
			this->Registerlbl->AutoSize = true;
			this->Registerlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Registerlbl->Location = System::Drawing::Point(180, 0);
			this->Registerlbl->Name = L"Registerlbl";
			this->Registerlbl->Size = System::Drawing::Size(77, 20);
			this->Registerlbl->TabIndex = 0;
			this->Registerlbl->Text = L"Register";
			// 
			// LastNametb
			// 
			this->LastNametb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LastNametb->Location = System::Drawing::Point(228, 46);
			this->LastNametb->Name = L"LastNametb";
			this->LastNametb->Size = System::Drawing::Size(203, 22);
			this->LastNametb->TabIndex = 19;
			this->LastNametb->Text = L"Last Name";
			this->LastNametb->Click += gcnew System::EventHandler(this, &RegisterForm::LastNametb_Clicked);
			this->LastNametb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::LastNametb_KeyDown);
			// 
			// Emailtb
			// 
			this->Emailtb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Emailtb->Location = System::Drawing::Point(10, 82);
			this->Emailtb->Name = L"Emailtb";
			this->Emailtb->Size = System::Drawing::Size(203, 22);
			this->Emailtb->TabIndex = 18;
			this->Emailtb->Text = L"Email";
			this->Emailtb->Click += gcnew System::EventHandler(this, &RegisterForm::Emailtb_Clicked);
			this->Emailtb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::Emailtb_KeyDown);
			// 
			// Loginlbl
			// 
			this->Loginlbl->AutoSize = true;
			this->Loginlbl->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Loginlbl->Location = System::Drawing::Point(321, 166);
			this->Loginlbl->Name = L"Loginlbl";
			this->Loginlbl->Size = System::Drawing::Size(53, 20);
			this->Loginlbl->TabIndex = 11;
			this->Loginlbl->TabStop = true;
			this->Loginlbl->Text = L"Login";
			this->Loginlbl->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::Loginlbl_LinkClicked);
			// 
			// enterbtn
			// 
			this->enterbtn->BackColor = System::Drawing::Color::SlateBlue;
			this->enterbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->enterbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enterbtn->ForeColor = System::Drawing::Color::White;
			this->enterbtn->Location = System::Drawing::Point(185, 166);
			this->enterbtn->Name = L"enterbtn";
			this->enterbtn->Size = System::Drawing::Size(65, 24);
			this->enterbtn->TabIndex = 10;
			this->enterbtn->Text = L"Submit";
			this->enterbtn->UseVisualStyleBackColor = false;
			this->enterbtn->Click += gcnew System::EventHandler(this, &RegisterForm::enterbtn_Click);
			// 
			// confirmpwtb
			// 
			this->confirmpwtb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmpwtb->Location = System::Drawing::Point(228, 120);
			this->confirmpwtb->Name = L"confirmpwtb";
			this->confirmpwtb->Size = System::Drawing::Size(203, 22);
			this->confirmpwtb->TabIndex = 8;
			this->confirmpwtb->Text = L"Confirm password";
			this->confirmpwtb->Click += gcnew System::EventHandler(this, &RegisterForm::confirmpwtb_Clicked);
			this->confirmpwtb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::confirmpwtb_KeyDown);
			// 
			// confirmpwlbl
			// 
			this->confirmpwlbl->AutoSize = true;
			this->confirmpwlbl->Location = System::Drawing::Point(6, 156);
			this->confirmpwlbl->Name = L"confirmpwlbl";
			this->confirmpwlbl->Size = System::Drawing::Size(0, 20);
			this->confirmpwlbl->TabIndex = 7;
			// 
			// passwordtb
			// 
			this->passwordtb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordtb->Location = System::Drawing::Point(10, 122);
			this->passwordtb->Name = L"passwordtb";
			this->passwordtb->Size = System::Drawing::Size(203, 22);
			this->passwordtb->TabIndex = 6;
			this->passwordtb->Text = L"Password";
			this->passwordtb->Click += gcnew System::EventHandler(this, &RegisterForm::passwordtb_Clicked);
			this->passwordtb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::passwordtb_KeyDown);
			// 
			// usernametb
			// 
			this->usernametb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernametb->Location = System::Drawing::Point(228, 82);
			this->usernametb->Name = L"usernametb";
			this->usernametb->Size = System::Drawing::Size(203, 22);
			this->usernametb->TabIndex = 5;
			this->usernametb->Text = L"Username";
			this->usernametb->Click += gcnew System::EventHandler(this, &RegisterForm::usernametb_Clicked);
			this->usernametb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::usernametb_KeyDown);
			// 
			// FirstNametb
			// 
			this->FirstNametb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FirstNametb->Location = System::Drawing::Point(10, 46);
			this->FirstNametb->Name = L"FirstNametb";
			this->FirstNametb->Size = System::Drawing::Size(203, 22);
			this->FirstNametb->TabIndex = 4;
			this->FirstNametb->Text = L"First Name";
			this->FirstNametb->Click += gcnew System::EventHandler(this, &RegisterForm::FirstNametb_Clicked);
			this->FirstNametb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegisterForm::FirstNametb_KeyDown);
			// 
			// passwordlbl
			// 
			this->passwordlbl->AutoSize = true;
			this->passwordlbl->Location = System::Drawing::Point(11, 122);
			this->passwordlbl->Name = L"passwordlbl";
			this->passwordlbl->Size = System::Drawing::Size(0, 20);
			this->passwordlbl->TabIndex = 3;
			// 
			// Usernamelbl
			// 
			this->Usernamelbl->AutoSize = true;
			this->Usernamelbl->Location = System::Drawing::Point(6, 91);
			this->Usernamelbl->Name = L"Usernamelbl";
			this->Usernamelbl->Size = System::Drawing::Size(0, 20);
			this->Usernamelbl->TabIndex = 2;
			// 
			// Namelbl
			// 
			this->Namelbl->AutoSize = true;
			this->Namelbl->Location = System::Drawing::Point(37, 59);
			this->Namelbl->Name = L"Namelbl";
			this->Namelbl->Size = System::Drawing::Size(0, 20);
			this->Namelbl->TabIndex = 1;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::BlueViolet;
			this->ClientSize = System::Drawing::Size(544, 452);
			this->Controls->Add(this->RegisterContainer);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::RegisterForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::RegisterForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::RegisterForm_MouseUp);
			this->RegisterContainer->ResumeLayout(false);
			this->RegisterContainer->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: User^ user = nullptr;
	public: bool switchtoLogin = false;

	private: System::Void enterbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = usernametb->Text;
		String^ password = passwordtb->Text;
		String^ firstname = FirstNametb->Text;
		String^ lastname = LastNametb->Text;
		String^ confirmpw = confirmpwtb->Text;
		String^ email = Emailtb->Text;
		int ID = 0;

		if (firstname->Length == 0 || lastname->Length == 0 || email->Length == 0 || username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Required feild is empty. Please update");
			return;
		}

		if (String::Compare(password, confirmpw) != 0) {
			MessageBox::Show("Password and confirmed password dont match");
			return;
		}
		try {
			String^ connectString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
			SqlConnection sqlConn(connectString);
			sqlConn.Open();




			String^ sqlQuery = "INSERT INTO users" +
				"(firstname, lastname, username, password, email)VALUES" +
				"(@firstname, @lastname, @username, @password, @email); ";



			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@firstname", firstname);
			command.Parameters->AddWithValue("@lastname", lastname);
			command.Parameters->AddWithValue("@username", username);
			command.Parameters->AddWithValue("@password", password);
			command.Parameters->AddWithValue("@email", email);


			command.ExecuteNonQuery();

			user = gcnew User;
			user->set_firstname(firstname);
			user->set_lastname(lastname);
			user->set_username(username);
			user->set_password(password);
			user->set_email(email);
			user->set_fullname(user->getfirstName(), user->getlastName());

			this->Close();

		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to register new user");
		}

	}
private: System::Void Loginlbl_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchtoLogin = true;
	this->Close();
}
private: System::Void FirstNametb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	FirstNametb->Text = " ";
}
private: System::Void LastNametb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	LastNametb->Text = " ";
}

private: System::Void usernametb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	usernametb->Text = " ";
}
private: System::Void passwordtb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	passwordtb->Text = " ";
}
private: System::Void confirmpwtb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	confirmpwtb->Text = " ";
}
private: System::Void Emailtb_Clicked(System::Object^ sender, System::EventArgs^ e) {
	Emailtb->Text = " ";
}
	   bool dragging;
	   Point offset;
private: System::Void RegisterForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (dragging) {
		Point currentscreenPos = PointToScreen(Point(e->X, e->Y));
		Location = Point(currentscreenPos.X - offset.X, currentscreenPos.Y - offset.Y);
	}
}
private: System::Void RegisterForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = false;
}
private: System::Void RegisterForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = true;
	offset.X = e->X;
	offset.Y = e->Y;
}
private: System::Void FirstNametb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		LastNametb->Focus();
	}
}

private: System::Void LastNametb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		Emailtb->Focus();
	}
}

private: System::Void usernametb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		passwordtb->Focus();
	}
}

private: System::Void confirmpwtb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		enterbtn->PerformClick();
	}
}
private: System::Void passwordtb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		confirmpwtb->Focus();
	}
}
private: System::Void Emailtb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		usernametb->Focus();
	}
}
};
}
