#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/untitled_autogen/include/ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
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

void mainwindow::on_loginButton_clicked()
{
    ptrProducts->show();
}

