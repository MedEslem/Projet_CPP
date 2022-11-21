#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;

}

void login::on_pushButton_clicked()
{
    QString id = ui->lineEdit_C->text();
     QString P = ui->lineEdit_mdp->text();
     if (id=="123456789" && P=="Happy")
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("welcome(gestion employe)\n"
                                 "Click OK to enter."), QMessageBox::Ok);

         M =new MainWindow(this);
         M->show();

     }

else
     {
QMessageBox::critical(nullptr, QObject::tr("database is open"),
            QObject::tr("wrong admin or password.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
     }
}
