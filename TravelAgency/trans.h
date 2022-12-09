#ifndef TRANS_H
#define TRANS_H

#include <QDialog>
#include "transport.h"



namespace Ui {
class Trans;
}

class Trans : public QDialog
{
    Q_OBJECT

public:
    explicit Trans(QWidget *parent = nullptr);
    ~Trans();

private slots:
    void on_Ajouter_clicked();

    void on_Modifier_clicked();

    void on_Trier_clicked();

    void on_stat_clicked();

    void on_pdf_clicked();

    void on_supprimer_clicked();

    void on_recherche_clicked();

private:
    Ui::Trans *ui;
    Transport T;

};

#endif // TRANS_H
