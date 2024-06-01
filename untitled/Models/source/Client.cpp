#include "../include/Client.h"
#include "../include/DatabaseManager.h"
#include <iostream>
#include <utility>

Client::Client() = default;

Client::Client(std::string name, std::string RFC, FiscalRegimen fiscal_regimen, std::string address,
               std::string city, std::string state, std::string zip_code)
        : name(std::move(name)), RFC(std::move(RFC)), fiscal_regimen(std::move(std::move(fiscal_regimen))), address(std::move(address)),
          city(std::move(city)), state(std::move(state)), zip_code(std::move(zip_code)) {}

Client Client::create_client(std::string name, std::string RFC, FiscalRegimen fiscal_regimen, std::string address,
                             std::string city, std::string state, std::string zip_code) {
    Client client;
    client.name = std::move(name);
    client.RFC = std::move(RFC);
    client.fiscal_regimen = std::move(fiscal_regimen);
    client.address = std::move(address);
    client.city = std::move(city);
    client.state = std::move(state);
    client.zip_code = std::move(zip_code);
    return client;
}

void Client::create_client_table() {
    if (!DatabaseManager::table_exists("CLIENTS")) {
        std::cout << "Creating table CLIENTS" << std::endl;
        DatabaseManager::create_table("CLIENTS",
                                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "NAME TEXT NOT NULL, "
                                      "RFC TEXT NOT NULL, "
                                      "FISCAL_REGIMEN INT NOT NULL, "
                                      "ADDRESS TEXT NOT NULL, "
                                      "CITY TEXT NOT NULL, "
                                      "STATE TEXT NOT NULL, "
                                      "ZIP_CODE TEXT NOT NULL, "
                                      "FOREIGN KEY (FISCAL_REGIMEN) REFERENCES FISCAL_REGIMEN(ID)");
    } else {
        std::cout << "Table CLIENTS already exists" << std::endl;
    }
}

void Client::insert_client(Client &client) {
    std::string sql = "INSERT INTO CLIENTS (NAME, RFC, FISCAL_REGIMEN, ADDRESS, CITY, STATE, ZIP_CODE) VALUES ('" +
                      client.name + "', '" + client.RFC + "', " + std::to_string(client.fiscal_regimen.get_id()) + ", '" +
                      client.address + "', '" + client.city + "', '" + client.state + "', '" + client.zip_code + "');";
    DatabaseManager::execute_query(sql);
}

Client Client::read_client(Client &client) {
    std::string sql = "SELECT * FROM CLIENTS WHERE ID = " + std::to_string(client.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        client.id = sqlite3_column_int(stmt, 0);
        client.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        client.RFC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        client.fiscal_regimen = FiscalRegimen::read_fiscal_regimen(sqlite3_column_int(stmt, 3));
        client.address = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
        client.city = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
        client.state = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
        client.zip_code = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return client;
}

Client Client::read_client(int id) {
    Client client;
    std::string sql = "SELECT * FROM CLIENTS WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        client.id = sqlite3_column_int(stmt, 0);
        client.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        client.RFC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        client.fiscal_regimen = FiscalRegimen::read_fiscal_regimen(sqlite3_column_int(stmt, 3));
        client.address = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
        client.city = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
        client.state = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
        client.zip_code = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return client;
}

void Client::delete_client(Client &client) {
    std::string sql = "DELETE FROM CLIENTS WHERE ID = " + std::to_string(client.id) + ";";
    DatabaseManager::execute_query(sql);
}

void Client::delete_client(int id) {
    std::string sql = "DELETE FROM CLIENTS WHERE ID = " + std::to_string(id) + ";";
    DatabaseManager::execute_query(sql);
}
