//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_FISCALREGIMEN_H
#define MVC_TEMPLATE_FISCALREGIMEN_H

#include <string>
#include "DatabaseManager.h"
#include <utility>
#include "iostream"

class FiscalRegimen {
public:
    FiscalRegimen();
    FiscalRegimen(int id, int code, std::string name);
    static void create_fiscal_regimen_table();
    static FiscalRegimen create_fiscal_regimen(int code, std::string name);

    // CRUD operations
    static void insert_fiscal_regimen(FiscalRegimen &fiscal_regimen);
    static FiscalRegimen read_fiscal_regimen(FiscalRegimen &fiscal_regimen);
    static FiscalRegimen read_fiscal_regimen(int id);
    static void delete_fiscal_regimen(FiscalRegimen &fiscal_regimen);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] int get_code() const { return code; }
    [[nodiscard]] std::string get_name() const { return name; }

    // Setters
    void set_id(int id) { FiscalRegimen::id = id; }
    void set_code(int code) { FiscalRegimen::code = code; }
    void set_name(const std::string &name) { FiscalRegimen::name = name; }

    // other operations
    static FiscalRegimen get_fiscal_regimen_by_code(const int &code);
private:
    int id{};
    int code{};
    std::string name;
};


#endif //MVC_TEMPLATE_FISCALREGIMEN_H
