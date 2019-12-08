#pragma once
#include "Budget.h"
#include <string>
#include <mysql.h>

class User {

private:
	int id;
	std::string username;
	std::string password;
	Budget budget;
	static int CURRENT_ID;

public:
	User();
	User(std::string username, std::string password, Budget& budget);

	//getters
	Budget& getBudget();
	std::string getUsername() const;
	std::string getPassword() const;
	int getID() const;
	static int getCurrentID();

	//setters
	void setUsername(std::string& username);
	void setPassword(std::string& password);
	void setBudget(Budget& budget);
	void setID(int id);
	static void setCurrentID(int id);

	//helpers
	bool login(const std::string& username, const std::string& password);
	static int getNextID();


};