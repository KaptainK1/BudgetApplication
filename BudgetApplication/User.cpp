#include <limits.h>
#include <float.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include "Budget.h"
#include "User.h"

//default constructor
User::User() {
	Budget budget;
	username = "test";
	password = "test";
}

//full argument constructor
User::User(std::string username, std::string password, Budget& budget) {
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