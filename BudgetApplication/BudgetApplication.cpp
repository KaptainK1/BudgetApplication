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
	Database *db = new UserTable("localhost", "root", "password", "budget_application_db", 3306);
	Database *dbC = new CategoryTable("localhost", "root", "password", "budget_application_db", 3306);
	Database *dbT = new TransactionTable("localhost", "root", "password", "budget_application_db", 3306);
	db->createTableIfNotExists();
	dbC->createTableIfNotExists();
	dbT->createTableIfNotExists();

	User user;
	user.getCurrentID();
	*/


	/*
	int qstate = 0;
	std::cout << endl;


	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;

	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "test", 3306, NULL, 0);

	string query = "Select * from newTable";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		double d = 0.00;
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			printf("ID :%s, Amount: $%s \n", row[0], row[1]);
			cout << "Hello" << endl;
			d += atof(row[1]);
		}

		cout << "The total amount is: $" << d << endl;

	}

	else {
		cout << "Query failed: " << mysql_error(connection) << endl;
	}


	mysql_close(connection);

	*/

	
	Date date1;
	Date date2(2001, 1, 27);
	Date stringDate("2019/12/10");

	cout << stringDate;

	
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

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
