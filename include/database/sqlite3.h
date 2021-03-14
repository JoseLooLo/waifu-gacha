
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
			/**
			 * Database start
			 */
			void database_start(std::string db);
			/**
			 * Database end
			 */
			void database_end(void);
			/**
	 		* Database Create account
	 		*/	
			int database_create_account(std::string account_login, std::string account_password);
			/**
			 * Database Login
			 */
			int database_login_account(std::string account_login, std::string account_password);
	};


#endif  /* DATABASE_SQLITE3_H_ */