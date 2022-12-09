#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    //MainWindow *M;
};

#endif // LOGIN_H
