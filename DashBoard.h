#pragma once
#include "User.h"
#include <stdio.h>


namespace v1PocketCheckercpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Threading::Tasks;
	using namespace System::Threading;
	using namespace System::Windows;
	using namespace System::Globalization;
	using namespace System::Reflection;

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
			currentuser->changedItems = gcnew List<Item^>();
			currentuser->dueItems = gcnew List<Item^>();
			
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
	private: System::Windows::Forms::Panel^ removePanel;
	private: System::Windows::Forms::Button^ removeDonebtn;
	private: System::Windows::Forms::Button^ removeRemovebtn;


	private: System::Windows::Forms::ComboBox^ removeComboBox;
	private: System::Windows::Forms::Label^ RemovePromptlbl;
	private: System::Windows::Forms::Label^ currentDTlbl;
	private: System::Windows::Forms::Panel^ editpanel;

	private: System::Windows::Forms::TextBox^ editpanelAmnttb;


	private: System::Windows::Forms::Label^ editpromptlbl;
	private: System::Windows::Forms::ComboBox^ editComboBox;


	private: System::Windows::Forms::Button^ editcancelbtn;
	private: System::Windows::Forms::Button^ editEditbtn;


	private: System::Windows::Forms::TextBox^ editpercycletb;
	private: System::Windows::Forms::ComboBox^ editcyclecb;
	private: System::Windows::Forms::Button^ editDonebtn;
	private: System::Windows::Forms::Panel^ SaveDatapanel;
	private: System::Windows::Forms::Label^ CloseQuestionlbl;



	private: System::Windows::Forms::Button^ SaveNobtn;
private: System::Windows::Forms::Button^ saveYesbtn;
private: System::Windows::Forms::DateTimePicker^ enterCalander;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::DateTimePicker^ editCalendar;
private: System::Windows::Forms::DataGridView^ PlanHolder;


private: System::Windows::Forms::Button^ PlanAddbtn;
private: System::Windows::Forms::Panel^ PlanMakerPanel;

