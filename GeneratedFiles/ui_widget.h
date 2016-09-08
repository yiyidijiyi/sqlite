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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit_message;
    QPushButton *pushButton_clearMessage;
    QPushButton *pushButton_connectDB;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        textEdit_message = new QTextEdit(Widget);
        textEdit_message->setObjectName(QStringLiteral("textEdit_message"));
        textEdit_message->setGeometry(QRect(10, 10, 300, 300));
        pushButton_clearMessage = new QPushButton(Widget);
        pushButton_clearMessage->setObjectName(QStringLiteral("pushButton_clearMessage"));
        pushButton_clearMessage->setGeometry(QRect(10, 320, 75, 23));
        pushButton_connectDB = new QPushButton(Widget);
        pushButton_connectDB->setObjectName(QStringLiteral("pushButton_connectDB"));
        pushButton_connectDB->setGeometry(QRect(330, 10, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton_clearMessage->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
        pushButton_connectDB->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
