// BudgetApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Date.h"
#include "User.h"
#include "Budget.h"
#include "Database.h"
#include "UserTable.h"
#include "CategoryTable.h"
#include "TransactionTable.h"

//using mysql library
//see below for setup
//https://www.youtube.com/watch?v=yNniOHn9Xe0
#include <mysql.h>

using namespace std;

int main()
{

	/*
		bool test = date1 > date2;
		cout << test << endl;
		cout << date1 << endl;
		cout << date2 << endl;
		UserTable* db = new UserTable("localhost", "root", "password", "budget_application_db", 3306);
		TransactionTable* tdb = new TransactionTable("localhost", "root", "password", "budget_application_db", 3306);
		Budget dylBudget;
		User mainUser("Dylan", "password", dylBudget, db );
		User user;
		Transaction t("test",date1,false,25.00, tdb);
		user.getBudget().addTransaction(user.getBudget().getCategory(0), t);
		user.getBudget().addTransaction(user.getBudget().getCategory(0), t);
		user.getBudget().printCategories();
		cout << user.getBudget().getTotalSpent();
	*/

	//Database Setup
	UserTable* userDB = new UserTable("localhost", "root", "password", "budget_application_db", 3306);
	CategoryTable* categoryDB = new CategoryTable("localhost", "root", "password", "budget_application_db", 3306);
	TransactionTable* TransactionDB = new TransactionTable("localhost", "root", "password", "budget_application_db", 3306);
	userDB->createTableIfNotExists();
	categoryDB->createTableIfNotExists();
	TransactionDB->createTableIfNotExists();

	User user;
	string username = "";
	string password = "";
	string actualPassword = "";

	cout << "Welcome to the Budget Application!" << endl;

	cout << "Please enter your username" << endl;
	getline(cin, username);

	actualPassword = userDB->getPassword(username);

	cout << "Please enter your password" << endl;
	getline(cin, password);
	
	while (cin.fail() || password != actualPassword)
	{
		cout << "login failed, please enter username and password again " << endl;
		cout << "Please enter your username" << endl;
		getline(cin, username);

		actualPassword = userDB->getPassword(username);

		cout << "Please enter your password" << endl;
		getline(cin, password);

	}

	user = user.getUser(username);
	user.getBudget().initCategories(user.getID());
	user.getBudget().printCategories();

	cout << "Menu: enter your choice of what you want to do! " << endl;
	cout << "1: Print Categories and Transactions" << endl;
	cout << "2: Add Transaction" << endl;
	cout << "3: Adjust overall budget values" << endl;
	cout << "4: Adjust Categoy limit values" << endl;
	cout << "0: Exit" << endl;







	return 0;
}
