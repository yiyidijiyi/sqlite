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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
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
    QLineEdit *lineEdit_dbName;
    QLabel *label_2;
    QLineEdit *lineEdit_passward;
    QLabel *label_3;
    QLineEdit *lineEdit_DBPath;
    QPushButton *pushButton_selDB;
    QPushButton *pushButton_connectDB;
    QPushButton *pushButton_disconnectDB;
    QPushButton *pushButton_createDB;
    QPushButton *pushButton_createAccount;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit_setUserName;
    QLabel *label_5;
    QLineEdit *lineEdit_setPassward;
    QPushButton *pushButton_setPassward;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_accountName;
    QLineEdit *lineEdit_accountPassward;
    QComboBox *comboBox_accountType;
    QPushButton *pushButton_insertAccount;
    QTableView *tableView;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QLineEdit *lineEdit_tableName;
    QPushButton *pushButton_showTable;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1366, 768);
        textEdit_message = new QTextEdit(Widget);
        textEdit_message->setObjectName(QStringLiteral("textEdit_message"));
        textEdit_message->setGeometry(QRect(10, 320, 400, 300));
        pushButton_clearMessage = new QPushButton(Widget);
        pushButton_clearMessage->setObjectName(QStringLiteral("pushButton_clearMessage"));
        pushButton_clearMessage->setGeometry(QRect(10, 630, 75, 23));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 295, 170));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 50, 60, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_dbName = new QLineEdit(groupBox);
        lineEdit_dbName->setObjectName(QStringLiteral("lineEdit_dbName"));
        lineEdit_dbName->setGeometry(QRect(70, 50, 160, 20));
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
        pushButton_connectDB->setGeometry(QRect(10, 100, 80, 24));
        pushButton_disconnectDB = new QPushButton(groupBox);
        pushButton_disconnectDB->setObjectName(QStringLiteral("pushButton_disconnectDB"));
        pushButton_disconnectDB->setGeometry(QRect(100, 100, 80, 24));
        pushButton_createDB = new QPushButton(groupBox);
        pushButton_createDB->setObjectName(QStringLiteral("pushButton_createDB"));
        pushButton_createDB->setGeometry(QRect(190, 100, 80, 24));
        pushButton_createAccount = new QPushButton(groupBox);
        pushButton_createAccount->setObjectName(QStringLiteral("pushButton_createAccount"));
        pushButton_createAccount->setGeometry(QRect(10, 130, 80, 24));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 295, 120));
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
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(330, 10, 230, 170));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 20, 60, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 45, 60, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 70, 60, 20));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_accountName = new QLineEdit(groupBox_3);
        lineEdit_accountName->setObjectName(QStringLiteral("lineEdit_accountName"));
        lineEdit_accountName->setGeometry(QRect(90, 20, 120, 20));
        lineEdit_accountPassward = new QLineEdit(groupBox_3);
        lineEdit_accountPassward->setObjectName(QStringLiteral("lineEdit_accountPassward"));
        lineEdit_accountPassward->setGeometry(QRect(90, 45, 120, 20));
        comboBox_accountType = new QComboBox(groupBox_3);
        comboBox_accountType->setObjectName(QStringLiteral("comboBox_accountType"));
        comboBox_accountType->setGeometry(QRect(90, 69, 120, 22));
        pushButton_insertAccount = new QPushButton(groupBox_3);
        pushButton_insertAccount->setObjectName(QStringLiteral("pushButton_insertAccount"));
        pushButton_insertAccount->setGeometry(QRect(20, 100, 80, 24));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(420, 320, 400, 300));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(330, 190, 230, 120));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 25, 54, 20));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_tableName = new QLineEdit(groupBox_4);
        lineEdit_tableName->setObjectName(QStringLiteral("lineEdit_tableName"));
        lineEdit_tableName->setGeometry(QRect(70, 25, 120, 20));
        pushButton_showTable = new QPushButton(groupBox_4);
        pushButton_showTable->setObjectName(QStringLiteral("pushButton_showTable"));
        pushButton_showTable->setGeometry(QRect(20, 60, 80, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton_clearMessage->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", 0));
        label->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit_passward->setText(QApplication::translate("Widget", "123", 0));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\272\223\357\274\232", 0));
        lineEdit_DBPath->setText(QString());
        pushButton_selDB->setText(QApplication::translate("Widget", "...", 0));
        pushButton_connectDB->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", 0));
        pushButton_disconnectDB->setText(QApplication::translate("Widget", "\346\226\255\345\274\200\346\225\260\346\215\256\345\272\223", 0));
        pushButton_createDB->setText(QApplication::translate("Widget", "\347\224\237\346\210\220\346\225\260\346\215\256\345\272\223", 0));
        pushButton_createAccount->setText(QApplication::translate("Widget", "\347\224\237\346\210\220\350\264\246\346\210\267\350\241\250", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\350\256\276\347\275\256\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_5->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0));
        pushButton_setPassward->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\346\217\222\345\205\245\350\264\246\346\210\267", 0));
        label_6->setText(QApplication::translate("Widget", "\350\264\246\346\210\267\345\220\215\347\247\260\357\274\232", 0));
        label_7->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0));
        label_8->setText(QApplication::translate("Widget", "\350\264\246\346\210\267\347\261\273\345\236\213\357\274\232", 0));
        lineEdit_accountName->setText(QString());
        lineEdit_accountPassward->setText(QString());
        comboBox_accountType->clear();
        comboBox_accountType->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\265\213\350\257\225\345\221\230", 0)
         << QApplication::translate("Widget", "\347\256\241\347\220\206\345\221\230", 0)
         << QApplication::translate("Widget", "\345\274\200\345\217\221\350\200\205", 0)
        );
        pushButton_insertAccount->setText(QApplication::translate("Widget", "\346\217\222\345\205\245\350\264\246\345\217\267", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\346\230\276\347\244\272\350\241\250", 0));
        label_9->setText(QApplication::translate("Widget", "\350\241\250\345\220\215\347\247\260\357\274\232", 0));
        pushButton_showTable->setText(QApplication::translate("Widget", "\346\230\276\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
