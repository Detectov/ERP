#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AddClientWindow; }
QT_END_NAMESPACE

class AddClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddClientWindow(QWidget *parent = nullptr);
    ~AddClientWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_viewButton_clicked();

private:
    Ui::AddClientWindow *ui;
};

#endif // ADDCLIENTWINDOW_H
