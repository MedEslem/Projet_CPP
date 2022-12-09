#ifndef CRUD_H
#define CRUD_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class CRUD;
}

class CRUD : public QDialog
{
    Q_OBJECT

public:
    explicit CRUD(QWidget *parent = nullptr);
    ~CRUD();

    QString add_combo() const;
    QString line_mat() const ;
    QString line_etat() const ;

    int num() const;


    void fill_form(int);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CRUD *ui;
};

#endif // CRUD_H
