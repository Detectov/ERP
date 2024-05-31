#ifndef ADDSALESWINDOW_H
#define ADDSALESWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AddSalesWindow; }
QT_END_NAMESPACE

class AddSalesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSalesWindow(QWidget *parent = nullptr);
    ~AddSalesWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_viewButton_clicked();

private:
    Ui::AddSalesWindow *ui;
};

#endif // ADDSALESWINDOW_H
