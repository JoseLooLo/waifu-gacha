
#ifndef WAIFU_INTERFACE_CONTA_H_
#define WAIFU_INTERFACE_CONTA_H_

    #include <string>
	#include <domain/conta.h>

/*============================================================================*
 * Interface Conta Implementation Checking                                    *
 *============================================================================*/

#ifdef __check_interface__

	#ifndef ___interface_create_account_fn
	#error "___database_start_fn function wasn't defined"
	#endif
	#ifndef ___interface_login_account_fn
	#error "___create_account_fn function wasn't defined"
	#endif

#endif

/*============================================================================*
 * Interface Conta Interface                                                  *
 *============================================================================*/

    /**
	 * Interface Create account
	 */

	extern Conta* interface_create_account(std::string account_login, std::string account_password);

	/**
	 * Interface Login
	 */

	extern Conta* interface_login_account(std::string account_login, std::string account_password);


#endif  /* WAIFU_INTERFACE_CONTA_H_ */