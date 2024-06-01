#ifndef USER_H
#define USER_H

#include <string>
#include "DatabaseManager.h"

class User {
public:
    User();
    User(int id, std::string username, std::string password, std::string role, std::string name, std::string lastname, std::string date_joined);

    static void create_user_table();
    static User create_user(std::string username, std::string password, std::string role, std::string name, std::string lastname, std::string date_joined);

    static void insert_user(User &user);
    static User read_user(int id);
    static void delete_user(int id);

    static User get_user_by_username_and_password(const std::string &usr, const std::string &passwd);
    static int user_count();

    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] std::string get_username() const { return username; }
    [[nodiscard]] std::string get_password() const { return password; }
    [[nodiscard]] std::string get_role() const { return role; }
    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] std::string get_lastname() const { return lastname; }
    [[nodiscard]] std::string get_date_joined() const { return date_joined; }

    [[nodiscard]] bool is_logged_in() const { return _is_logged_in; };
    void set_is_logged_in(bool arg) { _is_logged_in = arg; }

private:
    int id;
    std::string username;
    std::string password;
    std::string role;
    std::string name;
    std::string lastname;
    std::string date_joined;
    bool _is_logged_in = false;
};

#endif // USER_H
