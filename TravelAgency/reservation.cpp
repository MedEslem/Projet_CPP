#include "reservation.h"
Reservation::Reservation(QString Numero,QDate Dat,QTime Heure,QString Destination,QString Hotel,float Prix)
{
    this->Numero = Numero;
    this->Dat = Dat;
    this-> Heure= Heure;
    this->Destination= Destination;
   this->Hotel = Hotel;
    this->Prix=Prix;
}
bool Reservation::ajouterReservation()
{
    QSqlQuery query;

    query.prepare("insert into Reservation (Numero,Dat,Heure, Destination,Hotel,Prix)" "values (:Numero,:Dat,:Heure, :Destination,:Hotel,:Prix)");

    query.bindValue(":Numero",Numero);
    query.bindValue(":Dat",Dat);
    query.bindValue(":Heure",Heure);
    query.bindValue(":Destination",Destination);
    query.bindValue(":Hotel",Hotel);
    query.bindValue(":Prix",Prix);

    return query.exec();

}

QSqlQueryModel * Reservation::afficherReservation()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from Reservation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("HEURE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HOTEL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRIX"));


    return model;


}

bool Reservation::modifierReservation(QString, QDate, QTime, QString, QString, float)
{
    QSqlQuery query;
    query.prepare("UPDATE Reservation SET Numero= :Numero,Dat= :Dat,Heure= :Heure,Destination= :Destination,Hotel= :Hotel,Prix=:Prix Where Numero= :Numero");

    query.bindValue(":Numero",Numero);
    query.bindValue(":Dat",Dat);
    query.bindValue(":Heure",Heure);
    query.bindValue(":Destination",Destination);
    query.bindValue(":Hotel",Hotel);
    query.bindValue(":Prix",Prix);
    return query.exec();
}

bool Reservation::supprimerReservation(QString Numero)
{
    QSqlQuery query;
    query.prepare("Delete from Reservation where Numero= :Numero");
    query.bindValue(":Numero",Numero);
    return query.exec();
}
QSqlQueryModel * Reservation::chercherBillet(QString Numero)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from Reservation WHERE Numero = :Numero");
query.bindValue(":Numero",Numero);
query.exec();
model ->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("DAT"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("HEURE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("HOTEL"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRIX"));



return model;
}

