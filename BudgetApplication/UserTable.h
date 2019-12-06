#pragma once
#include <mysql.h>
#include "Database.h"
#include <string>

class UserTable : public Database {

private:
	std::string table_name = "Users";

public:

	UserTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port);

	virtual void createTableIfNotExists();
	virtual void select();

};
