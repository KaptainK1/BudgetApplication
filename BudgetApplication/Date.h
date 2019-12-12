#pragma once
#include<ctime>
#include<string>
#include<iostream>


//array to hold the number of days in a month 0-11
static const int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//array to hold the names of the months 0-11
static const std::string monthNames[12] = { "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

class Date {

	//members
private:
	int year;
	int month;
	int day;
public:
	//getters
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	//setters
	void setYear(int);
	void setMonth(int);
	void setDay(int);

	//default constructor
	//initializes to local current date
	Date();
	Date(std::string s);

	//sets the date to the passed in value
	Date(int year, int month, int day);

	//overload the comparsion operators
	//Date operator = (const Date& date);
	bool operator < (const Date& date);
	bool operator > (const Date& date);
	bool operator == (const Date& date);
	friend std::ostream& operator << (std::ostream&, const Date&);
};
