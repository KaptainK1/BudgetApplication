#include "User.h"

User::~User() {
	//delete table;
}

//default constructor
User::User() {
	table = new UserTable;
	table->setCurrentID(USER_CURRENT_ID, table->getTableName());
	setID(USER_CURRENT_ID);
	Budget budget;
	username = "test";
	password = "test";
}

//full argument constructor
User::User(std::string username, std::string password, Budget& budget, UserTable* t) {
	table = t;
	table->setCurrentID(USER_CURRENT_ID, table->getTableName());
	setID(USER_CURRENT_ID);
	setUsername(username);
	setPassword(password);
	setBudget(budget);
}

User::User(int id, std::string username, std::string password, double totalLimit, double totalSpent, UserTable* t) {
	table = t;
	setID(id);
	setUsername(username);
	setPassword(password);
	Budget budget(totalLimit, totalSpent);

}

//getters
std::string User::getUsername() const{
	return username;
}

std::string User::getPassword() const{
	return password;
}

Budget& User::getBudget() {
	return budget;
}

//setters
void User::setBudget(Budget& budget) {
	this->budget = budget;
}

void User::setPassword(std::string& password) {
	this->password = password;
}

void User::setUsername(std::string& username) {
	this->username = username;
}

//helpers
bool User::login(const std::string& username, const std::string& password) {
	bool isSuccessfulLogin = false;
	if (this->getUsername() == username && this->getPassword() == password)
	{
		isSuccessfulLogin = true;
	}

	return isSuccessfulLogin;
}

void User::setID(int id) {

	if (id > 0)
	{
		this->id = id;
	}
	else {
		throw "ID must be greater than 0";
	}
}

int User::getID() const {
	return id;
}

User User::getUser(std::string username) {

	std::string password = "";
	int qstate = 0;
	MYSQL* connection;
	User user;

	connection = mysql_init(0);
	connection = table->getConnection();

	MYSQL_ROW row;
	MYSQL_RES* res;
	std::stringstream ss;
	ss << "Select password from Users WHERE username = " << '"' << username << '"';
	std::string query = ss.str();
	const char* q = query.c_str();
	qstate = mysql_query(connection, q);

	//using c syntax
	if (!qstate)
	{
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			User foundUser(atoi(row[0]), row[1], row[2], atof(row[3]), atof(row[4]), this->table);
			user = foundUser;
		}
	}

	else {
		std::cout << "Query failed: " << mysql_error(connection) << std::endl;
	}

	mysql_close(connection);
	return user;


}