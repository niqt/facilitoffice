/********************************************************************************
** Form generated from reading UI file 'dialog_configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CONFIGURATION_H
#define UI_DIALOG_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tabSintesi;
    QComboBox *voiceComboBox;
    QLabel *label;
    QSlider *speedHorizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *volumeHorizontalSlider;
    QTextEdit *textEdit;
    QPushButton *playPushButton;
    QPushButton *stopPushButton;
    QCheckBox *evidenziaCheckBox;
    QCheckBox *mantieniCheckBox;
    QGroupBox *groupBox;
    QRadioButton *modificaRadioButton;
    QRadioButton *evidenziaRadioButton;
    QRadioButton *sottolineaRadioButton;
    QPushButton *colorePushButton;
    QSlider *waitHorizontalSlider;
    QLabel *label_5;
    QWidget *tabPulsanti;
    QCheckBox *letturaCheckBox;
    QCheckBox *evidenziaRigaCheckBox;
    QCheckBox *scelteCheckBox;
    QCheckBox *quaderniCheckBox;
    QWidget *tabScelte;
    QLabel *label_4;
    QCheckBox *eliminaScelteCheckBox;
    QCheckBox *eliminaQuaderniCheckBox;
    QPushButton *reimpostaPushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(787, 564);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(700, 30, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 681, 531));
        tabSintesi = new QWidget();
        tabSintesi->setObjectName(QStringLiteral("tabSintesi"));
        voiceComboBox = new QComboBox(tabSintesi);
        voiceComboBox->setObjectName(QStringLiteral("voiceComboBox"));
        voiceComboBox->setGeometry(QRect(20, 50, 81, 24));
        label = new QLabel(tabSintesi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 52, 15));
        speedHorizontalSlider = new QSlider(tabSintesi);
        speedHorizontalSlider->setObjectName(QStringLiteral("speedHorizontalSlider"));
        speedHorizontalSlider->setGeometry(QRect(20, 110, 160, 23));
        speedHorizontalSlider->setMinimum(5);
        speedHorizontalSlider->setMaximum(20);
        speedHorizontalSlider->setSingleStep(1);
        speedHorizontalSlider->setPageStep(1);
        speedHorizontalSlider->setValue(10);
        speedHorizontalSlider->setSliderPosition(10);
        speedHorizontalSlider->setOrientation(Qt::Horizontal);
        speedHorizontalSlider->setTickInterval(1);
        label_2 = new QLabel(tabSintesi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 52, 15));
        label_3 = new QLabel(tabSintesi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 52, 15));
        volumeHorizontalSlider = new QSlider(tabSintesi);
        volumeHorizontalSlider->setObjectName(QStringLiteral("volumeHorizontalSlider"));
        volumeHorizontalSlider->setGeometry(QRect(20, 170, 160, 23));
        volumeHorizontalSlider->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(tabSintesi);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(230, 30, 351, 161));
        playPushButton = new QPushButton(tabSintesi);
        playPushButton->setObjectName(QStringLiteral("playPushButton"));
        playPushButton->setGeometry(QRect(230, 220, 97, 24));
        stopPushButton = new QPushButton(tabSintesi);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));
        stopPushButton->setGeometry(QRect(480, 220, 97, 24));
        evidenziaCheckBox = new QCheckBox(tabSintesi);
        evidenziaCheckBox->setObjectName(QStringLiteral("evidenziaCheckBox"));
        evidenziaCheckBox->setGeometry(QRect(20, 300, 191, 23));
        mantieniCheckBox = new QCheckBox(tabSintesi);
        mantieniCheckBox->setObjectName(QStringLiteral("mantieniCheckBox"));
        mantieniCheckBox->setGeometry(QRect(40, 340, 271, 23));
        groupBox = new QGroupBox(tabSintesi);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 380, 241, 101));
        modificaRadioButton = new QRadioButton(groupBox);
        modificaRadioButton->setObjectName(QStringLiteral("modificaRadioButton"));
        modificaRadioButton->setGeometry(QRect(10, 20, 171, 21));
        evidenziaRadioButton = new QRadioButton(groupBox);
        evidenziaRadioButton->setObjectName(QStringLiteral("evidenziaRadioButton"));
        evidenziaRadioButton->setGeometry(QRect(10, 50, 161, 21));
        sottolineaRadioButton = new QRadioButton(groupBox);
        sottolineaRadioButton->setObjectName(QStringLiteral("sottolineaRadioButton"));
        sottolineaRadioButton->setGeometry(QRect(10, 80, 93, 21));
        colorePushButton = new QPushButton(tabSintesi);
        colorePushButton->setObjectName(QStringLiteral("colorePushButton"));
        colorePushButton->setGeometry(QRect(280, 390, 97, 24));
        waitHorizontalSlider = new QSlider(tabSintesi);
        waitHorizontalSlider->setObjectName(QStringLiteral("waitHorizontalSlider"));
        waitHorizontalSlider->setGeometry(QRect(20, 240, 160, 23));
        waitHorizontalSlider->setMinimum(5);
        waitHorizontalSlider->setMaximum(40);
        waitHorizontalSlider->setSingleStep(5);
        waitHorizontalSlider->setValue(10);
        waitHorizontalSlider->setOrientation(Qt::Horizontal);
        waitHorizontalSlider->setTickPosition(QSlider::TicksBothSides);
        waitHorizontalSlider->setTickInterval(5);
        label_5 = new QLabel(tabSintesi);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 210, 111, 16));
        tabWidget->addTab(tabSintesi, QString());
        tabPulsanti = new QWidget();
        tabPulsanti->setObjectName(QStringLiteral("tabPulsanti"));
        letturaCheckBox = new QCheckBox(tabPulsanti);
        letturaCheckBox->setObjectName(QStringLiteral("letturaCheckBox"));
        letturaCheckBox->setGeometry(QRect(10, 20, 131, 23));
        letturaCheckBox->setChecked(true);
        evidenziaRigaCheckBox = new QCheckBox(tabPulsanti);
        evidenziaRigaCheckBox->setObjectName(QStringLiteral("evidenziaRigaCheckBox"));
        evidenziaRigaCheckBox->setGeometry(QRect(10, 60, 121, 23));
        evidenziaRigaCheckBox->setChecked(true);
        scelteCheckBox = new QCheckBox(tabPulsanti);
        scelteCheckBox->setObjectName(QStringLiteral("scelteCheckBox"));
        scelteCheckBox->setGeometry(QRect(10, 100, 111, 23));
        scelteCheckBox->setChecked(true);
        quaderniCheckBox = new QCheckBox(tabPulsanti);
        quaderniCheckBox->setObjectName(QStringLiteral("quaderniCheckBox"));
        quaderniCheckBox->setGeometry(QRect(10, 140, 82, 23));
        quaderniCheckBox->setChecked(true);
        tabWidget->addTab(tabPulsanti, QString());
        tabScelte = new QWidget();
        tabScelte->setObjectName(QStringLiteral("tabScelte"));
        label_4 = new QLabel(tabScelte);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 641, 16));
        QFont font;
        font.setPointSize(15);
        label_4->setFont(font);
        eliminaScelteCheckBox = new QCheckBox(tabScelte);
        eliminaScelteCheckBox->setObjectName(QStringLiteral("eliminaScelteCheckBox"));
        eliminaScelteCheckBox->setGeometry(QRect(10, 60, 341, 23));
        eliminaQuaderniCheckBox = new QCheckBox(tabScelte);
        eliminaQuaderniCheckBox->setObjectName(QStringLiteral("eliminaQuaderniCheckBox"));
        eliminaQuaderniCheckBox->setGeometry(QRect(10, 100, 151, 23));
        reimpostaPushButton = new QPushButton(tabScelte);
        reimpostaPushButton->setObjectName(QStringLiteral("reimpostaPushButton"));
        reimpostaPushButton->setGeometry(QRect(150, 180, 251, 61));
        QFont font1;
        font1.setPointSize(19);
        reimpostaPushButton->setFont(font1);
        tabWidget->addTab(tabScelte, QString());

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        voiceComboBox->clear();
        voiceComboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Maschio", Q_NULLPTR)
         << QApplication::translate("Dialog", "Femmina", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Dialog", "Voce", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Velocit\303\240", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Volume", Q_NULLPTR));
        playPushButton->setText(QApplication::translate("Dialog", "Prova Lettura", Q_NULLPTR));
        stopPushButton->setText(QApplication::translate("Dialog", "Interrompi", Q_NULLPTR));
        evidenziaCheckBox->setText(QApplication::translate("Dialog", "Evidenzia durante la lettura", Q_NULLPTR));
        mantieniCheckBox->setText(QApplication::translate("Dialog", "Mantieni evidenziato durante la lettura", Q_NULLPTR));
        groupBox->setTitle(QString());
        modificaRadioButton->setText(QApplication::translate("Dialog", "Modifica colore del testo", Q_NULLPTR));
        evidenziaRadioButton->setText(QApplication::translate("Dialog", "Evidenzia lo sfondo", Q_NULLPTR));
        sottolineaRadioButton->setText(QApplication::translate("Dialog", "Sottolinea", Q_NULLPTR));
        colorePushButton->setText(QApplication::translate("Dialog", "Colore", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Pausa di lettura", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabSintesi), QApplication::translate("Dialog", "Sintesi Vocale", Q_NULLPTR));
        letturaCheckBox->setText(QApplication::translate("Dialog", "Lettura del testo", Q_NULLPTR));
        evidenziaRigaCheckBox->setText(QApplication::translate("Dialog", "Evidenzia riga", Q_NULLPTR));
        scelteCheckBox->setText(QApplication::translate("Dialog", "Scelte rapide", Q_NULLPTR));
        quaderniCheckBox->setText(QApplication::translate("Dialog", "Quaderni", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabPulsanti), QApplication::translate("Dialog", "Pulsanti facilitati visibili", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Utilizzando questa funzione tutte le scelte effettuate verranno annullate", Q_NULLPTR));
        eliminaScelteCheckBox->setText(QApplication::translate("Dialog", "Elimina anche l'elenco personalizzato Scelte Rapide", Q_NULLPTR));
        eliminaQuaderniCheckBox->setText(QApplication::translate("Dialog", "Elimina Quaderni", Q_NULLPTR));
        reimpostaPushButton->setText(QApplication::translate("Dialog", "Reimposta", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabScelte), QApplication::translate("Dialog", "Reimposta tutte le scelte", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONFIGURATION_H
