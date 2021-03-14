
#include <iostream>
#include <domain/conta.h>
#include <database/sqlite3.h>
#include <interface/cli.h>

Conta* conta;
Database *database;

int main() {
    return cli_interface_init();
}