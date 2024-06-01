//
// Created by Daniel Moukarzel on 31/05/24.
//

#include "../include/Sale.h"

Sale::Sale() = default;

Sale::Sale(std::string dateofsale, User user, Client client, double amount) : dateofsale(std::move(dateofsale)), user(std::move(user)), client(std::move(client)), amount(amount) {}


void Sale::create_sale_table() {
    DatabaseManager::create_table("SALES",
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, dateofsale TEXT, user_id INTEGER, client_id INTEGER, amount REAL");
}

Sale Sale::create_sale(std::string dateofsale, User user, Client client ,double amount) {
    Sale sale;
    sale.dateofsale = std::move(dateofsale);
    sale.user = std::move(user);
    sale.client = std::move(client);
    sale.amount = amount;
    return sale;
}

void Sale::insert_sale(Sale &sale) {
    std::string query =
            "INSERT INTO SALES (dateofsale, user_id, client_id, amount) VALUES ('" + sale.dateofsale +
            "', " + std::to_string(sale.user.get_id()) + ", " + std::to_string(sale.client.get_id()) + ", " +
            std::to_string(sale.amount) + ")";
    DatabaseManager::execute_query(query);
}

Sale Sale::read_sale(Sale &sale) {
    Sale sale1;
    std::string sql = "SELECT * FROM SALES WHERE ID = " + std::to_string(sale.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        sale1.id = sqlite3_column_int(stmt, 0);
        sale1.dateofsale = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        sale1.user = User::read_user(sqlite3_column_int(stmt, 2));
        sale1.client = Client::read_client(sqlite3_column_int(stmt, 3));
        sale1.amount = sqlite3_column_double(stmt, 4);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return sale1;
}

Sale Sale::read_sale(int id) {
    Sale sale1;
    std::string sql = "SELECT * FROM SALES WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        sale1.id = sqlite3_column_int(stmt, 0);
        sale1.dateofsale = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        sale1.user = User::read_user(sqlite3_column_int(stmt, 2));
        sale1.client = Client::read_client(sqlite3_column_int(stmt, 3));
        sale1.amount = sqlite3_column_double(stmt, 4);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return sale1;
}

void Sale::delete_sale(Sale &sale) {
    std::string sql = "DELETE FROM SALES WHERE ID = " + std::to_string(sale.id) + ";";
    DatabaseManager::execute_query(sql);
}

void Sale::delete_sale(int id) {
    std::string sql = "DELETE FROM SALES WHERE ID = " + std::to_string(id) + ";";
    DatabaseManager::execute_query(sql);
}



