/********************************************************************************
** Form generated from reading UI file 'dialogvocabolario.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGVOCABOLARIO_H
#define UI_DIALOGVOCABOLARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogVocabolario
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabConsulta;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QWidget *tabGestisci;
    QGridLayout *gridLayout_2;
    QLabel *labelImgTxt;
    QLabel *labelTermine;
    QLabel *labelImg;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextEdit *textEdit;
    QListView *listView;
    QPushButton *pushButtonNuovo;
    QPushButton *pushButtonElimina;
    QPushButton *pushButtonImg;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *DialogVocabolario)
    {
        if (DialogVocabolario->objectName().isEmpty())
            DialogVocabolario->setObjectName(QStringLiteral("DialogVocabolario"));
        DialogVocabolario->setWindowModality(Qt::WindowModal);
        DialogVocabolario->resize(600, 421);
        gridLayout = new QGridLayout(DialogVocabolario);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(DialogVocabolario);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabConsulta = new QWidget();
        tabConsulta->setObjectName(QStringLiteral("tabConsulta"));
        gridLayout_3 = new QGridLayout(tabConsulta);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableView = new QTableView(tabConsulta);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_3->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(tabConsulta, QString());
        tabGestisci = new QWidget();
        tabGestisci->setObjectName(QStringLiteral("tabGestisci"));
        gridLayout_2 = new QGridLayout(tabGestisci);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelImgTxt = new QLabel(tabGestisci);
        labelImgTxt->setObjectName(QStringLiteral("labelImgTxt"));

        gridLayout_2->addWidget(labelImgTxt, 0, 0, 1, 1);

        labelTermine = new QLabel(tabGestisci);
        labelTermine->setObjectName(QStringLiteral("labelTermine"));

        gridLayout_2->addWidget(labelTermine, 0, 4, 2, 1);

        labelImg = new QLabel(tabGestisci);
        labelImg->setObjectName(QStringLiteral("labelImg"));

        gridLayout_2->addWidget(labelImg, 1, 0, 5, 3);

        lineEdit = new QLineEdit(tabGestisci);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 2, 4, 1, 1);

        label = new QLabel(tabGestisci);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 4, 1, 1);

        textEdit = new QTextEdit(tabGestisci);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 4, 4, 1, 1);

        listView = new QListView(tabGestisci);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_2->addWidget(listView, 5, 4, 2, 1);

        pushButtonNuovo = new QPushButton(tabGestisci);
        pushButtonNuovo->setObjectName(QStringLiteral("pushButtonNuovo"));

        gridLayout_2->addWidget(pushButtonNuovo, 6, 0, 1, 1);

        pushButtonElimina = new QPushButton(tabGestisci);
        pushButtonElimina->setObjectName(QStringLiteral("pushButtonElimina"));
        pushButtonElimina->setEnabled(false);

        gridLayout_2->addWidget(pushButtonElimina, 6, 1, 1, 1);

        pushButtonImg = new QPushButton(tabGestisci);
        pushButtonImg->setObjectName(QStringLiteral("pushButtonImg"));

        gridLayout_2->addWidget(pushButtonImg, 6, 2, 1, 1);

        pushButtonSave = new QPushButton(tabGestisci);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        gridLayout_2->addWidget(pushButtonSave, 6, 3, 1, 1);

        tabWidget->addTab(tabGestisci, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(DialogVocabolario);
        QObject::connect(pushButtonNuovo, SIGNAL(clicked()), DialogVocabolario, SLOT(nuovo()));
        QObject::connect(pushButtonElimina, SIGNAL(clicked()), DialogVocabolario, SLOT(elimina()));
        QObject::connect(pushButtonImg, SIGNAL(clicked()), DialogVocabolario, SLOT(immagine()));
        QObject::connect(pushButtonSave, SIGNAL(clicked()), DialogVocabolario, SLOT(save()));
        QObject::connect(listView, SIGNAL(clicked(QModelIndex)), DialogVocabolario, SLOT(select(QModelIndex)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogVocabolario);
    } // setupUi

    void retranslateUi(QDialog *DialogVocabolario)
    {
        DialogVocabolario->setWindowTitle(QApplication::translate("DialogVocabolario", "Termini", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabConsulta), QApplication::translate("DialogVocabolario", "Consultta Termini", Q_NULLPTR));
        labelImgTxt->setText(QApplication::translate("DialogVocabolario", "Immagine", Q_NULLPTR));
        labelTermine->setText(QApplication::translate("DialogVocabolario", "Termine:", Q_NULLPTR));
        labelImg->setText(QString());
        label->setText(QApplication::translate("DialogVocabolario", "Definizione:", Q_NULLPTR));
        pushButtonNuovo->setText(QApplication::translate("DialogVocabolario", "Nuovo", Q_NULLPTR));
        pushButtonElimina->setText(QApplication::translate("DialogVocabolario", "Elimina", Q_NULLPTR));
        pushButtonImg->setText(QApplication::translate("DialogVocabolario", "Immagine", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("DialogVocabolario", "Salva", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabGestisci), QApplication::translate("DialogVocabolario", "Gestisci Termini", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogVocabolario: public Ui_DialogVocabolario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGVOCABOLARIO_H
