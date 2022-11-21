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
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();


    void on_Rechercher_clicked();

    void on_pushButton_Trier_clicked();

    void on_pdf_clicked();

    void on_pushButton_valider_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data;
    //Arduino A;
    Employe Etmp;
};
#endif // MAINWINDOW_H

