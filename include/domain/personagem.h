#ifndef DOMAIN_PERSONAGEM_H_
#define DOMAIN_PERSONAGEM_H_

	#include <string>

	class Personagem {
		public:
			Personagem(int ID, std::string name, int rarity);
			std::string getName(void);
			int getRarity(void);
		private:
			int ID;
			std::string name;
			int rarity;
	};

#endif  /* DOMAIN_PERSONAGEM_H_ */