//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_SALE_H
#define MVC_TEMPLATE_SALE_H

#include <string>
#include "DatabaseManager.h"
#include "User.h"
#include "Client.h"
#include <iostream>
#include <ctime>

class Sale {
public:
    Sale();

    Sale(std::string dateofsale, User user, Client client, double amount);

    static void create_sale_table();
    static Sale create_sale(std::string dateofsale, User user, Client client, double amount);

    // CRUD operations
    static void insert_sale(Sale &sale);
    static Sale read_sale(Sale &sale);
    static Sale read_sale(int id);
    static void delete_sale(Sale &sale);
    static void delete_sale(int id);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] std::string get_dateofsale() const { return dateofsale; }
    [[nodiscard]] User get_user_id() const { return user; }
    [[nodiscard]] Client get_client_id() const { return client; }
    [[nodiscard]] double get_amount() const { return amount; }

    // Setters
    void set_id(int id) { Sale::id = id; }
    void set_dateofsale(const std::string &dateofsale) { Sale::dateofsale = dateofsale; }
    void set_user_id(const User &user) { Sale::user = user; }
    void set_client_id(const Client &client) { Sale::client = client; }
    void set_amount(double amount) { Sale::amount = amount; }

    // other operations
    static Sale get_sale_by_date(const std::string &dateofsale);
    static Sale get_sale_by_amount(double amount);
    static std::vector<Sale> get_all_sales();
    static std::vector<Sale> get_all_sales_by_date(const std::string &dateofsale);


    User user;
    Client client;

private:
    int id;
    std::string dateofsale;
    double amount;

};


#endif //MVC_TEMPLATE_SALE_H
