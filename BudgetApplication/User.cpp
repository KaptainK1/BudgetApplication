#include <limits.h>
#include <float.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include "Budget.h"
#include "User.h"
#include <mysql.h>

//default constructor
User::User() {
	setCurrentID(getCurrentID());
	Budget budget;
	username = "test";
	password = "test";
}

//full argument constructor
User::User(std::string username, std::string password, Budget& budget) {
	setCurrentID(getCurrentID());
	setUsername(username);
	setPassword(password);
	setBudget(budget);
}

//getters
std::string User::getUsername() const{
	return username;
}

std::string User::getPassword() const{
	return password;
}

Budget& User::getBudget() {
	return budget;
}

//setters
void User::setBudget(Budget& budget) {
	this->budget = budget;
}

void User::setPassword(std::string& password) {
	this->password = password;
}

void User::setUsername(std::string& username) {
	this->username = username;
}

//helpers
bool User::login(const std::string& username, const std::string& password) {
	bool isSuccessfulLogin = false;
	if (this->getUsername() == username && this->getPassword() == password)
	{
		isSuccessfulLogin = true;
	}

	return isSuccessfulLogin;
}

int User::getCurrentID() {
	return CURRENT_ID;
}

void User::setCurrentID(int id) {

	if (id < 1)
	{
		CURRENT_ID = getNextID();
	}
	else {

		CURRENT_ID++;
	}
}

void User::setID(int id) {

	if (id < 1)
	{
		this->id = id;
	}
	else {
		throw "ID must be greater than 0";
	}
}

int User::getID() const {
	return id;
}

int User::getNextID() {

	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "";
	int qstate = 0;
	int maxID = 0;

	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "budget_application_db", 3306, NULL, 0);

	query = "Select max(id) from USERS";
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			maxID = atof(row[0]);
		}

	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);
	return maxID;
}