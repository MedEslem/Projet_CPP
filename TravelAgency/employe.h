#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
class Employe
{QString NOM,PRENOM,ROLE,DIPLOME,DUREE_DE_TRAVAIL,DATE_DE_NAISSANCE,NUM_TELEPHONE,CIN,CONGE;
public:
    //constructeur
    Employe(){}
    Employe(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    //Getters

    QString getNom(){return NOM;}
    QString getPrenom(){return PRENOM;}
    QString getRole(){return ROLE;}
   QString getDuree(){return DUREE_DE_TRAVAIL;}
   QString getDaten(){return DATE_DE_NAISSANCE;}
   QString getDiplome(){return DIPLOME;}
    QString getConge(){return CONGE;}
   QString getCIN(){return CIN;}
   QString getNumT(){return NUM_TELEPHONE;}
   //setters
   void setcin(QString);
   void setnom(QString);
   //Fonctionssss
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimerC(QString);
   bool supprimerT(QString);
   bool modifier();
   QSqlQueryModel * rechercherC(const QString &);
    QSqlQueryModel * rechercherT(const QString &);
   QSqlQueryModel * trierN();
   QSqlQueryModel * trierCIN();
   QSqlQueryModel * trierConge();
   void pdf();


};

#endif // EMPLOYE_H
