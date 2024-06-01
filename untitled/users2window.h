#ifndef USERS2WINDOW_H
#define USERS2WINDOW_H

#include <QMainWindow>

namespace Ui {
class Users2Window;
}

class Users2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Users2Window(QWidget *parent = nullptr);
    ~Users2Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Users2Window *ui;
};

#endif // USERS2WINDOW_H
