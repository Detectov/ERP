//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_PRODUCT_H
#define MVC_TEMPLATE_PRODUCT_H

#include <string>
#include <iostream>
#include "DatabaseManager.h"
#include "Presentation.h"

class Product {
public:
    Product();
    Product(std::string UPC, std::string name, Presentation presentation, double price, double cost, bool has_iva, int stock);
    static void create_product_table();
    static Product create_product(std::string UPC, std::string name, Presentation presentation, double price, double cost, bool has_iva, int stock);

    // CRUD operations
    static void insert_product(Product &product);
    static Product read_product(Product &product);
    static Product read_product(int id);
    static void delete_product(Product &product);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] std::string get_UPC() const { return UPC; }
    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] Presentation get_presentation() const { return presentation; }
    [[nodiscard]] double get_price() const { return price; }
    [[nodiscard]] double get_cost() const { return cost; }
    [[nodiscard]] bool get_has_iva() const { return has_iva; }
    [[nodiscard]] int get_stock() const { return stock; }

    // Setters
    void set_id(int id) { Product::id = id; }
    void set_UPC(const std::string &UPC) { Product::UPC = UPC; }
    void set_name(const std::string &name) { Product::name = name; }
    void set_presentation(const Presentation &presentation) { Product::presentation = presentation; }
    void set_price(double price) { Product::price = price; }
    void set_cost(double cost) { Product::cost = cost; }
    void set_has_iva(bool has_iva) { Product::has_iva = has_iva; }
    void set_stock(int stock) { Product::stock = stock; }

    // other operations
    static Product get_product_by_name(const std::string &name);
    static Product get_product_by_UPC(const std::string &UPC);
    static std::vector<Product> get_all_products();
    static std::vector<Product> get_all_products_by_presentation(const Presentation &presentation);
    static std::vector<Product> get_all_products_by_presentation(int presentation_id);
    static std::vector<Product> get_all_products_by_presentation(const std::string &presentation_name);

    Presentation presentation;
private:
    int id;
    std::string UPC;
    std::string name;
    double price;
    double cost;
    bool has_iva;
    int stock;
};


#endif //MVC_TEMPLATE_PRODUCT_H
