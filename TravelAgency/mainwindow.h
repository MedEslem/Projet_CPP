#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include "arduino.h"
#include "dialog_stats.h"
#include "ui_dialog_stats.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
void update_label();
    void on_pushButton_ajouter_4_clicked();

    void on_pushButton_supprimer_4_clicked();

    void on_pushButton_modifier_4_clicked();


    void on_Rechercher_4_clicked();

    void on_pushButton_Trier_4_clicked();

   // void on_pdf_clicked();

    void on_pushButton_valider_4_clicked();

    void on_pushButton_4_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data;
    Employe Etmp;
    Arduino A;
    Dialog_stats *s;

};
#endif // MAINWINDOW_H

