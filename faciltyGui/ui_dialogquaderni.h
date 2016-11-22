/********************************************************************************
** Form generated from reading UI file 'dialogquaderni.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGQUADERNI_H
#define UI_DIALOGQUADERNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogQuaderni
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_1;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;

    void setupUi(QDialog *DialogQuaderni)
    {
        if (DialogQuaderni->objectName().isEmpty())
            DialogQuaderni->setObjectName(QStringLiteral("DialogQuaderni"));
        DialogQuaderni->resize(497, 463);
        gridLayout_2 = new QGridLayout(DialogQuaderni);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(DialogQuaderni);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(DialogQuaderni);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_3, 0, 3, 1, 1);

        pushButton_4 = new QPushButton(DialogQuaderni);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_4, 0, 4, 1, 1);

        pushButton_5 = new QPushButton(DialogQuaderni);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_5, 0, 5, 1, 1);

        pushButton_6 = new QPushButton(DialogQuaderni);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(DialogQuaderni);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(DialogQuaderni);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_10, 1, 5, 1, 1);

        pushButton_1 = new QPushButton(DialogQuaderni);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(DialogQuaderni);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_9, 1, 4, 1, 1);

        pushButton_8 = new QPushButton(DialogQuaderni);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 200));

        gridLayout->addWidget(pushButton_8, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(DialogQuaderni);
        QObject::connect(pushButton_1, SIGNAL(clicked()), DialogQuaderni, SLOT(q1()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), DialogQuaderni, SLOT(q2()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), DialogQuaderni, SLOT(q3()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), DialogQuaderni, SLOT(q4()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), DialogQuaderni, SLOT(q5()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), DialogQuaderni, SLOT(q6()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), DialogQuaderni, SLOT(q7()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), DialogQuaderni, SLOT(q10()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), DialogQuaderni, SLOT(q8()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), DialogQuaderni, SLOT(q9()));

        QMetaObject::connectSlotsByName(DialogQuaderni);
    } // setupUi

    void retranslateUi(QDialog *DialogQuaderni)
    {
        DialogQuaderni->setWindowTitle(QApplication::translate("DialogQuaderni", "DialogQuaderni", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("DialogQuaderni", "2\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("DialogQuaderni", "3\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("DialogQuaderni", "4\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("DialogQuaderni", "5\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("DialogQuaderni", "6\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("DialogQuaderni", "7\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("DialogQuaderni", "10\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("DialogQuaderni", "1\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("DialogQuaderni", "9\n"
"Quaderno\n"
"di", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("DialogQuaderni", "8\n"
"Quaderno\n"
"di", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogQuaderni: public Ui_DialogQuaderni {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGQUADERNI_H
