#include "products2window.h"
#include "ui_products2window.h"
#include <QMessageBox>

Products2Window::Products2Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Products2Window)
{
    ui->setupUi(this);

    // Inicializar ventanas secundarias
    salesWindow = new SalesWindow(this);
    reportsWindow = new Reports2Window(this);
    clientsWindow = new Clients2Window(this);
    usersWindow = new Users2Window(this);

    // Conectar botones a las ranuras
    connect(ui->pushButton, &QPushButton::clicked, this, &Products2Window::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Products2Window::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Products2Window::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Products2Window::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &Products2Window::on_pushButton_5_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &Products2Window::on_pushButton_10_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &Products2Window::on_pushButton_9_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &Products2Window::on_pushButton_8_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &Products2Window::on_pushButton_7_clicked);
}

Products2Window::~Products2Window()
{
    delete ui;
    delete salesWindow;
    delete reportsWindow;
    delete clientsWindow;
    delete usersWindow;
}

void Products2Window::on_pushButton_clicked()
{
    // Logic to open Products2Window
    this->show();
}

void Products2Window::on_pushButton_2_clicked()
{
    // Open Sales2Window
    salesWindow->show();
    this->close();
}

void Products2Window::on_pushButton_3_clicked()
{
    // Open Reports2Window
    reportsWindow->show();
    this->close();
}

void Products2Window::on_pushButton_4_clicked()
{
    // Open Clients2Window
    clientsWindow->show();
    this->close();
}

void Products2Window::on_pushButton_5_clicked()
{
    // Open Users2Window
    usersWindow->show();
    this->close();
}

void Products2Window::on_pushButton_10_clicked()
{
    // Lógica para el botón de Eliminar Producto
    QMessageBox::information(this, "Delete Product", "Delete Product button clicked");
}

void Products2Window::on_pushButton_9_clicked()
{
    // Lógica para el botón de Agregar Producto
    QMessageBox::information(this, "Add Product", "Add Product button clicked");
}

void Products2Window::on_pushButton_8_clicked()
{
    // Lógica para el botón de Editar Producto
    QMessageBox::information(this, "Edit Product", "Edit Product button clicked");
}

void Products2Window::on_pushButton_7_clicked()
{
    // Lógica para el botón de Ver Producto
    QMessageBox::information(this, "View Product", "View Product button clicked");
}
