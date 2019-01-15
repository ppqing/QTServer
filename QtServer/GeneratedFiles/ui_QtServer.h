/********************************************************************************
** Form generated from reading UI file 'QtServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERVER_H
#define UI_QTSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtServerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *portText;
    QPushButton *startButton;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *QtServerClass)
    {
        if (QtServerClass->objectName().isEmpty())
            QtServerClass->setObjectName(QStringLiteral("QtServerClass"));
        QtServerClass->resize(600, 400);
        centralWidget = new QWidget(QtServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        portText = new QLineEdit(centralWidget);
        portText->setObjectName(QStringLiteral("portText"));

        horizontalLayout_4->addWidget(portText);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_4->addWidget(startButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        verticalLayout->addLayout(verticalLayout_2);

        QtServerClass->setCentralWidget(centralWidget);

        retranslateUi(QtServerClass);
        QObject::connect(startButton, SIGNAL(clicked()), QtServerClass, SLOT(slotStartButtonClicked()));

        QMetaObject::connectSlotsByName(QtServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtServerClass)
    {
        QtServerClass->setWindowTitle(QApplication::translate("QtServerClass", "QtServer", Q_NULLPTR));
        label->setText(QApplication::translate("QtServerClass", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        startButton->setText(QApplication::translate("QtServerClass", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtServerClass: public Ui_QtServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVER_H
