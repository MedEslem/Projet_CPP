#include "transport.h"
#include "connection.h"


Transport::Transport(QString MAT,QString ETAT,QString TYPE,QString NBV)
{this->MAT=MAT;
this->ETAT=ETAT;
    this->TYPE=TYPE;
    this->NBV=NBV;
}
bool Transport::ajouter()
{QSqlQuery query;
    query.prepare("insert into TRANSPORT(MAT,NBV,TYPE,ETAT)""values(:MAT,:NBV,:TYPE,:ETAT)");
   query.bindValue(":MAT",MAT);
   query.bindValue(":NBV",NBV);
   query.bindValue(":TYPE",TYPE);
   query.bindValue(":ETAT",ETAT);
   return query.exec();
}
bool Transport::supprimer(QString M)
{QSqlQuery query;
    query.prepare("Delete from transport where MAT= :M");
    query.bindValue(0,M);
    return  query.exec();
}
QSqlQueryModel *Transport::afficher()
{QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from transport");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nombre de voyageurs"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));
return  model;
}
bool Transport::modifier()
{QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MAT=:Mat,nbv=:nbV,type=:type,etat=:etat WHERE mat=:Mat");
    query.bindValue(":matricule",MAT);
    query.bindValue(":nb_de_voyageurs",NBV);
    query.bindValue(":type",TYPE);
    query.bindValue(":etat",ETAT);

     return query.exec();
}
QSqlQueryModel *Transport::rechercher(const QString &M)
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from transport where (MAT LIKE '"+M+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NombreDeVouageurs"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));
    return model;

}
QSqlQueryModel *Transport::trierMat()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM transport order by MAT asc");

     return model;

}
QSqlQueryModel *Transport::triernbV()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM transport order by NBV asc");

     return model;

}

QSqlQueryModel *Transport::trierType()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM transport order by TYPE asc");

     return model;

}


