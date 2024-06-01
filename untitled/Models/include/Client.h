//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_CLIENT_H
#define MVC_TEMPLATE_CLIENT_H

#include <string>
#include "DatabaseManager.h"
#include <utility>
#include "iostream"
#include "FiscalRegimen.h"

class Client {
public:
    Client();
    Client(std::string name, std::string RFC, FiscalRegimen fiscal_regimen, std::string address, std::string city,
           std::string state, std::string zip_code);
    static void create_client_table();
    static Client create_client(std::string name, std::string RFC, FiscalRegimen fiscal_regimen, std::string address,
                                std::string city, std::string state, std::string zip_code);

    // CRUD operations
    static void insert_client(Client &client);
    static Client read_client(Client &client);
    static Client read_client(int id);
    static void delete_client(Client &client);
    static void delete_client(int id);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] std::string get_RFC() const { return RFC; }
    [[nodiscard]] FiscalRegimen get_fiscal_regimen() const { return fiscal_regimen; }
    [[nodiscard]] std::string get_address() const { return address; }
    [[nodiscard]] std::string get_city() const { return city; }
    [[nodiscard]] std::string get_state() const { return state; }
    [[nodiscard]] std::string get_zip_code() const { return zip_code; }

    // Setters
    void set_id(int id) { Client::id = id; }
    void set_name(const std::string &name) { Client::name = name; }
    void set_RFC(const std::string &RFC) { Client::RFC = RFC; }
    void set_fiscal_regimen(FiscalRegimen fiscal_regimen) { Client::fiscal_regimen = fiscal_regimen; }
    void set_address(const std::string &address) { Client::address = address; }
    void set_city(const std::string &city) { Client::city = city; }
    void set_state(const std::string &state) { Client::state = state; }
    void set_zip_code(const std::string &zip_code) { Client::zip_code = zip_code; }

    FiscalRegimen fiscal_regimen;

private:
    int id{};
    std::string name;
    std::string RFC;
    std::string address;
    std::string city;
    std::string state;
    std::string zip_code;
};


#endif //MVC_TEMPLATE_CLIENT_H
