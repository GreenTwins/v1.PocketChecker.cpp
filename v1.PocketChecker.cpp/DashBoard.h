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
	/// Summary for DashBoard
	/// </summary>
	public ref class DashBoard : public System::Windows::Forms::Form
	{
	public:
		DashBoard(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			currentuser = user;
			currentuser->incomeItems = gcnew List<Item^>();
			currentuser->debtItems = gcnew List<Item^>();
			currentuser->billItems = gcnew List<Item^>();
			
			grabUserID();//will only happen once
			DashBoard_Load(user);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DashBoard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelDesktop;
	protected:
	private: System::Windows::Forms::Panel^ billbtnspanel;
	private: System::Windows::Forms::Button^ Editbtnbill;
	private: System::Windows::Forms::Button^ Removebtnbill;
	private: System::Windows::Forms::Button^ Addbtnbill;
	private: System::Windows::Forms::Panel^ debtbtnspanel;
	private: System::Windows::Forms::Button^ Editbtndebt;
	private: System::Windows::Forms::Button^ Removebtndebt;
	private: System::Windows::Forms::Button^ Addbtndebt;
	private: System::Windows::Forms::Panel^ incomebtnspanel;
	private: System::Windows::Forms::Button^ EditbtnIncome;
	private: System::Windows::Forms::Button^ RemovebtnIncome;
	private: System::Windows::Forms::Button^ AddbtnIncome;

	private: System::Windows::Forms::Label^ Dashboardlbl;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ Updateboard;
	private: System::Windows::Forms::TextBox^ Updateboardtotalamttb;
	private: System::Windows::Forms::TextBox^ Updateboardamounttb;
	private: System::Windows::Forms::ComboBox^ updateboardcycletb;
	private: System::Windows::Forms::TextBox^ Updateboardnametb;
	private: System::Windows::Forms::Button^ Updatecancelbtn;
	private: System::Windows::Forms::Button^ Updateenterbtn;
	private: System::Windows::Forms::Label^ planslbl;
	private: System::Windows::Forms::Panel^ currentSpendableShow;
	private: System::Windows::Forms::Label^ spendableamtlbl;
	private: System::Windows::Forms::Label^ weekspendablelbl;
	private: System::Windows::Forms::Panel^ currentBillShow;
	private: System::Windows::Forms::Button^ billmorebtn;
	private: System::Windows::Forms::Label^ billamt;
	private: System::Windows::Forms::Label^ billamtlbl;
	private: System::Windows::Forms::Panel^ currentIncomeShow;
	private: System::Windows::Forms::Button^ Incomemorebtn;
	private: System::Windows::Forms::Label^ incomeamtlbl;
	private: System::Windows::Forms::Label^ weeksincomelbl;
	private: System::Windows::Forms::Panel^ currentDebtShow;
	private: System::Windows::Forms::Button^ weeksdebtamtbtn;
	private: System::Windows::Forms::Label^ debtamtlbl;
	private: System::Windows::Forms::Label^ weeksdbtlbl;
	private: System::Windows::Forms::Panel^ panelTitle;
	private: System::Windows::Forms::Button^ Downsizebtn;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Closebtn;
	private: System::Windows::Forms::Label^ userDashlbl;
	private: System::Windows::Forms::Label^ Title;

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
			this->panelDesktop = (gcnew System::Windows::Forms::Panel());
			this->Dashboardlbl = (gcnew System::Windows::Forms::Label());
			this->panelTitle = (gcnew System::Windows::Forms::Panel());
			this->Downsizebtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Closebtn = (gcnew System::Windows::Forms::Button());
			this->userDashlbl = (gcnew System::Windows::Forms::Label());
			this->billbtnspanel = (gcnew System::Windows::Forms::Panel());
			this->Editbtnbill = (gcnew System::Windows::Forms::Button());
			this->Removebtnbill = (gcnew System::Windows::Forms::Button());
			this->Addbtnbill = (gcnew System::Windows::Forms::Button());
			this->debtbtnspanel = (gcnew System::Windows::Forms::Panel());
			this->Editbtndebt = (gcnew System::Windows::Forms::Button());
			this->Removebtndebt = (gcnew System::Windows::Forms::Button());
			this->Addbtndebt = (gcnew System::Windows::Forms::Button());
			this->incomebtnspanel = (gcnew System::Windows::Forms::Panel());
			this->EditbtnIncome = (gcnew System::Windows::Forms::Button());
			this->RemovebtnIncome = (gcnew System::Windows::Forms::Button());
			this->AddbtnIncome = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->planslbl = (gcnew System::Windows::Forms::Label());
			this->currentSpendableShow = (gcnew System::Windows::Forms::Panel());
			this->spendableamtlbl = (gcnew System::Windows::Forms::Label());
			this->weekspendablelbl = (gcnew System::Windows::Forms::Label());
			this->currentBillShow = (gcnew System::Windows::Forms::Panel());
			this->billmorebtn = (gcnew System::Windows::Forms::Button());
			this->billamt = (gcnew System::Windows::Forms::Label());
			this->billamtlbl = (gcnew System::Windows::Forms::Label());
			this->currentIncomeShow = (gcnew System::Windows::Forms::Panel());
			this->Incomemorebtn = (gcnew System::Windows::Forms::Button());
			this->incomeamtlbl = (gcnew System::Windows::Forms::Label());
			this->weeksincomelbl = (gcnew System::Windows::Forms::Label());
			this->currentDebtShow = (gcnew System::Windows::Forms::Panel());
			this->weeksdebtamtbtn = (gcnew System::Windows::Forms::Button());
			this->debtamtlbl = (gcnew System::Windows::Forms::Label());
			this->weeksdbtlbl = (gcnew System::Windows::Forms::Label());
			this->Updateboard = (gcnew System::Windows::Forms::Panel());
			this->Updateboardtotalamttb = (gcnew System::Windows::Forms::TextBox());
			this->Updateboardamounttb = (gcnew System::Windows::Forms::TextBox());
			this->updateboardcycletb = (gcnew System::Windows::Forms::ComboBox());
			this->Updateboardnametb = (gcnew System::Windows::Forms::TextBox());
			this->Updatecancelbtn = (gcnew System::Windows::Forms::Button());
			this->Updateenterbtn = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->panelDesktop->SuspendLayout();
			this->panelTitle->SuspendLayout();
			this->billbtnspanel->SuspendLayout();
			this->debtbtnspanel->SuspendLayout();
			this->incomebtnspanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->currentSpendableShow->SuspendLayout();
			this->currentBillShow->SuspendLayout();
			this->currentIncomeShow->SuspendLayout();
			this->currentDebtShow->SuspendLayout();
			this->Updateboard->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelDesktop
			// 
			this->panelDesktop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->panelDesktop->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDesktop->Controls->Add(this->Dashboardlbl);
			this->panelDesktop->Controls->Add(this->panelTitle);
			this->panelDesktop->Controls->Add(this->billbtnspanel);
			this->panelDesktop->Controls->Add(this->debtbtnspanel);
			this->panelDesktop->Controls->Add(this->incomebtnspanel);
			this->panelDesktop->Controls->Add(this->panel2);
			this->panelDesktop->Controls->Add(this->currentSpendableShow);
			this->panelDesktop->Controls->Add(this->currentBillShow);
			this->panelDesktop->Controls->Add(this->currentIncomeShow);
			this->panelDesktop->Controls->Add(this->currentDebtShow);
			this->panelDesktop->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDesktop->Location = System::Drawing::Point(0, 0);
			this->panelDesktop->Name = L"panelDesktop";
			this->panelDesktop->Size = System::Drawing::Size(826, 444);
			this->panelDesktop->TabIndex = 3;
			// 
			// Dashboardlbl
			// 
			this->Dashboardlbl->AutoSize = true;
			this->Dashboardlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Dashboardlbl->Location = System::Drawing::Point(348, 37);
			this->Dashboardlbl->Name = L"Dashboardlbl";
			this->Dashboardlbl->Size = System::Drawing::Size(122, 20);
			this->Dashboardlbl->TabIndex = 0;
			this->Dashboardlbl->Text = L"DASHBOARD";
			// 
			// panelTitle
			// 
			this->panelTitle->BackColor = System::Drawing::Color::SlateBlue;
			this->panelTitle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTitle->Controls->Add(this->Downsizebtn);
			this->panelTitle->Controls->Add(this->button1);
			this->panelTitle->Controls->Add(this->Closebtn);
			this->panelTitle->Controls->Add(this->userDashlbl);
			this->panelTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTitle->Location = System::Drawing::Point(0, 0);
			this->panelTitle->Name = L"panelTitle";
			this->panelTitle->Size = System::Drawing::Size(824, 22);
			this->panelTitle->TabIndex = 8;
			// 
			// Downsizebtn
			// 
			this->Downsizebtn->BackColor = System::Drawing::Color::SlateBlue;
			this->Downsizebtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Downsizebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Downsizebtn->FlatAppearance->BorderSize = 0;
			this->Downsizebtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Downsizebtn->ForeColor = System::Drawing::Color::White;
			this->Downsizebtn->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->Downsizebtn->Location = System::Drawing::Point(681, -1);
			this->Downsizebtn->Margin = System::Windows::Forms::Padding(0);
			this->Downsizebtn->Name = L"Downsizebtn";
			this->Downsizebtn->Size = System::Drawing::Size(43, 21);
			this->Downsizebtn->TabIndex = 2;
			this->Downsizebtn->Text = L"__";
			this->Downsizebtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->Downsizebtn->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SlateBlue;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->button1->Location = System::Drawing::Point(729, 0);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(43, 21);
			this->button1->TabIndex = 1;
			this->button1->Text = L"[  ]";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// Closebtn
			// 
			this->Closebtn->BackColor = System::Drawing::Color::SlateBlue;
			this->Closebtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Closebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Closebtn->FlatAppearance->BorderSize = 0;
			this->Closebtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Closebtn->ForeColor = System::Drawing::Color::White;
			this->Closebtn->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->Closebtn->Location = System::Drawing::Point(781, -1);
			this->Closebtn->Margin = System::Windows::Forms::Padding(0);
			this->Closebtn->Name = L"Closebtn";
			this->Closebtn->Size = System::Drawing::Size(43, 21);
			this->Closebtn->TabIndex = 0;
			this->Closebtn->Text = L"X";
			this->Closebtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->Closebtn->UseVisualStyleBackColor = false;
			this->Closebtn->Click += gcnew System::EventHandler(this, &DashBoard::Closebtn_Click);
			// 
			// userDashlbl
			// 
			this->userDashlbl->AutoSize = true;
			this->userDashlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userDashlbl->ForeColor = System::Drawing::Color::White;
			this->userDashlbl->Location = System::Drawing::Point(20, 4);
			this->userDashlbl->Name = L"userDashlbl";
			this->userDashlbl->Size = System::Drawing::Size(0, 13);
			this->userDashlbl->TabIndex = 0;
			// 
			// billbtnspanel
			// 
			this->billbtnspanel->BackColor = System::Drawing::Color::White;
			this->billbtnspanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billbtnspanel->Controls->Add(this->Editbtnbill);
			this->billbtnspanel->Controls->Add(this->Removebtnbill);
			this->billbtnspanel->Controls->Add(this->Addbtnbill);
			this->billbtnspanel->Location = System::Drawing::Point(412, 132);
			this->billbtnspanel->Name = L"billbtnspanel";
			this->billbtnspanel->Size = System::Drawing::Size(171, 23);
			this->billbtnspanel->TabIndex = 7;
			this->billbtnspanel->Visible = false;
			// 
			// Editbtnbill
			// 
			this->Editbtnbill->Location = System::Drawing::Point(108, 1);
			this->Editbtnbill->Name = L"Editbtnbill";
			this->Editbtnbill->Size = System::Drawing::Size(59, 21);
			this->Editbtnbill->TabIndex = 2;
			this->Editbtnbill->Text = L"Edit";
			this->Editbtnbill->UseVisualStyleBackColor = true;
			this->Editbtnbill->Click += gcnew System::EventHandler(this, &DashBoard::Editbtnbill_Click);
			// 
			// Removebtnbill
			// 
			this->Removebtnbill->Location = System::Drawing::Point(47, 1);
			this->Removebtnbill->Name = L"Removebtnbill";
			this->Removebtnbill->Size = System::Drawing::Size(56, 21);
			this->Removebtnbill->TabIndex = 1;
			this->Removebtnbill->Text = L"Remove";
			this->Removebtnbill->UseVisualStyleBackColor = true;
			this->Removebtnbill->Click += gcnew System::EventHandler(this, &DashBoard::Removebtnbill_Click);
			// 
			// Addbtnbill
			// 
			this->Addbtnbill->Location = System::Drawing::Point(0, 1);
			this->Addbtnbill->Name = L"Addbtnbill";
			this->Addbtnbill->Size = System::Drawing::Size(42, 21);
			this->Addbtnbill->TabIndex = 0;
			this->Addbtnbill->Text = L"Add";
			this->Addbtnbill->UseVisualStyleBackColor = true;
			this->Addbtnbill->Click += gcnew System::EventHandler(this, &DashBoard::Addbtnbill_Click);
			// 
			// debtbtnspanel
			// 
			this->debtbtnspanel->BackColor = System::Drawing::Color::White;
			this->debtbtnspanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->debtbtnspanel->Controls->Add(this->Editbtndebt);
			this->debtbtnspanel->Controls->Add(this->Removebtndebt);
			this->debtbtnspanel->Controls->Add(this->Addbtndebt);
			this->debtbtnspanel->Location = System::Drawing::Point(589, 134);
			this->debtbtnspanel->Name = L"debtbtnspanel";
			this->debtbtnspanel->Size = System::Drawing::Size(172, 23);
			this->debtbtnspanel->TabIndex = 7;
			this->debtbtnspanel->Visible = false;
			// 
			// Editbtndebt
			// 
			this->Editbtndebt->Location = System::Drawing::Point(108, 1);
			this->Editbtndebt->Name = L"Editbtndebt";
			this->Editbtndebt->Size = System::Drawing::Size(59, 21);
			this->Editbtndebt->TabIndex = 2;
			this->Editbtndebt->Text = L"Edit";
			this->Editbtndebt->UseVisualStyleBackColor = true;
			this->Editbtndebt->Click += gcnew System::EventHandler(this, &DashBoard::Editbtndebt_Click);
			// 
			// Removebtndebt
			// 
			this->Removebtndebt->Location = System::Drawing::Point(46, 1);
			this->Removebtndebt->Name = L"Removebtndebt";
			this->Removebtndebt->Size = System::Drawing::Size(56, 21);
			this->Removebtndebt->TabIndex = 1;
			this->Removebtndebt->Text = L"Remove";
			this->Removebtndebt->UseVisualStyleBackColor = true;
			this->Removebtndebt->Click += gcnew System::EventHandler(this, &DashBoard::Removebtndebt_Click);
			// 
			// Addbtndebt
			// 
			this->Addbtndebt->Location = System::Drawing::Point(0, 1);
			this->Addbtndebt->Name = L"Addbtndebt";
			this->Addbtndebt->Size = System::Drawing::Size(42, 21);
			this->Addbtndebt->TabIndex = 0;
			this->Addbtndebt->Text = L"Add";
			this->Addbtndebt->UseVisualStyleBackColor = true;
			this->Addbtndebt->Click += gcnew System::EventHandler(this, &DashBoard::Addbtndebt_Click);
			// 
			// incomebtnspanel
			// 
			this->incomebtnspanel->BackColor = System::Drawing::Color::White;
			this->incomebtnspanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->incomebtnspanel->Controls->Add(this->EditbtnIncome);
			this->incomebtnspanel->Controls->Add(this->RemovebtnIncome);
			this->incomebtnspanel->Controls->Add(this->AddbtnIncome);
			this->incomebtnspanel->Location = System::Drawing::Point(226, 132);
			this->incomebtnspanel->Name = L"incomebtnspanel";
			this->incomebtnspanel->Size = System::Drawing::Size(172, 23);
			this->incomebtnspanel->TabIndex = 6;
			this->incomebtnspanel->Visible = false;
			// 
			// EditbtnIncome
			// 
			this->EditbtnIncome->Location = System::Drawing::Point(108, 1);
			this->EditbtnIncome->Name = L"EditbtnIncome";
			this->EditbtnIncome->Size = System::Drawing::Size(59, 21);
			this->EditbtnIncome->TabIndex = 2;
			this->EditbtnIncome->Text = L"Edit";
			this->EditbtnIncome->UseVisualStyleBackColor = true;
			this->EditbtnIncome->Click += gcnew System::EventHandler(this, &DashBoard::EditbtnIncome_Click);
			// 
			// RemovebtnIncome
			// 
			this->RemovebtnIncome->Location = System::Drawing::Point(46, 1);
			this->RemovebtnIncome->Name = L"RemovebtnIncome";
			this->RemovebtnIncome->Size = System::Drawing::Size(56, 21);
			this->RemovebtnIncome->TabIndex = 1;
			this->RemovebtnIncome->Text = L"Remove";
			this->RemovebtnIncome->UseVisualStyleBackColor = true;
			this->RemovebtnIncome->Click += gcnew System::EventHandler(this, &DashBoard::RemovebtnIncome_Click);
			// 
			// AddbtnIncome
			// 
			this->AddbtnIncome->Location = System::Drawing::Point(0, 1);
			this->AddbtnIncome->Name = L"AddbtnIncome";
			this->AddbtnIncome->Size = System::Drawing::Size(42, 21);
			this->AddbtnIncome->TabIndex = 0;
			this->AddbtnIncome->Text = L"Add";
			this->AddbtnIncome->UseVisualStyleBackColor = true;
			this->AddbtnIncome->Click += gcnew System::EventHandler(this, &DashBoard::AddbtnIncome_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->planslbl);
			this->panel2->Location = System::Drawing::Point(41, 144);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(396, 226);
			this->panel2->TabIndex = 4;
			// 
			// planslbl
			// 
			this->planslbl->AutoSize = true;
			this->planslbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->planslbl->Location = System::Drawing::Point(12, 11);
			this->planslbl->Name = L"planslbl";
			this->planslbl->Size = System::Drawing::Size(99, 16);
			this->planslbl->TabIndex = 0;
			this->planslbl->Text = L"Current Plans";
			// 
			// currentSpendableShow
			// 
			this->currentSpendableShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(195)));
			this->currentSpendableShow->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->currentSpendableShow->Controls->Add(this->spendableamtlbl);
			this->currentSpendableShow->Controls->Add(this->weekspendablelbl);
			this->currentSpendableShow->Location = System::Drawing::Point(41, 74);
			this->currentSpendableShow->Name = L"currentSpendableShow";
			this->currentSpendableShow->Size = System::Drawing::Size(175, 58);
			this->currentSpendableShow->TabIndex = 3;
			// 
			// spendableamtlbl
			// 
			this->spendableamtlbl->AutoSize = true;
			this->spendableamtlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spendableamtlbl->ForeColor = System::Drawing::Color::White;
			this->spendableamtlbl->Location = System::Drawing::Point(78, 23);
			this->spendableamtlbl->Name = L"spendableamtlbl";
			this->spendableamtlbl->Size = System::Drawing::Size(0, 16);
			this->spendableamtlbl->TabIndex = 1;
			// 
			// weekspendablelbl
			// 
			this->weekspendablelbl->AutoSize = true;
			this->weekspendablelbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->weekspendablelbl->ForeColor = System::Drawing::Color::White;
			this->weekspendablelbl->Location = System::Drawing::Point(25, 10);
			this->weekspendablelbl->Name = L"weekspendablelbl";
			this->weekspendablelbl->Size = System::Drawing::Size(100, 13);
			this->weekspendablelbl->TabIndex = 0;
			this->weekspendablelbl->Text = L"Week\'s Spendable ";
			// 
			// currentBillShow
			// 
			this->currentBillShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(193)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->currentBillShow->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->currentBillShow->Controls->Add(this->billmorebtn);
			this->currentBillShow->Controls->Add(this->billamt);
			this->currentBillShow->Controls->Add(this->billamtlbl);
			this->currentBillShow->Location = System::Drawing::Point(405, 74);
			this->currentBillShow->Name = L"currentBillShow";
			this->currentBillShow->Size = System::Drawing::Size(175, 58);
			this->currentBillShow->TabIndex = 2;
			// 
			// billmorebtn
			// 
			this->billmorebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->billmorebtn->Location = System::Drawing::Point(150, 37);
			this->billmorebtn->Name = L"billmorebtn";
			this->billmorebtn->Size = System::Drawing::Size(24, 20);
			this->billmorebtn->TabIndex = 4;
			this->billmorebtn->Text = L"+";
			this->billmorebtn->UseVisualStyleBackColor = true;
			this->billmorebtn->Click += gcnew System::EventHandler(this, &DashBoard::billmorebtn_Click);
			// 
			// billamt
			// 
			this->billamt->AutoSize = true;
			this->billamt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->billamt->ForeColor = System::Drawing::Color::White;
			this->billamt->Location = System::Drawing::Point(55, 23);
			this->billamt->Name = L"billamt";
			this->billamt->Size = System::Drawing::Size(0, 16);
			this->billamt->TabIndex = 1;
			// 
			// billamtlbl
			// 
			this->billamtlbl->AutoSize = true;
			this->billamtlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->billamtlbl->ForeColor = System::Drawing::Color::White;
			this->billamtlbl->Location = System::Drawing::Point(36, 10);
			this->billamtlbl->Name = L"billamtlbl";
			this->billamtlbl->Size = System::Drawing::Size(59, 13);
			this->billamtlbl->TabIndex = 0;
			this->billamtlbl->Text = L"Bill Amount";
			// 
			// currentIncomeShow
			// 
			this->currentIncomeShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(154)));
			this->currentIncomeShow->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->currentIncomeShow->Controls->Add(this->Incomemorebtn);
			this->currentIncomeShow->Controls->Add(this->incomeamtlbl);
			this->currentIncomeShow->Controls->Add(this->weeksincomelbl);
			this->currentIncomeShow->Location = System::Drawing::Point(224, 74);
			this->currentIncomeShow->Name = L"currentIncomeShow";
			this->currentIncomeShow->Size = System::Drawing::Size(175, 58);
			this->currentIncomeShow->TabIndex = 1;
			// 
			// Incomemorebtn
			// 
			this->Incomemorebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Incomemorebtn->Location = System::Drawing::Point(150, 37);
			this->Incomemorebtn->Name = L"Incomemorebtn";
			this->Incomemorebtn->Size = System::Drawing::Size(24, 20);
			this->Incomemorebtn->TabIndex = 3;
			this->Incomemorebtn->Text = L"+";
			this->Incomemorebtn->UseVisualStyleBackColor = true;
			this->Incomemorebtn->Click += gcnew System::EventHandler(this, &DashBoard::Incomemorebtn_Click);
			// 
			// incomeamtlbl
			// 
			this->incomeamtlbl->AutoSize = true;
			this->incomeamtlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->incomeamtlbl->ForeColor = System::Drawing::Color::White;
			this->incomeamtlbl->Location = System::Drawing::Point(45, 23);
			this->incomeamtlbl->Name = L"incomeamtlbl";
			this->incomeamtlbl->Size = System::Drawing::Size(0, 16);
			this->incomeamtlbl->TabIndex = 1;
			// 
			// weeksincomelbl
			// 
			this->weeksincomelbl->AutoSize = true;
			this->weeksincomelbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->weeksincomelbl->ForeColor = System::Drawing::Color::White;
			this->weeksincomelbl->Location = System::Drawing::Point(29, 10);
			this->weeksincomelbl->Name = L"weeksincomelbl";
			this->weeksincomelbl->Size = System::Drawing::Size(81, 13);
			this->weeksincomelbl->TabIndex = 0;
			this->weeksincomelbl->Text = L"Week\'s Income";
			// 
			// currentDebtShow
			// 
			this->currentDebtShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(156)));
			this->currentDebtShow->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->currentDebtShow->Controls->Add(this->weeksdebtamtbtn);
			this->currentDebtShow->Controls->Add(this->debtamtlbl);
			this->currentDebtShow->Controls->Add(this->weeksdbtlbl);
			this->currentDebtShow->Location = System::Drawing::Point(586, 74);
			this->currentDebtShow->Name = L"currentDebtShow";
			this->currentDebtShow->Size = System::Drawing::Size(175, 58);
			this->currentDebtShow->TabIndex = 0;
			// 
			// weeksdebtamtbtn
			// 
			this->weeksdebtamtbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->weeksdebtamtbtn->Location = System::Drawing::Point(150, 37);
			this->weeksdebtamtbtn->Name = L"weeksdebtamtbtn";
			this->weeksdebtamtbtn->Size = System::Drawing::Size(24, 20);
			this->weeksdebtamtbtn->TabIndex = 5;
			this->weeksdebtamtbtn->Text = L"+";
			this->weeksdebtamtbtn->UseVisualStyleBackColor = true;
			this->weeksdebtamtbtn->Click += gcnew System::EventHandler(this, &DashBoard::weeksdebtamtbtn_Click);
			// 
			// debtamtlbl
			// 
			this->debtamtlbl->AutoSize = true;
			this->debtamtlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->debtamtlbl->ForeColor = System::Drawing::Color::White;
			this->debtamtlbl->Location = System::Drawing::Point(68, 23);
			this->debtamtlbl->Name = L"debtamtlbl";
			this->debtamtlbl->Size = System::Drawing::Size(0, 16);
			this->debtamtlbl->TabIndex = 1;
			// 
			// weeksdbtlbl
			// 
			this->weeksdbtlbl->AutoSize = true;
			this->weeksdbtlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->weeksdbtlbl->ForeColor = System::Drawing::Color::White;
			this->weeksdbtlbl->Location = System::Drawing::Point(39, 10);
			this->weeksdbtlbl->Name = L"weeksdbtlbl";
			this->weeksdbtlbl->Size = System::Drawing::Size(69, 13);
			this->weeksdbtlbl->TabIndex = 0;
			this->weeksdbtlbl->Text = L"Weeks\' Debt";
			// 
			// Updateboard
			// 
			this->Updateboard->BackColor = System::Drawing::Color::White;
			this->Updateboard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Updateboard->Controls->Add(this->Updateboardtotalamttb);
			this->Updateboard->Controls->Add(this->Updateboardamounttb);
			this->Updateboard->Controls->Add(this->updateboardcycletb);
			this->Updateboard->Controls->Add(this->Updateboardnametb);
			this->Updateboard->Controls->Add(this->Updatecancelbtn);
			this->Updateboard->Controls->Add(this->Updateenterbtn);
			this->Updateboard->Location = System::Drawing::Point(280, 162);
			this->Updateboard->Name = L"Updateboard";
			this->Updateboard->Size = System::Drawing::Size(338, 189);
			this->Updateboard->TabIndex = 8;
			this->Updateboard->Visible = false;
			// 
			// Updateboardtotalamttb
			// 
			this->Updateboardtotalamttb->Location = System::Drawing::Point(223, 51);
			this->Updateboardtotalamttb->Name = L"Updateboardtotalamttb";
			this->Updateboardtotalamttb->Size = System::Drawing::Size(97, 20);
			this->Updateboardtotalamttb->TabIndex = 9;
			this->Updateboardtotalamttb->Text = L"Total Amount";
			this->Updateboardtotalamttb->Click += gcnew System::EventHandler(this, &DashBoard::Updateboardtotalamttb_Click);
			this->Updateboardtotalamttb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::Updateboardtotalamttb_KeyDown);
			// 
			// Updateboardamounttb
			// 
			this->Updateboardamounttb->Location = System::Drawing::Point(27, 90);
			this->Updateboardamounttb->Name = L"Updateboardamounttb";
			this->Updateboardamounttb->Size = System::Drawing::Size(97, 20);
			this->Updateboardamounttb->TabIndex = 8;
			this->Updateboardamounttb->Text = L"Amount per Cycle";
			this->Updateboardamounttb->Click += gcnew System::EventHandler(this, &DashBoard::Updateboardamounttb_Click);
			this->Updateboardamounttb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::Updateboardamounttb_KeyDown);
			// 
			// updateboardcycletb
			// 
			this->updateboardcycletb->FormattingEnabled = true;
			this->updateboardcycletb->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Monthly", L"Bi-Weekly", L"Weekly" });
			this->updateboardcycletb->Location = System::Drawing::Point(223, 90);
			this->updateboardcycletb->Name = L"updateboardcycletb";
			this->updateboardcycletb->Size = System::Drawing::Size(97, 21);
			this->updateboardcycletb->TabIndex = 7;
			this->updateboardcycletb->Text = L"Pick Cycle";
			this->updateboardcycletb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::updateboardcycletb_KeyDown);
			// 
			// Updateboardnametb
			// 
			this->Updateboardnametb->Location = System::Drawing::Point(27, 51);
			this->Updateboardnametb->Name = L"Updateboardnametb";
			this->Updateboardnametb->Size = System::Drawing::Size(97, 20);
			this->Updateboardnametb->TabIndex = 6;
			this->Updateboardnametb->Text = L"Name";
			this->Updateboardnametb->Click += gcnew System::EventHandler(this, &DashBoard::Updateboardnametb_Click);
			this->Updateboardnametb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::Updateboardnametb_KeyDown);
			// 
			// Updatecancelbtn
			// 
			this->Updatecancelbtn->Location = System::Drawing::Point(189, 164);
			this->Updatecancelbtn->Name = L"Updatecancelbtn";
			this->Updatecancelbtn->Size = System::Drawing::Size(52, 20);
			this->Updatecancelbtn->TabIndex = 2;
			this->Updatecancelbtn->Text = L"Cancel";
			this->Updatecancelbtn->UseVisualStyleBackColor = true;
			this->Updatecancelbtn->Click += gcnew System::EventHandler(this, &DashBoard::Updatecancelbtn_Click);
			// 
			// Updateenterbtn
			// 
			this->Updateenterbtn->Location = System::Drawing::Point(119, 164);
			this->Updateenterbtn->Name = L"Updateenterbtn";
			this->Updateenterbtn->Size = System::Drawing::Size(52, 20);
			this->Updateenterbtn->TabIndex = 1;
			this->Updateenterbtn->Text = L"Enter";
			this->Updateenterbtn->UseVisualStyleBackColor = true;
			this->Updateenterbtn->Click += gcnew System::EventHandler(this, &DashBoard::Updateenterbtn_Click);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(380, 165);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(0, 20);
			this->Title->TabIndex = 10;
			this->Title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// DashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::BlueViolet;
			this->ClientSize = System::Drawing::Size(826, 444);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->Updateboard);
			this->Controls->Add(this->panelDesktop);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"DashBoard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DashBoard";
			this->panelDesktop->ResumeLayout(false);
			this->panelDesktop->PerformLayout();
			this->panelTitle->ResumeLayout(false);
			this->panelTitle->PerformLayout();
			this->billbtnspanel->ResumeLayout(false);
			this->debtbtnspanel->ResumeLayout(false);
			this->incomebtnspanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->currentSpendableShow->ResumeLayout(false);
			this->currentSpendableShow->PerformLayout();
			this->currentBillShow->ResumeLayout(false);
			this->currentBillShow->PerformLayout();
			this->currentIncomeShow->ResumeLayout(false);
			this->currentIncomeShow->PerformLayout();
			this->currentDebtShow->ResumeLayout(false);
			this->currentDebtShow->PerformLayout();
			this->Updateboard->ResumeLayout(false);
			this->Updateboard->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: User^ currentuser = nullptr;
		public: String^ currentUpdateClicked = " ";
		public: Item^ newItem = nullptr;
			  //land of local variables
			  int currentTab = 0;
			  int billmorebtnClick = 0;
			  int numIncomemorebtnClick = 0;
			  int weeksdebtamtbtnclick = 0;
			  int numofItems = 0;
	public: void grabUserID() {
		String^ currentUsername = currentuser->getUsername();
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
			SqlConnection newsqlConn(connString);
			newsqlConn.Open();


			String^ sqlQuery = "SELECT userID FROM users WHERE username=@currentUsername";
			SqlCommand newdBConn(sqlQuery, % newsqlConn);
			newdBConn.Parameters->AddWithValue("@currentUsername", currentUsername);

			SqlCommand command(sqlQuery, % newsqlConn);

			SqlDataReader^ reader = newdBConn.ExecuteReader();
			if (reader->Read()) {
				currentuser->set_userID(System::Convert::ToInt32(reader["userID"]));
				//int foundID = System::Convert::ToInt32(ID);
				MessageBox::Show(" " + currentuser->get_userID());
			}
			else {
				MessageBox::Show("didnt get userID");

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}

	}
	public: void checkInventory() {
		int ID = currentuser->get_userID();
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
			SqlConnection reloadConn(connString);
			reloadConn.Open();


			String^ Query = "SELECT COUNT(*) as VaultId FROM Vault WHERE usersID = @ID ";
			SqlCommand newdBConn(Query, % reloadConn);
			newdBConn.Parameters->AddWithValue("@ID", currentuser->get_userID());

			//SqlCommand command(sqlQuery, % newsqlConn);

			SqlDataReader^ reader = newdBConn.ExecuteReader();
			if (reader->Read()) {
				numofItems = System::Convert::ToInt32(reader["VaultId"]);
				//int foundID = System::Convert::ToInt32(ID);
				MessageBox::Show(" " + numofItems);
			}
			else {
				MessageBox::Show("didnt get userID");

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}
	}

	public: void loaddBData() {
		List<Item^>^ container = gcnew List<Item^>();
		try {
			for (int i = 0; i < numofItems; i++) {
				String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
				SqlConnection reloadConn(connString);
				reloadConn.Open();

				String^ Query = "SELECT * FROM Vault WHERE usersID=@ID";
				SqlCommand newdBConn(Query, % reloadConn);
				newdBConn.Parameters->AddWithValue("@ID", currentuser->get_userID());

				//SqlCommand command(sqlQuery, % newsqlConn);

				SqlDataReader^ reader = newdBConn.ExecuteReader();
				if (reader->Read()) {
					//MessageBox::Show("Started the read");
					newItem = gcnew Item;
					newItem->set_type((String^)reader["itemType"]);
					newItem->set_name((String^)reader["itemName"]);
					//MessageBox::Show("got the name and type");
					newItem->set_totalamt(System::Convert::ToInt64((String^)reader["itemtotalpayment"]));
					//MessageBox::Show(""+newItem->gettotal());
					newItem->set_payment(System::Convert::ToInt32((String^)reader["itemcurrentpayment"]));
					//MessageBox::Show("payment");
					newItem->set_frequency(System::Convert::ToInt32((String^)reader["itempaymentoccurance"]));
					//MessageBox::Show("freq");
					container->Add(newItem);
				}
				else {
					//MessageBox::Show("didnt get userID. Terminating Program");
					this->Close();
				}
			}
		}
			
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}
		//MessageBox::Show("Completed the load");
		
	}
	private: System::Void DashBoard_Load(User^ user) {
		float incometotal = 0;
		float debttotal = 0;
		float billtotal = 0;
		float spendable = 0;
		int ID = 0;
		
		userDashlbl->Text = "Welcome back " +
			currentuser->getfullName();

		

		//load any items for user thats in dB
		checkInventory();
		if (numofItems > 0) {
			loaddBData();
		}
		
		if (currentuser->incomeItems->Count > 0) {
			for (int i = 0; i < currentuser->incomeItems->Count; i++) {
				incometotal += currentuser->incomeItems[i]->getpayment();
			}
		}
		else {
			incometotal = 0.00;
		}
		//debt
		if (currentuser->debtItems->Count >0) {
			for (int i = 0; i < currentuser->debtItems->Count; i++) {
				debttotal += currentuser->debtItems[i]->getpayment();
			}
		}
		else {
			debttotal = 0.00;
		}

		//bill
		if (currentuser->billItems->Count >0) {
			for (int i = 0; i < currentuser->billItems->Count; i++) {
				billtotal += currentuser->billItems[i]->getpayment();
			}
		}
		else {
			billtotal = 0.00;
		}

		spendable = incometotal - (billtotal + debttotal);
		incomeamtlbl->Text = "$ " + incometotal;
		billamt->Text = "$ " + billtotal;
		debtamtlbl->Text = "$ " + debttotal;
		spendableamtlbl->Text = "$ " + spendable;

	}
	private: System::Void Closebtn_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
	}
	public: System::Void PopulateUpdateBoard(int tag, String^ destination, int reciever) {//IBD
			Updateboard->Location.X = 0;
			Updateboard->Location.Y = 0;
			Updateboard->Visible = true;
			currentTab = reciever;

			switch (tag) {
			case 1:
				Title->Text = "Add " + destination;

				break;
			case 2:
				Title->Text = "Edit " + destination;
				break;
			case 3:
				Title->Text = "Remove " + destination;
				break;
			default:
				break;
			}
		}
