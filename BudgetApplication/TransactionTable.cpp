#include <mysql.h>
#include <string>
#include"TransactionTable.h"
#include <iostream>


TransactionTable::TransactionTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port) :
	Database(db_host, db_user, db_password, db_schema, port) {}

void TransactionTable::createTableIfNotExists() {

	int qstate = 0;

	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	std::string query = "CREATE TABLE IF NOT EXISTS TRANSACTIONS (ID int primary key, TITLE varchar(100) not null, AMOUNT decimal(10,2) not null, PURCHASE_DATE date not null, ISCREDIT boolean not null, USER_ID int not null, Category_ID int not null, foreign key (USER_ID) references USERS(ID), foreign key (Category_ID) references Categorys(ID));";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		std::cout << "Create statment executed!" << std::endl;
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);

}

void TransactionTable::select() {

	int qstate = 0;
	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "Select Transactions.ID, Transactions.Title, Transactions.Amount, Transactions.Purchase_Date, Users.Username, Categorys.Title from ((Transactions Inner join Users on Users.ID = Transactions.User_ID) Inner join Categorys on Categorys.ID = Transactions.Category_ID);  ";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			printf("ID :%s, Title: %s Amount $%s Purchase_Date: %s User: %s Category: %s  \n", row[0], row[1], row[2], row[3], row[4], row[5]);
		}
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);

}