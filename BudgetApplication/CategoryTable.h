#pragma once
#include <mysql.h>
#include "Database.h"
#include <string>

class CategoryTable : public Database {

private:
	std::string table_name = "Categorys";

public:

	CategoryTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port);

	virtual void createTableIfNotExists();
	virtual void select();

};
