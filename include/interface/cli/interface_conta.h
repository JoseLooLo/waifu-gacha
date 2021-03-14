
#ifndef INTERFACE_CLI_INTERFACE_CONTA_H_
#define INTERFACE_CLI_INTERFACE_CONTA_H_

    #include <string>
    #include <domain/conta.h>

    #define ___interface_conta_cl

	
/*============================================================================*
 * Interface                                                         *
 *============================================================================*/

    extern Conta* cli_interface_create_account(std::string account_login, std::string account_password);

	extern Conta* cli_interface_login_account(std::string account_login, std::string account_password);

#endif  /* INTERFACE_CLI_INTERFACE_CONTA_H_ */