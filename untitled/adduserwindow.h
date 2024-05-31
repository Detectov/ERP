#ifndef ADDUSERWINDOW_H
#define ADDUSERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AddUserWindow; }
QT_END_NAMESPACE

class AddUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddUserWindow(QWidget *parent = nullptr);
    ~AddUserWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_viewButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddUserWindow *ui;
};

#endif // ADDUSERWINDOW_H
