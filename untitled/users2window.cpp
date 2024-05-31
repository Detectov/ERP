#include "users2window.h"
#include "ui_users2window.h"

Users2Window::Users2Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Users2Window)
{
    ui->setupUi(this);
}

Users2Window::~Users2Window()
{
    delete ui;
}
