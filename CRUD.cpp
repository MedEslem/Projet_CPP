#include "CRUD.h"
#include "ui_CRUD.h"
CRUD::CRUD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRUD)
{
    ui->setupUi(this);
}

CRUD::~CRUD()
{
    delete ui;
}


//config ok et cancel
void CRUD::on_buttonBox_accepted()
{
accept();
}

void CRUD::on_buttonBox_rejected()
{
reject();
}


//recuperation des donnees du formulaire


QString CRUD::add_combo() const { //combo box

    return ui->comboBox->currentText();
}

QString CRUD::line_mat() const { //line edit_mat

    return ui->label_mat->text();
}
QString CRUD::line_etat() const { //line edit_etat

    return ui->line_etat->text();
}

int CRUD::num() const { //integer

    return ui->spinBox_Nb->value();
}


//remplissage des champs du formulaire a partir de la base

void CRUD::fill_form(int selected ) {
    QSqlQuery query;
    query.prepare("select * from CRUD where V_INT= :integer");
    query.bindValue(":integer", selected);
    query.exec();
    while(query.next()){
   ui->label_mat->setText(query.value(4).toString()); //line mat
  ui->line_etat->setText(query.value(3).toString()); //line etat
   ui->comboBox->setCurrentText(query.value(2).toString()); //combobox
    ui->spinBox_Nb->setValue(selected);// integer


    }

}

