#include "users.h"
#include "./ui_users.h"
#include "qwidget.h"

Users::Users(QWidget *parent)
    : QUsers(parent)
    , ui(new Ui::Users)
{
    ui->setupUi(this);
    ptrProducts = new Products();
    ptrClients = new Clients();
    ptrReports = new Reports();
    ptrSales = new Sales();
    ptrUsers = new Users();
}

mainwindow::~mainwindow()
{
    delete ptrProducts;
    delete ptrClients;
    delete ptrReports;
    delete ptrSales;
    delete ptrUsers;
    delete ui;
}
