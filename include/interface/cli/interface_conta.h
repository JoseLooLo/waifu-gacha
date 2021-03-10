
#ifndef INTERFACE_CLI_INTERFACE_CONTA_H_
#define INTERFACE_CLI_INTERFACE_CONTA_H_

    #include <string>
    #include <domain/conta.h>

    #define ___interface_conta_cl

	extern Conta* cli_interface_create_account(std::string account_login, std::string account_password);

	extern Conta* cli_interface_login_account(std::string account_login, std::string account_password);

/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

    #define ___interface_create_account_fn
    #define ___interface_login_account_fn

    /**
	 * Interface Create account
	 */

	Conta* interface_create_account(std::string account_login, std::string account_password) {
        return cli_interface_create_account(account_login, account_password);
    }

	/**
	 * Interface Login
	 */

	Conta* interface_login_account(std::string account_login, std::string account_password) {
        return cli_interface_login_account(account_login, account_password);
    }


#endif  /* INTERFACE_CLI_INTERFACE_CONTA_H_ */