//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_SOLDPRODUCT_H
#define MVC_TEMPLATE_SOLDPRODUCT_H

#include "Sale.h"
#include "Product.h"
#include <string>
#include <iostream>

class SoldProduct {
public:
    SoldProduct();
    SoldProduct(Sale sale, Product product, int quantity, double price_per_unit);
    static void create_soldproduct_table();
    static SoldProduct create_soldproduct(Sale sale, Product product, int quantity, double price_per_unit);

    // CRUD operations
    static void insert_soldproduct(SoldProduct &soldproduct);
    static SoldProduct read_soldproduct(SoldProduct &soldproduct);
    static SoldProduct read_soldproduct(int id);
    static void delete_soldproduct(SoldProduct &soldproduct);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] Sale get_sale_id() const { return sale; }
    [[nodiscard]] Product get_product_id() const { return product; }
    [[nodiscard]] int get_quantity() const { return quantity; }
    [[nodiscard]] double get_price_per_unit() const { return price_per_unit; }

    // Setters
    void set_id(int id) { SoldProduct::id = id; }
    void set_sale_id(const Sale &sale) { SoldProduct::sale = sale; }
    void set_product_id(const Product &product) { SoldProduct::product = product; }
    void set_quantity(int quantity) { SoldProduct::quantity = quantity; }
    void set_price_per_unit(double price_per_unit) { SoldProduct::price_per_unit = price_per_unit; }





    Sale sale;
    Product product;
private:
    int id;
    int quantity;
    double price_per_unit;

};


#endif //MVC_TEMPLATE_SOLDPRODUCT_H
