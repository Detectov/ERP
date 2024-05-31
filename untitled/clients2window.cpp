#include "clients2window.h"
#include "ui_clients2window.h"

Clients2Window::Clients2Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clients2Window)
{
    ui->setupUi(this);
}

Clients2Window::~Clients2Window()
{
    delete ui;
}
