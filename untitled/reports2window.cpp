#include "reports2window.h"
#include "ui_reports2window.h"

Reports2Window::Reports2Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reports2Window)
{
    ui->setupUi(this);
}

Reports2Window::~Reports2Window()
{
    delete ui;
}
