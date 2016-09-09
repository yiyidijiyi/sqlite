/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit_message;
    QPushButton *pushButton_clearMessage;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_userName;
    QLabel *label_2;
    QLineEdit *lineEdit_passward;
    QLabel *label_3;
    QLineEdit *lineEdit_DBPath;
    QPushButton *pushButton_selDB;
    QPushButton *pushButton_connectDB;
    QPushButton *pushButton_disconnectDB;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit_setUserName;
    QLabel *label_5;
    QLineEdit *lineEdit_setPassward;
    QPushButton *pushButton_setPassward;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1366, 768);
        textEdit_message = new QTextEdit(Widget);
        textEdit_message->setObjectName(QStringLiteral("textEdit_message"));
        textEdit_message->setGeometry(QRect(620, 10, 400, 300));
        pushButton_clearMessage = new QPushButton(Widget);
        pushButton_clearMessage->setObjectName(QStringLiteral("pushButton_clearMessage"));
        pushButton_clearMessage->setGeometry(QRect(620, 320, 75, 23));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 300, 140));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 54, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_userName = new QLineEdit(groupBox);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(70, 50, 160, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 75, 54, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_passward = new QLineEdit(groupBox);
        lineEdit_passward->setObjectName(QStringLiteral("lineEdit_passward"));
        lineEdit_passward->setGeometry(QRect(70, 75, 160, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 25, 54, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_DBPath = new QLineEdit(groupBox);
        lineEdit_DBPath->setObjectName(QStringLiteral("lineEdit_DBPath"));
        lineEdit_DBPath->setGeometry(QRect(70, 25, 160, 20));
        pushButton_selDB = new QPushButton(groupBox);
        pushButton_selDB->setObjectName(QStringLiteral("pushButton_selDB"));
        pushButton_selDB->setGeometry(QRect(240, 23, 40, 24));
        pushButton_connectDB = new QPushButton(groupBox);
        pushButton_connectDB->setObjectName(QStringLiteral("pushButton_connectDB"));
        pushButton_connectDB->setGeometry(QRect(70, 100, 75, 24));
        pushButton_disconnectDB = new QPushButton(groupBox);
        pushButton_disconnectDB->setObjectName(QStringLiteral("pushButton_disconnectDB"));
        pushButton_disconnectDB->setGeometry(QRect(150, 100, 80, 24));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 300, 120));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 25, 54, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_setUserName = new QLineEdit(groupBox_2);
        lineEdit_setUserName->setObjectName(QStringLiteral("lineEdit_setUserName"));
        lineEdit_setUserName->setGeometry(QRect(70, 25, 160, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 50, 54, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_setPassward = new QLineEdit(groupBox_2);
        lineEdit_setPassward->setObjectName(QStringLiteral("lineEdit_setPassward"));
        lineEdit_setPassward->setGeometry(QRect(70, 50, 160, 20));
        pushButton_setPassward = new QPushButton(groupBox_2);
        pushButton_setPassward->setObjectName(QStringLiteral("pushButton_setPassward"));
        pushButton_setPassward->setGeometry(QRect(150, 80, 80, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton_clearMessage->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", 0));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\272\223\357\274\232", 0));
        pushButton_selDB->setText(QApplication::translate("Widget", "...", 0));
        pushButton_connectDB->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", 0));
        pushButton_disconnectDB->setText(QApplication::translate("Widget", "\346\226\255\345\274\200\346\225\260\346\215\256\345\272\223", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\350\256\276\347\275\256\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_5->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0));
        pushButton_setPassward->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
