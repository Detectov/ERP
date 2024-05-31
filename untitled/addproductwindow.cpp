#include "addproductwindow.h"
#include "ui_addproductwindow.h"

AddProductWindow::AddProductWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddProductWindow)
{
    ui->setupUi(this);
}

AddProductWindow::~AddProductWindow()
{
    delete ui;
}

void AddProductWindow::on_addButton_clicked()
{
    // Add functionality to add a product
}

void AddProductWindow::on_editButton_clicked()
{
    // Add functionality to edit a product
}

void AddProductWindow::on_deleteButton_clicked()
{
    // Add functionality to delete a product
}

void AddProductWindow::on_viewButton_clicked()
{
    // Add functionality to view product details
}
