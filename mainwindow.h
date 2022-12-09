#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


#include "Trans.h"
#include "CRUD.h"
#include "smtp.h"
#include "stat_combo.h"
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

    void update_label();

    Trans tmp;
    QSortFilterProxyModel *proxy;

    void show_tables();


private slots:


    void on_recherche_textChanged(const QString &arg1);

    void on_tableau_doubleClicked();

    void on_tableau_clicked(const QModelIndex &index);

    void sendMail();
    void mailSent(QString);
    void browse();



    void on_stat_clicked();

    void on_pdf_clicked();


    void on_stat_3_clicked();

    void on_Ajout_clicked();

    void on_supp_clicked();

    void on_pushButton_clicked();

    void on_Arduino_clicked();

private:
    QMediaPlayer* player;
    QVideoWidget* vw;
    Ui::MainWindow *ui;
    int selected=0;
    QStringList files;
    stat_combo *s;
        Arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
