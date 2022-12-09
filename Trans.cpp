#include "Trans.h"

Trans::Trans()
{

}



Trans::Trans(int i,QString s1 ,QString s2,QString s3 ){
   num=i;
   combo=s1;
   line_mat=s2;
   line_etat=s3;

}


bool Trans::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CRUD (V_INT,COMBO,LINE_MAT,LINE_ETAT) "
                        "VALUES (:num,:combo,:line_mat,:line_etat)");
    query.bindValue(":num", num);
    query.bindValue(":combo", combo);
    query.bindValue(":line_mat", line_mat);
    query.bindValue(":line_etat", line_etat);

    return    query.exec();

}

bool Trans::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE CRUD SET LINE_MAT= :line_mat ,COMBO= :combo,LINE_ETAT= :line_etat  "
                  ",where V_INT= :num");
    query.bindValue(":num", selected);
    query.bindValue(":combo", combo);
    query.bindValue(":line_mat", line_mat);
    query.bindValue(":line_etat", line_etat);

    return    query.exec();

}

 QSqlQueryModel * Trans::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM CRUD");

     return modal;

 }
  bool Trans::supprimer(int selected){

      QSqlQuery query;
      query.prepare("Delete from CRUD where V_INT = :sel ");
      query.bindValue(":sel", selected);
      return    query.exec();
}
