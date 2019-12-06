#pragma once
#include <string>
#include "Transaction.h"
#include <vector>

//static list of categories
const static std::string CATEGORY_NAMES[9] = { "Auto/Transport", "Utilities", "Education" , "Entertainment", "Food/Dining", 
								"Shopping", "Travel/Vacation", "Home" , "Personal Care" };

class Category {
	//members
private:
	std::string name;
	double limit;
	double spent;
	std::vector<Transaction> transactions;
	bool isOverSpent;

public:
	//constructors
	Category();
	Category(std::string name, double limit, double spent, std::vector<Transaction> transactions);
	Category(std::string name);

	//getters
	std::string getName() const;
	double getLimit() const;
	double getSpent() const;
	std::vector<Transaction> getTransactions() const;
	bool getIsOverSpent() const;

	//setters
	void setIsOverSpent();
	void setIsOverSpent(const bool& isOverSpent);
	void setName(const std::string& name);
	void setLimit(const double& limit);
	void setSpent(const double& spent);
	void setTransactions(const std::vector<Transaction>& transactions);

	//helpers
	void addToSpentAndCheckIfOverSpent(const double& amount);
	void addTransaction(Transaction& t);
	void printTransactions();

	//overload the ostream operator
	friend std::ostream& operator << (std::ostream&, const Category&);

};