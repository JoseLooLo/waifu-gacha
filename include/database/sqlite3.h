
#ifndef DATABASE_SQLITE3_H_
#define DATABASE_SQLITE3_H_

	#include <sqlite3.h>
	#include <string>

/*============================================================================*
 * Database Interface                                                         *
 *============================================================================*/

	class Database {
		private:
			sqlite3 *database;
		public:
			Database(std::string db);

			~Database(void);
			/**
	 		* Database Create account
	 		*/	
			int database_create_account(std::string account_login, std::string account_password);
			/**
			 * Database Login
			 */
			int database_login_account(std::string account_login, std::string account_password);
	
			void getAllCharacters(void);
	};


#endif  /* DATABASE_SQLITE3_H_ */