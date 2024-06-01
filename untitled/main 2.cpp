#include <iostream>
#include "Models/include/User.h"
#include "Models/include/Client.h"
#include "Models/include/FiscalRegimen.h"
#include "Models/include/Presentation.h"
#include "Models/include/Presentation.h"
#include "Models/include/Product.h"
#include "Views/SimpleLoginFormTerminal.h"

DatabaseManager dbm;

void setupDatabase() {
    User::create_user_table();
    Client::create_client_table();
    FiscalRegimen::create_fiscal_regimen_table();
    Presentation::create_presentation_table();
    Product::create_product_table();


    User admin = User::get_user_by_username_and_password("admin", "admin");
    if (admin.get_id() == 0) {
        admin = User::create_user("admin", "admin", "Admin", "Default", "Admin", "2024-05-31");
        User::insert_user(admin);
    }
}

void tests() {
    //create regimen object
    //FiscalRegimen regimen = FiscalRegimen::create_fiscal_regimen(601, "General de Ley Personas Morales");
    //FiscalRegimen::insert_fiscal_regimen(regimen);

    //create client object
    //Client client = Client::create_client("Mauricio", "GOMM940528", regimen, "Calle 123", "CDMX", "CDMX", "12345");
    //Client::insert_client(client);

    // query client
    //Client client2 = Client::read_client(1);
    //std::cout << "Client: " << client2.get_id() << std::endl;
    //std::cout << "Client: " << client2.get_name() << std::endl;
    // std::cout << "Fiscal Regimen: " << client2.fiscal_regimen.get_id() << std::endl;
    //std::cout << "Fiscal Regimen: " << client2.fiscal_regimen.get_name() << std::endl;
    // std::cout << "Fiscal Regimen: " << client2.fiscal_regimen.get_code() << std::endl;

    // query regimen
    // FiscalRegimen regimen2 = FiscalRegimen::read_fiscal_regimen(0);
    // std::cout << "Regimen: " << regimen2.get_id() << std::endl;
    // std::cout << "Regimen: " << regimen2.get_name() << std::endl;

    // create presentation object
    Presentation presentation = Presentation::create_presentation("Presentation 1");
    Presentation::insert_presentation(presentation);

    // Create product object
    Product product = Product::create_product("1234567890", "Product 1", presentation, 100.0, 50.0, true, 10);
    Product::insert_product(product);

    // query product
    Product product2 = Product::read_product(1);
    std::cout << "Product: " << product2.get_id() << std::endl;
    std::cout << "Product: " << product2.get_name() << std::endl;
    std::cout << "Product: " << product2.get_UPC() << std::endl;
    std::cout << "Product: " << product2.presentation.get_name() << std::endl;
}

int main() {
    setupDatabase();
    tests();
    // login_menu();

    return 0;
}
