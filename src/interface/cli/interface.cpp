#include <iostream>
#include <string>
#include <domain/conta.h>
#include <database/sqlite3.h>
#include <domain/roleta.h>

/**
 *  This class should be the main class of the interface.
 *  All interactions with the user should be done through this class
 */

Conta* conta;
Database *database = new Database("waifuG.sqlite3");
Roleta* roleta = new Roleta(database);

void cli_clear(void);
void account(void);
void account_login(void);
void roleta_testes(void);
void personagens_teste(void);


void cli_clear(void) {
    #if (defined(__linux__))
        system("clear");
    #endif
}

int cli_interface_init(void) {
    cli_clear();
    account();
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
        std::cout << "[777] - Roleta debug" << std::endl;
        std::cout << "[999] - Obter personagens do database" << std::endl;
        std::cin >> op;

        if (op == "1") {
            std::cout << "Not yet made!" << std::endl;
            continue;
        } else if (op == "2") {
            std::cout << "Not yet made!" << std::endl;
            continue;
        } else if (op == "3") {
            return;
        } else if (op == "777") {
            roleta_testes();
            continue;
        } else if (op == "999") {
            personagens_teste();
            continue;
        } else {
            cli_clear();
            std::cout << "Invalid Input" << std::endl;
            continue;
        }
    }
    
    
        
}

void account_login(void) {


}

void roleta_testes(void) {
    cli_clear();
    std::cout << "Roleta debug" << std::endl;
    std::cout << std::endl;
    std::string op;
    while (1) {
        std::cout << "1- Ver probabilidades" << std::endl;
        std::cout << "2- Voltar" << std::endl;
        std::cin >> op;
        
        if (op == "1") {
                roleta->get_probability();
                continue;
        } else if (op == "2") {
            return;
        } else {
            cli_clear();
            std::cout << "Invalid Input" << std::endl;
            continue;
        }
    }

}

void personagens_teste(void) {
    std::vector<std::vector<std::string>> personagens = database->getAllCharacters();
    cli_clear();

    std::cout << "Personagens na database: " << std::endl;
    for (std::size_t i = 0; i < personagens.size(); i++) {
        std::string rarity;

        switch (std::stoi(personagens[i][2])) {
            case 1:
                rarity = "C";
                break;
            case 2:
                rarity = "R";
                break;
            case 3:
                rarity = "SR";
                break;
            default:
                rarity = "SSR";
                break;
        }

        std::cout << "ID: " << personagens[i][0] << " / " << personagens[i][1] << " / Rarity: " << rarity << std::endl;
    }
}