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

int menuChoice(int& choice, User& user);
void categoryChoice(User& user);
void adjustBudget(User& user);
void adjustCategory(User& user);
double checkDoubleValue();

int main()
{

	//Database Setup
	UserTable* userDB = new UserTable("localhost", "root", "password", "budget_application_db", 3306);
	CategoryTable* categoryDB = new CategoryTable("localhost", "root", "password", "budget_application_db", 3306);
	TransactionTable* TransactionDB = new TransactionTable("localhost", "root", "password", "budget_application_db", 3306);
	userDB->createTableIfNotExists();
	categoryDB->createTableIfNotExists();
	TransactionDB->createTableIfNotExists();

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

	User user = user.getUser(username, TransactionDB, userDB, categoryDB);
	user.getBudget().setCategories(user.getBudget().initCategories(user.getID()));
	user.getBudget().printCategories();

	int userChoice = 0;

	while (userChoice != -1)
	{

		cout << "Menu: enter your choice of what you want to do! " << endl;
		cout << "0: Print Categories and Transactions" << endl;
		cout << "1: Add Transaction" << endl;
		cout << "2: Adjust budget limit" << endl;
		cout << "3: Adjust Categoy limit values" << endl;
		cout << "-1: Exit" << endl;

		cin >> userChoice;

		while (cin.fail() || userChoice < -1 || userChoice > 3)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Invalid menu option, please select 0-4";
			cin >> userChoice;

		}

		cin.clear();
		cin.ignore(2000, '\n');

		menuChoice(userChoice, user);
	}

	return 0;
}


int menuChoice(int& choice, User& user) {

	switch (choice) {

	case -1:
		return -1;
	case 0:
		user.getBudget().printCategories();
		return 0;
		break;
	case 1:
		categoryChoice(user);
		return 0;
		break;
	case 2:
		adjustBudget(user);
		return 0;
		break;
	case 3:
		adjustCategory(user);
		return 0;
		break;
	default:
		return -1;
	}
}

void categoryChoice(User& user) {
	Date userDate;
	string title = "";
	string strDate = "";
	double amount = 0.00;
	int i = 0;
	int userChoice = -1;
	cout << "Select Category: ";
	for (Category category : user.getBudget().getCategories()) {
		std::cout<< i << ": " << category.getName();
		cout << endl;
		i++;
	}

	cin >> userChoice;

	while (cin.fail() || userChoice < 0 || userChoice > user.getBudget().getCategories().capacity())
	{
		cin.clear();
		cin.ignore(2000, '\n');
		cout << "Invalid menu option, please select a valid category";
		cin >> userChoice;

	}

	cin.clear();
	cin.ignore(2000, '\n');

	cout << "Enter Transaction Title" << endl;
	getline(cin, title);

	cout << "Enter Date as YYYY-MM-DD" << endl;
	getline(cin, strDate);

	cout << "Enter amount: " << endl;
	cin >> amount;

	while (cin.fail() || title == "" || amount < 0.00 || amount > DBL_MAX)
	{
		cin.clear();
		cin.ignore(2000, '\n');

		cout << "Error with Transaction Data, please try again";

		cout << "Enter Transaction Title" << endl;
		getline(cin, title);

		cout << "Enter Date as YYYY-MM-DD" << endl;
		getline(cin, strDate);

		try
		{
			Date date(strDate);
			userDate = date;
		}
		catch (const std::exception&)
		{
			cout << "Error with Date, please enter in YYYY-MM-DD format" << endl;
		}

		cout << "Enter amount: " << endl;
		cin >> amount;
	}

	cin.clear();
	cin.ignore(2000, '\n');

	try
	{
		Date date(strDate);
		userDate = date;
	}
	catch (const std::exception&)
	{
		cout << "Error with Date, please enter in YYYY-MM-DD format" << endl;
	}

	//create a new transaction
	Transaction t(title, userDate, false, amount, user.getTransactionTable());
	//add the transaction to the category
	user.getBudget().addTransaction(user.getBudget().getCategory(userChoice), t);
	//add the transaction to the database
	user.getBudget().addTransactionToDatabase(user.getBudget().getCategory(userChoice), t, user.getID());

}

void adjustBudget(User& user) {

	double amountLimit = checkDoubleValue();
	user.getBudget().setTotalLimit(amountLimit);
}

void adjustCategory(User& user) {

	double newAmount = 0.00;

	//check to ensure name is in the category names array
	for (int i = 0; i < (sizeof(CATEGORY_NAMES) / sizeof(std::string)); i++)
	{
		std::cout << ": " << user.getBudget().getCategory(i).getName();
		newAmount = checkDoubleValue();
		user.getBudget().getCategory(i).setLimit(newAmount);
	}

}

double checkDoubleValue() {
	cout << endl;
	double amount = 0.00;
	cout << "Enter amount: " << endl;
	cin >> amount;

	while (cin.fail() || amount < 0.00 || amount > DBL_MAX)
	{
		cin.clear();
		cin.ignore(2000, '\n');

		cout << "Error with new limit, pleast try again" << endl;
		cin >> amount;
	}

	cin.clear();
	cin.ignore(2000, '\n');

	return amount;

}