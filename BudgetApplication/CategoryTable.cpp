#include <mysql.h>
#include <string>
#include"CategoryTable.h"
#include <iostream>


CategoryTable::CategoryTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port) :
	Database(db_host, db_user, db_password, db_schema, port) {}

void CategoryTable::createTableIfNotExists() {

	int qstate = 0;

	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	std::string query = "CREATE TABLE IF NOT EXISTS CATEGORYS (ID int primary key, TITLE varchar(100) not null, AMOUNT_SPENT decimal(10,2) not null, AMOUNT_LIMIT decimal(10,2) not null, USER_ID int not null, foreign key (USER_ID) references USERS(ID));";
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

void CategoryTable::select() {

	int qstate = 0;
	MYSQL* connection;

	connection = mysql_init(0);
	connection = getConnection();

	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "Select * from Categorys";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			printf("ID :%s, Title: %s Amount_Spent: $%s Amount_Limit: $%s  \n", row[0], row[1], row[2], row[3]);
		}
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);

}