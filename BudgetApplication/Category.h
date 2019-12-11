#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
#include "CategoryTable.h"
#include <iostream>
#include <limits.h>
#include <float.h>
#include <stdexcept>

//static list of categories
const static std::string CATEGORY_NAMES[9] = { "Auto/Transport", "Utilities", "Education" , "Entertainment", "Food/Dining", 
								"Shopping", "Travel/Vacation", "Home" , "Personal Care" };

class Category {
	//members
private:
	CategoryTable* table;
	std::string name;
	double limit;
	double spent;
	std::vector<Transaction> transactions;
	bool isOverSpent;
	int id;

public:
	//constructors
	~Category();
	Category();
	Category(std::string name, double limit, double spent, std::vector<Transaction> transactions, CategoryTable* t);
	Category(std::string name);

	//getters
	std::string getName() const;
	double getLimit() const;
	double getSpent() const;
	std::vector<Transaction> getTransactions() const;
	bool getIsOverSpent() const;
	int getID() const;

	//setters
	void setIsOverSpent();
	void setIsOverSpent(const bool& isOverSpent);
	void setName(const std::string& name);
	void setLimit(const double& limit);
	void setSpent(const double& spent);
	void setTransactions(const std::vector<Transaction>& transactions);
	void setID(int id);

	//helpers
	void addToSpentAndCheckIfOverSpent(const double& amount);
	void addTransaction(Transaction& t);
	void printTransactions();
	std::vector<Transaction> initTransactions(int userID);
	std::vector<Category> initCategories(int userID);

	//overload the ostream operator
	friend std::ostream& operator << (std::ostream&, const Category&);

};