/********************************************************************************
** Form generated from reading UI file 'dialogetichetta.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGETICHETTA_H
#define UI_DIALOGETICHETTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEtichetta
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogEtichetta)
    {
        if (DialogEtichetta->objectName().isEmpty())
            DialogEtichetta->setObjectName(QStringLiteral("DialogEtichetta"));
        DialogEtichetta->resize(581, 286);
        gridLayout_2 = new QGridLayout(DialogEtichetta);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogEtichetta);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(DialogEtichetta);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setScaledContents(false);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(13, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit = new QLineEdit(DialogEtichetta);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 72));
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton = new QPushButton(DialogEtichetta);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setPointSize(25);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(DialogEtichetta);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogEtichetta, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEtichetta);
    } // setupUi

    void retranslateUi(QDialog *DialogEtichetta)
    {
        DialogEtichetta->setWindowTitle(QApplication::translate("DialogEtichetta", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogEtichetta", "Quaderno n.", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogEtichetta", "0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogEtichetta", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEtichetta: public Ui_DialogEtichetta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGETICHETTA_H
