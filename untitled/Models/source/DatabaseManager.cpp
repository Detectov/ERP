#include "../include/DatabaseManager.h"
#include <stdexcept>

sqlite3* DatabaseManager::db = nullptr;
char* DatabaseManager::zErrMsg = nullptr;
int DatabaseManager::rc = 0;

DatabaseManager::DatabaseManager() {
    rc = sqlite3_open("/Users/Mou/Downloads/MVC_template/database.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        throw std::runtime_error("Can't open database");
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

bool DatabaseManager::table_exists(const std::string &table_name) {
    std::string sql = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + table_name + "';";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return false;
    }
    bool exists = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return exists;
}

void DatabaseManager::create_database(const std::string &database_name) {
    rc = sqlite3_open(database_name.c_str(), &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        throw std::runtime_error("Can't open database");
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

void DatabaseManager::create_table(const std::string &table_name, const std::string &columns) {
    std::string sql = "CREATE TABLE " + table_name + " (" + columns + ");";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        throw std::runtime_error("SQL error: " + std::string(zErrMsg));
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

void DatabaseManager::execute_query(const std::string &query) {
    rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        throw std::runtime_error("SQL error: " + std::string(zErrMsg));
    } else {
        fprintf(stdout, "Query executed successfully\n");
    }
}

sqlite3_stmt* DatabaseManager::execute_query_and_return(const std::string &query) {
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return nullptr;
    }
    return stmt;
}

int DatabaseManager::count_records(const std::string &table_name) {
    std::string sql = "SELECT COUNT(*) FROM " + table_name + ";";
    sqlite3_stmt *stmt = execute_query_and_return(sql);
    int count = 0;
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);
    return count;
}

int DatabaseManager::get_last_insert_rowid(const std::string &table_name) {
    std::string sql = "SELECT MAX(ID) FROM " + table_name + ";";
    sqlite3_stmt *stmt = execute_query_and_return(sql);
    int rowid = 0;
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        rowid = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);
    return rowid;
}
