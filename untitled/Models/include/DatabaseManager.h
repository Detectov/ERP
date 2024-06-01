#ifndef MVC_TEMPLATE_DATABASEMANAGER_H
#define MVC_TEMPLATE_DATABASEMANAGER_H

#include "sqlite3.h"
#include <string>

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();
    static void create_database(const std::string& database_name);
    static void create_table(const std::string& table_name, const std::string& columns);
    static bool table_exists(const std::string& table_name);
    static int count_records(const std::string& table_name);
    static int get_last_insert_rowid(const std::string& table_name);

    // Execute a query
    static void execute_query(const std::string& query);

    // Execute a query and return the result
    static sqlite3_stmt* execute_query_and_return(const std::string& query);
private:
    static sqlite3 *db;
    static char *zErrMsg;
    static int rc;
};

extern DatabaseManager dbm; // Declaración externa

#endif //MVC_TEMPLATE_DATABASEMANAGER_H
