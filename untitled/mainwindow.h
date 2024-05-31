#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "products2window.h"
#include "clients2window.h"
#include "reports2window.h"
#include "saleswindow.h"
#include "users2window.h"

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
    Products2Window *ptrProducts2window;
    Clients2Window *ptrClients2window;
    Reports2Window *ptrReports2window;
    SalesWindow *ptrSaleswindow;
    Users2Window *ptrUsers2window;

private slots:
    void on_pushButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
