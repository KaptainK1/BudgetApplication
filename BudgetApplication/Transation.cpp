#include "Transaction.h"

Transaction::~Transaction() {
	//delete table;
}

//default constructor
Transaction::Transaction() {
	table = new TransactionTable;
	table->setCurrentID(TRANSACTION_CURRENT_ID, table->getTableName());
	setID(TRANSACTION_CURRENT_ID+1);
	Date date;
	setTransactionTitle("Transaction");
	setDate( date );
	setIsCredit(false);
	setTransactionAmount(0.00);
}

//all argument constructor
Transaction::Transaction(std::string title, Date& date, bool isCredit, double amount, TransactionTable* t) {
	table = t;
	table->setCurrentID(TRANSACTION_CURRENT_ID, table->getTableName());
	setID(TRANSACTION_CURRENT_ID+1);
	setTransactionAmount(amount);
	setTransactionTitle(title);
	setDate(date);
	setIsCredit(isCredit);

}

Transaction::Transaction(int id, std::string title, Date& date, bool isCredit, double amount) {
	table = new TransactionTable;
	setTransactionAmount(amount);
	setTransactionTitle(title);
	setDate(date);
	setIsCredit(isCredit);
	setID(id);

}

//getters
//get the title as a string
std::string Transaction::getTransactionTitle() const{
	return transactionTitle;
}

//get the date as a Date
Date Transaction::getDate() const{
	return date;
}

//get the isCredit as boolean
bool Transaction::getIsCredit() const{
	return isCredit;
}

//get the amount as a double
double Transaction::getTransactionAmount() const{
	return transactionAmount;
}

//get the id as an int
int Transaction::getID() const{
	return id;
}

//setters
//set the title
void Transaction::setTransactionTitle(std::string title) {
	transactionTitle = title;
}

//set the Date
void Transaction::setDate(Date& date) {
	this->date = date;
}

//set the isCredit boolean
void Transaction::setIsCredit(bool isCredit) {
	this->isCredit = isCredit;
}

//set the amount
//must be greater than 0 and less than the double max limit
void Transaction::setTransactionAmount(double amount) {
	//check to ensure amount is within limits
	if (amount > 0.00 || amount < DBL_MAX)
	{ 
		transactionAmount = amount;
	}
	else {
		std::invalid_argument("amount must be greater than 0 and less than the max " + std::to_string(DBL_MAX));
	}
}

//set the ID
void Transaction::setID(int id) {
	this->id = id;
}

//overload the + operator
//to add two transactions together
Transaction Transaction::operator + (const Transaction& t) {

	Transaction temp;
	temp.setDate(this->date);
	temp.setID(this->id);
	temp.setIsCredit(this->isCredit);
	temp.setTransactionTitle(this->transactionTitle);
	temp.setTransactionAmount(this->transactionAmount + t.transactionAmount);

	return temp;

}

//overloaded cout operator
std::ostream& operator << (std::ostream& stream, const Transaction& t) {

	stream << "\t" << "Title: " << t.transactionTitle << std::endl;
	stream << "\t" << "Amount: " << t.transactionAmount << std::endl;
	stream << "\t" << "Date: " << t.date << std::endl;

	return stream;

}