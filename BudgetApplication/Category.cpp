#include "Category.h"
#include <sstream>


Category::~Category() {
	//delete table;
}


Category::Category(int id, std::string name, double limit, double spent) {
	table = new CategoryTable;
	setID(id);
	std::vector<Transaction> transactions;
	setName(name);
	setLimit(limit);
	setSpent(spent);
}

//default constructor
Category::Category() {
	table = new CategoryTable;
	table->setCurrentID(CATEGORY_CURRENT_ID, table->getTableName());
	setID(CATEGORY_CURRENT_ID);
	std::vector<Transaction> transactions;
	
	setName(CATEGORY_NAMES[0]);
	setLimit(1000.00);
	setSpent(0.00);
	setIsOverSpent(false);
	setTransactions(transactions);

}

//constructor that only takes the name
Category::Category(std::string name, CategoryTable* t) {
	table = t;
	table->setCurrentID(CATEGORY_CURRENT_ID, table->getTableName());
	setID(CATEGORY_CURRENT_ID);

	setName(name);
	setLimit(1000.00);
	setSpent(0.00);
	setIsOverSpent(false);
	setTransactions(transactions);

}

//constructor that takes all arguments except is over spent bool
Category::Category(std::string name, double limit, double spent, std::vector<Transaction> transactions, CategoryTable* t) {

	table = t;
	table->setCurrentID(CATEGORY_CURRENT_ID, table->getTableName());
	setID(CATEGORY_CURRENT_ID);

	setName(name);
	setLimit(limit);
	setSpent(spent);
	setIsOverSpent();
	setTransactions(transactions);

}

//getters


CategoryTable* Category::getTable() {
	return table;
}

std::string Category::getName() const{
	return name;
}

double Category::getLimit() const{
	return limit;
}

double Category::getSpent() const{
	return spent;
}

bool Category::getIsOverSpent() const {
	return isOverSpent;
}

std::vector<Transaction> Category::getTransactions() const {
	return transactions;
}

//setters
void Category::setLimit(const double& limit) {
	this->limit = limit;
}

void Category::setSpent(const double& spent) {
	this->spent = spent;
}

void Category::setTransactions(const std::vector<Transaction>& transactions) {
	this->transactions = transactions;
}

void Category::setName(const std::string& name) {

	//check to ensure name is in the category names array
	for (int i = 0; i < (sizeof(CATEGORY_NAMES)/sizeof(std::string)); i++)
	{
		if (name == CATEGORY_NAMES[i]) {
			this->name = name;
			break;

		}
	}

}

void Category::setIsOverSpent() {
	if (spent > limit) {
		isOverSpent = true;
	}
	else {
		isOverSpent = false;
	}
}

void Category::setIsOverSpent(const bool& isOverSpent) {
	this->isOverSpent = isOverSpent;
}

//method to add the amount of a transaction to the amount spent
void Category::addToSpentAndCheckIfOverSpent(const double& amount) {

	//check to ensure amount is within acceptable range
	if (amount > 0 && amount < DBL_MAX) {
		spent += amount;
		setIsOverSpent();
	}
	else {
		throw std::invalid_argument("amount must be greater than 0 and less than the max " + std::to_string(DBL_MAX));
	}

}
//method to add a transaction to the category transactions vector
void Category::addTransaction(Transaction& t) {
	this->transactions.push_back(t);
	addToSpentAndCheckIfOverSpent(t.getTransactionAmount());
}

//overloaded cout operator
std::ostream& operator << (std::ostream& stream, const Category& category) {

	stream << "Name: " << category.name << std::endl;
	stream << "Spent: $" << category.spent << std::endl;
	stream << "Limit: $" << category.limit << std::endl;

	return stream;

}

void Category::printTransactions() {

	for (Transaction t : getTransactions()) {

		std::cout << t;

	}


}

void Category::setID(int id) {

	if (id > 0)
	{
		this->id = id;
	}
	else {
		throw "ID must be greater than 0";
	}
}

int Category::getID() const {
	return id;
}