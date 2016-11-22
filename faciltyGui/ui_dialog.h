/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *leggiPushButton;
    QPushButton *stopPushButton;
    QPushButton *evidenzaPushButton;
    QPushButton *sceltePushButton;
    QPushButton *quaderniPushButton;
    QPushButton *configurazioniPushButton;
    QPushButton *infoPushButton;
    QPushButton *esciPushButton;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->setWindowModality(Qt::ApplicationModal);
        MainDialog->resize(772, 51);
        layoutWidget = new QWidget(MainDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 726, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leggiPushButton = new QPushButton(layoutWidget);
        leggiPushButton->setObjectName(QStringLiteral("leggiPushButton"));

        horizontalLayout->addWidget(leggiPushButton);

        stopPushButton = new QPushButton(layoutWidget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));

        horizontalLayout->addWidget(stopPushButton);

        evidenzaPushButton = new QPushButton(layoutWidget);
        evidenzaPushButton->setObjectName(QStringLiteral("evidenzaPushButton"));

        horizontalLayout->addWidget(evidenzaPushButton);

        sceltePushButton = new QPushButton(layoutWidget);
        sceltePushButton->setObjectName(QStringLiteral("sceltePushButton"));

        horizontalLayout->addWidget(sceltePushButton);

        quaderniPushButton = new QPushButton(layoutWidget);
        quaderniPushButton->setObjectName(QStringLiteral("quaderniPushButton"));

        horizontalLayout->addWidget(quaderniPushButton);

        configurazioniPushButton = new QPushButton(layoutWidget);
        configurazioniPushButton->setObjectName(QStringLiteral("configurazioniPushButton"));

        horizontalLayout->addWidget(configurazioniPushButton);

        infoPushButton = new QPushButton(layoutWidget);
        infoPushButton->setObjectName(QStringLiteral("infoPushButton"));

        horizontalLayout->addWidget(infoPushButton);

        esciPushButton = new QPushButton(layoutWidget);
        esciPushButton->setObjectName(QStringLiteral("esciPushButton"));

        horizontalLayout->addWidget(esciPushButton);


        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "FacilitOffice", Q_NULLPTR));
        leggiPushButton->setText(QApplication::translate("MainDialog", "Leggi", Q_NULLPTR));
        stopPushButton->setText(QApplication::translate("MainDialog", "Stop", Q_NULLPTR));
        evidenzaPushButton->setText(QApplication::translate("MainDialog", "Evidenzia a riga", Q_NULLPTR));
        sceltePushButton->setText(QApplication::translate("MainDialog", "Scelte rapide", Q_NULLPTR));
        quaderniPushButton->setText(QApplication::translate("MainDialog", "Quaderni", Q_NULLPTR));
        configurazioniPushButton->setText(QApplication::translate("MainDialog", "Configurazioni", Q_NULLPTR));
        infoPushButton->setText(QApplication::translate("MainDialog", "Info", Q_NULLPTR));
        esciPushButton->setText(QApplication::translate("MainDialog", "Esci", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
