#pragma once
#include <mysql.h>
#include "Database.h"
#include <string>

//static int variable to hold the current ID for the user database
static int USER_CURRENT_ID = 0;

class UserTable : public Database {

private:
	std::string table_name = "Users";
	
public:
	UserTable();
	UserTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port);

	virtual void createTableIfNotExists();
	virtual void select();
	std::string getTableName() const;
};
