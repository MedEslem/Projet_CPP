#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>

class Reservation
{
    QString Destination,Hotel;
    QString Numero;
    float Prix;
    QDate Dat;
    QTime Heure;

public:
    Reservation(){};
    Reservation(QString,QDate,QTime,QString,QString,float);

    QString getNumero(){return Numero;}
    QDate getDate(){return Dat;};
    QTime getHeure(){return Heure;}
    QString getDestination(){return Destination;}
    QString getHotel(){return Hotel;}
    float getPrix(){return Prix;}


    void setNumero (QString c ){Numero=c;}
    void setDate(QDate n){Dat=n;}
    void setPrenom(QTime p){Heure=p;}
    void setMail(QString m){ Destination=m;}
    void setTel(QString t){Hotel=t;}
    void setSalaire(float a){Prix=a;}


    bool ajouterReservation();
    QSqlQueryModel * afficherReservation();
    bool modifierReservation(QString,QDate, QTime, QString,QString,float);
    bool supprimerReservation(QString);
    QSqlQueryModel * chercherBillet(QString Numero);


};

#endif // RESERVATION_H
