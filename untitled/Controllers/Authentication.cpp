//
// Created by Mauricio on 29/05/24.
//

#include "Authentication.h"

User Authentication::login(const std::string &username, const std::string &password) {
    User user = User::get_user_by_username_and_password(username, password);
    if (user.get_id() != -1) {
        user.set_is_logged_in(true);
    }
    return user;
}

