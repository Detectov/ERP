#include "products2window.h"
#include "ui_products2window.h"

Products2Window::Products2Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Products2Window)
{
    ui->setupUi(this);
}

Products2Window::~Products2Window()
{
    delete ui;
}

void Products2Window::on_pushButton_clicked()
{

}

