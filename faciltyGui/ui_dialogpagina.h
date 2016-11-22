/********************************************************************************
** Form generated from reading UI file 'dialogpagina.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPAGINA_H
#define UI_DIALOGPAGINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogPagina
{
public:
    QAction *actionChiudi;
    QAction *actionEliminazione;
    QAction *actionInserisci;
    QAction *actionApri;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QPushButton *pushButtonNuova;

    void setupUi(QDialog *DialogPagina)
    {
        if (DialogPagina->objectName().isEmpty())
            DialogPagina->setObjectName(QStringLiteral("DialogPagina"));
        DialogPagina->resize(574, 300);
        actionChiudi = new QAction(DialogPagina);
        actionChiudi->setObjectName(QStringLiteral("actionChiudi"));
        actionEliminazione = new QAction(DialogPagina);
        actionEliminazione->setObjectName(QStringLiteral("actionEliminazione"));
        actionInserisci = new QAction(DialogPagina);
        actionInserisci->setObjectName(QStringLiteral("actionInserisci"));
        actionApri = new QAction(DialogPagina);
        actionApri->setObjectName(QStringLiteral("actionApri"));
        gridLayout = new QGridLayout(DialogPagina);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        tableView = new QTableView(DialogPagina);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        pushButtonNuova = new QPushButton(DialogPagina);
        pushButtonNuova->setObjectName(QStringLiteral("pushButtonNuova"));
        pushButtonNuova->setStyleSheet(QStringLiteral("background-color:rgb(170, 0, 0)"));

        gridLayout->addWidget(pushButtonNuova, 1, 1, 1, 1);


        retranslateUi(DialogPagina);
        QObject::connect(actionChiudi, SIGNAL(triggered()), DialogPagina, SLOT(reject()));
        QObject::connect(actionInserisci, SIGNAL(triggered()), DialogPagina, SLOT(inserisci()));
        QObject::connect(pushButtonNuova, SIGNAL(clicked()), DialogPagina, SLOT(nuova()));
        QObject::connect(actionEliminazione, SIGNAL(triggered()), DialogPagina, SLOT(elimina()));
        QObject::connect(tableView, SIGNAL(clicked(QModelIndex)), DialogPagina, SLOT(selectedItem(QModelIndex)));
        QObject::connect(actionApri, SIGNAL(triggered()), DialogPagina, SLOT(apri()));

        QMetaObject::connectSlotsByName(DialogPagina);
    } // setupUi

    void retranslateUi(QDialog *DialogPagina)
    {
        DialogPagina->setWindowTitle(QApplication::translate("DialogPagina", "Dialog", Q_NULLPTR));
        actionChiudi->setText(QApplication::translate("DialogPagina", "&Chiudi", Q_NULLPTR));
        actionEliminazione->setText(QApplication::translate("DialogPagina", "&Eliminazione", Q_NULLPTR));
        actionInserisci->setText(QApplication::translate("DialogPagina", "&Inserisci Pagina Esistente", Q_NULLPTR));
        actionApri->setText(QApplication::translate("DialogPagina", "Apri", Q_NULLPTR));
        pushButtonNuova->setText(QApplication::translate("DialogPagina", "Nuova Pagina", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPagina: public Ui_DialogPagina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPAGINA_H
