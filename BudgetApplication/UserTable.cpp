#include <mysql.h>
#include <string>
#include"UserTable.h"
#include "Database.h"
#include <iostream>
#include <sstream>

UserTable::UserTable()
	: Database("localhost", "root", "password", "budget_application_db", 3306)
{
	//std::cout << "UserTable default constructor called!"<< std::endl;
	//CURRENT_ID++;
}

UserTable::UserTable(std::string db_host = "localhost", std::string db_user = "root", 
	std::string db_password ="password", std::string db_schema = "budget_application_db", int port = 3306)
	: Database(db_host, db_user, db_password, db_schema, port) 

{
	//std::cout << "UserTable constructor called!" << std::endl;
	//CURRENT_ID++;
}

void UserTable::createTableIfNotExists() {

	int qstate = 0;

	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	std::string query = "CREATE TABLE IF NOT EXISTS USERS (ID int primary key, USERNAME varchar(50) not null, PASSWORD varchar(50) not null, BUDGET_LIMIT decimal(10,2) not null, BUDGET_SPENT decimal(10,2) not null);";
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

void UserTable::select() {

	int qstate = 0;
	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "Select * from Users";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			printf("ID :%s, Username: %s Password: %s Budget_Limit: $%s Budget_Spent: $%s \n", row[0], row[1], row[2], row[3], row[4]);
		}
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);

}

std::string UserTable::getTableName() const{
	return table_name;
}


std::string UserTable::getPassword(std::string username){

	std::string password = "";
	int qstate = 0;
	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	MYSQL_ROW row;
	MYSQL_RES* res;
	std::stringstream ss;
	ss << "Select password from Users WHERE username = " << '"' << username << '"';
	std::string query = ss.str();
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			password = row[0];
		}
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);
	return password;

}