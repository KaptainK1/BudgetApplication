#include "Budget.h"
#include "Category.h"
#include <iostream>
#include <string>
#include <limits.h>
#include <float.h>
#include <stdexcept>
#include <vector>

//default constructor
Budget::Budget() {

	setIsAtOrUnderBudget(true);
	setTotalLimit(10000.00);
	setTotalSpent(0.00);
	createCategories();

}

//constructor that takes a double, vector of categories, and another double for spent
Budget::Budget(double limit, std::vector<Category> categories, double spent) {

	setTotalLimit(limit);
	setCategories(categories);
	setTotalSpent(spent);
}

Budget::Budget(double limit, double spent) {
	setTotalLimit(limit);
	setTotalSpent(spent);
	createCategories();
}


//get the total limit as double
double Budget::getTotalLimit() {
	return totalLimit;
}

//get the total spent as double
double Budget::getTotalSpent() {
	return totalSpent;
}

//get the categories as a vector
std::vector<Category> Budget::getCategories() {
	return categories;
}

//get the isAtOrUnderBudget as a boolean
bool Budget::getIsAtOrUnderBudget() {
	return isAtOrUnderBudget;
}

//setters
//set the categories to the referenced catetories
void Budget::setCategories(const std::vector<Category>& categories) {
	this->categories = categories;
}

//set the is at or under budget boolean
//by checking if the total spent is less than the total limit
void Budget::setIsAtOrUnderBudget() {
	if (getTotalSpent() < getTotalLimit())
	{
		isAtOrUnderBudget = true;
	}
	else {
		isAtOrUnderBudget = false;
	}
}

//set the is at or under budget bool
void Budget::setIsAtOrUnderBudget(const bool& isAtOrUnderBudget) {
	this->isAtOrUnderBudget = isAtOrUnderBudget;
}

//set the total limit if the value is greater than 0 and less than the max value of a double
void Budget::setTotalLimit(const double& limit) {
	if (limit > 0 && limit < DBL_MAX)
	{
		totalLimit = limit;
	}
	else {
		std::invalid_argument("amount must be greater than 0 and less than the max " + std::to_string(DBL_MAX));
	}
}

//set the total spent if the value is greater than 0 and less than the max value of a double
void Budget::setTotalSpent(const double& spent) {
	if (spent > 0 && spent < DBL_MAX)
	{
		totalSpent = spent;
	}
	else {
		std::invalid_argument("amount must be greater than 0 and less than the max " + std::to_string(DBL_MAX));
	}
}


//method to create all 9 default categories and add them to the categories vector
void Budget::createCategories() {

	for (int i = 0; i < (sizeof(CATEGORY_NAMES) / sizeof(std::string)); i++)
	{
		Category category(CATEGORY_NAMES[i]);
		addCategory(category);

	}

}

//method to add a category to the categories vector
void Budget::addCategory( Category& category) {
	categories.push_back(category);
}

//method to add a transaction to the transaction vector for the referenced category class
void Budget::addTransaction(Category& category, std::string& name, Date& date, bool& isCredit, double& amount, TransactionTable* t) {

	Transaction transaction(name, date, isCredit, amount, t);
	category.addTransaction(transaction);

	//add the transaction amount to the total spent budget variable. 
	this->addToSpentAndCheckIfOverSpent(transaction.getTransactionAmount());

}

//method to add a transaction to the transaction vector for the referenced category class
void Budget::addTransaction(Category& category, Transaction& t) {

	category.addTransaction(t);

	//add the transaction amount to the total spent budget variable. 
	this->addToSpentAndCheckIfOverSpent(t.getTransactionAmount());

}

//get a referenced category this budget by passing in an index
Category& Budget::getCategory(int index) {

	return categories[index];
}

//print the categories
void Budget::printCategories() {

	for (Category category : categories) {
		std::cout << category;
		category.printTransactions();
	}

}

//method to add to the total spent variable
//method also updates the is at or under budget boolean
void Budget::addToSpentAndCheckIfOverSpent(const double& amount) {

	this->totalSpent += amount;

	if (this->totalSpent <= this->totalLimit)
	{
		this->isAtOrUnderBudget = true;
	}
	else {
		this->isAtOrUnderBudget = false;
	}

}
