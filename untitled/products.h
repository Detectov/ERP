#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QMainWindow>
#include "clients.h"
#include "reports.h"
#include "sales.h"
#include "users.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Products;
}
QT_END_NAMESPACE

class Products : public QMainWindow
{
    Q_OBJECT

public:
    Products(QWidget *parent = nullptr);
    ~Products();
    Clients *ptrClients;
    Reports *ptrReports;
    Sales *ptrSales;
    Users *ptrUsers;

private slots:
    void on_loginButton_clicked();

private:
    Ui::Products *ui;
};
#endif // MAINWINDOW_H
