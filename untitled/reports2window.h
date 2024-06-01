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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Reports2Window *ui;
};

#endif // REPORTS2WINDOW_H
