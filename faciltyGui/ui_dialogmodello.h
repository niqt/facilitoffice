/********************************************************************************
** Form generated from reading UI file 'dialogmodello.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODELLO_H
#define UI_DIALOGMODELLO_H

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

QT_BEGIN_NAMESPACE

class Ui_DialogModello
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_load;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_chiudi;

    void setupUi(QDialog *DialogModello)
    {
        if (DialogModello->objectName().isEmpty())
            DialogModello->setObjectName(QStringLiteral("DialogModello"));
        DialogModello->resize(546, 279);
        gridLayout = new QGridLayout(DialogModello);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DialogModello);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(DialogModello);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font1;
        font1.setPointSize(20);
        lineEdit->setFont(font1);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label_2 = new QLabel(DialogModello);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_load = new QPushButton(DialogModello);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setFont(font1);

        horizontalLayout->addWidget(pushButton_load);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_chiudi = new QPushButton(DialogModello);
        pushButton_chiudi->setObjectName(QStringLiteral("pushButton_chiudi"));
        pushButton_chiudi->setFont(font1);

        horizontalLayout->addWidget(pushButton_chiudi);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(DialogModello);
        QObject::connect(pushButton_chiudi, SIGNAL(clicked()), DialogModello, SLOT(accept()));
        QObject::connect(pushButton_load, SIGNAL(clicked()), DialogModello, SLOT(loadModello()));

        QMetaObject::connectSlotsByName(DialogModello);
    } // setupUi

    void retranslateUi(QDialog *DialogModello)
    {
        DialogModello->setWindowTitle(QApplication::translate("DialogModello", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogModello", "Descrizione", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_load->setText(QApplication::translate("DialogModello", "Carica modello", Q_NULLPTR));
        pushButton_chiudi->setText(QApplication::translate("DialogModello", "Chiudi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogModello: public Ui_DialogModello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODELLO_H
