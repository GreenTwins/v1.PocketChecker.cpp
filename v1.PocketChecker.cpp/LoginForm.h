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
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		User^ main_user = nullptr;
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ LoginLabel;
	private: System::Windows::Forms::GroupBox^ loginContainer;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ usernamelgn;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::LinkLabel^ Registerlbl;
	private: System::Windows::Forms::Button^ Enterbtn;
	private: System::Windows::Forms::TextBox^ passwordtb;
	private: System::Windows::Forms::TextBox^ usernametb;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LoginLabel = (gcnew System::Windows::Forms::Label());
			this->loginContainer = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->usernamelgn = (gcnew System::Windows::Forms::Label());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->Registerlbl = (gcnew System::Windows::Forms::LinkLabel());
			this->Enterbtn = (gcnew System::Windows::Forms::Button());
			this->passwordtb = (gcnew System::Windows::Forms::TextBox());
			this->usernametb = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->loginContainer->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->LoginLabel);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(437, 44);
			this->panel1->TabIndex = 11;
			// 
			// LoginLabel
			// 
			this->LoginLabel->AutoSize = true;
			this->LoginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginLabel->Location = System::Drawing::Point(3, 15);
			this->LoginLabel->Name = L"LoginLabel";
			this->LoginLabel->Size = System::Drawing::Size(66, 20);
			this->LoginLabel->TabIndex = 0;
			this->LoginLabel->Text = L"Sign In";
			// 
			// loginContainer
			// 
			this->loginContainer->BackColor = System::Drawing::Color::White;
			this->loginContainer->Controls->Add(this->panel1);
			this->loginContainer->Controls->Add(this->panel3);
			this->loginContainer->Controls->Add(this->panel2);
			this->loginContainer->Controls->Add(this->linkLabel2);
			this->loginContainer->Controls->Add(this->Registerlbl);
			this->loginContainer->Controls->Add(this->Enterbtn);
			this->loginContainer->Controls->Add(this->passwordtb);
			this->loginContainer->Controls->Add(this->usernametb);
			this->loginContainer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginContainer->Location = System::Drawing::Point(54, 107);
			this->loginContainer->Name = L"loginContainer";
			this->loginContainer->Size = System::Drawing::Size(437, 201);
			this->loginContainer->TabIndex = 10;
			this->loginContainer->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(32, 106);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(85, 20);
			this->panel3->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"PASSWORD";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->usernamelgn);
			this->panel2->Location = System::Drawing::Point(32, 62);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(85, 20);
			this->panel2->TabIndex = 8;
			// 
			// usernamelgn
			// 
			this->usernamelgn->AutoSize = true;
			this->usernamelgn->Location = System::Drawing::Point(3, 2);
			this->usernamelgn->Name = L"usernamelgn";
			this->usernamelgn->Size = System::Drawing::Size(76, 13);
			this->usernamelgn->TabIndex = 1;
			this->usernamelgn->Text = L"USERNAME";
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->linkLabel2->Location = System::Drawing::Point(366, 182);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(31, 13);
			this->linkLabel2->TabIndex = 7;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Q+A";
			// 
			// Registerlbl
			// 
			this->Registerlbl->AutoSize = true;
			this->Registerlbl->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Registerlbl->Location = System::Drawing::Point(275, 182);
			this->Registerlbl->Name = L"Registerlbl";
			this->Registerlbl->Size = System::Drawing::Size(54, 13);
			this->Registerlbl->TabIndex = 6;
			this->Registerlbl->TabStop = true;
			this->Registerlbl->Text = L"Register";
			this->Registerlbl->Click += gcnew System::EventHandler(this, &LoginForm::Registerbtn_Click);
			// 
			// Enterbtn
			// 
			this->Enterbtn->BackColor = System::Drawing::Color::SlateBlue;
			this->Enterbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Enterbtn->ForeColor = System::Drawing::SystemColors::Window;
			this->Enterbtn->Location = System::Drawing::Point(186, 146);
			this->Enterbtn->Name = L"Enterbtn";
			this->Enterbtn->Size = System::Drawing::Size(60, 29);
			this->Enterbtn->TabIndex = 5;
			this->Enterbtn->Text = L"Sign In";
			this->Enterbtn->UseVisualStyleBackColor = false;
			this->Enterbtn->Click += gcnew System::EventHandler(this, &LoginForm::Enterbtn_Click);
			// 
			// passwordtb
			// 
			this->passwordtb->Location = System::Drawing::Point(116, 106);
			this->passwordtb->Name = L"passwordtb";
			this->passwordtb->Size = System::Drawing::Size(281, 20);
			this->passwordtb->TabIndex = 4;
			this->passwordtb->UseSystemPasswordChar = true;
			this->passwordtb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::passwordtb_KeyDown);
			// 
			// usernametb
			// 
			this->usernametb->Location = System::Drawing::Point(116, 62);
			this->usernametb->Name = L"usernametb";
			this->usernametb->Size = System::Drawing::Size(281, 20);
			this->usernametb->TabIndex = 3;
			this->usernametb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::usernametb_KeyDown);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::BlueViolet;
			this->ClientSize = System::Drawing::Size(544, 452);
			this->Controls->Add(this->loginContainer);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->loginContainer->ResumeLayout(false);
			this->loginContainer->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Enterbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->usernametb->Text;
		String^ password = this->passwordtb->Text;



		if (password->Length == 0 || username->Length == 0) {
			MessageBox::Show("Required fields are empty");
			return;
		}
		try {
			String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
			SqlConnection sqlConnect(connectionString);
			sqlConnect.Open();

			String^ sqlQuery = "SELECT * FROM users WHERE username=@username AND password=@password;";
			SqlCommand dbConn(sqlQuery, % sqlConnect);
			dbConn.Parameters->AddWithValue("@username", username);
			dbConn.Parameters->AddWithValue("@password", password);


			SqlDataReader^ reader = dbConn.ExecuteReader();
			if (reader->Read()) {
				//MessageBox::Show(((String^)reader["userID"]));
				//User^ user;
				main_user = gcnew User;
				main_user->set_fullname(((String^)reader["firstname"]), ((String^)reader["lastname"]));
				main_user->set_username((String^)reader["username"]);
				main_user->set_password((String^)reader["password"]);
				//main_user->set_userID((int)reader["userID"]);

				//main_user = user;
				//this is where we will display their data such as goals/plans current money available etc
				this->Close();
			}
			else {
				MessageBox::Show("Email or Password is incorrect");

			}

		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to connect to database: " + e->Message);
		}
	}

public: bool switchToRegister = false;

private: System::Void Registerbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToRegister = true;
	this->Close();
}
private: System::Void usernametb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		passwordtb->Focus();
	}
}
private: System::Void passwordtb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		Enterbtn->PerformClick();
	}
}
};
}
