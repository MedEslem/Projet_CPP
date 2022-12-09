#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include<QMessageBox>
#include<QMainWindow>
#include <QtDebug>
#include "connection.h"
#include<QPdfWriter>
#include<qpdfwriter.h>
#include<QDesktopServices>
#include <QPainter>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QTextDocument>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
        switch(ret)
        {case(0):qDebug()<<"arduino is available and connected:"<<A.getarduino_port_name();
        break;
        case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
            break;
           case(-1):qDebug()<<"arduino is not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    ui->tableView_4->setModel(Etmp.afficher());




}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_4_clicked()
{
    QString cin=ui->lineEdit_cin_4->text();
    QString nom=ui->lineEdit_nom_4->text();
    QString prenom=ui->lineEdit_prenom_4->text();
    QString num_telephone=ui->lineEdit_tel_4->text();
    QString diplome=ui->comboBox_diplome_4->currentText();
    QString role=ui->comboBox_role_4->currentText();
    QString duree_de_travail=ui->comboBox_duree_4->currentText();
    QString date_de_naissance=ui->lineEdit_daten_4->text();
    QString conge=ui->lineEdit_conge_4->text();
    Employe e(cin,nom,prenom,role,diplome,duree_de_travail,date_de_naissance,conge,num_telephone);
     bool test=e.ajouter();
   if(test)
   { A.write_to_arduino("1");
       ui->tableView_4->setModel(e.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);


   }
   else
         { A.write_to_arduino("0");
       QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                 QObject::tr("Ajout non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_supprimer_4_clicked()
{QString S=ui->comboBox_p_4->currentText();
    if(S=="CIN")
    {QString R=ui->lineEdit_cins_4->text();
        bool test=Etmp.supprimerC(R);
        if(test)
        {
            ui->tableView_4->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                      QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}
    else if(S=="TELEPHONE")
    {QString R=ui->lineEdit_cins_4->text();
        bool test=Etmp.supprimerT(R);
        if(test)
        {
            ui->tableView_4->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                      QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}


void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_58->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_58->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
void MainWindow::on_pushButton_modifier_4_clicked()
{QString cin=ui->lineEdit_cin_4->text();
    QString nom=ui->lineEdit_nom_4->text();
    QString prenom=ui->lineEdit_prenom_4->text();
   QString num_telephone=ui->lineEdit_tel_4->text();
    QString diplome=ui->comboBox_diplome_4->currentText();
    QString role=ui->comboBox_role_4->currentText();
    QString duree_de_travail=ui->comboBox_duree_4->currentText();
    QString date_de_naissance=ui->lineEdit_daten_4->text();
    QString conge=ui->lineEdit_conge_4->text();
     Employe e(cin,nom,prenom,diplome,role,duree_de_travail,date_de_naissance,conge,num_telephone);
     bool test=e.modifier();
     if(test)
     {
         ui->tableView_4->setModel(Etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
 }
     else
         QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                   QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_Rechercher_4_clicked()
{QString S=ui->comboBox_p_4->currentText();
    QString rech=ui->lineEdit_cins_4->text();
    if(S=="CIN")
     {if(rech!="")
     { ui->tableView_r_4->setModel(Etmp.rechercherC(rech)); }

     else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
     ui->tableView_4->setModel(Etmp.afficher());
     }
    }
    if(S=="TELEPHONE")
    {if(rech!="")
        { ui->tableView_r_4->setModel(Etmp.rechercherT(rech)); }

        else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
        ui->tableView_4->setModel(Etmp.afficher());
        }
}
}

void MainWindow::on_pushButton_Trier_4_clicked()
{QString T=ui->comboBox_trie_4->currentText();
    if(T=="CIN")
ui->tableView_4->setModel(Etmp.trierCIN());
    else if(T=="NOM")
    ui->tableView_4->setModel(Etmp.trierN());
    else if(T=="CONGE")
     ui->tableView_4->setModel(Etmp.trierConge());
}





void MainWindow::on_pushButton_valider_4_clicked()
{int nbR=0;
    if(ui->Q1R2->isChecked())
        nbR=nbR+1;
    if(ui->Q2R1->isChecked())
        nbR=nbR+1;
    if(ui->Q3R3->isChecked())
        nbR=nbR+1;
    if(ui->Q4R1->isChecked())
        nbR=nbR+1;
    if(ui->Q5R1->isChecked())
        nbR=nbR+1;
    if(nbR==5)
    QMessageBox::information(nullptr,QObject::tr("OK"),
                           QObject::tr("You succeeded\n""Click Cancel to exit."),QMessageBox::Cancel);
    else
      {  if(nbR<5)
        {QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("You failed sorry\n""Click Cancel to exit."),QMessageBox::Cancel);}

       }
}
//PDF
void MainWindow::on_pushButton_4_clicked()
{   QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_4->model()->rowCount();
    const int columnCount =ui->tableView_4->model()->columnCount();


    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("employe")
            <<  "</head>\n"
            "<body bgcolor=#4891FF link=#5000A0>\n"
                "<h1>Liste des Employes</h1>"

                "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_4->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
           for (int row = 0; row < rowCount; row++) {
               out << "<tr>";
               for (int column = 0; column < columnCount; column++) {
                   if (!ui->tableView_4->isColumnHidden(column)) {
                       QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                   }
               }
               out << "</tr>\n";
           }
           out <<  "</table>\n"
               "</body>\n"
               "</html>\n";



QTextDocument *document = new QTextDocument();
document->setHtml(strStream);


// QTextDocument *document;
//  document->setHtml(strStream);
//  document->setHtml(html);
QPrinter printer(QPrinter::PrinterResolution);
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setOutputFileName("EmployePDF.pdf");
document->print(&printer);


}

void MainWindow::on_stat_clicked()
{
    s = new Dialog_stats();

        s->setWindowTitle("statistique ComboBox");
        s->choix_bar();
        s->show();

}
