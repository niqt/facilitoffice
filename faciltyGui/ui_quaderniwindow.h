/********************************************************************************
** Form generated from reading UI file 'quaderniwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUADERNIWINDOW_H
#define UI_QUADERNIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *quaderno1PushButton;
    QPushButton *quaderno2PushButton;
    QPushButton *quaderno3PushButton;
    QPushButton *quaderno4PushButton;
    QPushButton *quaderno5PushButton;
    QPushButton *quaderno6PushButton;
    QPushButton *quaderno7pushButton;
    QPushButton *quaderno8PushButton;
    QPushButton *quaderno9PushButton;
    QPushButton *quaderno10PushButton;
    QMenuBar *menubar;
    QMenu *menuChiudi;
    QMenu *menuInserisci_Etichetta_al_Quaderno;
    QMenu *menuApri_Quaderno;
    QMenu *menuGestisci_Modelli;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setPointSize(17);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        quaderno1PushButton = new QPushButton(centralwidget);
        quaderno1PushButton->setObjectName(QStringLiteral("quaderno1PushButton"));
        quaderno1PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno1PushButton, 0, 0, 1, 1);

        quaderno2PushButton = new QPushButton(centralwidget);
        quaderno2PushButton->setObjectName(QStringLiteral("quaderno2PushButton"));
        quaderno2PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno2PushButton, 0, 1, 1, 1);

        quaderno3PushButton = new QPushButton(centralwidget);
        quaderno3PushButton->setObjectName(QStringLiteral("quaderno3PushButton"));
        quaderno3PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno3PushButton, 0, 2, 1, 1);

        quaderno4PushButton = new QPushButton(centralwidget);
        quaderno4PushButton->setObjectName(QStringLiteral("quaderno4PushButton"));
        quaderno4PushButton->setMinimumSize(QSize(150, 190));

        gridLayout->addWidget(quaderno4PushButton, 0, 3, 1, 1);

        quaderno5PushButton = new QPushButton(centralwidget);
        quaderno5PushButton->setObjectName(QStringLiteral("quaderno5PushButton"));
        quaderno5PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno5PushButton, 0, 4, 1, 1);

        quaderno6PushButton = new QPushButton(centralwidget);
        quaderno6PushButton->setObjectName(QStringLiteral("quaderno6PushButton"));
        quaderno6PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno6PushButton, 1, 0, 1, 1);

        quaderno7pushButton = new QPushButton(centralwidget);
        quaderno7pushButton->setObjectName(QStringLiteral("quaderno7pushButton"));
        quaderno7pushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno7pushButton, 1, 1, 1, 1);

        quaderno8PushButton = new QPushButton(centralwidget);
        quaderno8PushButton->setObjectName(QStringLiteral("quaderno8PushButton"));
        quaderno8PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno8PushButton, 1, 2, 1, 1);

        quaderno9PushButton = new QPushButton(centralwidget);
        quaderno9PushButton->setObjectName(QStringLiteral("quaderno9PushButton"));
        quaderno9PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno9PushButton, 1, 3, 1, 1);

        quaderno10PushButton = new QPushButton(centralwidget);
        quaderno10PushButton->setObjectName(QStringLiteral("quaderno10PushButton"));
        quaderno10PushButton->setMinimumSize(QSize(140, 190));

        gridLayout->addWidget(quaderno10PushButton, 1, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 34));
        menuChiudi = new QMenu(menubar);
        menuChiudi->setObjectName(QStringLiteral("menuChiudi"));
        QFont font1;
        font1.setPointSize(20);
        menuChiudi->setFont(font1);
        menuInserisci_Etichetta_al_Quaderno = new QMenu(menubar);
        menuInserisci_Etichetta_al_Quaderno->setObjectName(QStringLiteral("menuInserisci_Etichetta_al_Quaderno"));
        menuApri_Quaderno = new QMenu(menubar);
        menuApri_Quaderno->setObjectName(QStringLiteral("menuApri_Quaderno"));
        menuGestisci_Modelli = new QMenu(menubar);
        menuGestisci_Modelli->setObjectName(QStringLiteral("menuGestisci_Modelli"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuChiudi->menuAction());
        menubar->addAction(menuInserisci_Etichetta_al_Quaderno->menuAction());
        menubar->addAction(menuApri_Quaderno->menuAction());
        menubar->addAction(menuGestisci_Modelli->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(quaderno2PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno2()));
        QObject::connect(quaderno1PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno1()));
        QObject::connect(quaderno3PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno3()));
        QObject::connect(quaderno4PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno4()));
        QObject::connect(quaderno5PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno5()));
        QObject::connect(quaderno10PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno10()));
        QObject::connect(quaderno9PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno9()));
        QObject::connect(quaderno8PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno8()));
        QObject::connect(quaderno7pushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno7()));
        QObject::connect(quaderno6PushButton, SIGNAL(clicked()), MainWindow, SLOT(quaderno6()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        quaderno1PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno2PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno3PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno4PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno5PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno6PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno7pushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno8PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno9PushButton->setText(QApplication::translate("MainWindow", "Quaderno di", Q_NULLPTR));
        quaderno10PushButton->setText(QApplication::translate("MainWindow", "Quaderni di", Q_NULLPTR));
        menuChiudi->setTitle(QApplication::translate("MainWindow", "Chiudi", Q_NULLPTR));
        menuInserisci_Etichetta_al_Quaderno->setTitle(QApplication::translate("MainWindow", "Inserisci Etichetta al Quaderno", Q_NULLPTR));
        menuApri_Quaderno->setTitle(QApplication::translate("MainWindow", "Apri Quaderno", Q_NULLPTR));
        menuGestisci_Modelli->setTitle(QApplication::translate("MainWindow", "Gestisci Modelli", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADERNIWINDOW_H
