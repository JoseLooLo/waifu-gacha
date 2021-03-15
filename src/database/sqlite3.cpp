
#include <database/sqlite3.h>
#include <iostream>

Database::Database(std::string db) {
	int rc;
   	rc = sqlite3_open(db.c_str(), &database);
	if( rc ) {
		exit(1);
	}
}

Database::~Database() {
	sqlite3_close(database);
}

	std::vector <std::vector <std::string>> records;

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

int callback(void *NotUsed, int argc, char **argv, char **azColName){
	NotUsed = NotUsed;
	std::vector<std::string> result;

    for(int i = 0; i < argc; i++) {
		std::cout << azColName[i] << std::endl;
		result.push_back(argv[i]);
    }
    records.push_back(result);
    return 0;
}

std::vector<std::vector<std::string>> Database::getAllCharacters(void) {
	records.clear();
	std::string sql = "SELECT * FROM 'WAIFU';";
	std::cout << sql << std::endl;
	char *zErrMsg = 0;
	int rc = sqlite3_exec(database, sql.c_str(), callback, &records, &zErrMsg);
	if( rc ) {
		exit(1);
	}

	return records;
}