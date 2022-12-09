#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trans.h"
#include "ui_trans.h"
#include "res.h"
#include "ui_res.h"
#include<QMessageBox>
#include "spons.h"
#include "ui_spons.h"
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
{MainWindow *M;
    Trans *Ts;
    res *R;
    spons *S;


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
     else if (id=="123456789" && P=="Happyy")
     { QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("welcome(gestion Transport)\n"
                                            "Click OK to enter."), QMessageBox::Ok);

                    Ts =new Trans(this);
                    Ts->show();

     }
      else if (id=="123456789" && P=="Happyyy")
     { QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("welcome(gestion reservation)\n"
                                            "Click OK to enter."), QMessageBox::Ok);

                    R =new res(this);
                    R->show();

     }
     else if (id=="123456789" && P=="Happyyyy")
     { QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("welcome(gestion sponsor)\n"
                                            "Click OK to enter."), QMessageBox::Ok);

                    S =new spons(this);
                    S->show();

     }
else
     {
QMessageBox::critical(nullptr, QObject::tr("database is open"),
            QObject::tr("wrong admin or password.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
     }
}

void login::on_pushButton_2_clicked()
{QMessageBox::information(nullptr, QObject::tr("mot de passe oubilier"),
                          QObject::tr("gestion employe :Happy\n"
                                      "gestion transport :Happyy\n"
                                      "gestion reservation  :Happyyy\n"
                                      "gestion sponsor  :Happyyyy\n"
                                      "Click OK to enter."), QMessageBox::Ok);

}
