//
// Created by Daniel Moukarzel on 31/05/24.
//

#ifndef MVC_TEMPLATE_PRESENTATION_H
#define MVC_TEMPLATE_PRESENTATION_H

#include <string>
#include "DatabaseManager.h"
#include <iostream>


class Presentation {
public:
    Presentation();
    Presentation(std::string name);
    static void create_presentation_table();
    static Presentation create_presentation(std::string name);

    // CRUD operations
    static void insert_presentation(Presentation &presentation);
    static Presentation read_presentation(Presentation &presentation);
    static Presentation read_presentation(int id);
    static void delete_presentation(Presentation &presentation);

    // Getters
    [[nodiscard]] int get_id() const { return id; }
    [[nodiscard]] std::string get_name() const { return name; }

    // Setters
    void set_id(int id) { Presentation::id = id; }
    void set_name(const std::string &name) { Presentation::name = name; }

    // other operations
    static Presentation get_presentation_by_name(const std::string &name);
private:
    int id;
    std::string name;
};


#endif //MVC_TEMPLATE_PRESENTATION_H
