#include "employe.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "arduino.h"

Employe::Employe(QString CIN,QString NOM,QString PRENOM,QString ROLE,QString DIPLOME,QString DUREE_DE_TRAVAIL,QString DATE_DE_NAISSANCE,QString CONGE,QString NUM_TELEPHONE)
{this->CIN=CIN;
  this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->ROLE=ROLE;
    this->DIPLOME=DIPLOME;
    this->DUREE_DE_TRAVAIL=DUREE_DE_TRAVAIL;
    this->DATE_DE_NAISSANCE=DATE_DE_NAISSANCE;
    this->NUM_TELEPHONE=NUM_TELEPHONE;
    this->CONGE=CONGE;

}
bool Employe::ajouter()
{QSqlQuery query;
  /* QString res=QString::number(CIN);
    QString T=QString::number(num_telephone);
    QString Con=QString::number(conge);*/
 query.prepare("insert into EMPLOYE(CIN,NOM,PRENOM,ROLE,DIPLOME,DUREE_DE_TRAVAIL,DATE_DE_NAISSANCE,NUM_TELEPHONE,CONGE)"
                  "values(:CIN,:NOM,:PRENOM,:ROLE,:DIPLOME,:DUREE_DE_TRAVAIL,:DATE_DE_NAISSANCE,:NUM_TELEPHONE,:CONGE)");
query.bindValue(":CIN",CIN);
query.bindValue(":NOM",NOM);
query.bindValue(":PRENOM",PRENOM);
query.bindValue(":ROLE",ROLE);
query.bindValue(":DIPLOME",DIPLOME);
query.bindValue(":DUREE_DE_TRAVAIL",DUREE_DE_TRAVAIL);
query.bindValue(":DATE_DE_NAISSANCE",DATE_DE_NAISSANCE);
query.bindValue(":NUM_TELEPHONE",NUM_TELEPHONE);
query.bindValue(":CONGE",CONGE);
return query.exec();



}
bool Employe::supprimerC(QString cin)
{QSqlQuery query;
    //QString res=QString::number(cin);
    query.prepare("Delete from employe where CIN= :cin");
    query.bindValue(0,cin);
    return  query.exec();
}
bool Employe::supprimerT(QString tel)
{QSqlQuery query;
    //QString res=QString::number(cin);
    query.prepare("Delete from employe where num_telephone= :tel");
    query.bindValue(0,tel);
    return  query.exec();
}

QSqlQueryModel *Employe::afficher()
{QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Diplome"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DUREE_DE_TRAVAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("NUM_TELEPHONE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("CONGE"));

    return  model;
}
bool Employe::modifier()
{QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET CIN=:CIN,NOM=:NOM,PRENOM=:PRENOM,ROLE=:ROLE,DIPLOME=:DIPLOME,DUREE_DE_TRAVAIL=:DUREE_DE_TRAVAIL,DATE_DE_NAISSANCE=:DATE_DE_NAISSANCE,NUM_TELEPHONE=:NUM_TELEPHONE,CONGE=:CONGE WHERE CIN=:CIN");
    query.bindValue(":CIN",CIN);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":ROLE",ROLE);
    query.bindValue(":DIPLOME",DIPLOME);
    query.bindValue(":DUREE_DE_TRAVAIL",DUREE_DE_TRAVAIL);
    query.bindValue(":DATE_DE_NAISSANCE",DATE_DE_NAISSANCE);
    query.bindValue(":NUM_TELEPHONE",NUM_TELEPHONE);
    query.bindValue(":CONGE",CONGE);
    return query.exec();

}


QSqlQueryModel *Employe::rechercherC(const QString &cin)
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employe where (cin LIKE '"+cin+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ROLE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIPLOME"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DUREE_DE_TRAVAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("NUM_TELEPHONE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("CONGE"));

    return model;

}
QSqlQueryModel *Employe::rechercherT(const QString &tel)
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employe where (num_telephone LIKE '"+tel+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ROLE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIPLOME"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DUREE_DE_TRAVAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("NUM_TELEPHONE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("CONGE"));

    return model;

}
//trie alphabetique
QSqlQueryModel *Employe::trierN()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM employe order by NOM asc");

  return model;
}
QSqlQueryModel *Employe::trierCIN()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM employe order by CIN asc");

  return model;
}
QSqlQueryModel *Employe::trierConge()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM employe order by CONGE asc");

  return model;
}
void Employe::setcin(QString R)
{
    CIN=R;
}
void Employe::setnom(QString R)
{
    NOM=R;
}
