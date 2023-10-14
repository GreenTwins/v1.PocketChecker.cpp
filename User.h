#pragma once

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Reflection;

public ref class Item {
private:
	String^ name;
	String^ type;
	int payment = 0;
	int amountdue = 0;
	int totalamount = 0;
	String^ date;
	int frequency = 0;
	int owner = 0;
	int dueDate_day = 0;
	int dueDate_month = 0;
	int dueDate_year = 0;

public:

	void set_name(String^ Name) {
		name = Name;
	}
	String^ getName() {
		return name;
	}
	void set_type(String^ t) {
		type = t;
	}
	String^ get_type() {
		return type;
	}
	void set_dueDate(int day, int month, int year) {
		dueDate_day = day;
	    dueDate_month = month;
		dueDate_year = year;
	}
	DateTime get_dueDate() {
		return Convert::ToDateTime(dueDate_month + "/" + dueDate_day + "/" + dueDate_year);
	}
	void set_payment(int pay) {
		payment = pay;
	}
	float getpayment() {
		return payment;
	}
	void set_amountdue(int amt) {
		amountdue = amt;
	}
	float getamtdue() {
		return amountdue;
	}
	void set_totalamt(int total) {
		totalamount = total;
	}
	float gettotal() {
		return totalamount;
	}
	void set_date(String^ Date) {
		date = Date;
	}
	String^ getDate() {
		return date;
	}
	void set_frequency(int freq) {
		frequency = freq;
	}
	int getfrequency() {
		return frequency;
	}
	void set_owner(int usersID) {
		owner = usersID;
	}
	int get_owner() {
		return owner;
	}
};


public ref class User {
private:
	String^ fullname;
	String^ firstname;
	String^ lastname;
	String^ email;
	String^ username;
	String^ password;
	int ID;


	//or try to have a separate class for items
public:
	List<Item^>^ incomeItems;
	List<Item^>^ debtItems;
	List<Item^>^ billItems;
	List<Item^>^ changedItems;
	void set_fullname(String^ firstName, String^ lastName) {
		fullname = firstName + " " + lastName;
	}
	String^ getfullName() {
		return fullname;
	}
	void set_firstname(String^ firstName) {
		firstname = firstName;
	}
	String^ getfirstName() {
		return firstname;
	}
	void set_lastname(String^ lastName) {
		lastname = lastName;
	}
	String^ getlastName() {
		return lastname;
	}
	void set_email(String^ newEmail) {
		email = newEmail;
	}
	String^ getEmail() {
		return email;
	}
	void set_username(String^ newUsername) {
		username = newUsername;
	}
	String^ getUsername() {
		return username;
	}
	void set_password(String^ newPassword) {
		password = newPassword;
	}
	String^ getPassword() {
		return password;
	}
	void addIncomeItem(Item^ income) {
		incomeItems->Add(income);
	}
	void adddebtItem(Item^ debt) {
		debtItems->Add(debt);
	}
	void addbillItem(Item^ bill) {
		billItems->Add(bill);
	}
	void set_userID(int n) {
		ID = n;
	}
	int get_userID() {
		return ID;
	}
	int get_incomesize() {
		return incomeItems->Count;
	}
	int get_debtsize() {
		return debtItems->Count;//((sizeof(debtItems) / sizeof(debtItems[0])));
	}
	int get_billsize() {
		return billItems->Count;
	}
	void updatedItems(Item^ update) {
		changedItems->Add(update);
	}

	/*
	public:
		String^ firstname;
		String^ lasttname;
		String^ email;
		String^ username;
		String^ password;
		String^ currentDebtitemName;
		int currentDebtItemtotalAmount;
		int currentDebtItemperPay;
		int currentDebtPaymentFrequency;
		Dictionary<String^, String^>^ vector_list;

	*/

};
