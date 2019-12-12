#pragma once
#include "Budget.h"
#include <string>
#include <mysql.h>
#include "UserTable.h"
#include <limits.h>
#include <float.h>
#include <stdexcept>
#include <iostream>
#include "TransactionTable.h"

class User {

private:
	UserTable* table;
	TransactionTable* transactionTable;
	int id;
	std::string username;
	std::string password;
	Budget budget;

public:
	~User();
	User();
	User(TransactionTable *ttable, UserTable* table, CategoryTable* ct);
	User(std::string username, std::string password, Budget& budget, UserTable* table);
	User(int id, std::string username, std::string password, double totalLimit, double totalSpent, UserTable* t, CategoryTable* ct);
	User(int id, std::string username, std::string password, double totalLimit, double totalSpent, TransactionTable* ttable, UserTable* t, CategoryTable* ct);

	//getters
	Budget& getBudget();
	std::string getUsername() const;
	std::string getPassword() const;
	int getID() const;
	User getUser(std::string username, TransactionTable* ttable, UserTable* userTable, CategoryTable* t);
	TransactionTable* getTransactionTable();

	//setters
	void setUsername(std::string& username);
	void setPassword(std::string& password);
	void setBudget(Budget& budget);
	void setID(int id);

	//helpers
	bool login(const std::string& username, const std::string& password);
};