#ifndef PRODUCTS2WINDOW_H
#define PRODUCTS2WINDOW_H

#include <QMainWindow>
#include "saleswindow.h"
#include "reports2window.h"
#include "clients2window.h"
#include "users2window.h"

namespace Ui {
class Products2Window;
}

class Products2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Products2Window(QWidget *parent = nullptr);
    ~Products2Window();

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
    Ui::Products2Window *ui;
    SalesWindow *salesWindow;
    Reports2Window *reportsWindow;
    Clients2Window *clientsWindow;
    Users2Window *usersWindow;
};

#endif // PRODUCTS2WINDOW_H
