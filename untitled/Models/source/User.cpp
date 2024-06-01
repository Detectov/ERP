#include "../include/User.h"
#include "../include/DatabaseManager.h"
#include <utility>
#include <iostream>

User::User() = default;

User::User(int id, std::string username, std::string password, std::string role, std::string name, std::string lastname, std::string date_joined)
        : id(id), username(std::move(username)), password(std::move(password)), role(std::move(role)), name(std::move(name)), lastname(std::move(lastname)), date_joined(std::move(date_joined)) {}

User User::create_user(std::string username, std::string password, std::string role, std::string name, std::string lastname, std::string date_joined) {
    User user(user_count(), std::move(username), std::move(password), std::move(role), std::move(name), std::move(lastname), std::move(date_joined));
    return user;
}

void User::create_user_table() {
    if (!DatabaseManager::table_exists("USERS")) {
        std::cout << "Creating table USERS" << std::endl;
        DatabaseManager::create_table("USERS",
                                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "USERNAME TEXT NOT NULL, "
                                      "PASSWORD TEXT NOT NULL, "
                                      "ROLE TEXT NOT NULL, "
                                      "NAME TEXT NOT NULL, "
                                      "LASTNAME TEXT NOT NULL, "
                                      "DATE_JOINED TEXT NOT NULL");
    } else {
        std::cout << "Table USERS already exists" << std::endl;
    }
}

void User::insert_user(User &user) {
    std::string sql = "INSERT INTO USERS (USERNAME, PASSWORD, ROLE, NAME, LASTNAME, DATE_JOINED) VALUES ('" +
                      user.username + "', '" + user.password + "', '" + user.role +
                      "', '" + user.name + "', '" + user.lastname + "', '" + user.date_joined + "');";
    DatabaseManager::execute_query(sql);
}

User User::read_user(int id) {
    User user;
    std::string sql = "SELECT * FROM USERS WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        user.id = sqlite3_column_int(stmt, 0);
        user.username = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        user.password = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        user.role = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
        user.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
        user.lastname = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
        user.date_joined = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return user;
}

void User::delete_user(int id) {
    std::string sql = "DELETE FROM USERS WHERE ID = " + std::to_string(id) + ";";
    DatabaseManager::execute_query(sql);
}

User User::get_user_by_username_and_password(const std::string &usr, const std::string &passwd) {
    User user;
    std::string sql = "SELECT * FROM USERS WHERE USERNAME = '" + usr + "' AND PASSWORD = '" + passwd + "';";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        user.id = sqlite3_column_int(stmt, 0);
        user.username = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        user.password = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        user.role = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
        user.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
        user.lastname = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
        user.date_joined = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return user;
}

int User::user_count() {
    return DatabaseManager::count_records("USERS");
}
