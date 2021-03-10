#ifndef DOMAIN_CONTA_H_
#define DOMAIN_CONTA_H_

	#include <string>

	class Conta {
		public:
			Conta();
			int create_account(std::string account_login, std::string account_password);
			void load_account(std::string account_login, std::string account_password);

		private:
			std::string login;
			std::string password;
	};

#endif  /* DOMAIN_CONTA_H_ */