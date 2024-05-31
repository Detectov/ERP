#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Products.h"
#include "clients.h"
#include "reports.h"
#include "sales.h"
#include "users.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
    Products *ptrProducts;
    Clients *ptrClients;
    Reports *ptrReports;
    Sales *ptrSales;
    Users *ptrUsers;

private slots:
    void on_loginButton_clicked();

    void on_passwordInput_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