private: System::Void AddbtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
	incomebtnspanel->Visible = false;
	currentUpdateClicked = "Income";
	PopulateUpdateBoard(1, currentUpdateClicked, 1);
	Incomemorebtn->Text = "+";
	numIncomemorebtnClick = 0;
}

private: System::Void Updateenterbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	int itempaymentoccurance;
	int usersID;
	String^ frequency = updateboardcycletb->Text;
	String^ itemName = Updateboardnametb->Text;
	int itemtotalamount = (Convert::ToInt32(Updateboardtotalamttb->Text));
	int itemcurrentpayment = (Convert::ToInt32(Updateboardamounttb->Text));
	String^ itemType = " ";

	if (frequency == "Monthly") {
		itempaymentoccurance = 1;
	}
	else if (frequency == "Weekly") {
		itempaymentoccurance = 4;
	}
	else {
		itempaymentoccurance = 2;
	}

	if (currentUpdateClicked == "Income") {
		itemType = "I";
	}
	else if (currentUpdateClicked == "Bills") {
		itemType = "B";
	}
	else {
		itemType = "D";
	}
	

	//for sql
	

	usersID = currentuser->get_userID();
	//MessageBox::Show(sqlColumnName);
	//update sql
	
	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
		SqlConnection newsqlConn(connString);
		newsqlConn.Open();

		//MessageBox::Show(newsqlConn.State.ToString());

		String^ sqlQuery = "INSERT INTO Vault" +
			"(itemType, itemName, itemtotalamount, itemcurrentpayment, itempaymentoccurance, usersID)VALUES" +
			"(@itemType, @itemName, @itemtotalamount, @itemcurrentpayment, @itempaymentoccurance, @usersID);"; //changing the above to match is what allowed the connection

		//MessageBox::Show("query set to insert");

		SqlCommand command(sqlQuery, % newsqlConn);


		command.Parameters->AddWithValue("@itemType", itemType);
		command.Parameters->AddWithValue("@itemName", itemName);
		command.Parameters->AddWithValue("@itemtotalamount", itemtotalamount);
		command.Parameters->AddWithValue("@itemcurrentpayment", itemcurrentpayment);
		command.Parameters->AddWithValue("@itempaymentoccurance", itempaymentoccurance);
		command.Parameters->AddWithValue("@usersID", usersID);

		

		
		
		command.ExecuteNonQuery();
		//MessageBox::Show("Executed");
		newItem = gcnew Item;
		newItem->set_name(itemName);
		newItem->set_payment(itemcurrentpayment);

		newItem->set_frequency(itempaymentoccurance);
		newItem->set_totalamt(itemtotalamount);
		newItem->set_owner(usersID);

		if (currentUpdateClicked == "Income") {
			currentuser->incomeItems->Add(newItem);
		}
		else if (currentUpdateClicked == "Bills") {
			currentuser->billItems->Add(newItem);
		}
		else {
			currentuser->debtItems->Add(newItem);
		}
		
		
		Updateboard->Visible = false;
		Title->Text = "";

		
	}

	catch (Exception^ x) {
		MessageBox::Show("Failed to register new item "+x->Message);
		Updatecancelbtn_Click(this, e);

	}
	DashBoard_Load(currentuser);
	
}

	   //--------BUTTON CLICK EVENTS-----------//
