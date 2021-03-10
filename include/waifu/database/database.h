
#ifndef WAIFU_DATABASE_H_
#define WAIFU_DATABASE_H_

	/* Database Interface Implementation */
	#include "waifu/database/_database.h"


	#include <string>

	typedef DATABASE_TYPE database_t;

/*============================================================================*
 * Database Implementation Checking                                           *
 *============================================================================*/

#ifdef __check_interface__

	#ifndef ___database_type
	#error "___database_type macro wasn't defined"
	#endif
	#ifndef ___database_start_fn
	#error "___database_start_fn function wasn't defined"
	#endif
	#ifndef ___database_create_account_fn
	#error "___database_create_account_fn function wasn't defined"
	#endif
	#ifndef ___database_login_account_fn
	#error "___database_login_account_fn function wasn't defined"
	#endif

#endif

/*============================================================================*
 * Database Interface                                                         *
 *============================================================================*/

	class Database {
		private:
			database_t *database;
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

#endif  /* WAIFU_DATABASE_H_ */