#include "res.h"
#include "ui_res.h"
#include "reservation.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QtPrintSupport>
#include<QtCharts> //stat
#include<QChartView> //stat
#include<QPieSeries> //stat
#include<QPieSlice> //stat
#include "connection.h"

res::res(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::res)
{
    ui->setupUi(this);
}

res::~res()
{
    delete ui;
}

void res::on_pushButton_res_2_clicked()
{
    QPrinter printer;
        printer.setPrinterName("diserter printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tableView_reservation->render(&printer);
}

void res::on_sendBtn_3_clicked()
{
    connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn_3, SIGNAL(clicked()),this, SLOT(close()));
    //connect(ui->browseBtn_4, SIGNAL(clicked()), this, SLOT(browse()));
}



void res::on_pushButton_chercherBillet_clicked()
{
    QString Numero= ui->lineEdit_CherBillet->text() ;

    ui->tableView_reservation->setModel(tempreservation.chercherBillet(Numero));
}




void res::on_buttonBox_ReservationA_accepted()
{
    QString Numero = ui->lineEdit_Numero_A->text();
    QDate Dat = ui->dateEdit_A->date();
    QTime Heure = ui->timeEdit_A->time();
    QString Destination = ui->lineEdit_Destination_A->text();
    QString Hotel = ui->lineEdit_Hotel_A->text();
    int Prix = ui->lineEdit_Prix_A->text().toInt();


Reservation R(Numero,Dat,Heure,Destination,Hotel,Prix);
    bool test = R.ajouterReservation();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_reservation->setModel(tempreservation.afficherReservation());
        ui->lineEdit_Numero_A->clear();
        ui->dateEdit_A->clear();
        ui->timeEdit_A->clear();
        ui->lineEdit_Destination_A->clear();
        ui->lineEdit_Hotel_A->clear();
        ui->lineEdit_Prix_A->clear();




    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Ajout non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel); }
}




void res::on_buttonBox_ModifierReservation_accepted()
{
    QString Numero = ui->lineEdit_Numero_M->text();
    QDate Dat = ui->dateEdit_M->date();
    QTime Heure = ui->timeEdit_M->time();
    QString Destination = ui->lineEdit_Destination_M->text();
    QString Hotel = ui->lineEdit_Hotel_M->text();
    int Prix = ui->lineEdit_Prix_M->text().toInt();




    Reservation R(Numero,Dat,Heure,Destination,Hotel,Prix);
     bool test=R.modifierReservation(Numero,Dat,Heure,Destination,Hotel,Prix);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier une Reservation!"),
                                 QObject::tr("  Reservation modifié ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_reservation->setModel(tempreservation.afficherReservation());
        ui->lineEdit_Numero_M->clear();
        ui->dateEdit_M->clear();
        ui->timeEdit_M->clear();
        ui->lineEdit_Destination_M->clear();
        ui->lineEdit_Hotel_M->clear();
        ui->lineEdit_Prix_M->clear();
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier une Reservation"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




void res::on_buttonBox_SupRes_accepted()
{
    QString Billet = ui->lineEdit_Billet_S->text();
    Reservation temp;

    bool test=temp.supprimerReservation(Billet);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Suppresion non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}
}









void res::on_pushPlay_clicked()
{
    player = new QMediaPlayer();
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);

    if (ui->RadB_Pack1->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/asus/Downloads/Istanbul, Turkey 8K Video Ultra HD 120 FPS in Drone View.mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }
    if (ui->RadB_Pack2->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/asus/Downloads/Dubai, United Arab Emirates 🇦🇪 - by drone [4K].mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }
    if (ui->RadB_Pack3->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/asus/Downloads/Paris in 4K.mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }

    vw->show();
    player->play();
}




void res::on_pushStop_clicked()
{
    player->stop();
    vw->close();
}




void res::on_pushButton_listres_clicked()
{
    ui->tableView_reservation->setModel(tempreservation.afficherReservation());
}
