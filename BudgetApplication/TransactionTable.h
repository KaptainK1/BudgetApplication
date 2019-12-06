#pragma once
#include <mysql.h>
#include "Database.h"
#include <string>

class TransactionTable : public Database {

private:
	std::string table_name = "Transactions";

public:

	TransactionTable(std::string db_host, std::string db_user, std::string db_password, std::string db_schema, int port);

	virtual void createTableIfNotExists();
	virtual void select();

};
