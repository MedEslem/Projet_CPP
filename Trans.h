#ifndef TRANS_H
#define TRANS_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class Trans
{
public:


    Trans();
    Trans(int,QString,QString,QString);


    bool ajouter();
    bool modifier(int);
     QSqlQueryModel * afficher();
      bool supprimer(int);

      int num;
      QString  line_etat, combo, line_mat;


};

#endif // TRANS_H
