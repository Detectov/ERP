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

private:
    Ui::Clients2Window *ui;
};

#endif // CLIENTS2WINDOW_H
