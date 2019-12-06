#pragma once

#include <mysql.h>
#include <string>

class Database {

private:
	std::string db_host;
	std::string db_user;
	std::string db_password;
	std::string db_schema;
	int port;

public:
	//return a pointer to the db connection
	MYSQL* getConnection();

	//void function to create the table if it doesnt exist
	//must be overriden in child class
	virtual void createTableIfNotExists();

	virtual void select();

	//getters
	std::string getDBHost();
	std::string getDBPassword();
	std::string getDBUser();
	std::string getDBSchema();
	int getDBPort();

	//setters
	void setDBHost(std::string db_host);
	void setDBUser(std::string db_user);
	void setDBPassword(std::string db_password);
	void setDBSchema(std::string db_schema);
	void setDBPort(int port);

	//constructor
	Database(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port);


};

