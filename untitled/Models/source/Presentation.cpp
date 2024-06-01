//
// Created by Daniel Moukarzel on 31/05/24.
//

#include "../include/Presentation.h"

Presentation::Presentation() = default;

Presentation::Presentation(std::string name) : name(std::move(name)) {}

void Presentation::create_presentation_table() {
    if (!DatabaseManager::table_exists("PRESENTATIONS")) {
        std::cout << "Creating table PRESENTATIONS" << std::endl;
        DatabaseManager::create_table("PRESENTATIONS",
                                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "NAME TEXT NOT NULL");
    } else {
        std::cout << "Table PRESENTATIONS already exists" << std::endl;
    }
}

Presentation Presentation::create_presentation(std::string name) {
    Presentation presentation;
    presentation.name = std::move(name);
    return presentation;
}

void Presentation::insert_presentation(Presentation &presentation) {
    std::string sql = "INSERT INTO presentations (name) VALUES ('" + presentation.name + "');";
    DatabaseManager::execute_query(sql);

    presentation.id = DatabaseManager::get_last_insert_rowid("PRESENTATIONS");
}

Presentation Presentation::read_presentation(Presentation &presentation) {
    std::string sql = "SELECT * FROM presentations WHERE id = " + std::to_string(presentation.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        presentation.id = sqlite3_column_int(stmt, 0);
        presentation.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    }
    return presentation;
}

Presentation Presentation::read_presentation(int id) {
    Presentation presentation;
    presentation.id = id;
    return read_presentation(presentation);
}

void Presentation::delete_presentation(Presentation &presentation) {
    std::string sql = "DELETE FROM presentations WHERE id = " + std::to_string(presentation.id) + ";";
    DatabaseManager::execute_query(sql);
}

Presentation Presentation::get_presentation_by_name(const std::string &name) {
    Presentation presentation;
    std::string sql = "SELECT * FROM presentations WHERE name = '" + name + "';";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        presentation.id = sqlite3_column_int(stmt, 0);
        presentation.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    }
    return presentation;
}

