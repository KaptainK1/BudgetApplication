#pragma once
#include <string>
#include <vector>
#include "Category.h"
#include "Transaction.h"
#include "Date.h"
#include <sstream>

class Budget {

private:
	//members
	double totalLimit;
	std::vector<Category> categories;
	double totalSpent;
	bool isAtOrUnderBudget;

public:
	//constructors
	Budget();
	Budget(double limit, std::vector<Category> categories, double spent);
	Budget(double limit, double spent, CategoryTable* t);

	//getters
	double getTotalLimit();
	double getTotalSpent();
	std::vector<Category>& getCategories();
	bool getIsAtOrUnderBudget();
	double calculateAmountSpent();

	//setters
	void setTotalLimit(const double& limit);
	void setTotalSpent(const double& spent);
	void setCategories(const std::vector<Category>& categories);
	void setIsAtOrUnderBudget();
	void setIsAtOrUnderBudget(const bool& isAtOrUnderBudget);

	//helpers
	void addCategory( Category& category);
	void addTransaction(Category& category, std::string& name, Date& date, bool& isCredit, double& amount, TransactionTable* t);
	void addTransaction(Category& category, Transaction& t);
	void addToSpentAndCheckIfOverSpent(const double& amount);
	void addTransactionToDatabase(Category& category, Transaction& transaction, int userID);

	//void createCategories();
	void createCategories(CategoryTable* t);
	void printCategories();

	std::vector<Transaction> initTransactions(int userID, Category& category);
	std::vector<Category> initCategories( int userID);

	Category& getCategory(int index);
};