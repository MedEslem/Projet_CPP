#include "spons.h"
#include "ui_spons.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QObject>
#include <QSqlQuery>
#include <exportexcelobject.h>

spons::spons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spons)
{
    ui->setupUi(this);

    ui->lineEdit_tel->setValidator(new QIntValidator(20000000, 99999999, this));
    ui->num_spon_supp->setValidator(new QIntValidator(20000000, 99999999, this));
    ui->lineEdit_montant->setValidator(new QIntValidator(1, 200000, this));
    ui->tab_sponsor->setModel(S.afficher());
    ui->lineEdit_num_mod->setValidator(new QIntValidator(20000000, 99999999, this));
    ui->lineEdit_montatnt_mod->setValidator(new QIntValidator(20000000, 99999999, this));
}

spons::~spons()
{
    delete ui;
}

void spons::on_pushButton_ajouter_clicked()
{
    QString nom=ui->lineEdit_nom->text();
    QDate date_debut=ui->dateEdit_debut->date();
    QDate date_fin=ui->dateEdit_fin->date();
    int montant=ui->lineEdit_montant->text().toInt();
    int num_tel=ui->lineEdit_tel->text().toInt();
    QString ad_mail=ui->lineEdit_mail->text();
    SPONSOR S(nom,date_debut,date_fin,montant,num_tel,ad_mail);

    QMessageBox msgBox;
    bool test=S.ajouter();
    if (test)
    {
     msgBox.setText("Ajout effectué");
     ui->tab_sponsor->setModel(S.afficher());
    }
    else
    {
        msgBox.setText("Ajout non effectué");
    ui->tab_sponsor->setModel(S.afficher());
    }
        msgBox.exec();
}



void spons::on_Push_button_supprimer_clicked()
{
    SPONSOR S1;
    S1.set_num_tel(ui->num_spon_supp->text().toInt());
    bool test=S1.supprimer(S1.get_num_tel());

    QMessageBox msg;
    if(test)
    {msg.setText("suppression avec succès");
     ui->tab_sponsor->setModel(S.afficher());

    }
                else
                msg.setText("echec de suppression");
    msg.exec();
}



void spons::on_pushButton_rechercher_clicked()
{
    QSqlQuery query;
        QString nom=ui->sponsor_recherche->text();
        query.prepare("SELECT nom,date_debut,date_fin,montant,num_tel,ad_mail FROM  SPONSOR where nom = :nom   ");
        query.bindValue(":nom",nom);
        QSqlQueryModel * model=new QSqlQueryModel();

        if(query.exec())
        {
            query.next();
            model->setQuery(query);
            ui->tab_recherche->setModel(model);
        }
}




void spons::on_pushButton_trier_clicked()
{
    {
        QSqlQuery query;
        query.prepare("SELECT nom,date_debut,date_fin,montant,num_tel,ad_mail FROM  SPONSOR ORDER BY montant ASC  ");
        QSqlQueryModel * model=new QSqlQueryModel();

        if(query.exec())
        {
            query.next();
            model->setQuery(query);
            ui->table_trie->setModel(model);
        }
}
}



void spons::on_pushButton_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    QMessageBox msgBox;
    const int rowCount = ui->tab_sponsor->model()->rowCount();
    const int columnCount =ui->tab_sponsor->model()->columnCount();
        out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("eleve")
        <<  "</head>\n"
        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
        "<h1>La liste des sponsors</h1>"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_sponsor->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_sponsor->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_sponsor->isColumnHidden(column)) {
                            QString data = ui->tab_sponsor->model()->data(ui->tab_sponsor->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));}}
                            out << "</tr>\n";}
                            out <<  "</table>\n"
                            "</body>\n"
                            "</html>\n";
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("La liste des sponsors.pdf");
            document->print(&printer);
            msgBox.setText("Le document PDF a été généré avec succés.");
            msgBox.exec();
}




void spons::on_pushButton_export_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tab_sponsor);

        //colums to export
        obj.addField(0, "nom", "char(20)");
        obj.addField(1, "date_debut", "char(20)");
        obj.addField(2, "date_fin", "char(20)");
        obj.addField(3, "montant", "char(20)");
        obj.addField(4, "num_tel", "char(20)");
        obj.addField(5, "ad_mail", "char(20)");

        int retVal = obj.export2Excel();
        if( retVal > 0){
            QMessageBox::information(this, tr("Done"),QString(tr("%1 sponsors exportés!")).arg(retVal));}

}




void spons::on_pushButton_modifier_clicked()
{
    QString nom=ui->lineEdit_nom_mod->text();
    QDate date_debut=ui->dateEdit_date_debut_mod->date();
    QDate date_fin=ui->dateEdit_date_fin_mod->date();
    int montant=ui->lineEdit_montatnt_mod->text().toInt();
    int num_tel=ui->lineEdit_num_mod->text().toInt();
    QString ad_mail=ui->lineEdit_ad_mail_mod->text();

     SPONSOR S(nom,date_debut,date_fin,montant,num_tel,ad_mail);

    QMessageBox msgBox;
    bool test=S.modifier(nom, date_debut, date_fin, montant, num_tel, ad_mail);
    if (test){
        ui->tab_sponsor->setModel(S.afficher());
        msgBox.setText("Modification avec succés");
        stat();}
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
        ui->tab_sponsor->setModel(S.afficher());
}
