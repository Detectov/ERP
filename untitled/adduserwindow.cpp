#include "adduserwindow.h"
#include "ui_adduserwindow.h"

AddUserWindow::AddUserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddUserWindow)
{
    ui->setupUi(this);
}

AddUserWindow::~AddUserWindow()
{
    delete ui;
}

void AddUserWindow::on_addButton_clicked()
{
    // Add functionality to add a user
}

void AddUserWindow::on_editButton_clicked()
{
    // Add functionality to edit a user
}

void AddUserWindow::on_deleteButton_clicked()
{
    // Add functionality to delete a user
}

void AddUserWindow::on_viewButton_clicked()
{
    // Add functionality to view user details
}

void AddUserWindow::on_pushButton_clicked()
{

}

