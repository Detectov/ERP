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

private:
    Ui::Users2Window *ui;
};

#endif // USERS2WINDOW_H
