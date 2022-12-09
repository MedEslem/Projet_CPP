#include "trans.h"
#include "ui_trans.h"
#include "connection.h"
#include<QPdfWriter>
#include<qpdfwriter.h>
#include<QDesktopServices>
#include <QPainter>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QTextDocument>
#include <QIntValidator>
#include<QTextStream>

Trans::Trans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trans)
{
    ui->setupUi(this);
    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
ui->tableView->setModel(T.afficher());
}

Trans::~Trans()
{
    delete ui;
}

void Trans::on_Ajouter_clicked()
{
QString Mat=ui->line_Mat->text();
QString etat=ui->comboBox_etat->currentText();
QString type=ui->comboBox_type->currentText();
QString nbV=ui->line_nbV->text();
Transport t(Mat,etat,type,nbV);
bool test=t.ajouter();
if(test)
{
    ui->tableView->setModel(t.afficher());
   QMessageBox::information(nullptr,QObject::tr("OK"),
                          QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);


}
else
      {
    QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                              QObject::tr("Ajout non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}
}



void Trans::on_Modifier_clicked()
{QString Mat=ui->line_Mat->text();
    QString etat=ui->comboBox_etat->currentText();
    QString type=ui->comboBox_type->currentText();
    QString nbV=ui->line_nbV->text();
    Transport t(Mat,etat,type,nbV);
    bool test=t.modifier();
    if(test)
    {
        ui->tableView->setModel(t.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                              QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                  QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);


}

void Trans::on_Trier_clicked()
{QString S=ui->comboBox_trie->currentText();
    if(S=="MATRICULE")
ui->tableView->setModel(T.trierMat());
    else if(S=="NB VOYAGEURS")
    ui->tableView->setModel(T.triernbV());
    else if(S=="TYPE")
     ui->tableView->setModel(T.trierType());

}

void Trans::on_stat_clicked()
{

}

void Trans::on_pdf_clicked()
{QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount =ui->tableView->model()->columnCount();


    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("Moyens de Transport")
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
printer.setOutputFileName("TransportPDf.pdf");
document->print(&printer);



}

void Trans::on_supprimer_clicked()
{QString S=ui->lineEdit_r->text();
    bool test=T.supprimer(S);
    if(test)
    {
        ui->tableView->setModel(T.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                              QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr,QObject::tr(" NOT OK"),
                                  QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);


}

void Trans::on_recherche_clicked()
{QString rech=ui->lineEdit_r->text();
    if(rech!="")
         { ui->tableView_r->setModel(T.rechercher(rech)); }

         else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
         ui->tableView->setModel(T.afficher());
         }
}
