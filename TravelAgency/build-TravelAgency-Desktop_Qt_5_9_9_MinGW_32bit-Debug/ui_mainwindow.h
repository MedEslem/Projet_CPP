/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_7;
    QGroupBox *groupBox_4;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLineEdit *lineEdit_cin_4;
    QLineEdit *lineEdit_nom_4;
    QLineEdit *lineEdit_prenom_4;
    QLineEdit *lineEdit_tel_4;
    QLineEdit *lineEdit_daten_4;
    QComboBox *comboBox_diplome_4;
    QComboBox *comboBox_role_4;
    QLineEdit *lineEdit_conge_4;
    QLabel *label_57;
    QComboBox *comboBox_duree_4;
    QPushButton *pushButton_ajouter_4;
    QPushButton *pushButton_modifier_4;
    QTableView *tableView_4;
    QPushButton *Rechercher_4;
    QPushButton *pushButton_supprimer_4;
    QComboBox *comboBox_p_4;
    QPushButton *pushButton_Trier_4;
    QComboBox *comboBox_trie_4;
    QPushButton *pushButton_4;
    QLabel *label_58;
    QLineEdit *lineEdit_cins_4;
    QTableView *tableView_r_4;
    QWidget *tab_8;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_61;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QRadioButton *radioButton_46;
    QRadioButton *radioButton_47;
    QRadioButton *radioButton_48;
    QRadioButton *radioButton_49;
    QRadioButton *radioButton_50;
    QRadioButton *radioButton_51;
    QRadioButton *radioButton_52;
    QRadioButton *radioButton_53;
    QRadioButton *radioButton_54;
    QRadioButton *radioButton_55;
    QRadioButton *radioButton_56;
    QRadioButton *radioButton_57;
    QRadioButton *radioButton_58;
    QRadioButton *radioButton_59;
    QRadioButton *radioButton_60;
    QPushButton *pushButton_valider_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1224, 663);
        MainWindow->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"border-radius: 10px;\n"
