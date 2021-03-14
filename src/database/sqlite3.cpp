
#include <database/sqlite3.h>
#include <string>
#include <iostream>

void Database::database_start(std::string db) {
	int rc;

   	rc = sqlite3_open(db.c_str(), &(this->database));

	if( rc ) {
		exit(1);
	}

	std::string sql = "CREATE TABLE IF NOT EXISTS Conta(" \
      "Login PRIMARY KEY NOT NULL," \
      "Senha TEXT NOT NULL);";

	/* Execute SQL statement */
	sqlite3_exec(this->database, sql.c_str(), NULL, NULL, NULL);
	Database::database_end();
	return;
}

void Database::database_end() {
	sqlite3_close(this->database);
}

int Database::database_create_account(std::string account_login, std::string account_password) {
	account_login = account_login;
	account_password = account_password;
	return 0;
}

int Database::database_login_account(std::string account_login, std::string account_password) {
	account_login = account_login;
	account_password = account_password;
	return 0;
}