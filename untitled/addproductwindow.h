#ifndef ADDPRODUCTWINDOW_H
#define ADDPRODUCTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AddProductWindow; }
QT_END_NAMESPACE

class AddProductWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddProductWindow(QWidget *parent = nullptr);
    ~AddProductWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_viewButton_clicked();

private:
    Ui::AddProductWindow *ui;
};

#endif // ADDPRODUCTWINDOW_H
