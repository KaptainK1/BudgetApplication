#include "Database.h"
#include <mysql.h>
#include <string>
#include <iostream>

Database::Database(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port) {

	setDBHost(db_host);
	setDBUser(db_user);
	setDBPassword(db_password);
	setDBSchema(db_schema);
	setDBPort(port);
}

//setters
void Database::setDBHost(std::string host) {
	db_host = host;
}

void Database::setDBPassword(std::string password) {
	db_password = password;
}

void Database::setDBUser(std::string user) {
	db_user = user;
}

void Database::setDBSchema(std::string schema) {
	db_schema = schema;
}

void Database::setDBPort(int p) {
	port = p;
}

//getters
std::string Database::getDBHost() {
	return db_host;
}

std::string Database::getDBUser() {
	return db_user;
}

std::string Database::getDBPassword() {
	return db_password;
}

std::string Database::getDBSchema() {
	return db_schema;
}

int Database::getDBPort() {
	return port;
}

MYSQL* Database::getConnection() {

	MYSQL* connection = mysql_init(0);
	connection = mysql_real_connect(connection, db_host.c_str(), db_user.c_str(), db_password.c_str(), db_schema.c_str(), port, NULL, 0);
	return connection;

}

void Database::createTableIfNotExists() {

	std::cout << "Parent function Create Table, use Child class to create the table!";

}

void Database::select() {

	std::cout << "Parent function select statement, use Child class to run the select query!";

}

//method to get the next unique id from the database
//utilizes the max function within mysql
//and will return the highest id
int Database::getNextID(std::string table) {

	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "Select max(id) from " + table;
	int qstate = 0;
	int maxID = 0;

	connection = mysql_init(0);
	connection = getConnection();

	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			if (row[0] == nullptr)
			{
				maxID = 1;
			}
			else {
				maxID = atoi(row[0]);
			}
		}

	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);
	return maxID;
}

void Database::setCurrentID(int& id, std::string table) {

	if (id < 1)
	{
		id = getNextID(table);
	}
	else {

		std::cout << "adding one to current ID" << std::endl;
		id++;
	}
}