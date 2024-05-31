#ifndef USERS_H
#define USERS_H

#include <QMainWindow>
//#include "Products.h"
#include "clients.h"
#include "reports.h"
#include "sales.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Users;
}
QT_END_NAMESPACE

class Users : public QMainWindow
{
    Q_OBJECT

public:
    Users(QWidget *parent = nullptr);
    ~Users();
    //Products *ptrProducts;
    Clients *ptrClients;
    Reports *ptrReports;
    Sales *ptrSales;

private:
    Ui::Users *ui;
};

#endif // USERS_H
