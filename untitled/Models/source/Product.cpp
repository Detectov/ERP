//
// Created by Daniel Moukarzel on 31/05/24.
//

#include <utility>

#include "../include/Product.h"


Product::Product() = default;

Product::Product(std::string UPC, std::string name, Presentation presentation, double price, double cost, bool has_iva,
                 int stock) : UPC(std::move(UPC)), name(std::move(name)), presentation(std::move(presentation)),
                               price(price), cost(cost), has_iva(has_iva), stock(stock) {}



void Product::create_product_table() {
    DatabaseManager::create_table("PRODUCTS",
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, UPC TEXT, name TEXT, presentation_id INTEGER, price REAL, cost REAL, has_iva BOOLEAN, stock INTEGER");
}

Product Product::create_product(std::string UPC, std::string name, Presentation presentation, double price, double cost,
                                bool has_iva, int stock) {
    Product product;
    product.UPC = std::move(UPC);
    product.name = std::move(name);
    product.presentation = std::move(presentation);
    product.price = price;
    product.cost = cost;
    product.has_iva = has_iva;
    product.stock = stock;
    return product;
}

void Product::insert_product(Product &product) {
    std::string query =
            "INSERT INTO PRODUCTS (UPC, name, presentation_id, price, cost, has_iva, stock) VALUES ('" + product.UPC +
            "', '" + product.name + "', " + std::to_string(product.presentation.get_id()) + ", " +
            std::to_string(product.price) + ", " + std::to_string(product.cost) + ", " +
            std::to_string(product.has_iva) + ", " + std::to_string(product.stock) + ")";
    DatabaseManager::execute_query(query);
}

Product Product::read_product(Product &product) {
    Product product1;
    std::string sql = "SELECT * FROM PRODUCTS WHERE ID = " + std::to_string(product.id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        product1.id = sqlite3_column_int(stmt, 0);
        product1.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product1.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product1.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product1.price = sqlite3_column_double(stmt, 4);
        product1.cost = sqlite3_column_double(stmt, 5);
        product1.has_iva = sqlite3_column_int(stmt, 6);
        product1.stock = sqlite3_column_int(stmt, 7);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return product1;
}

Product Product::read_product(int id) {
    Product product;
    std::string sql = "SELECT * FROM PRODUCTS WHERE ID = " + std::to_string(id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return product;
}

void Product::delete_product(Product &product) {
    std::string query = "DELETE FROM PRODUCTS WHERE ID = " + std::to_string(product.id) + ";";
    DatabaseManager::execute_query(query);
}

Product Product::get_product_by_name(const std::string &name) {
    Product product;
    std::string sql = "SELECT * FROM PRODUCTS WHERE name = '" + name + "';";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return product;
}

Product Product::get_product_by_UPC(const std::string &UPC) {
    Product product;
    std::string sql = "SELECT * FROM PRODUCTS WHERE UPC = '" + UPC + "';";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    if (stmt && sqlite3_step(stmt) == SQLITE_ROW) {
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return product;
}

std::vector<Product> Product::get_all_products() {
    std::vector<Product> products;
    std::string sql = "SELECT * FROM PRODUCTS;";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Product product;
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
        products.push_back(product);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return products;
}

std::vector<Product> Product::get_all_products_by_presentation(const Presentation &presentation) {
    std::vector<Product> products;
    std::string sql = "SELECT * FROM PRODUCTS WHERE presentation_id = " + std::to_string(presentation.get_id()) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Product product;
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
        products.push_back(product);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return products;
}

std::vector<Product> Product::get_all_products_by_presentation(int presentation_id) {
    std::vector<Product> products;
    std::string sql = "SELECT * FROM PRODUCTS WHERE presentation_id = " + std::to_string(presentation_id) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Product product;
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
        products.push_back(product);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return products;
}

std::vector<Product> Product::get_all_products_by_presentation(const std::string &presentation_name) {
    std::vector<Product> products;
    std::string sql = "SELECT * FROM PRODUCTS WHERE presentation_id = " +
                      std::to_string(Presentation::get_presentation_by_name(presentation_name).get_id()) + ";";
    sqlite3_stmt *stmt = DatabaseManager::execute_query_and_return(sql);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Product product;
        product.id = sqlite3_column_int(stmt, 0);
        product.UPC = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        product.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        product.presentation = Presentation::read_presentation(sqlite3_column_int(stmt, 3));
        product.price = sqlite3_column_double(stmt, 4);
        product.cost = sqlite3_column_double(stmt, 5);
        product.has_iva = sqlite3_column_int(stmt, 6);
        product.stock = sqlite3_column_int(stmt, 7);
        products.push_back(product);
    }
    sqlite3_finalize(stmt);  // Liberar el statement
    return products;
}
