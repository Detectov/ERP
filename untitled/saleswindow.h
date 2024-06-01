#ifndef SALESWINDOW_H
#define SALESWINDOW_H

#include <QMainWindow>
#include "products2window.h"
#include "reports2window.h"
#include "clients2window.h"
#include "users2window.h"

namespace Ui {
class SalesWindow;
}

class SalesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalesWindow(QWidget *parent = nullptr);
    ~SalesWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::SalesWindow *ui;
    Products2Window *productsWindow;
    Reports2Window *reportsWindow;
    Clients2Window *clientsWindow;
    Users2Window *usersWindow;
};

#endif // SALESWINDOW_H