"background: white;\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(72, 145, 217, 255), stop: 1 rgba(255, 255, 255, 255));\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1201, 651));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_4 = new QGroupBox(tab_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 10, 521, 351));
        label_49 = new QLabel(groupBox_4);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(20, 50, 47, 14));
        label_50 = new QLabel(groupBox_4);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(20, 90, 47, 14));
        label_51 = new QLabel(groupBox_4);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(20, 130, 47, 14));
        label_52 = new QLabel(groupBox_4);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(20, 180, 91, 16));
        label_53 = new QLabel(groupBox_4);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(40, 280, 47, 14));
        label_54 = new QLabel(groupBox_4);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(280, 100, 47, 16));
        label_55 = new QLabel(groupBox_4);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(280, 50, 47, 14));
        label_56 = new QLabel(groupBox_4);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(20, 240, 101, 16));
        lineEdit_cin_4 = new QLineEdit(groupBox_4);
        lineEdit_cin_4->setObjectName(QStringLiteral("lineEdit_cin_4"));
        lineEdit_cin_4->setGeometry(QRect(80, 50, 113, 20));
        lineEdit_nom_4 = new QLineEdit(groupBox_4);
        lineEdit_nom_4->setObjectName(QStringLiteral("lineEdit_nom_4"));
        lineEdit_nom_4->setGeometry(QRect(80, 90, 113, 20));
        lineEdit_prenom_4 = new QLineEdit(groupBox_4);
        lineEdit_prenom_4->setObjectName(QStringLiteral("lineEdit_prenom_4"));
        lineEdit_prenom_4->setGeometry(QRect(80, 130, 113, 20));
        lineEdit_tel_4 = new QLineEdit(groupBox_4);
        lineEdit_tel_4->setObjectName(QStringLiteral("lineEdit_tel_4"));
        lineEdit_tel_4->setGeometry(QRect(130, 180, 113, 20));
        lineEdit_daten_4 = new QLineEdit(groupBox_4);
        lineEdit_daten_4->setObjectName(QStringLiteral("lineEdit_daten_4"));
        lineEdit_daten_4->setGeometry(QRect(140, 240, 113, 20));
        comboBox_diplome_4 = new QComboBox(groupBox_4);
        comboBox_diplome_4->setObjectName(QStringLiteral("comboBox_diplome_4"));
        comboBox_diplome_4->setGeometry(QRect(370, 40, 81, 22));
        comboBox_role_4 = new QComboBox(groupBox_4);
        comboBox_role_4->setObjectName(QStringLiteral("comboBox_role_4"));
        comboBox_role_4->setGeometry(QRect(370, 100, 62, 22));
        lineEdit_conge_4 = new QLineEdit(groupBox_4);
        lineEdit_conge_4->setObjectName(QStringLiteral("lineEdit_conge_4"));
        lineEdit_conge_4->setGeometry(QRect(110, 280, 113, 20));
        label_57 = new QLabel(groupBox_4);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(280, 150, 91, 16));
        comboBox_duree_4 = new QComboBox(groupBox_4);
        comboBox_duree_4->setObjectName(QStringLiteral("comboBox_duree_4"));
        comboBox_duree_4->setGeometry(QRect(400, 150, 62, 22));
        pushButton_ajouter_4 = new QPushButton(groupBox_4);
        pushButton_ajouter_4->setObjectName(QStringLiteral("pushButton_ajouter_4"));
        pushButton_ajouter_4->setGeometry(QRect(300, 280, 75, 23));
        pushButton_modifier_4 = new QPushButton(groupBox_4);
        pushButton_modifier_4->setObjectName(QStringLiteral("pushButton_modifier_4"));
        pushButton_modifier_4->setGeometry(QRect(400, 280, 75, 23));
        tableView_4 = new QTableView(tab_7);
        tableView_4->setObjectName(QStringLiteral("tableView_4"));
        tableView_4->setGeometry(QRect(550, 10, 541, 351));
        Rechercher_4 = new QPushButton(tab_7);
        Rechercher_4->setObjectName(QStringLiteral("Rechercher_4"));
        Rechercher_4->setGeometry(QRect(220, 440, 75, 23));
        pushButton_supprimer_4 = new QPushButton(tab_7);
        pushButton_supprimer_4->setObjectName(QStringLiteral("pushButton_supprimer_4"));
        pushButton_supprimer_4->setGeometry(QRect(320, 440, 75, 23));
        comboBox_p_4 = new QComboBox(tab_7);
        comboBox_p_4->setObjectName(QStringLiteral("comboBox_p_4"));
        comboBox_p_4->setGeometry(QRect(181, 400, 101, 21));
        pushButton_Trier_4 = new QPushButton(tab_7);
        pushButton_Trier_4->setObjectName(QStringLiteral("pushButton_Trier_4"));
        pushButton_Trier_4->setGeometry(QRect(1020, 470, 75, 23));
        comboBox_trie_4 = new QComboBox(tab_7);
        comboBox_trie_4->setObjectName(QStringLiteral("comboBox_trie_4"));
        comboBox_trie_4->setGeometry(QRect(1030, 430, 62, 22));
        pushButton_4 = new QPushButton(tab_7);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1020, 380, 75, 23));
        label_58 = new QLabel(tab_7);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(70, 390, 47, 14));
        lineEdit_cins_4 = new QLineEdit(tab_7);
        lineEdit_cins_4->setObjectName(QStringLiteral("lineEdit_cins_4"));
        lineEdit_cins_4->setGeometry(QRect(290, 400, 131, 20));
        tableView_r_4 = new QTableView(tab_7);
        tableView_r_4->setObjectName(QStringLiteral("tableView_r_4"));
        tableView_r_4->setGeometry(QRect(450, 380, 491, 141));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        label_59 = new QLabel(tab_8);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(400, 20, 121, 71));
        label_59->setStyleSheet(QStringLiteral("font: 32pt \"MS UI Gothic\";"));
        label_60 = new QLabel(tab_8);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setGeometry(QRect(90, 150, 71, 16));
        label_61 = new QLabel(tab_8);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(520, 270, 61, 16));
        label_62 = new QLabel(tab_8);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setGeometry(QRect(90, 370, 61, 16));
        label_63 = new QLabel(tab_8);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(500, 150, 61, 16));
        label_64 = new QLabel(tab_8);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(90, 260, 61, 16));
        radioButton_46 = new QRadioButton(tab_8);
        radioButton_46->setObjectName(QStringLiteral("radioButton_46"));
        radioButton_46->setGeometry(QRect(30, 190, 83, 18));
        radioButton_47 = new QRadioButton(tab_8);
        radioButton_47->setObjectName(QStringLiteral("radioButton_47"));
        radioButton_47->setGeometry(QRect(140, 190, 83, 18));
        radioButton_48 = new QRadioButton(tab_8);
        radioButton_48->setObjectName(QStringLiteral("radioButton_48"));
        radioButton_48->setGeometry(QRect(240, 190, 83, 18));
        radioButton_49 = new QRadioButton(tab_8);
        radioButton_49->setObjectName(QStringLiteral("radioButton_49"));
        radioButton_49->setGeometry(QRect(440, 190, 83, 18));
        radioButton_50 = new QRadioButton(tab_8);
        radioButton_50->setObjectName(QStringLiteral("radioButton_50"));
        radioButton_50->setGeometry(QRect(20, 400, 83, 18));
        radioButton_51 = new QRadioButton(tab_8);
        radioButton_51->setObjectName(QStringLiteral("radioButton_51"));
        radioButton_51->setGeometry(QRect(20, 290, 83, 18));
        radioButton_52 = new QRadioButton(tab_8);
        radioButton_52->setObjectName(QStringLiteral("radioButton_52"));
        radioButton_52->setGeometry(QRect(500, 320, 83, 18));
        radioButton_53 = new QRadioButton(tab_8);
        radioButton_53->setObjectName(QStringLiteral("radioButton_53"));
        radioButton_53->setGeometry(QRect(550, 190, 83, 18));
        radioButton_54 = new QRadioButton(tab_8);
        radioButton_54->setObjectName(QStringLiteral("radioButton_54"));
        radioButton_54->setGeometry(QRect(130, 400, 83, 18));
        radioButton_55 = new QRadioButton(tab_8);
        radioButton_55->setObjectName(QStringLiteral("radioButton_55"));
        radioButton_55->setGeometry(QRect(140, 290, 83, 18));
        radioButton_56 = new QRadioButton(tab_8);
        radioButton_56->setObjectName(QStringLiteral("radioButton_56"));
        radioButton_56->setGeometry(QRect(390, 320, 83, 18));
        radioButton_57 = new QRadioButton(tab_8);
        radioButton_57->setObjectName(QStringLiteral("radioButton_57"));
        radioButton_57->setGeometry(QRect(610, 320, 83, 18));
        radioButton_58 = new QRadioButton(tab_8);
        radioButton_58->setObjectName(QStringLiteral("radioButton_58"));
        radioButton_58->setGeometry(QRect(650, 190, 83, 18));
        radioButton_59 = new QRadioButton(tab_8);
        radioButton_59->setObjectName(QStringLiteral("radioButton_59"));
        radioButton_59->setGeometry(QRect(240, 400, 83, 18));
        radioButton_60 = new QRadioButton(tab_8);
        radioButton_60->setObjectName(QStringLiteral("radioButton_60"));
        radioButton_60->setGeometry(QRect(260, 290, 83, 18));
        pushButton_valider_4 = new QPushButton(tab_8);
        pushButton_valider_4->setObjectName(QStringLiteral("pushButton_valider_4"));
        pushButton_valider_4->setGeometry(QRect(630, 490, 75, 23));
        tabWidget->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1224, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Employe", Q_NULLPTR));
        label_49->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_50->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_51->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_52->setText(QApplication::translate("MainWindow", "Num Telephone", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWindow", "Conge", Q_NULLPTR));
        label_54->setText(QApplication::translate("MainWindow", "Role", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "Diplome", Q_NULLPTR));
        label_56->setText(QApplication::translate("MainWindow", "Date de naissance", Q_NULLPTR));
        comboBox_diplome_4->clear();
        comboBox_diplome_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "License", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Master", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Doctorat", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Ingenieurie", Q_NULLPTR)
        );
        comboBox_role_4->clear();
        comboBox_role_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Management", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Informatique", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Contabilite", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Reception", Q_NULLPTR)
        );
        label_57->setText(QApplication::translate("MainWindow", "Duree de travail", Q_NULLPTR));
        comboBox_duree_4->clear();
        comboBox_duree_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3 Mois", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6 Mois", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1 Ans", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3 Ans", Q_NULLPTR)
         << QApplication::translate("MainWindow", "+5 Ans", Q_NULLPTR)
        );
        pushButton_ajouter_4->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_modifier_4->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        Rechercher_4->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_supprimer_4->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        comboBox_p_4->clear();
        comboBox_p_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "CIN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "TELEPHONE", Q_NULLPTR)
        );
        pushButton_Trier_4->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        comboBox_trie_4->clear();
        comboBox_trie_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOM", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CONGE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CIN", Q_NULLPTR)
        );
        pushButton_4->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        label_58->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "CRUD", Q_NULLPTR));
        label_59->setText(QApplication::translate("MainWindow", "QUIZ", Q_NULLPTR));
        label_60->setText(QApplication::translate("MainWindow", "Question 1", Q_NULLPTR));
        label_61->setText(QApplication::translate("MainWindow", "Question 5", Q_NULLPTR));
        label_62->setText(QApplication::translate("MainWindow", "Question 3", Q_NULLPTR));
        label_63->setText(QApplication::translate("MainWindow", "Question 4", Q_NULLPTR));
        label_64->setText(QApplication::translate("MainWindow", "Question 2", Q_NULLPTR));
        radioButton_46->setText(QApplication::translate("MainWindow", "Reponse 1", Q_NULLPTR));
        radioButton_47->setText(QApplication::translate("MainWindow", "Reponse 2", Q_NULLPTR));
        radioButton_48->setText(QApplication::translate("MainWindow", "Reponse 3", Q_NULLPTR));
        radioButton_49->setText(QApplication::translate("MainWindow", "Reponse 1", Q_NULLPTR));
        radioButton_50->setText(QApplication::translate("MainWindow", "Reponse 1", Q_NULLPTR));
        radioButton_51->setText(QApplication::translate("MainWindow", "Reponse 1", Q_NULLPTR));
        radioButton_52->setText(QApplication::translate("MainWindow", "Reponse 2", Q_NULLPTR));
        radioButton_53->setText(QApplication::translate("MainWindow", "Reponse 2", Q_NULLPTR));
        radioButton_54->setText(QApplication::translate("MainWindow", "Reponse 2", Q_NULLPTR));
        radioButton_55->setText(QApplication::translate("MainWindow", "Reponse 2", Q_NULLPTR));
        radioButton_56->setText(QApplication::translate("MainWindow", "Reponse 1", Q_NULLPTR));
        radioButton_57->setText(QApplication::translate("MainWindow", "Reponse 3", Q_NULLPTR));
        radioButton_58->setText(QApplication::translate("MainWindow", "Reponse 3", Q_NULLPTR));
        radioButton_59->setText(QApplication::translate("MainWindow", "Reponse 3", Q_NULLPTR));
        radioButton_60->setText(QApplication::translate("MainWindow", "Reponse 3", Q_NULLPTR));
        pushButton_valider_4->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "QUIZ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
