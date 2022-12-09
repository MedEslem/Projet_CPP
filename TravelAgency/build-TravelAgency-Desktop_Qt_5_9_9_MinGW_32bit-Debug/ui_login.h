/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLineEdit *lineEdit_C;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_mdp;
    QPushButton *pushButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(641, 446);
        login->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"border-radius: 10px;\n"
"background: white;\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(72, 145, 217, 255), stop: 1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 311, 91));
        label->setStyleSheet(QStringLiteral("font: 32pt \"MS UI Gothic\";"));
        lineEdit_C = new QLineEdit(login);
        lineEdit_C->setObjectName(QStringLiteral("lineEdit_C"));
        lineEdit_C->setGeometry(QRect(180, 190, 161, 20));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 260, 71, 16));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 190, 47, 14));
        lineEdit_mdp = new QLineEdit(login);
        lineEdit_mdp->setObjectName(QStringLiteral("lineEdit_mdp"));
        lineEdit_mdp->setGeometry(QRect(180, 260, 161, 20));
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 330, 75, 23));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("login", "Happy Travelers", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "Password", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "ID", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "LOGIN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
