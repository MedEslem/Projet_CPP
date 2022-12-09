#ifndef TRANSPORT_H
#define TRANSPORT_H

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
#include<QMessageBox>
class Transport
{QString MAT,ETAT,TYPE,NBV;

public:
    Transport(){};
    Transport(QString,QString,QString,QString);
    //getters
    QString getmat(){return  MAT;}
    QString getetat(){return  ETAT;}
    QString gettype(){return  TYPE;}
    QString getnbV(){return NBV;}
    //setters
    /*void setmat(QString);
    void setetat(QString);
    void settype(QString);
    void setnbV(int);*/
    //fonction
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel *rechercher(const QString &);
    QSqlQueryModel *trierMat();
    QSqlQueryModel *triernbV();
    QSqlQueryModel *trierType();
    /*QString add_combo() const;
    QString line_mat() const ;
    QString line_etat() const ;

    int num() const;
    void fill_form(int);*/
};

#endif // TRANSPORT_H
