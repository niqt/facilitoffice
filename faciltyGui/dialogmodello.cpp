#include "dialogmodello.h"
#include "ui_dialogmodello.h"
#include <QtWidgets/QFileDialog>

DialogModello::DialogModello(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogModello)
{
    m_ui->setupUi(this);
}

void DialogModello::loadModello()
{
     QString fileName = QFileDialog::getOpenFileName(this, tr("Carica"),
                                                 QDir::homePath(),
                                                 tr("Modelli (*.odt *pdf )"));
     m_ui->label_2->setText(fileName);
}

QStringList DialogModello::getModello()
{
    QStringList model;
    QDialog::exec();
    model << m_ui->label_2->text() << m_ui->lineEdit->text();
    return model;
}

DialogModello::~DialogModello()
{
    delete m_ui;
}

void DialogModello::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
