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

	Database* db = new UserTable("localhost", "root", "password", "budget_application_db", 3306);
	Database* dbC = new CategoryTable("localhost", "root", "password", "budget_application_db", 3306);
	Database* dbT = new TransactionTable("localhost", "root", "password", "budget_application_db", 3306);
	db->createTableIfNotExists();
	dbC->createTableIfNotExists();
	dbT->createTableIfNotExists();

	string username = "";
	string password = "";
	string actualPassword = "";

	cout << "Welcome to the Budget Application!" << endl;

	cout << "Please enter your username" << endl;
	getline(cin, username);



	cout << "Please enter your password" << endl;
	getline(cin, password);





	return 0;
}
