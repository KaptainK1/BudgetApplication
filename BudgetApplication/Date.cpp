#include "Date.h"
#include <ctime>
#include <iostream>
#include <cstdio>

 Date::Date() {
	 //create a time object and set to now
	 time_t now = time(0);
	 //create a tm struct and set it to the current local time
	 //tm* ltm = localtime(&now);
	 struct tm ltm;
	 localtime_s(&ltm, &now);

	 setYear(ltm.tm_year + 1900);
	 setMonth(ltm.tm_mon);
	 setDay(ltm.tm_mday);
}

 //constructor that takes year, month and day
 Date::Date(int year, int month, int day) {
	 setYear(year);
	 setMonth(month);
	 setDay(day);
 }

 //constructor to take in a string value and covert to date
 //String should be in int/int/int format
 //the format is YYYY-MM-DD as this is the format for MySQL
 Date::Date(std::string s) {

	 int year = 0;
	 int month = 0;
	 int day = 0;

	 sscanf_s(s.c_str(), "%d-%d-%d", &year, &month, &day);

	 setYear(year);
	 setMonth(month-1);
	 setDay(day);
 }

 //getters
 int Date::getDay() const{
	 return day;
 }

 int Date::getYear() const{
	 return year;
 }

 int Date::getMonth() const{
	 return month;
 }

 //setters
 void Date::setDay(int day) {

	 if (day > daysInMonth[this->month])
	 {
		 throw "Number of Days exceeds the calendar limit for: ";
	 }

	 this->day = day;

 }

 void Date::setMonth(int month) {

	 if (month > 11 || month < 0)
	 {
		 throw "Months must be between 0 and 11";
	 }

	 this->month = month;

 }

 void Date::setYear(int year) {

	 if (year < 999 || year > 10000)
	 {
		 throw "Year must be a 4 digit number";
	 }

	 this->year = year;
 }

 //overloaded operator for less than
 bool Date::operator < (const Date& date) {

	 if (getYear() < date.year)
	 {
		 return false;
	 }
	 else if (getYear() == date.year && getMonth() < date.month) {
		 return false;
	 }
	 else if (getYear() == date.year && getMonth() == date.month && getDay() < date.day) {
		 return false;
	 }

	 return true;
 }

 //overloaded operator for greater than
 bool Date::operator > (const Date& date) {

	 if (getYear() > date.year)
	 {
		 return false;
	 }
	 else if (getYear() == date.year && getMonth() > date.month) {
		 return false;
	 }
	 else if (getYear() == date.year && getMonth() == date.month && getDay() > date.day) {
		 return false;
	 }

	 return true;

 }

 //overloaded operator for =
 bool Date::operator == (const Date& date) {

	 if (getYear() == date.year && getMonth() == date.month && getDay() == date.day) {
		 return true;
	 }

	 return false;

 }

 /*
 Date Date::operator = (const Date& date) {

	 Date temp;
	 temp.setYear(date.getYear());
	 temp.setMonth(date.getMonth());
	 temp.setDay(date.getDay());
 
	 return temp;
 
 }
 */
 //overloaded cout operator
 std::ostream& operator << (std::ostream& stream, const Date& date) {

	 stream << date.year << "-" << date.month + 1 << "-" << date.day;
//	 stream << date.month+1 << "/" << date.day << "/" << date.year;
	 return stream;

 }
