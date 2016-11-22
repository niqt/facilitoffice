/********************************************************************************
** Form generated from reading UI file 'show_voc_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_VOC_DIALOG_H
#define UI_SHOW_VOC_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VocabolarioDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *maiuscoloButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *imgLabel;
    QLabel *descrLabel;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *leggiButton;

    void setupUi(QDialog *VocabolarioDialogClass)
    {
        if (VocabolarioDialogClass->objectName().isEmpty())
            VocabolarioDialogClass->setObjectName(QStringLiteral("VocabolarioDialogClass"));
        VocabolarioDialogClass->resize(626, 449);
        gridLayout = new QGridLayout(VocabolarioDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        maiuscoloButton = new QPushButton(VocabolarioDialogClass);
        maiuscoloButton->setObjectName(QStringLiteral("maiuscoloButton"));

        horizontalLayout_2->addWidget(maiuscoloButton);

        horizontalSpacer_2 = new QSpacerItem(465, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(VocabolarioDialogClass);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imgLabel = new QLabel(VocabolarioDialogClass);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setMinimumSize(QSize(245, 305));

        horizontalLayout->addWidget(imgLabel);

        descrLabel = new QLabel(VocabolarioDialogClass);
        descrLabel->setObjectName(QStringLiteral("descrLabel"));

        horizontalLayout->addWidget(descrLabel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 304, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(478, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        leggiButton = new QPushButton(VocabolarioDialogClass);
        leggiButton->setObjectName(QStringLiteral("leggiButton"));

        horizontalLayout_3->addWidget(leggiButton);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);


        retranslateUi(VocabolarioDialogClass);
        QObject::connect(leggiButton, SIGNAL(clicked()), VocabolarioDialogClass, SLOT(leggi()));
        QObject::connect(maiuscoloButton, SIGNAL(clicked()), VocabolarioDialogClass, SLOT(upper()));

        QMetaObject::connectSlotsByName(VocabolarioDialogClass);
    } // setupUi

    void retranslateUi(QDialog *VocabolarioDialogClass)
    {
        VocabolarioDialogClass->setWindowTitle(QApplication::translate("VocabolarioDialogClass", "Dialog", Q_NULLPTR));
        maiuscoloButton->setText(QApplication::translate("VocabolarioDialogClass", "Maiuscolo", Q_NULLPTR));
        label->setText(QApplication::translate("VocabolarioDialogClass", "TextLabel", Q_NULLPTR));
        imgLabel->setText(QApplication::translate("VocabolarioDialogClass", "img", Q_NULLPTR));
        descrLabel->setText(QApplication::translate("VocabolarioDialogClass", "TextLabel", Q_NULLPTR));
        leggiButton->setText(QApplication::translate("VocabolarioDialogClass", "Leggi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VocabolarioDialogClass: public Ui_VocabolarioDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_VOC_DIALOG_H
