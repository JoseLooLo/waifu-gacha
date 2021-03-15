#include <domain/personagem.h>
#include <string>

Personagem::Personagem(int ID, std::string name, int rarity) {
    this->ID = ID;
    this->name = name;
    this->rarity = rarity;
}

std::string Personagem::getName(void) {
    return this->name;
}

int Personagem::getRarity(void) {
    return this->rarity;
}