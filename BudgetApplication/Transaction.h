#pragma once
#include <string>
#include <ctime>
#include "Date.h"
#include "TransactionTable.h"
#include <limits.h>
#include <float.h>
#include <stdexcept>
#include <iostream>


class Transaction {
	//members
private:
	TransactionTable* table;
	std::string transactionTitle;
	Date date;
	bool isCredit;
	double transactionAmount;
	int id;
public:

	//constructors
	~Transaction();
	Transaction();
	Transaction(int id, std::string title, Date& date, bool isCredit, double amount);
	Transaction(std::string title, Date& date, bool isCredit, double amount, TransactionTable* t);

	//getters
	std::string getTransactionTitle() const;
	Date getDate() const;
	bool getIsCredit() const;
	double getTransactionAmount() const;
	int getID() const;

	//setters
	void setID(int id);
	void setDate(Date& date);
	void setIsCredit(bool isCredit);
	void setTransactionAmount(double amount);
	void setTransactionTitle(std::string title);

	Transaction operator +(const Transaction& t);
	//overload the ostream operator
	friend std::ostream& operator << (std::ostream&, const Transaction&);
};
