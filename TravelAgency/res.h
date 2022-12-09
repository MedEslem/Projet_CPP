#ifndef RES_H
#define RES_H

#include <QMainWindow>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include "reservation.h"
#include <QFileDialog>
#include <QDialog>
#include<QtCharts> //stat
#include<QChartView> //stat
#include<QPieSeries> //stat
#include<QPieSlice> //stat
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>

namespace Ui {
class res;
}

class res : public QDialog
{
    Q_OBJECT

public:
    explicit res(QWidget *parent = nullptr);
    ~res();

private slots:
    void on_pushButton_res_2_clicked();

    void on_sendBtn_3_clicked();

    void on_pushButton_chercherBillet_clicked();

    void on_buttonBox_ReservationA_accepted();

    void on_buttonBox_ModifierReservation_accepted();

    void on_buttonBox_SupRes_accepted();

    //void on_radioButton_triNumero_clicked();

    void on_pushPlay_clicked();

    void on_pushStop_clicked();

    void on_pushButton_listres_clicked();

private:
    Ui::res *ui;
    Reservation tempreservation;
    QStringList files;

    QMediaPlayer* player;
    QVideoWidget* vw;
};

#endif // RES_H
