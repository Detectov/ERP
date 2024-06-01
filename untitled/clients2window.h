#ifndef CLIENTS2WINDOW_H
#define CLIENTS2WINDOW_H

#include <QMainWindow>

namespace Ui {
class Clients2Window;
}

class Clients2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clients2Window(QWidget *parent = nullptr);
    ~Clients2Window();

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
    Ui::Clients2Window *ui;
};

#endif // CLIENTS2WINDOW_H
