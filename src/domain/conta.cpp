#include <domain/conta.h>

Conta::Conta() {

}

int Conta::create_account(std::string account_login, std::string account_password) {
    this->login = account_login;
    this->password = account_password;
    return 0;
}

void Conta::load_account(std::string account_login, std::string account_password) {
    this->login = account_login;
    this->password = account_password;
}