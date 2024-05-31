#ifndef REPORTS2WINDOW_H
#define REPORTS2WINDOW_H

#include <QMainWindow>

namespace Ui {
class Reports2Window;
}

class Reports2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reports2Window(QWidget *parent = nullptr);
    ~Reports2Window();

private:
    Ui::Reports2Window *ui;
};

#endif // REPORTS2WINDOW_H
