#include "../include/FiscalRegimen.h"
#include "../include/DatabaseManager.h"
#include <iostream>

FiscalRegimen::FiscalRegimen() = default;

FiscalRegimen::FiscalRegimen(int id, int code, std::string name) : id(id), code(code), name(std::move(name)) {}

void FiscalRegimen::create_fiscal_regimen_table() {
    if (!DatabaseManager::table_exists("FISCAL_REGIMEN")) {
        std::cout << "Creating table FISCAL_REGIMEN" << std::endl;
        DatabaseManager::create_table("FISCAL_REGIMEN",
                                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "CODE INT NOT NULL, "
                                      "NAME TEXT NOT NULL");
    } else {
        std::cout << "Table FISCAL_REGIMEN already exists" << std::endl;
    }
}

FiscalRegimen FiscalRegimen::create_fiscal_regimen(int code, std::string name) {
    FiscalRegimen fiscal_regimen;
    fiscal_regimen.code = code;
    fiscal_regimen.name = std::move(name);
    return fiscal_regimen;
}

void FiscalRegimen::insert_fiscal_regimen(FiscalRegimen &fiscal_regimen) {
    std::string sql = "INSERT INTO FISCAL_REGIMEN (CODE, NAME) VALUES (" +
                      std::to_string(fiscal_regimen.code) + ", '" + fiscal_regimen.name + "');";
    DatabaseManager::execute_query(sql);

    fiscal_regimen.id = DatabaseManager::get_last_insert_rowid("FISCAL_REGIMEN");

}

FiscalRegimen FiscalRegimen::read_fiscal_regimen(FiscalRegimen &fiscal_regimen) {
    std::string sql = "SELECT * FROM FISCAL_REGIMEN WHERE ID = " + std::to_string(fiscal_regimen.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        fiscal_regimen.id = sqlite3_column_int(stmt, 0);
        fiscal_regimen.code = sqlite3_column_int(stmt, 1);
        fiscal_regimen.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return fiscal_regimen;
}

FiscalRegimen FiscalRegimen::read_fiscal_regimen(int id) {
    FiscalRegimen fiscal_regimen;
    std::string sql = "SELECT * FROM FISCAL_REGIMEN WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        fiscal_regimen.id = sqlite3_column_int(stmt, 0);
        fiscal_regimen.code = sqlite3_column_int(stmt, 1);
        fiscal_regimen.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return fiscal_regimen;
}

void FiscalRegimen::delete_fiscal_regimen(FiscalRegimen &fiscal_regimen) {
    std::string sql = "DELETE FROM FISCAL_REGIMEN WHERE ID = " + std::to_string(fiscal_regimen.id) + ";";
    DatabaseManager::execute_query(sql);
}

FiscalRegimen FiscalRegimen::get_fiscal_regimen_by_code(const int &code) {
    FiscalRegimen fiscal_regimen;
    std::string sql = "SELECT * FROM FISCAL_REGIMEN WHERE CODE = " + std::to_string(code) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        fiscal_regimen.id = sqlite3_column_int(stmt, 0);
        fiscal_regimen.code = sqlite3_column_int(stmt, 1);
        fiscal_regimen.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return fiscal_regimen;
}
