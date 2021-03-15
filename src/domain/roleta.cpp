#include <domain/roleta.h>
#include <domain/personagem.h>
#include <database/sqlite3.h>
#include <vector>
#include <iostream>
#include <string>

Roleta::Roleta(Database* database) {
    this->pity = 0;
    this->character_amount = 0;

    std::vector<std::vector<std::string>> character_list = database->getAllCharacters();

    for (std::size_t i = 0; i < character_list.size(); i++) {
        int id = std::stoi(character_list[i][0]);
        std::string name = character_list[i][1];
        int rarity = std::stoi(character_list[i][2]);

        Personagem* personagem = new Personagem(id, name, rarity);

        switch (rarity) {
            case 1:
                this->charactersC.push_back(personagem);
                break;
            case 2:
                this->charactersR.push_back(personagem);
                break;
            case 3:
                this->charactersSR.push_back(personagem);
                break;
            case 4:
                this->charactersSSR.push_back(personagem);
                break;
        }

        this->character_amount++;
    }
}

void Roleta::get_probability(void) {
    std::cout << "Tabela de probabilidades" << std::endl;
    std::cout << "Comum (C): 50%" << std::endl;
    std::cout << "Raro (R): 30%" << std::endl;
    std::cout << "Super Raro (SR): 15%" << std::endl;
    std::cout << "Super Super Raro (SSR) : 5%" << std::endl;
    std::cout << std::endl;


    std::cout << "Personagens comums" << std::endl;
    for (std::size_t i = 0; i < this->charactersC.size(); i++) {
        std::cout << "Nome: " << this->charactersC[i]->getName() << " (C) / " << 100*0.5*1/(this->charactersC.size()) << "%" << std::endl; 
    }
    std::cout << std::endl;

    std::cout << "Personagens raros" << std::endl;
    for (std::size_t i = 0; i < this->charactersR.size(); i++) {
        std::cout << "Nome: " << this->charactersR[i]->getName() << " (R) / " << 100*0.3*1/(this->charactersR.size()) << "%" << std::endl; 
    }
    std::cout << std::endl;

    std::cout << "Personagens super raros" << std::endl;
    for (std::size_t i = 0; i < this->charactersSR.size(); i++) {
        std::cout << "Nome: " << this->charactersSR[i]->getName() << " (SR) / " << 100*0.15*1/(this->charactersSR.size()) << "%" << std::endl; 
    }
    std::cout << std::endl;

    std::cout << "Personagens super super raros" << std::endl;
    for (std::size_t i = 0; i < this->charactersSSR.size(); i++) {
        std::cout << "Nome: " << this->charactersSSR[i]->getName() << " (SSR) / " << 100*0.05*1/(this->charactersSSR.size()) << "%" << std::endl; 
    }
    std::cout << std::endl;
}