private: System::Windows::Forms::RadioButton^ reducedbt;
private: System::Windows::Forms::RadioButton^ savemon;
private: System::Windows::Forms::MaskedTextBox^ howmuchtb;
private: System::Windows::Forms::MaskedTextBox^ completebydatetb;
private: System::Windows::Forms::Label^ howmuchlbl;
private: System::Windows::Forms::Label^ enddatelbl;
private: System::Windows::Forms::Button^ cancelplanbtn;
private: System::Windows::Forms::Button^ createplanbtn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
















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
			this->editpanel = (gcnew System::Windows::Forms::Panel());
			this->editCalendar = (gcnew System::Windows::Forms::DateTimePicker());
			this->editDonebtn = (gcnew System::Windows::Forms::Button());
			this->editcyclecb = (gcnew System::Windows::Forms::ComboBox());
			this->editpercycletb = (gcnew System::Windows::Forms::TextBox());
			this->editpanelAmnttb = (gcnew System::Windows::Forms::TextBox());
			this->editpromptlbl = (gcnew System::Windows::Forms::Label());
			this->editComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->editcancelbtn = (gcnew System::Windows::Forms::Button());
			this->editEditbtn = (gcnew System::Windows::Forms::Button());
			this->removePanel = (gcnew System::Windows::Forms::Panel());
			this->RemovePromptlbl = (gcnew System::Windows::Forms::Label());
			this->removeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->removeDonebtn = (gcnew System::Windows::Forms::Button());
			this->removeRemovebtn = (gcnew System::Windows::Forms::Button());
			this->SaveDatapanel = (gcnew System::Windows::Forms::Panel());
			this->CloseQuestionlbl = (gcnew System::Windows::Forms::Label());
			this->SaveNobtn = (gcnew System::Windows::Forms::Button());
			this->saveYesbtn = (gcnew System::Windows::Forms::Button());
			this->Dashboardlbl = (gcnew System::Windows::Forms::Label());
			this->panelTitle = (gcnew System::Windows::Forms::Panel());
			this->currentDTlbl = (gcnew System::Windows::Forms::Label());
			this->Downsizebtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Closebtn = (gcnew System::Windows::Forms::Button());
			this->userDashlbl = (gcnew System::Windows::Forms::Label());
			this->Updateboard = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->enterCalander = (gcnew System::Windows::Forms::DateTimePicker());
			this->Updateboardtotalamttb = (gcnew System::Windows::Forms::TextBox());
			this->Updateboardamounttb = (gcnew System::Windows::Forms::TextBox());
			this->updateboardcycletb = (gcnew System::Windows::Forms::ComboBox());
			this->Updateboardnametb = (gcnew System::Windows::Forms::TextBox());
			this->Updatecancelbtn = (gcnew System::Windows::Forms::Button());
			this->Updateenterbtn = (gcnew System::Windows::Forms::Button());
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
			this->PlanAddbtn = (gcnew System::Windows::Forms::Button());
			this->PlanHolder = (gcnew System::Windows::Forms::DataGridView());
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
			this->PlanMakerPanel = (gcnew System::Windows::Forms::Panel());
			this->cancelplanbtn = (gcnew System::Windows::Forms::Button());
			this->createplanbtn = (gcnew System::Windows::Forms::Button());
			this->enddatelbl = (gcnew System::Windows::Forms::Label());
			this->howmuchlbl = (gcnew System::Windows::Forms::Label());
			this->completebydatetb = (gcnew System::Windows::Forms::MaskedTextBox());
			this->howmuchtb = (gcnew System::Windows::Forms::MaskedTextBox());
			this->reducedbt = (gcnew System::Windows::Forms::RadioButton());
			this->savemon = (gcnew System::Windows::Forms::RadioButton());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panelDesktop->SuspendLayout();
			this->editpanel->SuspendLayout();
			this->removePanel->SuspendLayout();
			this->SaveDatapanel->SuspendLayout();
			this->panelTitle->SuspendLayout();
			this->Updateboard->SuspendLayout();
			this->billbtnspanel->SuspendLayout();
			this->debtbtnspanel->SuspendLayout();
			this->incomebtnspanel->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlanHolder))->BeginInit();
			this->currentSpendableShow->SuspendLayout();
			this->currentBillShow->SuspendLayout();
			this->currentIncomeShow->SuspendLayout();
			this->currentDebtShow->SuspendLayout();
			this->PlanMakerPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelDesktop
			// 
			this->panelDesktop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->panelDesktop->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDesktop->Controls->Add(this->editpanel);
			this->panelDesktop->Controls->Add(this->removePanel);
			this->panelDesktop->Controls->Add(this->SaveDatapanel);
			this->panelDesktop->Controls->Add(this->Dashboardlbl);
			this->panelDesktop->Controls->Add(this->panelTitle);
			this->panelDesktop->Controls->Add(this->Updateboard);
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
			// editpanel
			// 
			this->editpanel->BackColor = System::Drawing::Color::White;
			this->editpanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->editpanel->Controls->Add(this->editCalendar);
			this->editpanel->Controls->Add(this->editDonebtn);
			this->editpanel->Controls->Add(this->editcyclecb);
			this->editpanel->Controls->Add(this->editpercycletb);
			this->editpanel->Controls->Add(this->editpanelAmnttb);
			this->editpanel->Controls->Add(this->editpromptlbl);
			this->editpanel->Controls->Add(this->editComboBox);
			this->editpanel->Controls->Add(this->editcancelbtn);
			this->editpanel->Controls->Add(this->editEditbtn);
			this->editpanel->Location = System::Drawing::Point(474, 419);
			this->editpanel->Name = L"editpanel";
			this->editpanel->Size = System::Drawing::Size(338, 189);
			this->editpanel->TabIndex = 10;
			this->editpanel->Visible = false;
			// 
			// editCalendar
			// 
			this->editCalendar->Location = System::Drawing::Point(133, 116);
			this->editCalendar->Name = L"editCalendar";
			this->editCalendar->Size = System::Drawing::Size(200, 20);
			this->editCalendar->TabIndex = 12;
			this->editCalendar->Visible = false;
			// 
			// editDonebtn
			// 
			this->editDonebtn->Location = System::Drawing::Point(221, 164);
			this->editDonebtn->Name = L"editDonebtn";
			this->editDonebtn->Size = System::Drawing::Size(58, 20);
			this->editDonebtn->TabIndex = 11;
			this->editDonebtn->Text = L"Done";
			this->editDonebtn->UseVisualStyleBackColor = true;
			this->editDonebtn->Visible = false;
			this->editDonebtn->Click += gcnew System::EventHandler(this, &DashBoard::editDonebtn_Click);
			// 
			// editcyclecb
			// 
			this->editcyclecb->FormattingEnabled = true;
			this->editcyclecb->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Monthly", L"Bi-Weekly", L"Weekly" });
			this->editcyclecb->Location = System::Drawing::Point(236, 83);
			this->editcyclecb->Name = L"editcyclecb";
			this->editcyclecb->Size = System::Drawing::Size(97, 21);
			this->editcyclecb->TabIndex = 10;
			this->editcyclecb->Visible = false;
			// 
			// editpercycletb
			// 
			this->editpercycletb->Location = System::Drawing::Point(13, 116);
			this->editpercycletb->Name = L"editpercycletb";
			this->editpercycletb->Size = System::Drawing::Size(97, 20);
			this->editpercycletb->TabIndex = 9;
			this->editpercycletb->Visible = false;
			// 
			// editpanelAmnttb
			// 
			this->editpanelAmnttb->Location = System::Drawing::Point(145, 83);
			this->editpanelAmnttb->Name = L"editpanelAmnttb";
			this->editpanelAmnttb->Size = System::Drawing::Size(69, 20);
			this->editpanelAmnttb->TabIndex = 7;
			this->editpanelAmnttb->Visible = false;
			// 
			// editpromptlbl
			// 
			this->editpromptlbl->AutoSize = true;
			this->editpromptlbl->Location = System::Drawing::Point(8, 62);
			this->editpromptlbl->Name = L"editpromptlbl";
			this->editpromptlbl->Size = System::Drawing::Size(132, 13);
			this->editpromptlbl->TabIndex = 4;
			this->editpromptlbl->Text = L"What do you want to edit\?";
			// 
			// editComboBox
			// 
			this->editComboBox->FormattingEnabled = true;
			this->editComboBox->Location = System::Drawing::Point(13, 82);
			this->editComboBox->Name = L"editComboBox";
			this->editComboBox->Size = System::Drawing::Size(112, 21);
			this->editComboBox->TabIndex = 3;
			// 
			// editcancelbtn
			// 
			this->editcancelbtn->Location = System::Drawing::Point(152, 164);
			this->editcancelbtn->Name = L"editcancelbtn";
			this->editcancelbtn->Size = System::Drawing::Size(52, 20);
			this->editcancelbtn->TabIndex = 2;
			this->editcancelbtn->Text = L"Cancel";
			this->editcancelbtn->UseVisualStyleBackColor = true;
			this->editcancelbtn->Click += gcnew System::EventHandler(this, &DashBoard::editcancelbtn_Click);
			// 
			// editEditbtn
			// 
			this->editEditbtn->Location = System::Drawing::Point(76, 164);
			this->editEditbtn->Name = L"editEditbtn";
			this->editEditbtn->Size = System::Drawing::Size(58, 20);
			this->editEditbtn->TabIndex = 1;
			this->editEditbtn->Text = L"Edit";
			this->editEditbtn->UseVisualStyleBackColor = true;
			this->editEditbtn->Click += gcnew System::EventHandler(this, &DashBoard::editEditbtn_Click);
			// 
			// removePanel
			// 
			this->removePanel->BackColor = System::Drawing::Color::White;
			this->removePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->removePanel->Controls->Add(this->RemovePromptlbl);
			this->removePanel->Controls->Add(this->removeComboBox);
			this->removePanel->Controls->Add(this->removeDonebtn);
			this->removePanel->Controls->Add(this->removeRemovebtn);
			this->removePanel->Location = System::Drawing::Point(117, 419);
			this->removePanel->Name = L"removePanel";
			this->removePanel->Size = System::Drawing::Size(338, 189);
			this->removePanel->TabIndex = 9;
			this->removePanel->Visible = false;
			// 
			// RemovePromptlbl
			// 
			this->RemovePromptlbl->AutoSize = true;
			this->RemovePromptlbl->Location = System::Drawing::Point(112, 66);
			this->RemovePromptlbl->Name = L"RemovePromptlbl";
			this->RemovePromptlbl->Size = System::Drawing::Size(150, 13);
			this->RemovePromptlbl->TabIndex = 4;
			this->RemovePromptlbl->Text = L"What do you want to remove\?";
			// 
			// removeComboBox
			// 
			this->removeComboBox->FormattingEnabled = true;
			this->removeComboBox->Location = System::Drawing::Point(119, 82);
			this->removeComboBox->Name = L"removeComboBox";
			this->removeComboBox->Size = System::Drawing::Size(121, 21);
			this->removeComboBox->TabIndex = 3;
			// 
			// removeDonebtn
			// 
			this->removeDonebtn->Location = System::Drawing::Point(189, 164);
			this->removeDonebtn->Name = L"removeDonebtn";
			this->removeDonebtn->Size = System::Drawing::Size(52, 20);
			this->removeDonebtn->TabIndex = 2;
			this->removeDonebtn->Text = L"Done";
			this->removeDonebtn->UseVisualStyleBackColor = true;
			this->removeDonebtn->Click += gcnew System::EventHandler(this, &DashBoard::removeDonebtn_Click);
			// 
			// removeRemovebtn
			// 
			this->removeRemovebtn->Location = System::Drawing::Point(119, 164);
			this->removeRemovebtn->Name = L"removeRemovebtn";
			this->removeRemovebtn->Size = System::Drawing::Size(58, 20);
			this->removeRemovebtn->TabIndex = 1;
			this->removeRemovebtn->Text = L"Remove";
			this->removeRemovebtn->UseVisualStyleBackColor = true;
			this->removeRemovebtn->Click += gcnew System::EventHandler(this, &DashBoard::removeRemovebtn_Click);
			// 
			// SaveDatapanel
			// 
			this->SaveDatapanel->BackColor = System::Drawing::Color::White;
			this->SaveDatapanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SaveDatapanel->Controls->Add(this->CloseQuestionlbl);
			this->SaveDatapanel->Controls->Add(this->SaveNobtn);
			this->SaveDatapanel->Controls->Add(this->saveYesbtn);
			this->SaveDatapanel->Location = System::Drawing::Point(816, 56);
			this->SaveDatapanel->Name = L"SaveDatapanel";
			this->SaveDatapanel->Size = System::Drawing::Size(236, 115);
			this->SaveDatapanel->TabIndex = 11;
			this->SaveDatapanel->Visible = false;
			// 
			// CloseQuestionlbl
			// 
			this->CloseQuestionlbl->AutoSize = true;
			this->CloseQuestionlbl->Location = System::Drawing::Point(3, 32);
			this->CloseQuestionlbl->Name = L"CloseQuestionlbl";
			this->CloseQuestionlbl->Size = System::Drawing::Size(224, 13);
			this->CloseQuestionlbl->TabIndex = 4;
			this->CloseQuestionlbl->Text = L"Do you want to save this data before quitting\?";
			// 
			// SaveNobtn
			// 
			this->SaveNobtn->Location = System::Drawing::Point(155, 70);
			this->SaveNobtn->Name = L"SaveNobtn";
			this->SaveNobtn->Size = System::Drawing::Size(52, 20);
			this->SaveNobtn->TabIndex = 2;
			this->SaveNobtn->Text = L"No";
			this->SaveNobtn->UseVisualStyleBackColor = true;
			this->SaveNobtn->Click += gcnew System::EventHandler(this, &DashBoard::SaveNobtn_Click);
			// 
			// saveYesbtn
			// 
			this->saveYesbtn->Location = System::Drawing::Point(21, 68);
			this->saveYesbtn->Name = L"saveYesbtn";
			this->saveYesbtn->Size = System::Drawing::Size(58, 20);
			this->saveYesbtn->TabIndex = 1;
			this->saveYesbtn->Text = L"Yes";
			this->saveYesbtn->UseVisualStyleBackColor = true;
			this->saveYesbtn->Click += gcnew System::EventHandler(this, &DashBoard::saveYesbtn_Click);
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
			this->panelTitle->Controls->Add(this->currentDTlbl);
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
			// currentDTlbl
			// 
			this->currentDTlbl->AutoSize = true;
			this->currentDTlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentDTlbl->ForeColor = System::Drawing::Color::White;
			this->currentDTlbl->Location = System::Drawing::Point(515, 4);
			this->currentDTlbl->Name = L"currentDTlbl";
			this->currentDTlbl->Size = System::Drawing::Size(0, 13);
			this->currentDTlbl->TabIndex = 10;
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
			// Updateboard
			// 
			this->Updateboard->BackColor = System::Drawing::Color::White;
			this->Updateboard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Updateboard->Controls->Add(this->label1);
			this->Updateboard->Controls->Add(this->enterCalander);
			this->Updateboard->Controls->Add(this->Updateboardtotalamttb);
			this->Updateboard->Controls->Add(this->Updateboardamounttb);
			this->Updateboard->Controls->Add(this->updateboardcycletb);
			this->Updateboard->Controls->Add(this->Updateboardnametb);
			this->Updateboard->Controls->Add(this->Updatecancelbtn);
			this->Updateboard->Controls->Add(this->Updateenterbtn);
			this->Updateboard->Location = System::Drawing::Point(816, 254);
			this->Updateboard->Name = L"Updateboard";
			this->Updateboard->Size = System::Drawing::Size(338, 189);
			this->Updateboard->TabIndex = 8;
			this->Updateboard->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Next due date:";
			// 
			// enterCalander
			// 
			this->enterCalander->Location = System::Drawing::Point(82, 128);
			this->enterCalander->Name = L"enterCalander";
			this->enterCalander->Size = System::Drawing::Size(200, 20);
			this->enterCalander->TabIndex = 10;
			// 
			// Updateboardtotalamttb
			// 
			this->Updateboardtotalamttb->Location = System::Drawing::Point(230, 51);
			this->Updateboardtotalamttb->Name = L"Updateboardtotalamttb";
			this->Updateboardtotalamttb->Size = System::Drawing::Size(97, 20);
			this->Updateboardtotalamttb->TabIndex = 9;
			this->Updateboardtotalamttb->Text = L"Total Amount";
			this->Updateboardtotalamttb->Click += gcnew System::EventHandler(this, &DashBoard::Updateboardtotalamttb_Click);
			this->Updateboardtotalamttb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::Updateboardtotalamttb_KeyDown);
			// 
			// Updateboardamounttb
			// 
			this->Updateboardamounttb->Location = System::Drawing::Point(6, 90);
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
			this->updateboardcycletb->Location = System::Drawing::Point(230, 90);
			this->updateboardcycletb->Name = L"updateboardcycletb";
			this->updateboardcycletb->Size = System::Drawing::Size(97, 21);
			this->updateboardcycletb->TabIndex = 7;
			this->updateboardcycletb->Text = L"Pick Cycle";
			this->updateboardcycletb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DashBoard::updateboardcycletb_KeyDown);
			// 
			// Updateboardnametb
			// 
			this->Updateboardnametb->Location = System::Drawing::Point(6, 51);
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
			this->panel2->Controls->Add(this->PlanAddbtn);
			this->panel2->Controls->Add(this->PlanHolder);
			this->panel2->Controls->Add(this->planslbl);
			this->panel2->Location = System::Drawing::Point(201, 161);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(440, 252);
			this->panel2->TabIndex = 4;
			// 
			// PlanAddbtn
			// 
			this->PlanAddbtn->Location = System::Drawing::Point(53, 218);
			this->PlanAddbtn->Name = L"PlanAddbtn";
			this->PlanAddbtn->Size = System::Drawing::Size(75, 23);
			this->PlanAddbtn->TabIndex = 2;
			this->PlanAddbtn->Text = L"Add Plan";
			this->PlanAddbtn->UseVisualStyleBackColor = true;
			this->PlanAddbtn->Click += gcnew System::EventHandler(this, &DashBoard::PlanAddbtn_Click);
			// 
			// PlanHolder
			// 
			this->PlanHolder->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PlanHolder->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1, this->Column2,
					this->Column3
			});
			this->PlanHolder->Location = System::Drawing::Point(15, 45);
			this->PlanHolder->Name = L"PlanHolder";
			this->PlanHolder->Size = System::Drawing::Size(343, 160);
			this->PlanHolder->TabIndex = 1;
			this->PlanHolder->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashBoard::PlanHolder_CellContentClick);
			// 
			// planslbl
			// 
			this->planslbl->AutoSize = true;
			this->planslbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->planslbl->Location = System::Drawing::Point(36, 17);
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
			// PlanMakerPanel
			// 
			this->PlanMakerPanel->BackColor = System::Drawing::Color::White;
			this->PlanMakerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlanMakerPanel->Controls->Add(this->cancelplanbtn);
			this->PlanMakerPanel->Controls->Add(this->createplanbtn);
			this->PlanMakerPanel->Controls->Add(this->enddatelbl);
			this->PlanMakerPanel->Controls->Add(this->howmuchlbl);
			this->PlanMakerPanel->Controls->Add(this->completebydatetb);
			this->PlanMakerPanel->Controls->Add(this->howmuchtb);
			this->PlanMakerPanel->Controls->Add(this->reducedbt);
			this->PlanMakerPanel->Controls->Add(this->savemon);
			this->PlanMakerPanel->Location = System::Drawing::Point(0, 0);
			this->PlanMakerPanel->Name = L"PlanMakerPanel";
			this->PlanMakerPanel->Size = System::Drawing::Size(258, 152);
			this->PlanMakerPanel->TabIndex = 12;
			this->PlanMakerPanel->Visible = false;
			// 
			// cancelplanbtn
			// 
			this->cancelplanbtn->Location = System::Drawing::Point(99, 124);
			this->cancelplanbtn->Name = L"cancelplanbtn";
			this->cancelplanbtn->Size = System::Drawing::Size(52, 23);
			this->cancelplanbtn->TabIndex = 7;
			this->cancelplanbtn->Text = L"Cancel";
			this->cancelplanbtn->UseVisualStyleBackColor = true;
			this->cancelplanbtn->Click += gcnew System::EventHandler(this, &DashBoard::cancelplanbtn_Click);
			// 
			// createplanbtn
			// 
			this->createplanbtn->Location = System::Drawing::Point(8, 124);
			this->createplanbtn->Name = L"createplanbtn";
			this->createplanbtn->Size = System::Drawing::Size(52, 23);
			this->createplanbtn->TabIndex = 6;
			this->createplanbtn->Text = L"Add";
			this->createplanbtn->UseVisualStyleBackColor = true;
			this->createplanbtn->Visible = false;
			this->createplanbtn->Click += gcnew System::EventHandler(this, &DashBoard::createplanbtn_Click);
			// 
			// enddatelbl
			// 
			this->enddatelbl->AutoSize = true;
			this->enddatelbl->Location = System::Drawing::Point(145, 54);
			this->enddatelbl->Name = L"enddatelbl";
			this->enddatelbl->Size = System::Drawing::Size(88, 13);
			this->enddatelbl->TabIndex = 5;
			this->enddatelbl->Text = L"Desired end date";
			this->enddatelbl->Visible = false;
			// 
			// howmuchlbl
			// 
			this->howmuchlbl->AutoSize = true;
			this->howmuchlbl->Location = System::Drawing::Point(22, 54);
			this->howmuchlbl->Name = L"howmuchlbl";
			this->howmuchlbl->Size = System::Drawing::Size(64, 13);
			this->howmuchlbl->TabIndex = 4;
			this->howmuchlbl->Text = L"How much\?";
			this->howmuchlbl->Visible = false;
			// 
			// completebydatetb
			// 
			this->completebydatetb->Location = System::Drawing::Point(144, 70);
			this->completebydatetb->Mask = L"00/00/0000";
			this->completebydatetb->Name = L"completebydatetb";
			this->completebydatetb->Size = System::Drawing::Size(100, 20);
			this->completebydatetb->TabIndex = 3;
			this->completebydatetb->ValidatingType = System::DateTime::typeid;
			this->completebydatetb->Visible = false;
			// 
			// howmuchtb
			// 
			this->howmuchtb->Location = System::Drawing::Point(8, 70);
			this->howmuchtb->Mask = L"00000";
			this->howmuchtb->Name = L"howmuchtb";
			this->howmuchtb->Size = System::Drawing::Size(100, 20);
			this->howmuchtb->TabIndex = 2;
			this->howmuchtb->ValidatingType = System::Int32::typeid;
			this->howmuchtb->Visible = false;
			// 
			// reducedbt
			// 
			this->reducedbt->AutoSize = true;
			this->reducedbt->Location = System::Drawing::Point(146, 22);
			this->reducedbt->Name = L"reducedbt";
			this->reducedbt->Size = System::Drawing::Size(87, 17);
			this->reducedbt->TabIndex = 1;
			this->reducedbt->TabStop = true;
			this->reducedbt->Text = L"Reduce debt";
			this->reducedbt->UseVisualStyleBackColor = true;
			// 
			// savemon
			// 
			this->savemon->AutoSize = true;
			this->savemon->Location = System::Drawing::Point(11, 22);
			this->savemon->Name = L"savemon";
			this->savemon->Size = System::Drawing::Size(84, 17);
			this->savemon->TabIndex = 0;
			this->savemon->TabStop = true;
			this->savemon->Text = L"Save money";
			this->savemon->UseVisualStyleBackColor = true;
			this->savemon->CheckedChanged += gcnew System::EventHandler(this, &DashBoard::savemon_CheckedChanged);
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
			// Column1
			// 
			this->Column1->HeaderText = L"Plan Name";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Est. Time";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Progress";
			this->Column3->Name = L"Column3";
			// 
			// DashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::BlueViolet;
			this->ClientSize = System::Drawing::Size(826, 444);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->PlanMakerPanel);
			this->Controls->Add(this->panelDesktop);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"DashBoard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DashBoard";
			this->panelDesktop->ResumeLayout(false);
			this->panelDesktop->PerformLayout();
			this->editpanel->ResumeLayout(false);
			this->editpanel->PerformLayout();
			this->removePanel->ResumeLayout(false);
			this->removePanel->PerformLayout();
			this->SaveDatapanel->ResumeLayout(false);
			this->SaveDatapanel->PerformLayout();
			this->panelTitle->ResumeLayout(false);
			this->panelTitle->PerformLayout();
			this->Updateboard->ResumeLayout(false);
			this->Updateboard->PerformLayout();
			this->billbtnspanel->ResumeLayout(false);
			this->debtbtnspanel->ResumeLayout(false);
			this->incomebtnspanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlanHolder))->EndInit();
			this->currentSpendableShow->ResumeLayout(false);
			this->currentSpendableShow->PerformLayout();
			this->currentBillShow->ResumeLayout(false);
			this->currentBillShow->PerformLayout();
			this->currentIncomeShow->ResumeLayout(false);
			this->currentIncomeShow->PerformLayout();
			this->currentDebtShow->ResumeLayout(false);
			this->currentDebtShow->PerformLayout();
			this->PlanMakerPanel->ResumeLayout(false);
			this->PlanMakerPanel->PerformLayout();
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
			  int itemuniqueID = 0;
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
				//MessageBox::Show(" " + currentuser->get_userID());
			}
			else {
				MessageBox::Show("didnt get userID");

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}

	}
	public:void UniqueExists() {
		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
			SqlConnection reloadConn(connString);
			reloadConn.Open();

			String^ Query = "SELECT * FROM ";//this is where you will get the vaultID for the item 
			//then you will take that vaultID and see if it exists in the list
			//if it exists then go to the next item that has the same userID but different vaultID
			//if it doesnt exist then add it to the list and gather the data
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
				//MessageBox::Show(" " + numofItems);//works! data is read
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

		try {
			//we need to make "already have this data move to the next instance" array or function
				//what would we use thats unique to each of these bits of data? since we're using the ID to find them
				//we'll use their vaultID
				String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
				SqlConnection reloadConn(connString);
				reloadConn.Open();

				String^ Query = "SELECT * FROM Vault WHERE usersID=@ID";
				SqlCommand newdBConn(Query, % reloadConn);
				//MessageBox::Show("" + currentuser->get_userID());
				newdBConn.Parameters->AddWithValue("@ID", currentuser->get_userID());

				//SqlCommand command(sqlQuery, % newsqlConn);

				SqlDataReader^ reader = newdBConn.ExecuteReader();

				int currentDataReadNum = 0;
				//MessageBox::Show("Num of items:" + numofItems);
				while (currentDataReadNum < numofItems) {
					if (reader->Read()) {
						//MessageBox::Show("Started the read");
						newItem = gcnew Item;
						//6/28 OK so the issue is we now need to redo some of the Item in user.h to represent payment (income), amount due (debt/bills), givenAmount(if you arent paying the amount due exacttly)
						//if its income then amount due should be 0 as well as givenAmount and VICE VERSA
						itemuniqueID = ((int)reader["vaultId"]);
						//MessageBox::Show("" + itemuniqueID);
						newItem->set_type((String^)reader["itemType"]);
						newItem->set_name((String^)reader["itemName"]);
						//MessageBox::Show("got the name and type");
						newItem->set_totalamt((int)reader["itemtotalamount"]);
						//MessageBox::Show("" + newItem->gettotal());
						newItem->set_payment((int)reader["itemcurrentpayment"]);
						//MessageBox::Show("" + newItem->getpayment());
						newItem->set_frequency((int)reader["itempaymentoccurance"]);
						newItem->set_dueDate(((int)reader["nextdueday"]),(((int)reader["nextduemonth"])),(((int)reader["nextdueyear"])));
						//MessageBox::Show("" + newItem->getfrequency());
						//container->Add(newItem);
						if (newItem->get_type() == "I") {
							//MessageBox::Show("income added");
							currentuser->addIncomeItem(newItem);
							//MessageBox::Show("inc curr size: " + currentuser->get_incomesize());
						}
						else if (newItem->get_type() == "B") {
							//MessageBox::Show("bill added");
							currentuser->addbillItem(newItem);
							//MessageBox::Show("bill curr size: " + currentuser->get_billsize());
						}
						else if (newItem->get_type() == "D") {
							//MessageBox::Show("income debt");
							currentuser->adddebtItem(newItem);
						}
						else {
							MessageBox::Show("Unable to configure itemObj for storage.Retry");
						}
						++currentDataReadNum;
					}
					else {
						//MessageBox::Show("didnt get userID. Terminating Program");
						this->Close();
					}
					//MessageBox::Show(newItem->get_dueDate() + "");
				}
				
			}
			
		catch (Exception^ ex) {
			MessageBox::Show("Data Load: " + ex->Message);
		}
		//MessageBox::Show("Completed the load");
		
	}
	private: System::Void DashBoard_Load(User^ user) {
		float incometotal = 0;
		float debttotal = 0;
		float billtotal = 0;
		float spendable = 0;
		
		DateTime dt;
		String^ currDate = dt.Now.ToShortDateString();
		int ID = 0;
		//gotta find a way to get the beginning of the week and the end of the week
		
		
		
		userDashlbl->Text = "Welcome back " +
			currentuser->getfullName();


		currentDTlbl->Text = currDate;

		//load any items for user thats in dB
		checkInventory();
		if (numofItems > 0) {
			//newInsert
			//UniqueExists();
			loaddBData();
			
		}
		
		if (currentuser->get_incomesize() > 0) {
			//MessageBox::Show("We have income");
			//MessageBox::Show(currentuser->get_incomesize() + " :size");
			for (int i = 0; i < currentuser->get_incomesize(); i++) {
				incometotal += currentuser->incomeItems[i]->getpayment();
			}
			//MessageBox::Show(incometotal + " inc total");
		}
		else {
			incometotal = 0.00;
		}
		//debt
		if (currentuser->get_debtsize() >0) {
			//MessageBox::Show("We have debt");
			//MessageBox::Show(currentuser->get_debtsize() + " :size");
			for (int i = 0; i < currentuser->get_debtsize(); ++i) {
				//MessageBox::Show("current i: " + i);
				debttotal += currentuser->debtItems[i]->getpayment();
			}
			//MessageBox::Show(debttotal + " debt total");
		}
		else {
			debttotal = 0.00;
		}

		//bill
		if (currentuser->get_billsize() >0) {
			//MessageBox::Show("We have bills");
			//MessageBox::Show(currentuser->get_billsize() + " :size");
			for (int i = 0; i < currentuser->billItems->Count; i++) {
				billtotal += currentuser->billItems[i]->getpayment();
			}
			//MessageBox::Show(billtotal + " debt total");
		}
		else {
			billtotal = 0.00;
		}



		spendable = getWeeklySpendable();
		incomeamtlbl->Text = "$ " + incometotal;
		billamt->Text = "$ " + billtotal;
		debtamtlbl->Text = "$ " + debttotal;
		spendableamtlbl->Text = "$ " + spendable;



		//this whole thing gets the end of the week and moves the needle to the monday following
		
	}
	public: float getWeeklySpendable() {
		DateTime today = DateTime::Now;
		int weeklyincome = 0;
		int weeklybills = 0;
		int weeklydebt = 0;
		try {
			today = GetEndofWeek(today, today.DayOfWeek); //skip to sunday and validate backwards
				for each (Item ^ it in currentuser->incomeItems) {
					if (it->isDue(today)) {
						weeklyincome += it->getpayment();
					}
				}
				MessageBox::Show(weeklyincome + " ");
				for each (Item ^ it in currentuser->billItems) {
					if (it->isDue(today)) {
						weeklybills += it->getpayment();
					}
				}
				MessageBox::Show(weeklybills + " ");
				for each (Item ^ it in currentuser->debtItems) {
					if (it->isDue(today)) {
						weeklydebt += it->getpayment();
					}
				}
				MessageBox::Show(weeklydebt + " ");
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
		return (weeklyincome - (weeklybills + weeklydebt));
	}
	public: Void collectWeekData() {//include params soon
		DateTime today = DateTime::Now;
		DateTime endofWeek = GetEndofWeek(today, today.DayOfWeek);

		try {
			while (today.DayOfWeek != DayOfWeek::Sunday) {//this will get the data for the week
				currentuser->getDueItems(today);
				today = today.AddDays(1);
			}
			//MessageBox::Show(currentuser->dueItems->Count.ToString());
			/*for (int i = 0; i < currentuser->dueItems->Count; ++i) {
				MessageBox::Show(currentuser->dueItems[i]->getName());
			}*/
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

		//DateTime beginofWeek = endofWeek.AddDays(1); //this will be monday or the beginning of the new week
		//MessageBox::Show(endofWeek.Day.ToString());
		//MessageBox::Show(beginofWeek.Day.ToString());
	}

	public: DateTime GetEndofWeek(DateTime today, DayOfWeek currentDay) {
		int diff = Convert::ToInt32(DayOfWeek::Sunday) - Convert::ToInt32(currentDay);
		if (diff < 0) {
			diff += 7;
		}
		return today.AddDays(diff);
	}
	private: System::Void Closebtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentuser->changedItems->Count > 0) {
			SaveDatapanel->Visible = true;
			SaveDatapanel->Location = Point(260, 160);
		}
		else {
			Application::Exit();
		}
		
		
	}
	public: System::Void PopulateEditPanel(String^ destination,int reciever) {
		editpanel->Visible = true;
		editpanel->Location = Point(260, 160);
		editpanel->Location.X = 0;
		editpanel->Location.Y = 0;
		currentTab = reciever;
		Title->Text = "Edit " + destination;

		switch (currentTab) {
		case 1:
		{
			for (int i = 0; i < currentuser->get_incomesize(); i++) {
				editComboBox->Items->Add("" + currentuser->incomeItems[i]->getName());
			}
		}
		break;
		case 2:
		{
			for (int i = 0; i < currentuser->get_billsize(); ++i) {
				editComboBox->Items->Add("" + currentuser->billItems[i]->getName());
			}
		}
		break;
		case 3:
		{
			for (int i = 0; i < currentuser->get_debtsize(); i++) {
				editComboBox->Items->Add("" + currentuser->debtItems[i]->getName());
			}
		}
		break;
		default:
			MessageBox::Show("Info not loaded, please try again");
			break;
		}
	}
	public: System::Void PopulateRemovePanel(String^ destination, int reciever) {
		removePanel->Visible = true;
		removePanel->Location = Point(260, 160);
		removePanel->Location.X = 0;
		removePanel->Location.Y = 0;
		currentTab = reciever;
		Title->Text = "Remove " + destination;
		
		switch (currentTab) {
		case 1: 
			{
				for (int i = 0; i < currentuser->get_incomesize(); i++) {
				removeComboBox->Items->Add("" + currentuser->incomeItems[i]->getName());
				}
			}
			break;
		case 2:
			{
				for (int i = 0; i < currentuser->get_billsize(); ++i) {
				removeComboBox->Items->Add("" + currentuser->billItems[i]->getName());
				}
			}
			break;
		case 3: 
			{
				for (int i = 0; i < currentuser->get_debtsize(); i++) {
				removeComboBox->Items->Add("" + currentuser->debtItems[i]->getName());
				}
			}
			break;
		default:
			MessageBox::Show("Info not loaded, please try again");
			break;
		}
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

	   //--------BACKGROUND THREADS------------//

	   //--------BUTTON CLICK EVENTS-----------//
	int month;
	int day;
	int next_date_day;
	int next_date_month;
	int next_date_year;
	int next_date_tracker;
	
private: System::Void Updateenterbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	int itempaymentoccurance;
	int usersID;
	String^ frequency = updateboardcycletb->Text;
	String^ itemName = Updateboardnametb->Text;
	int itemtotalamount = (Convert::ToInt32(Updateboardtotalamttb->Text));
	int itemcurrentpayment = (Convert::ToInt32(Updateboardamounttb->Text));
	String^ itemType = " ";
	

	System::DateTime selectedDate = enterCalander->Value;
	month = selectedDate.Month;
	day = selectedDate.Day;
	next_date_year = selectedDate.Year;

	System::DateTime lastdayofMonth(selectedDate.Year, month, DateTime::DaysInMonth(selectedDate.Year, month));
	enterCalander->MaxDate = lastdayofMonth;
	
	
	
	if (frequency == "Monthly") {
		itempaymentoccurance = 1;
		next_date_tracker = 30;
	}
	else if (frequency == "Weekly") {
		itempaymentoccurance = 4;
		next_date_tracker = 7;
	}
	else {
		itempaymentoccurance = 2;
		next_date_tracker = 14;
	}
	try {
		if ((day + next_date_tracker) > enterCalander->MaxDate.Day) {
			//we are into the next month
			next_date_day = (day + next_date_tracker) - 30;
			next_date_month = month + 1;
			if (next_date_month > 12) {
				next_date_month = 1;
				next_date_year = selectedDate.Year + 1;
			}
		}
		else {
			next_date_day = day + next_date_tracker;
			next_date_month = month;
			//next_date_year = selectedDate.Year;
		}
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
	
	//MessageBox::Show("Afterwards the next time is: " + next_date_month + "/" + next_date_day + "/" + next_date_year);
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
		MessageBox::Show(next_date_month.ToString());

		String^ sqlQuery = "INSERT INTO Vault" +
			"(itemType, itemName, itemtotalamount, itemcurrentpayment, itempaymentoccurance, nextduemonth,nextdueday,nextdueyear, usersID)VALUES" +
			"(@itemType, @itemName, @itemtotalamount, @itemcurrentpayment, @itempaymentoccurance, @nextduemonth, @nextdueday, @nextdueyear, @usersID);"; //changing the above to match is what allowed the connection

		//MessageBox::Show("query set to insert");

		SqlCommand command(sqlQuery, % newsqlConn);

	
		command.Parameters->AddWithValue("@itemType", itemType);
		command.Parameters->AddWithValue("@itemName", itemName);
		command.Parameters->AddWithValue("@itemtotalamount", itemtotalamount);
		command.Parameters->AddWithValue("@itemcurrentpayment", itemcurrentpayment);
		command.Parameters->AddWithValue("@itempaymentoccurance", itempaymentoccurance);
		command.Parameters->AddWithValue("@nextduemonth", next_date_month);
		command.Parameters->AddWithValue("@nextdueday", next_date_day);
		command.Parameters->AddWithValue("@nextdueyear", next_date_year);
		command.Parameters->AddWithValue("@usersID", usersID);





		command.ExecuteNonQuery();
		//MessageBox::Show("Executed");
		newItem = gcnew Item;
		newItem->set_name(itemName);
		newItem->set_payment(itemcurrentpayment);

		newItem->set_frequency(itempaymentoccurance);
		newItem->set_totalamt(itemtotalamount);
		newItem->set_dueDate(next_date_day, next_date_month, next_date_year);
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
		MessageBox::Show("Failed to register new item " + x->Message);
		Updatecancelbtn_Click(this, e);

	}
	//reset textboxes

	Updateboardnametb->Text = "Name";
	Updateboardtotalamttb->Text = "Total Amount";
	Updateboardamounttb->Text = "Amount per cycle";
	updateboardcycletb->Text = "Pick Cycle";
	localReload();
	//DashBoard_Load(currentuser);

}
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
private: System::Void AddbtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
			Updateboard->Location = Point(260, 150);
			incomebtnspanel->Visible = false;
			currentUpdateClicked = "Income";
			PopulateUpdateBoard(1, currentUpdateClicked, 1);
			Incomemorebtn->Text = "+";
			numIncomemorebtnClick = 0;
		}
