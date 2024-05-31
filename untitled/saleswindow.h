#ifndef SALESWINDOW_H
#define SALESWINDOW_H

#include <QMainWindow>

namespace Ui {
class SalesWindow;
}

class SalesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalesWindow(QWidget *parent = nullptr);
    ~SalesWindow();

private:
    Ui::SalesWindow *ui;
};

#endif // SALESWINDOW_H
