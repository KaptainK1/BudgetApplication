#pragma once
#include <string>
#include <ctime>
#include "Date.h"

//static id to hold how many transactions have been created
static int TOTAL_ID;

class Transaction {
	//members
private:
	std::string transactionTitle;
	Date date;
	bool isCredit;
	double transactionAmount;
	int id;
public:

	//constructors
	Transaction();
	Transaction(std::string title, Date& date, bool isCredit, double amount);

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
