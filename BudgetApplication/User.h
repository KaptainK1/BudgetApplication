#pragma once
#include "Budget.h"
#include <string>

class User {

private:
	std::string username;
	std::string password;
	Budget budget;

public:
	User();
	User(std::string username, std::string password, Budget& budget);

	//getters
	Budget& getBudget();
	std::string getUsername() const;
	std::string getPassword() const;

	//setters
	void setUsername(std::string& username);
	void setPassword(std::string& password);
	void setBudget(Budget& budget);

	//helpers
	bool login(const std::string& username, const std::string& password);


};