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