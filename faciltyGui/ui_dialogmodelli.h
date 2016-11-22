/********************************************************************************
** Form generated from reading UI file 'dialogmodelli.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODELLI_H
#define UI_DIALOGMODELLI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogModelli
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_chiudi;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_gestidci;
    QTableView *tableView;
    QWidget *tab_abbina;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_nuovo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_elimina;

    void setupUi(QDialog *DialogModelli)
    {
        if (DialogModelli->objectName().isEmpty())
            DialogModelli->setObjectName(QStringLiteral("DialogModelli"));
        DialogModelli->resize(622, 430);
        gridLayout = new QGridLayout(DialogModelli);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_chiudi = new QPushButton(DialogModelli);
        pushButton_chiudi->setObjectName(QStringLiteral("pushButton_chiudi"));
        QFont font;
        font.setPointSize(20);
        pushButton_chiudi->setFont(font);

        gridLayout->addWidget(pushButton_chiudi, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(495, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        tabWidget = new QTabWidget(DialogModelli);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 300));
        tab_gestidci = new QWidget();
        tab_gestidci->setObjectName(QStringLiteral("tab_gestidci"));
        tableView = new QTableView(tab_gestidci);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 581, 241));
        tabWidget->addTab(tab_gestidci, QString());
        tab_abbina = new QWidget();
        tab_abbina->setObjectName(QStringLiteral("tab_abbina"));
        tableWidget = new QTableWidget(tab_abbina);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 591, 241));
        tabWidget->addTab(tab_abbina, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_nuovo = new QPushButton(DialogModelli);
        pushButton_nuovo->setObjectName(QStringLiteral("pushButton_nuovo"));
        pushButton_nuovo->setFont(font);

        horizontalLayout->addWidget(pushButton_nuovo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_elimina = new QPushButton(DialogModelli);
        pushButton_elimina->setObjectName(QStringLiteral("pushButton_elimina"));
        pushButton_elimina->setFont(font);

        horizontalLayout->addWidget(pushButton_elimina);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(DialogModelli);
        QObject::connect(pushButton_chiudi, SIGNAL(clicked()), DialogModelli, SLOT(accept()));
        QObject::connect(pushButton_nuovo, SIGNAL(clicked()), DialogModelli, SLOT(nuovo()));
        QObject::connect(pushButton_elimina, SIGNAL(clicked()), DialogModelli, SLOT(elimina()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), DialogModelli, SLOT(tabChanged(int)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogModelli);
    } // setupUi

    void retranslateUi(QDialog *DialogModelli)
    {
        DialogModelli->setWindowTitle(QApplication::translate("DialogModelli", "Dialog", Q_NULLPTR));
        pushButton_chiudi->setText(QApplication::translate("DialogModelli", "Chiudi", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_gestidci), QApplication::translate("DialogModelli", "Gestisci modelli", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_abbina), QApplication::translate("DialogModelli", "Abbina modello a quaderno", Q_NULLPTR));
        pushButton_nuovo->setText(QApplication::translate("DialogModelli", "Nuovo Modello", Q_NULLPTR));
        pushButton_elimina->setText(QApplication::translate("DialogModelli", "Elimina Modello", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogModelli: public Ui_DialogModelli {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODELLI_H
