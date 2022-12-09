#include "sponsor.h"
#include <QSqlQuery>
#include <QDate>
#include <QObject>
SPONSOR::SPONSOR()
{
////////
}
SPONSOR::SPONSOR(QString nom,QDate date_debut,QDate date_fin,int montant,int num_tel,QString ad_mail)
{this->nom=nom;this->date_debut=date_debut;this->date_fin=date_fin;this->montant=montant;this->num_tel=num_tel;this->ad_mail=ad_mail;}
QString SPONSOR::get_nom(){return nom;}
QDate SPONSOR::get_date_debut(){return date_debut;}
QDate SPONSOR::get_date_fin(){return date_fin;}
int SPONSOR::get_montant(){return montant;}
int SPONSOR::get_num_tel(){return num_tel;}
QString SPONSOR::get_ad_mail(){return ad_mail;}

void SPONSOR::set_nom(QString nom){this->nom=nom;}
void SPONSOR::set_date_debut(QDate date_debut){this->date_debut=date_debut;}
void SPONSOR::set_date_fin(QDate date_fin){this->date_fin=date_fin;}
void SPONSOR::set_montant(int montant){this->montant=montant;}
void SPONSOR::set_num_tel(int num_tel){this->num_tel=num_tel;}
void SPONSOR::set_ad_mail(QString ad_mail){this->ad_mail=ad_mail;}

bool SPONSOR::ajouter()
{
    bool test=false;
    QSqlQuery query;
    QString montant_string= QString::number(montant);
    QString num_tel_string= QString::number(num_tel);
    query.prepare("INSERT INTO SPONSOR (nom, date_debut, date_fin, montant, num_tel, ad_mail) "
                       "VALUES (:nom, :date_debut, :date_fin, :montant, :num_tel, :ad_mail)");
    query.bindValue(0,nom);
    query.bindValue(1,date_debut);
    query.bindValue(2,date_fin);
    query.bindValue(3,montant_string);
    query.bindValue(4,num_tel_string);
    query.bindValue(5,ad_mail);
    query.exec();
return test;
}
QSqlQueryModel* SPONSOR::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM SPONSOR");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FIN"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO_DE_TEL"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));

    return model;
}
bool SPONSOR::supprimer(int num_tel)
{
    QSqlQuery query;
    query.prepare(" Delete from SPONSOR where num_tel=:num_tel");
    QString num_tel_string= QString::number(num_tel);
    query.bindValue(0 ,num_tel_string);

    query.exec();
}

bool SPONSOR::modifier(QString nom, QDate date_debut, QDate date_fin, int montant, int num_tel, QString ad_mail)
{
    QSqlQuery query;

    QString montant_string= QString::number(montant);
    QString num_tel_string= QString::number(num_tel);
    query.prepare("UPDATE SPONSOR SET  nom= :nom, date_debut= :date_debut, date_fin= :date_fin, montant= :montant , num_tel= :num_tel, ad_mail= :ad_mail " " WHERE  nom = '"+nom+"' ");
    query.bindValue(":nom", nom);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":montant", montant_string);
    query.bindValue(":num_tel", num_tel_string);
    query.bindValue(":ad_mail", ad_mail);

    return    query.exec();
}