private: System::Void RemovebtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
	incomebtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateRemovePanel("Income", 1);
	Incomemorebtn->Text = "+";
	numIncomemorebtnClick = 0;
}
private: System::Void EditbtnIncome_Click(System::Object^ sender, System::EventArgs^ e) {
	incomebtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateEditPanel("Income", 1);
	Incomemorebtn->Text = "+";
	numIncomemorebtnClick = 0;
}
private: System::Void Addbtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	currentUpdateClicked = "Bills";
	PopulateUpdateBoard(1, currentUpdateClicked, 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Removebtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateRemovePanel("Bill", 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Editbtnbill_Click(System::Object^ sender, System::EventArgs^ e) {
	billbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateEditPanel("Bill", 2);
	billmorebtn->Text = "+";
	billmorebtnClick = 0;
}
private: System::Void Addbtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	currentUpdateClicked = "Debt";
	PopulateUpdateBoard(1, currentUpdateClicked, 3);
	weeksdebtamtbtn->Text = "+";
	weeksdebtamtbtnclick = 0;
}
private: System::Void Removebtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateRemovePanel("Debt", 3);
	weeksdebtamtbtn->Text = "+";
	weeksdebtamtbtnclick = 0;
}
private: System::Void Editbtndebt_Click(System::Object^ sender, System::EventArgs^ e) {
	debtbtnspanel->Visible = false;
	Updateboard->Location = Point(260, 150);
	PopulateEditPanel("Debt", 3);
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
private: System::Void removeDonebtn_Click(System::Object^ sender, System::EventArgs^ e) {
	removePanel->Visible = false;
	Title->Visible = false;
	removeComboBox->Items->Clear();
}
private: System::Void removeRemovebtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (removeComboBox->Text == "") {
		MessageBox::Show("Nothing selected");
		return;
	}
	
	String^ removeItem = removeComboBox->Text;
	
	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
		SqlConnection loadConn(connString);
		loadConn.Open();

		String^ query = "DELETE FROM Vault WHERE itemName=@removeItem";
		SqlCommand anotherConn(query, % loadConn);
		anotherConn.Parameters->AddWithValue("@removeItem", removeItem);

		anotherConn.ExecuteNonQuery();
		loadConn.Close();

	}
	catch (Exception^ ex) {
		MessageBox::Show("" + ex->Message);
	}
	//delete data from local class
	if (Title->Text == "Remove Income") {
		for (int i = 0; i < currentuser->get_incomesize(); ++i) {
			if (currentuser->incomeItems[i]->getName() == removeItem) {
				currentuser->incomeItems->Remove(currentuser->incomeItems[i]);
			}
		}
	}
	else if (Title->Text == "Remove Bill") {
		for (int i = 0; i < currentuser->get_billsize(); ++i) {
			if (currentuser->billItems[i]->getName() == removeItem) {
				currentuser->billItems->Remove(currentuser->billItems[i]);
			}
		}
	}
	else if (Title->Text == "Remove Debt") {
		for (int i = 0; i < currentuser->get_debtsize(); ++i) {
			if (currentuser->debtItems[i]->getName() == removeItem) {
				currentuser->debtItems->Remove(currentuser->debtItems[i]);
			}
		} 
	}
	else {
		MessageBox::Show("Internal Error");
		return;
	}
	//then reload with local class
	localReload();
}
public: Void localReload() {
	//go through all items and update totals
	float newweeklyincometotal = 0.0;
	float newbilltotal = 0.0;
	float newdebttotal = 0.0;
	for (int i = 0; i < currentuser->get_incomesize(); ++i) {
		newweeklyincometotal += currentuser->incomeItems[i]->getpayment();
	}
	incomeamtlbl->Text = newweeklyincometotal.ToString();

	for (int i = 0; i < currentuser->get_billsize(); ++i) {
		newbilltotal += currentuser->billItems[i]->getpayment();
	}
	billamt->Text = newbilltotal.ToString();

	for (int i = 0; i < currentuser->get_debtsize(); ++i) {
		newdebttotal += currentuser->debtItems[i]->getpayment();
	}
	debtamtlbl->Text = newdebttotal.ToString();

	spendableamtlbl->Text = (newweeklyincometotal - (newbilltotal + newdebttotal)).ToString();
}
private: System::Void editEditbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	editcyclecb->Visible = true;
	editpercycletb->Visible = true;
	editpanelAmnttb->Visible = true;
	editDonebtn->Visible = true;
	editCalendar->Visible = true;

	switch (currentTab) {
	case 1:
		{
			for (int i = 0; i < currentuser->get_incomesize(); ++i) {
				if (currentuser->incomeItems[i]->getName() == editComboBox->Text) {
				//load the data into panels
				editpanelAmnttb->Text = (currentuser->incomeItems[i]->gettotal()).ToString();
				editpercycletb->Text = (currentuser->incomeItems[i]->getpayment()).ToString();
				editCalendar->Value = currentuser->incomeItems[i]->get_dueDate();
				}
			}
		}
		break;
	case 2:
	{
		for (int i = 0; i < currentuser->get_billsize(); ++i) {
			if (currentuser->billItems[i]->getName() == editComboBox->Text) {
				//load the data into panels
				editpanelAmnttb->Text = (currentuser->billItems[i]->gettotal()).ToString();
				editpercycletb->Text = (currentuser->billItems[i]->getpayment()).ToString();
				editCalendar->Value = currentuser->billItems[i]->get_dueDate();
			}
		}
	}
	break;
	case 3:
	{
		for (int i = 0; i < currentuser->get_debtsize(); ++i) {
			if (currentuser->debtItems[i]->getName() == editComboBox->Text) {
				//load the data into panels
				editpanelAmnttb->Text = (currentuser->debtItems[i]->gettotal()).ToString();
				editpercycletb->Text = (currentuser->debtItems[i]->getpayment()).ToString();
				editCalendar->Value = currentuser->debtItems[i]->get_dueDate();
			}
		}
	}
	break;
	default:
		MessageBox::Show("Internal error while loading editing features. Please try again");
		break;
	}
	
}
private: System::Void editDonebtn_Click(System::Object^ sender, System::EventArgs^ e) {
	//load data back to local user but its NOT saved to the DB until the save button is hit
	
	
	try {
		switch (currentTab) {
		case 1: {
			for (int i = 0; i < currentuser->get_incomesize(); ++i) {
				if (currentuser->incomeItems[i]->getName() == editComboBox->Text) {
					//load the data into panels
					currentuser->incomeItems[i]->set_totalamt(Convert::ToInt32(editpanelAmnttb->Text));
					currentuser->incomeItems[i]->set_payment(Convert::ToInt32(editpercycletb->Text));
					currentuser->updatedItems(currentuser->incomeItems[i]);
				}
			}
			
		}
			  break;
		case 2: {
			for (int i = 0; i < currentuser->get_billsize(); ++i) {
				if (currentuser->billItems[i]->getName() == editComboBox->Text) {
					//load the data into panels
	
					currentuser->billItems[i]->set_totalamt(Convert::ToInt32(editpanelAmnttb->Text));
					currentuser->billItems[i]->set_payment(Convert::ToInt32(editpercycletb->Text));
					currentuser->updatedItems(currentuser->billItems[i]);
				}
			}
		}
			  break;
		case 3:
			for (int i = 0; i < currentuser->get_debtsize(); ++i) {
				if (currentuser->debtItems[i]->getName() == editComboBox->Text) {
					//load the data into panels
					currentuser->debtItems[i]->set_totalamt(Convert::ToInt32(editpanelAmnttb->Text));
					currentuser->debtItems[i]->set_payment(Convert::ToInt32(editpercycletb->Text));
					currentuser->updatedItems(currentuser->debtItems[i]);
				}
			}
			break;
		default:
			MessageBox::Show("Internal error when updating changes. Please try again");
			break;
		}

		
		editcyclecb->Text = " ";
		editpercycletb->Text = " ";
		editpanelAmnttb->Text = " ";
		editpanel->Visible = false;
		Title->Visible = false;
		localReload();
	}
	catch (Exception^ ex) {
		//MessageBox::Show("One or more of the tabs is missing information. Please fill it out before clicking 'Done' "+ex->Message);
	}
}
private: System::Void editcancelbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	editcyclecb->Visible = false;
	editpercycletb->Visible = false;
	editpanelAmnttb->Visible = false;
	editpanel->Visible = false;
	Title->Visible = false;
}

