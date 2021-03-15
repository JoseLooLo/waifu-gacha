#ifndef DOMAIN_ROLETA_H_
#define DOMAIN_ROLETA_H_

	#include <vector>
	#include <iostream>
	#include <database/sqlite3.h>
	#include <domain/personagem.h>

	class Roleta {
		public:
			Roleta(Database* database);

			void get_probability(void);
		private:
			int character_amount;
			int pity;

			std::vector<Personagem*> charactersC;
			std::vector<Personagem*> charactersR;
			std::vector<Personagem*> charactersSR;
			std::vector<Personagem*> charactersSSR;
	};

#endif  /* DOMAIN_ROLETA_H_ */