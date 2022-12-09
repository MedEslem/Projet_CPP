#ifndef SPONS_H
#define SPONS_H
#include "sponsor.h"

#include <QDialog>

namespace Ui {
class spons;
}

class spons : public QDialog
{
    Q_OBJECT

public:
    explicit spons(QWidget *parent = nullptr);
    ~spons();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_Push_button_supprimer_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_export_excel_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::spons *ui;
    SPONSOR S;
};

#endif // SPONS_H
