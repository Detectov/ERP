#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/untitled_autogen/include/ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    ptrProducts2window = new Products2Window();
    ptrClients2window = new Clients2Window();
    ptrReports2window = new Reports2Window();
    ptrSaleswindow = new SalesWindow();
    ptrUsers2window = new Users2Window();
}

mainwindow::~mainwindow()
{
    delete ptrProducts2window;
    delete ptrClients2window;
    delete ptrReports2window;
    delete ptrSaleswindow;
    delete ptrUsers2window;
    delete ui;
}


void mainwindow::on_loginButton_clicked()
{
    ptrProducts2window->show();
}