private: System::Void Updatecancelbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Updateboard->Visible = false;
	Title->Text = "";
}
private: System::Void Updateboardnametb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Updateboardnametb->Text = " ";
}
private: System::Void Updateboardtotalamttb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Updateboardtotalamttb->Text = " ";
}
private: System::Void Updateboardamounttb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Updateboardamounttb->Text = " ";
}
private: System::Void RemovebtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
	incomebtnspanel->Visible = false;
	PopulateUpdateBoard(3, "Income", 1);
	Incomemorebtn->Text = "+";
	numIncomemorebtnClick = 0;
}
private: System::Void EditbtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
	incomebtnspanel->Visible = false;
	PopulateUpdateBoard(2, "Income", 1);
	Incomemorebtn->Text = "+";
	numIncomemorebtnClick = 0;
}
private: System::Void Addbtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	currentUpdateClicked = "Bills";
	PopulateUpdateBoard(1, currentUpdateClicked, 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Removebtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	PopulateUpdateBoard(3, "Bill", 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Editbtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	PopulateUpdateBoard(2, "Bill", 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Addbtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	currentUpdateClicked = "Debt";
	PopulateUpdateBoard(1, currentUpdateClicked, 3);
	weeksdebtamtbtn->Text = "+";
	weeksdebtamtbtnclick = 0;
}
private: System::Void Removebtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	PopulateUpdateBoard(3, "Debt", 3);
	weeksdebtamtbtn->Text = "+";
	weeksdebtamtbtnclick = 0;
}
private: System::Void Editbtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	PopulateUpdateBoard(2, "Debt", 3);
	weeksdebtamtbtn->Text = "+";
	weeksdebtamtbtnclick = 0;
}
private: System::Void Incomemorebtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (numIncomemorebtnClick == 0) {
		incomebtnspanel->Visible = true;
		Incomemorebtn->Text = "-";
		numIncomemorebtnClick += 1;
	}
	else if (numIncomemorebtnClick > 0) {
		incomebtnspanel->Visible = false;
		Incomemorebtn->Text = "+";
		numIncomemorebtnClick -= 1;
	}
}
private: System::Void billmorebtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (billmorebtnClick == 0) {
		billbtnspanel->Visible = true;
		billmorebtn->Text = "-";
		billmorebtnClick += 1;
	}
	else if (billmorebtnClick > 0) {
		billbtnspanel->Visible = false;
		billmorebtn->Text = "+";
		billmorebtnClick -= 1;
	}
}
private: System::Void weeksdebtamtbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (weeksdebtamtbtnclick == 0) {
		debtbtnspanel->Visible = true;
		weeksdebtamtbtn->Text = "-";
		weeksdebtamtbtnclick += 1;
	}
	else if (weeksdebtamtbtnclick > 0) {
		debtbtnspanel->Visible = false;
		weeksdebtamtbtn->Text = "+";
		weeksdebtamtbtnclick -= 1;
	}
}

private: System::Void Updateboardnametb_Click(System::Object^ sender, System::EventArgs^ e) {
	Updateboardnametb->Text = " ";
}
private: System::Void Updateboardamounttb_Click(System::Object^ sender, System::EventArgs^ e) {
	Updateboardamounttb->Text = " ";
}
private: System::Void Updateboardtotalamttb_Click(System::Object^ sender, System::EventArgs^ e) {
	Updateboardtotalamttb->Text = " ";
}
private: System::Void Updateboardnametb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		Updateboardtotalamttb->Focus();
	}
}

private: System::Void Updateboardtotalamttb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		Updateboardamounttb->Focus();
	}
}

private: System::Void Updateboardamounttb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		updateboardcycletb->Focus();
	}
}
private: System::Void updateboardcycletb_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		Updateenterbtn->PerformClick();
	}
}
};
}
