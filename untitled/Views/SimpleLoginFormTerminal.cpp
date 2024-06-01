//
// Created by Mauricio on 29/05/24.
//

#include "../Controllers/Authentication.h"
#include <iostream>

extern int login_menu() {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    User user = Authentication::login(username, password);

    if (user.is_logged_in()) {
        std::cout << "Welcome " << user.get_username() << std::endl;
    } else {
        std::cout << "Invalid credentials" << std::endl;
    }
    return 0;
}

extern int create_user_menu() {
    std::string username, password, role, first_name, last_name, birth_date;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "Role: ";
    std::cin >> role;
    std::cout << "First name: ";
    std::cin >> first_name;
    std::cout << "Last name: ";
    std::cin >> last_name;
    std::cout << "Birth date: ";
    std::cin >> birth_date;

    User user = User::create_user(username, password, role, first_name, last_name, birth_date);
    User::insert_user(user);
    return 0;
}

