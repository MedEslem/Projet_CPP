#ifndef SPONSOR_H
#define SPONSOR_H
#include<QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>

class SPONSOR
{
public:
    SPONSOR();
    SPONSOR(QString nom,QDate date_debut,QDate date_fin,int montant,int num_tel,QString ad_mail);
    void set_nom(QString);
    void set_date_debut(QDate);
    void set_date_fin(QDate);
    void set_montant(int);
    void set_num_tel(int);
    void set_ad_mail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(QString,QDate,QDate,int,int,QString);

    QString get_nom();
    QDate get_date_debut();
    QDate get_date_fin();
    int get_montant();
    int get_num_tel();
    QString get_ad_mail();


private:
    QString nom,ad_mail;
    int montant,num_tel;
    QDate date_debut,date_fin;


};

#endif // SPONSOR_H
