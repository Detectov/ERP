//
// Created by Mauricio on 29/05/24.
//

#ifndef MVC_TEMPLATE_AUTHENTICATION_H
#define MVC_TEMPLATE_AUTHENTICATION_H

#include <string>
#include "../Models/include/User.h"

class Authentication {
public:
    static User login(const std::string &username, const std::string &password);

};


#endif //MVC_TEMPLATE_AUTHENTICATION_H
