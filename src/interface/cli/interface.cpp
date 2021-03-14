#include <iostream>
#include <string>
#include <domain/conta.h>
#include <database/sqlite3.h>

/**
 *  This class should be the main class of the interface.
 *  All interactions with the user should be done through this class
 */

Conta* conta;
Database *database = new Database("waifuG.sqlite3");

void cli_clear(void);
void account(void);
void account_login(void);


void cli_clear(void) {
    #if (defined(__linux__))
        system("clear");
    #endif
}

int cli_interface_init(void) {
    cli_clear();
    database->getAllCharacters();
    //account();
    std::cout << "Saindo...." << std::endl;
    return 0;
}

void account(void) {
    std::string op;
    while (1) {
        std::cout << "=======================================" << std::endl;
        std::cout << "[1] - Criar uma nova conta" << std::endl;
        std::cout << "[2] - Login" << std::endl;
        std::cout << "[3] - Sair" << std::endl;
        std::cin >> op;
        if (op == "1") {
            //
        } else if (op == "2") {
            database->getAllCharacters();
        } else if (op == "3") {
            return;
        } else {
            cli_clear();
            std::cout << "Inválid Input" << std::endl;
            continue;
        }
    }
    
    
        
}

void account_login(void) {


}