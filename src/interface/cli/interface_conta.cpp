
#include <domain/conta.h>

#include <string>

Conta* cli_interface_create_account(std::string account_login, std::string account_password) {
    Conta *nova_conta = new Conta();
    nova_conta->create_account(account_login, account_password);
    return nova_conta;
}

Conta* cli_interface_login_account(std::string account_login, std::string account_password) {
    Conta *nova_conta = new Conta();
    nova_conta->load_account(account_login, account_password);
    return nova_conta;
}
