#include "dialogetichetta.h"
#include "ui_dialogetichetta.h"

DialogEtichetta::DialogEtichetta(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogEtichetta)
{
    ui->setupUi(this);
}

QString DialogEtichetta::etichetta(QString n)
{
    ui->label_2->setText(n);
    QDialog::exec();
    return ui->lineEdit->text();
}




DialogEtichetta::~DialogEtichetta()
{
    delete ui;
}
