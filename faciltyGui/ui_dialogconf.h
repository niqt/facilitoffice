/********************************************************************************
** Form generated from reading UI file 'dialogconf.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONF_H
#define UI_DIALOGCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogConf
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButtonColor;
    QLabel *labelColor;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogConf)
    {
        if (DialogConf->objectName().isEmpty())
            DialogConf->setObjectName(QStringLiteral("DialogConf"));
        DialogConf->resize(306, 121);
        gridLayout = new QGridLayout(DialogConf);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonColor = new QPushButton(DialogConf);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));

        gridLayout->addWidget(pushButtonColor, 0, 0, 1, 1);

        labelColor = new QLabel(DialogConf);
        labelColor->setObjectName(QStringLiteral("labelColor"));

        gridLayout->addWidget(labelColor, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DialogConf);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(DialogConf);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConf, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConf, SLOT(reject()));
        QObject::connect(pushButtonColor, SIGNAL(clicked()), DialogConf, SLOT(setColor()));

        QMetaObject::connectSlotsByName(DialogConf);
    } // setupUi

    void retranslateUi(QDialog *DialogConf)
    {
        DialogConf->setWindowTitle(QApplication::translate("DialogConf", "Dialog", Q_NULLPTR));
        pushButtonColor->setText(QApplication::translate("DialogConf", "Scegli Colore Evidenza", Q_NULLPTR));
        labelColor->setText(QApplication::translate("DialogConf", "Testo prova", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogConf: public Ui_DialogConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONF_H
