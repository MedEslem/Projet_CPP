#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPort"
#include "connexion.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connexion c;
     c.createconnect();
    //affichage contenu base
    show_tables();

    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
int ret=A.connect_arduino();

switch (ret)
{case(0):qDebug()<<"Arduino is available  and connected to :"<<A.getarduino_port_name();
break;
case(1):qDebug()<<"Arduino is available  and not connected to :"<<A.getarduino_port_name();
        break;
case(-1):qDebug()<<"Arduino is not available :";
}
QObject::connect(A.getserial(),SIGNAL(ReadyRead()),this,SLOT(update_label()));
}
MainWindow::~MainWindow()
{
    delete ui;



     //affichage contenu de la base
     show_tables();

}

//CRUD

//ajout
void MainWindow::on_Ajout_clicked()
{//creation instance
    CRUD cr(this);

    //ouvrir dialog
    int res=cr.exec();
    if (res == QDialog::Rejected )
        return;

  //recuperation des donnees
    int i=cr.num();
    QString s1=cr.add_combo();
    QString s2=cr.line_mat();
    QString s3=cr.line_etat();

    //ajout
    Trans tr(i,s1,s2,s3);
    tr.ajouter();

//refresh du tableau (affichage)
 show_tables();

}



//affichage + metier tri
void MainWindow::show_tables(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableau->setModel(proxy);

}

//recuperer l'entier (integer) on l'appelle selected
void MainWindow::on_tableau_clicked(const QModelIndex &index)
{
     selected=ui->tableau->model()->data(index).toInt();
}

//supression
void MainWindow::on_supp_clicked()
{
    Trans tr;
  tr.supprimer(selected);

 //refresh du tableau (affichage)
   show_tables();
}

//modification
void MainWindow::on_tableau_doubleClicked()
{

    CRUD cr(this);

  cr.fill_form(selected);
  int res=cr.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
    QString s1=cr.add_combo();
    QString s2=cr.line_mat();
    QString s3=cr.line_etat();

    //mofication
    Trans tr(selected,s1,s2,s3);
    tr.modifier(selected);



  //refresh du tableau (affichage)
   show_tables();

}

//METIER

//recherche dynamique
void MainWindow::on_recherche_textChanged(const QString &arg1)
{
proxy->setFilterFixedString(arg1);
}


//mailing
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("karray.Slim@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("karray.Slim@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("karray.Slim@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

//stat
void MainWindow::on_stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();

}

//pdf : vous trouver le fichier dans le dossier build
void MainWindow::on_pdf_clicked()
{

    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableau->model()->rowCount();
                const int columnCount =ui->tableau->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des Evenements</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableau->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableau->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableau->isColumnHidden(column)) {
                                   QString data = ui->tableau->model()->data(ui->tableau->model()->index(row, column)).toString().simplified();
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


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("mypdffile.pdf");
        document->print(&printer);

}


void MainWindow::on_Arduino_clicked()
{
  A.write_to_arduino("1");
}
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->labela->setText("Il y a une véhicule"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->labela->setText("Il n'y a pas du véhicule");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher OFF
}
