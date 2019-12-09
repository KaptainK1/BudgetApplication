#pragma once
#include "Budget.h"
#include <string>
#include <mysql.h>
#include "UserTable.h"

class User {

private:
	UserTable* table;
	int id;
	std::string username;
	std::string password;
	Budget budget;

public:
	~User();
	User();
	User(std::string username, std::string password, Budget& budget, UserTable* table);
	User(int id, std::string username, std::string password, double totalLimit, double totalSpent, UserTable* t);

	//getters
	Budget& getBudget();
	std::string getUsername() const;
	std::string getPassword() const;
	int getID() const;

	//setters
	void setUsername(std::string& username);
	void setPassword(std::string& password);
	void setBudget(Budget& budget);
	void setID(int id);

	//helpers
	bool login(const std::string& username, const std::string& password);
};