//
// Created by Daniel Moukarzel on 31/05/24.
//

#include "../include/SoldProduct.h"

SoldProduct::SoldProduct() = default;

SoldProduct::SoldProduct(Sale sale, Product product, int quantity, double price_per_unit) : sale(sale), product(product), quantity(quantity), price_per_unit(price_per_unit) {}

void SoldProduct::create_soldproduct_table() {
    DatabaseManager::create_table("SoldProduct", "id INTEGER PRIMARY KEY AUTOINCREMENT, sale_id INTEGER, product_id INTEGER, quantity INTEGER, price_per_unit REAL");
}


SoldProduct SoldProduct::create_soldproduct(Sale sale, Product product, int quantity, double price_per_unit) {
    SoldProduct soldproduct;
    soldproduct.sale = std::move(sale);
    soldproduct.product = std::move(product);
    soldproduct.quantity = quantity;
    soldproduct.price_per_unit = price_per_unit;
    return soldproduct;
}

void SoldProduct::insert_soldproduct(SoldProduct &soldproduct) {
    std::string query = "INSERT INTO SoldProduct (sale_id, product_id, quantity, price_per_unit) VALUES (" + std::to_string(soldproduct.sale.get_id()) + ", " + std::to_string(soldproduct.product.get_id()) + ", " + std::to_string(soldproduct.quantity) + ", " + std::to_string(soldproduct.price_per_unit) + ")";
    DatabaseManager::execute_query(query);
}

SoldProduct SoldProduct::read_soldproduct(SoldProduct &soldproduct) {
    SoldProduct soldproduct1;
    std::string sql = "SELECT * FROM SoldProduct WHERE ID = " + std::to_string(soldproduct.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        soldproduct1.id = sqlite3_column_int(stmt, 0);
        soldproduct1.sale = Sale::read_sale(sqlite3_column_int(stmt, 1));
        soldproduct1.product = Product::read_product(sqlite3_column_int(stmt, 2));
        soldproduct1.quantity = sqlite3_column_int(stmt, 3);
        soldproduct1.price_per_unit = sqlite3_column_double(stmt, 4);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return soldproduct1;
}

SoldProduct SoldProduct::read_soldproduct(int id) {
    SoldProduct soldproduct1;
    std::string sql = "SELECT * FROM SoldProduct WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        soldproduct1.id = sqlite3_column_int(stmt, 0);
        soldproduct1.sale = Sale::read_sale(sqlite3_column_int(stmt, 1));
        soldproduct1.product = Product::read_product(sqlite3_column_int(stmt, 2));
        soldproduct1.quantity = sqlite3_column_int(stmt, 3);
        soldproduct1.price_per_unit = sqlite3_column_double(stmt, 4);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return soldproduct1;
}

void SoldProduct::delete_soldproduct(SoldProduct &soldproduct) {
    std::string sql = "DELETE FROM SoldProduct WHERE ID = " + std::to_string(soldproduct.id) + ";";
    DatabaseManager::execute_query(sql);
}