private: System::Void SaveNobtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void saveYesbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	//loop through users data
	

	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
		SqlConnection updateConn(connString);
		updateConn.Open();
		for (int i = 0; i < currentuser->changedItems->Count; ++i) {
			String^ itemN = currentuser->changedItems[i]->getName();
			int amt = (currentuser->changedItems[i]->gettotal());
			int payment = currentuser->changedItems[i]->getpayment();

			String^ query = "UPDATE Vault SET itemtotalamount= @amt, itemcurrentpayment= @payment WHERE itemName=@itemN";
			SqlCommand dbConn(query, % updateConn);
			dbConn.Parameters->AddWithValue("@itemN", itemN);
			dbConn.Parameters->AddWithValue("@amt", amt);
			dbConn.Parameters->AddWithValue("@payment", payment);

			dbConn.ExecuteNonQuery();
		}
		SaveDatapanel->Visible = false;
		MessageBox::Show("Data saved!");
		Application::Exit();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
	
}

private: System::Void PlanAddbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	PlanMakerPanel->Visible = true;
	PlanMakerPanel->Location = Point(260, 160);
}
private: System::Void savemon_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	howmuchtb->Visible = true;
	howmuchlbl->Visible = true;
	enddatelbl->Visible = true;
	completebydatetb->Visible = true;
	createplanbtn->Visible = true;
	createplanbtn->Location = Point(57, 124);
	cancelplanbtn->Location = Point(144, 124);
	    
}
private: System::Void PlanHolder_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
public: Void ClearPlanMakingData() {
	savemon->Checked = false;
	reducedbt->Checked = false;
	howmuchtb->Text = " ";
	completebydatetb->Text = " ";
	cancelplanbtn->Location = Point(99, 124);
	PlanMakerPanel->Visible = false;
}
private: System::Void cancelplanbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	//make everything invisible
	ClearPlanMakingData();
}
private: System::Void createplanbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ action;
	try {
		if (savemon->Checked) {
			action = "Save " + howmuchtb->Text;
		}
		else {
			action = "Reduce ";
		}
		PlanHolder->Rows->Add(action);
		
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
	ClearPlanMakingData();
}
};
}
