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
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_r->setModel(Etmp.rechercherC(QString R);
   /* int ret=A.connect_arduino();
    switch (ret)
    {case(0):qDebug()<<"arduino is available and connected:"<<A.getarduino_port_name();
    break;
    case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
       case(-1):qDebug()<<"arduino is not available";
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{QString cin=ui->lineEdit_cin->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString num_telephone=ui->lineEdit_tel->text();
    QString diplome=ui->comboBox_diplome->currentText();
    QString role=ui->comboBox_role->currentText();
    QString duree_de_travail=ui->comboBox_duree->currentText();
    QString date_de_naissance=ui->lineEdit_daten->text();
    QString conge=ui->lineEdit_conge->text();
    Employe e(cin,nom,prenom,role,diplome,duree_de_travail,date_de_naissance,conge,num_telephone);
     bool test=e.ajouter();
   if(test)
   {ui->tableView->setModel(e.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                 QObject::tr("Ajout non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{QString S=ui->comboBox_p->currentText();
    if(S=="CIN")
    {QString cin=ui->lineEdit_cins->text();
        bool test=Etmp.supprimerC(cin);
        if(test)
        {
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                      QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}
    else if(S=="TELEPHONE")
    {QString tel=ui->lineEdit_cins->text();
        bool test=Etmp.supprimerT(tel);
        if(test)
        {
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                      QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_modifier_clicked()
{QString cin=ui->lineEdit_cin->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
   QString num_telephone=ui->lineEdit_tel->text();
    QString diplome=ui->comboBox_diplome->currentText();
    QString role=ui->comboBox_role->currentText();
    QString duree_de_travail=ui->comboBox_duree->currentText();
    QString date_de_naissance=ui->lineEdit_daten->text();
    QString conge=ui->lineEdit_conge->text();
     Employe e(cin,nom,prenom,diplome,role,duree_de_travail,date_de_naissance,conge,num_telephone);
     bool test=e.modifier();
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
 }
     else
         QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                   QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_Rechercher_clicked()
{
   QString S=ui->comboBox_p->currentText();
   QString R=ui->lineEdit_cins->text();
   if(S=="CIN")
      ui->tableView_r->setModel(Etmp.rechercherC(R));
   else if(S=="TELEPHONE")
ui->tableView_r->setModel(Etmp.rechercherT(R));
}

void MainWindow::on_pushButton_Trier_clicked()
{QString T=ui->comboBox_trie->currentText();
    if(T=="CIN")
ui->tableView->setModel(Etmp.trierCIN());
    else if(T=="NOM")
    ui->tableView->setModel(Etmp.trierN());
    else if(T=="CONGE")
     ui->tableView->setModel(Etmp.trierConge());
}

/*void MainWindow::on_pdf_clicked()
{

         }
*/



void MainWindow::on_pushButton_valider_clicked()
{
    QMessageBox::information(nullptr,QObject::tr("OK"),
                           QObject::tr("Bienvenue dans notre agence\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{   QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount =ui->tableView->model()->columnCount();


    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("employe")
            <<  "</head>\n"
            "<body bgcolor=#4891FF link=#5000A0>\n"
                "<h1>Liste des Evenements</h1>"

                "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
           for (int row = 0; row < rowCount; row++) {
               out << "<tr>";
               for (int column = 0; column < columnCount; column++) {
                   if (!ui->tableView->isColumnHidden(column)) {
                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
printer.setOutputFileName("mypdffile.pdf");
document->print(&printer);


}
