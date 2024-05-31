#ifndef PRODUCTS2WINDOW_H
#define PRODUCTS2WINDOW_H

#include <QMainWindow>

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

private:
    Ui::Products2Window *ui;
};

#endif // PRODUCTS2WINDOW_H
