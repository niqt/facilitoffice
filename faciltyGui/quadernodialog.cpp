#include "quadernodialog.h"
#include "ui_quadernodialog.h"

QuadernoDialog::QuadernoDialog(QWidget *parent): QDialog(parent), ui(new Ui::DialogQuaderno)
{
    ui->setupUi(this);

}

QuadernoDialog::~QuadernoDialog()
{
    delete ui;
}
