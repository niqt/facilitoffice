/********************************************************************************
** Form generated from reading UI file 'quadernodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUADERNODIALOG_H
#define UI_QUADERNODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogQuaderno
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *nuovaPushButton;
    QPushButton *apriPushButton;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogQuaderno)
    {
        if (DialogQuaderno->objectName().isEmpty())
            DialogQuaderno->setObjectName(QStringLiteral("DialogQuaderno"));
        DialogQuaderno->resize(800, 600);
        QFont font;
        font.setPointSize(24);
        DialogQuaderno->setFont(font);
        gridLayout = new QGridLayout(DialogQuaderno);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(DialogQuaderno);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 60));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        nuovaPushButton = new QPushButton(DialogQuaderno);
        nuovaPushButton->setObjectName(QStringLiteral("nuovaPushButton"));
        nuovaPushButton->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(nuovaPushButton, 1, 0, 1, 1);

        apriPushButton = new QPushButton(DialogQuaderno);
        apriPushButton->setObjectName(QStringLiteral("apriPushButton"));
        apriPushButton->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(apriPushButton, 2, 0, 1, 1);

        pushButton = new QPushButton(DialogQuaderno);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);


        retranslateUi(DialogQuaderno);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogQuaderno, SLOT(reject()));
        QObject::connect(apriPushButton, SIGNAL(clicked()), DialogQuaderno, SLOT(apri()));
        QObject::connect(nuovaPushButton, SIGNAL(clicked()), DialogQuaderno, SLOT(nuova()));

        QMetaObject::connectSlotsByName(DialogQuaderno);
    } // setupUi

    void retranslateUi(QDialog *DialogQuaderno)
    {
        DialogQuaderno->setWindowTitle(QApplication::translate("DialogQuaderno", "Dialog", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("DialogQuaderno", "Nome Quaderno", Q_NULLPTR));
        nuovaPushButton->setText(QApplication::translate("DialogQuaderno", "Nuova pagina nel quaderno", Q_NULLPTR));
        apriPushButton->setText(QApplication::translate("DialogQuaderno", "Apri una pagina esistente", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogQuaderno", "Annulla", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogQuaderno: public Ui_DialogQuaderno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADERNODIALOG_H
