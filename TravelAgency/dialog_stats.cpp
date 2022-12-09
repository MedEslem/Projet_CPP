#include "dialog_stats.h"
#include "ui_dialog_stats.h"


Dialog_stats::Dialog_stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_stats)
{
    ui->setupUi(this);
}

Dialog_stats::~Dialog_stats()
{
    delete ui;
}

void Dialog_stats::choix_bar()
{
    QSqlQuery q1,q2,q3,q4,q5;
    qreal tot=0,c1=0,c2=0,c3=0,c4=0;
    QString R1="Informatique";
     QString R2="Reception";
      QString R3="Management";
       QString R4="Contabilite";

    q1.prepare("SELECT * FROM employe");
    q1.exec();

    q2.prepare("select * from employe where (role LIKE '"+R1+"%')");
    q2.exec();

    q3.prepare("select * from employe where (role LIKE '"+R2+"%')");
    q3.exec();

    q4.prepare("select * from employe where (role LIKE '"+R3+"%')");
    q4.exec();
    q5.prepare("select * from employe where (role LIKE '"+R4+"%')");
    q5.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}
    while (q5.next()){c4++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
    c4=c4/tot;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet(" Informatique");
            QBarSet *set1 = new QBarSet("Reception");
            QBarSet *set2 = new QBarSet("Management");
             QBarSet *set3 = new QBarSet("Contabilite");

            // Assign values for each bar
            *set0 << c1;
            *set1 << c2;
            *set2 << c3;
              *set3 << c4;



            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            series->append(set0);
            series->append(set1);
            series->append(set2);
            series->append(set3);

            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);


            // Adds categories to the axes
           // QBarCategoryAxis *axis = new QBarCategoryAxis();



            // 1. Bar chart
           // chart->setAxisX(axis, series);

            // Used to change the palette
            QPalette pal = qApp->palette();

            // Change the color around the chart widget and text
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

            // Apply palette changes to the application
            qApp->setPalette(pal);


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }
void Dialog_stats::choix_pie()
{  QSqlQuery q1,q2,q3,q4,q5;
    qreal tot=0,c1=0,c2=0,c3=0,c4=0;
    QString R1="Informatique";
     QString R2="Reception";
      QString R3="Management";
       QString R4="Contabilite";

    q1.prepare("SELECT * FROM employe");
    q1.exec();

    q2.prepare("select * from employe where (role LIKE '"+R1+"%')");
    q2.exec();

    q3.prepare("select * from employe where (role LIKE '"+R2+"%')");
    q3.exec();

    q4.prepare("select * from employe where (role LIKE '"+R3+"%')");
    q4.exec();
    q5.prepare("select * from employe where (role LIKE '"+R4+"%')");
    q5.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}
    while (q5.next()){c4++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
    c4=c4/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Informatique",c1);
    series->append("Reception",c2);
    series->append("Management",c3);
    series->append("Contabilite",c4);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();

}
