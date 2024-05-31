#include "addclientwindow.h"
#include "ui_addclientwindow.h"

AddClientWindow::AddClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddClientWindow)
{
    ui->setupUi(this);
}

AddClientWindow::~AddClientWindow()
{
    delete ui;
}

void AddClientWindow::on_addButton_clicked()
{
    // Add functionality to add a client
}

void AddClientWindow::on_editButton_clicked()
{
    // Add functionality to edit a client
}

void AddClientWindow::on_deleteButton_clicked()
{
    // Add functionality to delete a client
}

void AddClientWindow::on_viewButton_clicked()
{
    // Add functionality to view client details
}
