#include "addsaleswindow.h"
#include "ui_addsaleswindow.h"

AddSalesWindow::AddSalesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSalesWindow)
{
    ui->setupUi(this);
}

AddSalesWindow::~AddSalesWindow()
{
    delete ui;
}

void AddSalesWindow::on_addButton_clicked()
{
    // Add functionality to add a sale
}

void AddSalesWindow::on_editButton_clicked()
{
    // Add functionality to edit a sale
}

void AddSalesWindow::on_deleteButton_clicked()
{
    // Add functionality to delete a sale
}

void AddSalesWindow::on_viewButton_clicked()
{
    // Add functionality to view sale details
}
